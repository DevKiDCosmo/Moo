import com.sun.jna.*;
import com.sun.jna.ptr.PointerByReference;

public class Moo {
    public interface MooLib extends Library {
        MooLib INSTANCE = Native.load("moo", MooLib.class);

        double absolute(double x);
        long idiv(double a, double b);
        long floor(double a, double b);
    }

    public static double absolute(double x) {
        return MooLib.INSTANCE.absolute(x);
    }

    public static long idiv(double a, double b) {
        return MooLib.INSTANCE.idiv(a, b);
    }

    public static long floor(double a, double b) {
        return MooLib.INSTANCE.floor(a, b);
    }
}