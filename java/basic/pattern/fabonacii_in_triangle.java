import java.util.Scanner;

public class pat3 {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.println("Enter a no");
		int n = scn.nextInt();
		int f = 0;
		int s=1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				if(j==1&&i==1)
					System.out.print(f+" ");
				else if(i==2&&j==1)
					System.out.print(s+" ");
				else{
					s=s+f;
					f=s-f;
					System.out.print(s+" ");
				}
			}
			System.out.println();
		}
	}

}
