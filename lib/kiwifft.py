import array
import _io
import _decimal


class Unsafe:
    __slots__ = ('p', 'nogc')

    def __init__(self):
        self.nogc = []

    def magic(self):
        self.p = [0]
        f = _io._RawIOBase()
        f.readable = lambda: True
        f.readinto = lambda x: not self.p.__setitem__(0, x)
        r = _io.BufferedReader(f)
        r.read(1)
        del r
        ptr = self.p[0].cast('P')
        obj = [0] * len(ptr)
        self.nogc.append(obj)
        return ptr, obj

    def view(self, addr, n):
        ptr, obj = self.magic()
        data = array.array(
            'Q', [9, id(bytearray), n, n, addr, addr, 0]).tobytes()
        self.nogc.append(data)
        ptr[0] = id(data) + 32
        return obj[0]


class FFT:
    __slots__ = ('unsafe', 'a_repr', 'b_repr', 'a', 'b')
    _decimal.getcontext().prec = 1 << 30
    _decimal.getcontext().Emax = 1 << 30

    def __init__(self):
        self.unsafe = Unsafe()
        self.a_repr = array.array(
            'Q', [9, id(_decimal.Decimal), 0, 0, 0, 0, 0, 0, 0])
        self.b_repr = array.array('Q', self.a_repr)
        self.unsafe.nogc.append(self.a_repr)
        self.unsafe.nogc.append(self.b_repr)
        a_addr = int.from_bytes(
            self.unsafe.view(id(self.a_repr) + 24, 8), 'little')
        b_addr = int.from_bytes(
            self.unsafe.view(id(self.b_repr) + 24, 8), 'little')
        ptr, a_obj = self.unsafe.magic()
        ptr[0] = a_addr
        ptr, b_obj = self.unsafe.magic()
        ptr[0] = b_addr
        self.a = a_obj[0]
        self.b = b_obj[0]

    def conv(self, a: array.array('Q'), b: array.array('Q')) -> array.array('Q'):
        a_buf = int.from_bytes(self.unsafe.view(id(a) + 24, 8), 'little')
        self.a_repr[6] = len(a)
        self.a_repr[8] = a_buf
        b_buf = int.from_bytes(self.unsafe.view(id(b) + 24, 8), 'little')
        self.b_repr[6] = len(b)
        self.b_repr[8] = b_buf
        c = self.a * self.b
        c_repr = self.unsafe.view(id(c) + 48, 24)
        c_len = int.from_bytes(c_repr[:8], 'little')
        c_buf = int.from_bytes(c_repr[-8:], 'little')
        r = array.array('Q')
        r.frombytes(self.unsafe.view(c_buf, c_len * 8))
        return r


def main():
    fft = FFT()
    a = array.array('Q', [0, 1, 0, 1])
    b = array.array('Q', [1, 0, 1])
    print(a, '*', b, '=', fft.conv(a, b))


main()
