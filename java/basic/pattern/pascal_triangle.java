package feb3;

import java.util.Scanner;

public class pat4 {
	// public static int fac(int a){
	// int s=1;
	// for(int i=2;i<=a;i++)
	// s*=i;
	// return s;
	// }
	// public static int C(int a ,int b){
	// int c=fac(a)/(fac(b)*fac(a-b));
	// return c;
	//
	// }

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.println("Enter a no");
		int n = scn.nextInt();
		n--;
		for (int i = 0; i <=n; i++) {
			int k = 1;

			for (int j = 0; j <=i; j++) {

				System.out.print(k + " ");
				k = k * (i - j) / (j + 1);

			}
			System.out.println();
		}
	}

}
