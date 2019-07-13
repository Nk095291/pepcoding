import java.util.*;

public class Mango {

    static void recur(String ans, String s, String[] arr) {
        if(s.length() == 0) {
            System.out.println(ans);
            return;
        }
        for (int i = 0; i < arr.length; i++) {
            boolean found = true;
            if (s.length() < arr[i].length()) continue;
            for (int j = 0; j < arr[i].length(); j++) {
                if (s.charAt(j) != arr[i].charAt(j)) {
                    found = false;
                    break;
                }
            }
            if (found) {
                String temp = ans + arr[i] + " ";
                recur(temp, s.substring(arr[i].length()), arr);
            }
          
        }
    }

    public static void main(String[] args) {
        // String[] arr = {"I", "like", "man", "go", "mango"};
        String[] arr = {"I","love", "ice", "cream", "go","icecream","man", "mango"};
        
        String s = "Iloveicecreammango";
        recur("",s, arr);
    }
}