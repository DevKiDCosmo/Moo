local ffi = require("ffi")

ffi.cdef[[
    double absolute(double x);
    int64_t idiv(double a, double b);
    int64_t dfloor(double a);
    int64_t dceil(double a);
    int64_t gcd(int64_t a, int64_t b);
    int64_t lcm(int64_t a, int64_t b);
    int64_t mod(int64_t a, int64_t b);
    double flmod(double a, double b);
    int64_t fac(int64_t n);
    int64_t binom(int64_t n, int64_t k);
    int64_t* factable(int64_t n);
    void clearptr(int64_t* ptr);
    int64_t permutation(int n, int k);
    int64_t combination(int n, int k);
    int64_t* genPerm(int64_t n);
    void freePerm(int64_t* ptr);
    double max(double a, double b);
    double min(double a, double b);
]]

local lib = ffi.load("moo")

local moo = {}

function moo.abs(x)
    return lib.absolute(x)
end

function moo.idiv(a, b)
    return lib.idiv(a, b)
end

function moo.floor(a)
    return lib.dfloor(a)
end

function moo.ceil(a)
    return lib.dceil(a)
end

function moo.gcd(a, b)
    return lib.gcd(a, b)
end

function moo.lcm(a, b)
    return lib.lcm(a, b)
end

function moo.mod(a, b)
    return lib.mod(a, b)
end

function moo.flmod(a, b)
    return lib.flmod(a, b)
end

function moo.fac(n)
    return lib.fac(n)
end

function moo.binom(n, k)
    return lib.binom(n, k)
end

function moo.factable(n)
    if n <= 0 then error("n cannot be 0.") end
    local ptr = lib.factable(n)
    if ptr == nil then error("NULL pointer returned from factable function.") end
    local result = {}
    for i = 0, n do
        result[#result+1] = tonumber(ptr[i])
    end
    lib.clearptr(ptr)
    return result
end

function moo.permutation(n, k)
    return lib.permutation(n, k)
end

function moo.combination(n, k)
    return lib.combination(n, k)
end

function moo.genPerm(n)
    if n <= 0 then error("n cannot be 0.") end
    local ptr = lib.genPerm(n)
    if ptr == nil then error("NULL pointer returned from genPerm function.") end
    local total = 1
    for i = 1, n do total = total * i end
    local result = {}
    for i = 0, total-1 do
        local perm = {}
        for j = 0, n-1 do
            perm[#perm+1] = tonumber(ptr[i * n + j])
        end
        result[#result+1] = perm
    end
    lib.freePerm(ptr)
    return result
end

function moo.max(a, b)
    return lib.max(a, b)
end

function moo.min(a, b)
    return lib.min(a, b)
end

return moo