import com.sun.jna.*;
import com.sun.jna.ptr.PointerByReference;
import java.util.ArrayList;
import java.util.List;

public class Moo {
    public interface MooLib extends Library {
        MooLib INSTANCE = Native.load("moo", MooLib.class);

        double absolute(double x);
        long idiv(double a, double b);
        long floor(double a);
        long ceil(double a);
        long gcd(long a, long b);
        long lcm(long a, long b);
        long mod(long a, long b);
        double flmod(double a, double b);
        long fac(long n);
        long binom(long n, long k);
        Pointer factable(long n);
        long permutation(int n, int k);
        long combination(int n, int k);
        Pointer genPerm(long n);
        double max(double a, double b);
        double min(double a, double b);
    }

    public static double abs(double x) {
        return MooLib.INSTANCE.absolute(x);
    }

    public static long idiv(double a, double b) {
        return MooLib.INSTANCE.idiv(a, b);
    }

    public static long floor(double a) {
        return MooLib.INSTANCE.floor(a);
    }

    public static long ceil(double a) {
        return MooLib.INSTANCE.ceil(a);
    }

    public static long gcd(long a, long b) {
        return MooLib.INSTANCE.gcd(a, b);
    }

    public static long lcm(long a, long b) {
        return MooLib.INSTANCE.lcm(a, b);
    }

    public static long mod(long a, long b) {
        return MooLib.INSTANCE.mod(a, b);
    }

    public static double flmod(double a, double b) {
        return MooLib.INSTANCE.flmod(a, b);
    }

    public static long fac(long n) {
        return MooLib.INSTANCE.fac(n);
    }

    public static long binom(long n, long k) {
        return MooLib.INSTANCE.binom(n, k);
    }

    public static long[] factable(long n) {
        if (n <= 0) throw new IllegalArgumentException("n cannot be 0.");
        Pointer ptr = MooLib.INSTANCE.factable(n);
        if (ptr == null) throw new RuntimeException("NULL pointer returned from factable function.");
        long[] result = ptr.getLongArray(0, (int) n + 1);
        MooLib.INSTANCE.clearptr(ptr);
        return result;
    }

    public static long permutation(int n, int k) {
        return MooLib.INSTANCE.permutation(n, k);
    }

    public static long combination(int n, int k) {
        return MooLib.INSTANCE.combination(n, k);
    }

    public static List<long[]> genPerm(int n) {
        if (n <= 0) throw new IllegalArgumentException("n cannot be 0.");
        Pointer ptr = MooLib.INSTANCE.genPerm(n);
        if (ptr == null) throw new RuntimeException("NULL pointer returned from genPerm function.");
        int total = 1;
        for (int i = 1; i <= n; i++) total *= i;
        List<long[]> result = new ArrayList<>();
        for (int i = 0; i < total; i++) {
            long[] perm = new long[n];
            for (int j = 0; j < n; j++) {
                perm[j] = ptr.getLong((i * n + j) * Native.getNativeSize(Long.TYPE));
            }
            result.add(perm);
        }
        MooLib.INSTANCE.freeptr(ptr);
        return result;
    }

    public static double max(double a, double b) {
        return MooLib.INSTANCE.max(a, b);
    }

    public static double min(double a, double b) {
        return MooLib.INSTANCE.min(a, b);
    }
}