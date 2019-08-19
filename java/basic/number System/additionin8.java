package feb5;

import java.util.Scanner;

public class additionin8 {
//RJ
	public static void main(String[] args) {
		//Scanner scn = new Scanner(System.in);
		int a =777;
		int b=1;
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
			ans+=sum%8*p;
			a+=sum/8;
			p*=10;
		}
		System.out.println(ans);
	}

}
