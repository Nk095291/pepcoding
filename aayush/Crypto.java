import java.util.*;

public class Crypto {
    static void crypto(String s1, String s2, String sol, int[] val, int[] count) {

        char c1 = (char)(s1.charAt(s1.length() - 1) - 'A');
        char c2 = (char)(s2.charAt(s2.length() - 1) - 'A');
        char csol = (char)(sol.charAt(sol.length() - 1) - 'A');
        for(int i = 0; i <= 9; i++) {
            if(val[c1] == -1 && val[c2] == -1) {
                count[c2] = count[c1] = 1;
                val[c1] = val[c2] = i;
                crypto(s1, s2, sol, val, count);
            } else if (val[c1] == -1) {
                count[c1] = 1;
                val[c2] = i;
                crypto(s1, s2, sol, val, count);
            } else if (val[c2] == -1) {
                count[c2] = 1;
                val[c2] = i;
                crypto(s1, s2, sol, val, count);
            } else {
                int tot = val[c1] + val[c2];
                if (sol[csol])
            }
        }
    }

    public static void main(String[] args) {
        String s1 = "SEND";
        String s2 = "MORE";
        String sol = "MONEY";
        int[] val = new int[26];
        Arrays.fill(val, -1);
        int[] count = new int[26];        
        crypto(s1, s2, sol, val, count);
        // System.out.println();
        // for(int x: val) {
        //     System.out.println(x);
        // }
    }
}