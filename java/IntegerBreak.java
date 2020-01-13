import java.lang.Math;

public class IntegerBreak {
    public static void main(String[] args) {
        int n = 10;
        array = new int[n+1];

        for(int i= 0;i < n; i++){
            array[i] = i;
        }
        System.out.println("result: " + Solution(n));
    }

    public static int Solution(int n) {
        if (n <= 1) {
            return 1;
        }

        for (int i = 1; i < n; i++) {
            if(array[i] == 0)
                array[i] = Solution(i);
            if(array[n-i] == 0)
                array[n-i] = Solution(n-i);
            array[n] = Math.max(array[n], array[i]*array[n-i]);
        }
        
        return array[n];
    }

    private static int[] array;
}