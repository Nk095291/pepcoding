

import java.util.Scanner;

public class pat5 {

	public static void main(String[] args){
		Scanner scn = new Scanner(System.in);
		System.out.println("Enter a no");
		int n =scn.nextInt();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++){
				if(i==j||(i==(n-j-1)))
					System.out.print("*");
				else
					System.out.print(" ");
				
			}
			System.out.println();
			
		}
	}
}
