use std::io::{stdin, Read};
use std::str::FromStr;
use std::{cmp::*, collections::*, iter, mem::*, num::*, ops::*};

fn solve() {
    let mut str = String::new();
    stdin().read_to_string(&mut str).unwrap();
    let mut sc = Scanner::new(&str);
    let n = sc.next::<usize>();
    let A = sc.next_vec::<i64>(n);
    let B = sc.next_vec::<i64>(n);
    let m = n / 2;
    let mut left = vec![0i64; 1 << m];
    let mut right = vec![Vec::<(i64, usize)>::new(); m + 1 as usize];
    for msk in 0..1 << m {
        for j in 0..m {
            if (msk >> (m - j - 1)) & 1 == 0 {
                left[msk] += A[j] as i64;
            } else {
                left[msk] -= B[j] as i64;
            }
        }
    }
    for msk in 0..1 << m {
        let mut sum = 0i64;
        let mut cnt = 0;
        for j in 0..m {
            if (msk >> (m - j - 1)) & 1 == 0 {
                sum += A[j + m] as i64;
            } else {
                cnt += 1;
                sum -= B[j + m] as i64;
            }
        }
        right[cnt].push((sum, msk));
    }
    for sz in 0..m + 1 {
        right[sz].sort_unstable();
    }
    let mut ans = (1e18 as i64, 0usize);
    let mut update = |msk: usize, rem_size: usize, ptr: usize| {
        if ptr < right[rem_size].len() {
            ans = min(
                ans,
                (
                    i64::abs(left[msk] + right[rem_size][ptr].0),
                    right[rem_size][ptr].1 | (msk << m),
                ),
            );
        }
    };
    for msk in 0usize..1 << m {
        let sz = msk.count_ones() as usize;
        let rem_size = (m - sz) as usize;
        let mut cands = Vec::<usize>::new();
        let ptr = right[rem_size].partition_point(|&x| x < (-left[msk], 0));
        update(msk, rem_size, ptr);
        if ptr != 0 {
            update(
                msk,
                rem_size,
                right[rem_size].partition_point(|&x| x < (right[rem_size][ptr - 1].0, 0)),
            );
        }
        update(
            msk,
            rem_size,
            right[rem_size].partition_point(|&x| x < (-left[msk], 1 << m)),
        );
    }
    for i in (0..n).rev() {
        if (ans.1 >> i) & 1 == 0 {
            print!("{} ", 1);
        } else {
            print!("{} ", 2);
        }
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

fn main() {
    solve();
}
