package feb9;

import java.util.Scanner;

public class bitmanipulation {
	public static void main(String[] args) {
		// Scanner scn = new Scanner(System.in);
		int n = 57;		//no
		int k = 3;		//kth bit to be check
		int c = 2;		//options -----1.check weather on or off and if kth bit is off then no it  2.check and it on the turn it off 3.check and toggle the statusex if on then off it and if off then on it
		int a = -1;		// bit mask used for turning off the kth bit , we inilise it with -1 because -1 have all 32 bit of -1 is on
		if (c == 1) {
			if ((n & (1 << k)) > 0) {
				System.out.println("the bit is on");
			} else {
				System.out.println("the bit is off");
				n = n | (1 << k);
				System.out.println("now the bit is on and new no is");
				System.out.println(n);
			}
		} else if (c == 2) {
			if ((n & (1 << k)) > 0) {
				System.out.println("the bit is on");
				a=a-(1<<k);		//now only kth bit of a in off
				n = n & a ;		// way to turn off a bit
				System.out.println("now the bit is off and new no is");
				System.out.println(n);

			} else {
				System.out.println("the bit is off");
			}

		} else {
			if ((n & (1 << k)) > 0) {
				System.out.println("the bit is on");
				n = n ^ (1 << k);		// way to toggle the bit ,this line of code can be use for both the operation i.e.,turning off the bit and turning on the bit 
				System.out.println("now the bit is off and new no is");
				System.out.println(n);

			} else {
				System.out.println("the bit is off");
				n = n | (1 << k);
				System.out.println("now the bit is on and new no is");
				System.out.println(n);
			}
		}

	}

}
