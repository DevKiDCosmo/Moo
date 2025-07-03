using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;

public class Moo
{
    const string DllName = "moo.dll";

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern double absolute(double x);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern long idiv(double a, double b);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, EntryPoint = "dfloor")]
    public static extern long Floor(double a);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl, EntryPoint = "dceil")]
    public static extern long Ceil(double a);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern long gcd(long a, long b);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern long lcm(long a, long b);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern long mod(long a, long b);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern double flmod(double a, double b);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern long fac(long n);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern long binom(long n, long k);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    private static extern IntPtr factable(long n);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    private static extern void clearptr(IntPtr ptr);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern long permutation(int n, int k);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern long combination(int n, int k);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    private static extern IntPtr genPerm(long n);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    private static extern void freePerm(IntPtr ptr);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern double max(double a, double b);

    [DllImport(DllName, CallingConvention = CallingConvention.Cdecl)]
    public static extern double min(double a, double b);

    public static long[] Factable(long n)
    {
        if (n <= 0)
            throw new ArgumentException("n cannot be 0.");
        IntPtr ptr = factable(n);
        if (ptr == IntPtr.Zero)
            throw new Exception("NULL pointer returned from factable function.");
        long[] result = new long[n + 1];
        Marshal.Copy(ptr, result, 0, (int)n + 1);
        clearptr(ptr);
        return result;
    }

    public static List<long[]> GenPerm(long n)
    {
        if (n <= 0)
            throw new ArgumentException("n cannot be 0.");
        IntPtr ptr = genPerm(n);
        if (ptr == IntPtr.Zero)
            throw new Exception("NULL pointer returned from genPerm function.");
        long total = 1;
        for (long i = 1; i <= n; i++) total *= i;
        var result = new List<long[]>((int)total);
        int size = sizeof(long);
        for (long i = 0; i < total; i++)
        {
            long[] perm = new long[n];
            for (long j = 0; j < n; j++)
            {
                perm[j] = Marshal.ReadInt64(ptr, (int)((i * n + j) * size));
            }
            result.Add(perm);
        }
        freePerm(ptr);
        return result;
    }
}