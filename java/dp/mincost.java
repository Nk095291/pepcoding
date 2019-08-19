import com.sun.org.apache.xml.internal.resolver.helpers.PublicId;

public class mincost {
    public static int[][] minPrice(int[][] mat) {

        int[][] res = new int[mat.length][mat[0].length];
        res[mat.length - 1][mat[0].length - 1] = mat[mat.length - 1][mat[0].length - 1];
        int r = mat.length;
        int c = mat[0].length;
        for (int i = mat.length - 1; i >= 0; i--) {
            for (int j = mat[0].length - 1; j >= 0; j--) {
                if (i == r - 1 && j == c - 1)
                    continue;
                int a = Integer.MAX_VALUE;
                int b = Integer.MAX_VALUE;
                if (i < r - 1)
                    a = res[i + 1][j];
                if (j < c - 1)
                    b = res[i][j + 1];
                res[i][j] = Math.min(a, b) + mat[i][j];
            }
        }
        return res;
    }

    public static void runMinPrice() {
        int[][] mat = { { 2, 6, 5, 1, 3, 4 }, { 0, 4, 9, 2, 9, 0 }, { 4, 8, 1, 0, 6, 5 }, { 3, 3, 3, 1, 5, 4 },
                { 1, 2, 7, 0, 6, 9 }, { 5, 7, 1, 3, 8, 2 } };
        int[][] res = minPrice(mat);
        System.out.println(res[0][0]);
    }

    public static void main(String[] argv) {

    }
}