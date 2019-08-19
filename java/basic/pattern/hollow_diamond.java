

import java.util.Scanner;

public class pat7 {
//	public static void main(String[] args) {
//		Scanner scn = new Scanner(System.in);
//		System.out.println("Enter a no");
//		int n = scn.nextInt();
//		int t = (n + 1) / 2;
//		for (int i = 0; i <= t-1; i++) {
//			for (int j = 0; j <=t - 1-i; j++) {
//				System.out.print("x");
//			}
//			for (int j = t-i; j <=t+i; j++) {
//				System.out.print(" ");
//			}
//
//			for (int j = t+i+1; j <= n+1; j++) {
//				System.out.print("x");
//			}
//
//			System.out.println();
//
//		}
//		for (int i = t-2; i >=0; i--) {
//			for (int j = 0; j <=t - 1-i; j++) {
//				System.out.print("x");
//			}
//			for (int j = t-i; j <=t+i; j++) {
//				System.out.print(" ");
//			}
//
//			for (int j = t+i+1; j <= n+1; j++) {
//				System.out.print("x");
//			}
//
//			System.out.println();
//
//		}
//	}
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.println("Enter a no");
		int n = scn.nextInt();
		int space = (n/2) +1;
		int star = 1;
		boolean flag = true;
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < space; j++)
				System.out.print("x");
			for (int j = 0; j < star; j++)
				System.out.print(" ");
			for (int j = 0; j < space; j++)
				System.out.print("x");
			if (flag) {
				space--;
				star += 2;
			} else {
				space++;
				star -= 2;
			}
			if (star == n)
				flag = false;

			System.out.println();

		}

	}


}
