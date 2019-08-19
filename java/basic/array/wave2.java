// package feb12;

public class wave2 {

	public static void main(String[] args) {
		int a[][] = { 
		{ 1, 2, 3},
		 { 5, 6, 7 }, 
		 { 9, 10, 11 },
		 };
		int i = 0, j = 0;
		int rm = a.length, cm = a[0].length;
		while (i < rm && j < cm) {
			System.out.print(a[i][j] + " ");
			int sum = i + j;
			if (sum % 2 == 0) {
				if (i == rm - 1) {
					j++;
				} else {
					i++;
					if (j > 0)
						j--;
				}
			} else {
				if (j == cm - 1) {
					i++;
				} else {
					j++;
					if (i > 0)
						i--;
				}

			}
		}

	}

}
