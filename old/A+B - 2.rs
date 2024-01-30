use std::io::*;
use std::str::FromStr;
use std::{cmp::*, collections::*, iter, mem::*, num::*, ops::*};

fn solve(sc: &mut Scanner) {
    let a: i32 = sc.next();
    let b: i32 = sc.next();
    println!("{}", a + b);
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
