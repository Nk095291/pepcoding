

public class endpoint {
	public static void main(String[] args) {
		int[][] ar = { 
				{ 0, 0, 1, 0 }, 
				{ 1, 1, 0, 0 },
				{ 0, 0, 0, 0 },
				{ 1, 0, 1, 0 } };
		int d = 0;
		int i = 0;
		int j = 0;
		while (true) {
			// ------------condition for exit-----------------
			if (i < 0) {
				if (ar[i + 1][j] == 0) {
					System.out.println(i + 1 + " " + j);
					return;
				}

			}
			if (j < 0) {
				if (ar[i][j + 1] == 0) {
					System.out.println(i  + " " + (j+1));
					return;
				}

			}
			if (i == ar.length) {
				if (ar[i - 1][j] == 0) {
					System.out.println((i - 1) + " " + j);
					return;
				}

			}
			if (j == ar[0].length) {
				if (ar[i][j - 1] == 0) {
					System.out.println(i + " " + (j - 1));
					return;
				}

			}
			// -------------------------------------------------
			// -----------change in dir--------------------------

			if (d == 0) {
				j++;
			} else if (d == 1) {
				i++;
			} else if (d == 2) {
				j--;
			} else {
				i--;
			}
			if (i >= 0 && i < ar.length && j >= 0 && j < ar[0].length) {
				d=(d+ar[i][j])%4;
			// --------------------------------------------
			}
		}
	}

}
