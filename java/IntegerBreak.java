import java.lang.Math;

public class IntegerBreak {
    public static void main(String[] args) {
        System.out.println("result: " + Solution(4));
    }

    public static int Solution(int n) {
        if (n <= 2) {
            return 1;
        }

        int max = 0;
        for (int i = 1; i < n - 1; i++) {
            max = Math.max(Solution(i), Solution(i + 1));
        }

        return max + n;
    }

}