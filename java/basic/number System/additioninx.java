package feb5;

import java.util.Scanner;

public class additioninx {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int x=scn.nextInt();
		int a =scn.nextInt();
		int b=scn.nextInt();;
		int ra,rb;
		int sum;
		int ans=0;
		int p=1;
		while(a>0||b>0){
			ra=a%10;
			rb=b%10;
			sum = ra+rb;
			a/=10;
			b/=10;
			ans+=sum%x*p;
			a+=sum/x;
			p*=10;
		}
		System.out.println(ans);
	}

}
