use std::ffi::c_void;
use std::os::raw::{c_double, c_int, c_longlong};
use std::ptr;
use libloading::{Library, Symbol};

pub struct Moo {
    lib: Library,
}

impl Moo {
    pub fn new(path: &str) -> Result<Self, libloading::Error> {
        let lib = Library::new(path)?;
        Ok(Moo { lib })
    }

    pub unsafe fn abs(&self, x: f64) -> f64 {
        let func: Symbol<unsafe extern "C" fn(c_double) -> c_double> = self.lib.get(b"absolute").unwrap();
        func(x)
    }

    pub unsafe fn idiv(&self, a: f64, b: f64) -> i64 {
        let func: Symbol<unsafe extern "C" fn(c_double, c_double) -> c_longlong> = self.lib.get(b"idiv").unwrap();
        func(a, b)
    }

    pub unsafe fn floor(&self, a: f64) -> i64 {
        let func: Symbol<unsafe extern "C" fn(c_double) -> c_longlong> = self.lib.get(b"dfloor").unwrap();
        func(a)
    }

    pub unsafe fn ceil(&self, a: f64) -> i64 {
        let func: Symbol<unsafe extern "C" fn(c_double) -> c_longlong> = self.lib.get(b"dceil").unwrap();
        func(a)
    }

    pub unsafe fn gcd(&self, a: i64, b: i64) -> i64 {
        let func: Symbol<unsafe extern "C" fn(c_longlong, c_longlong) -> c_longlong> = self.lib.get(b"gcd").unwrap();
        func(a, b)
    }

    pub unsafe fn lcm(&self, a: i64, b: i64) -> i64 {
        let func: Symbol<unsafe extern "C" fn(c_longlong, c_longlong) -> c_longlong> = self.lib.get(b"lcm").unwrap();
        func(a, b)
    }

    pub unsafe fn mod_(&self, a: i64, b: i64) -> i64 {
        let func: Symbol<unsafe extern "C" fn(c_longlong, c_longlong) -> c_longlong> = self.lib.get(b"mod").unwrap();
        func(a, b)
    }

    pub unsafe fn flmod(&self, a: f64, b: f64) -> f64 {
        let func: Symbol<unsafe extern "C" fn(c_double, c_double) -> c_double> = self.lib.get(b"flmod").unwrap();
        func(a, b)
    }

    pub unsafe fn fac(&self, n: i64) -> i64 {
        let func: Symbol<unsafe extern "C" fn(c_longlong) -> c_longlong> = self.lib.get(b"fac").unwrap();
        func(n)
    }

    pub unsafe fn binom(&self, n: i64, k: i64) -> i64 {
        let func: Symbol<unsafe extern "C" fn(c_longlong, c_longlong) -> c_longlong> = self.lib.get(b"binom").unwrap();
        func(n, k)
    }

    pub unsafe fn factable(&self, n: i64) -> Vec<i64> {
        if n <= 0 {
            panic!("n cannot be 0.");
        }
        let func: Symbol<unsafe extern "C" fn(c_longlong) -> *mut c_longlong> = self.lib.get(b"factable").unwrap();
        let clear: Symbol<unsafe extern "C" fn(*mut c_longlong)> = self.lib.get(b"clearptr").unwrap();
        let ptr = func(n);
        if ptr.is_null() {
            panic!("NULL pointer returned from factable function.");
        }
        let result = std::slice::from_raw_parts(ptr, (n + 1) as usize).to_vec();
        clear(ptr);
        result
    }

    pub unsafe fn permutation(&self, n: i32, k: i32) -> i64 {
        let func: Symbol<unsafe extern "C" fn(c_int, c_int) -> c_longlong> = self.lib.get(b"permutation").unwrap();
        func(n, k)
    }

    pub unsafe fn combination(&self, n: i32, k: i32) -> i64 {
        let func: Symbol<unsafe extern "C" fn(c_int, c_int) -> c_longlong> = self.lib.get(b"combination").unwrap();
        func(n, k)
    }

    pub unsafe fn gen_perm(&self, n: i64) -> Vec<Vec<i64>> {
        if n <= 0 {
            panic!("n cannot be 0.");
        }
        let func: Symbol<unsafe extern "C" fn(c_longlong) -> *mut c_longlong> = self.lib.get(b"genPerm").unwrap();
        let free: Symbol<unsafe extern "C" fn(*mut c_longlong)> = self.lib.get(b"freePerm").unwrap();
        let ptr = func(n);
        if ptr.is_null() {
            panic!("NULL pointer returned from genPerm function.");
        }
        let total = (1..=n).product::<i64>();
        let slice = std::slice::from_raw_parts(ptr, (total * n) as usize);
        let mut result = Vec::with_capacity(total as usize);
        for i in 0..total {
            let start = (i * n) as usize;
            result.push(slice[start..start + n as usize].to_vec());
        }
        free(ptr);
        result
    }

    pub unsafe fn max(&self, a: f64, b: f64) -> f64 {
        let func: Symbol<unsafe extern "C" fn(c_double, c_double) -> c_double> = self.lib.get(b"max").unwrap();
        func(a, b)
    }

    pub unsafe fn min(&self, a: f64, b: f64) -> f64 {
        let func: Symbol<unsafe extern "C" fn(c_double, c_double) -> c_double> = self.lib.get(b"min").unwrap();
        func(a, b)
    }
}