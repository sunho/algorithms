use std::io::*;
use std::str::FromStr;
use std::{cmp::*, collections::*, iter, mem::*, num::*, ops::*};

fn solve(sc: &mut Scanner) {
    let n: usize = sc.next();
    let mut A = vec![0i32; n];
    for i in 0..n {
        A[i] = sc.next();
        A[i] -= 1;
    }
    let q: usize = sc.next();
    let mut Q = vec![(0, 0usize); q];
    let mut used = HashSet::<usize>::new();
    for i in 0..q {
        Q[i].0 = sc.next();
        Q[i].1 = sc.next();
        if Q[i].0 == 2 {
            used.insert(Q[i].1 - 1);
        }
    }
    let mut uf = UnionFind::new(n);
    for i in 0..n {
        if !used.contains(&i) {
            if A[i] != -1 {
                uf.unite(i, A[i] as usize);
            }
        }
    }
    let mut ans = Vec::<i32>::new();
    for i in (0..q).rev() {
        let qq = Q[i];
        if qq.0 == 2 {
            if A[qq.1 - 1] != -1 {
                uf.unite(qq.1 - 1 as usize, A[qq.1 - 1] as usize);
            }
        } else {
            let x = uf.leader(qq.1 - 1);
            ans.push(uf.ends[x]);
        }
    }
    ans.reverse();
    for a in ans {
        if a == -1 {
            println!("CIKLUS");
        } else {
            println!("{}", a + 1);
        }
    }
}

pub struct UnionFind {
    parent: Vec<usize>,
    size: Vec<usize>,
    pub ends: Vec<i32>,
}

impl UnionFind {
    fn new(n: usize) -> Self {
        Self {
            parent: (0..n).collect(),
            size: vec![1; n],
            ends: (0..n as i32).collect(),
        }
    }

    fn leader(&mut self, u: usize) -> usize {
        if u == self.parent[u] {
            return u;
        }
        self.parent[u] = self.leader(self.parent[u]);
        self.parent[u]
    }

    fn unite(&mut self, u: usize, v: usize) -> bool {
        let mut x = self.leader(u);
        let mut y = self.leader(v);
        if x == y {
            self.ends[x] = -1;
            return false;
        }
        let nw = self.ends[y];
        if self.size[x] > self.size[y] {
            (x, y) = (y, x);
        }
        self.parent[x] = y;
        self.size[y] += self.size[x];
        self.ends[y] = nw;
        true
    }
}

pub struct Scanner<'a> {
    iter: std::str::SplitWhitespace<'a>,
}

impl<'a> Scanner<'a> {
    pub fn new(s: &'a str) -> Scanner<'a> {
        Scanner {
            iter: s.split_whitespace(),
        }
    }

    pub fn next<T: FromStr>(&mut self) -> T {
        let s = self.iter.next().unwrap();
        if let Ok(v) = s.parse::<T>() {
            v
        } else {
            panic!("Parse error")
        }
    }

    pub fn next_vec_len<T: FromStr>(&mut self) -> Vec<T> {
        let n: usize = self.next();
        self.next_vec(n)
    }

    pub fn next_vec<T: FromStr>(&mut self, n: usize) -> Vec<T> {
        (0..n).map(|_| self.next()).collect()
    }
}

thread_local! {
    static STDOUT: std::cell::RefCell<BufWriter<StdoutLock<'static>>> = std::cell::RefCell::new(std::io::BufWriter::with_capacity(1 << 17, stdout().lock()));
}

#[macro_export]
macro_rules! println {
    ($($t:tt)*) => {
        STDOUT.with(|cell| writeln!(cell.borrow_mut(), $($t)*).unwrap());
    };
}

#[macro_export]
macro_rules! print {
    ($($t:tt)*) => {
       STDOUT.with(|cell| write!(cell.borrow_mut(), $($t)*).unwrap());
    };
}

#[macro_export]
macro_rules! flush {
    () => {
        STDOUT.with(|cell| cell.borrow_mut().flush().unwrap());
    };
}

fn main() {
    let mut str = String::new();
    stdin().read_to_string(&mut str).unwrap();
    let mut sc = Scanner::new(&str);
    solve(&mut sc);
}
