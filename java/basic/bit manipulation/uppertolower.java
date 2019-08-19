// package feb9;

import java.util.Scanner;

public class uppertolower {

	public static void main(String[] args) {
		// System.out.println(' '+0);		// way to check ascii code of any character
		Scanner scn = new Scanner(System.in);
		System.out.println("enter a character ");
		char a= scn.next().charAt(0);
		
		// if(a<97){
		// 	System.out.println("upper");
		// 	a=(char)( a + ('a'-'A'));		//'a'-'A' = 32
		// 	System.out.println(a);
		// }
		// else{
		// 	System.out.println("lower");
		// 	a=(char)( a - ('a'-'A'));  // type casting as 'a' will act as 97 (int) and 'A' as 65 (int)..
		// 	System.out.println(a);
			
			
		// }
		a^=32;
		System.out.println(a);

	}

}
