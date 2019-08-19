import java.util.Scanner;

public class a2b {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.println("enter where to where values");
		int a=scn.nextInt();
		int b=scn.nextInt();
		System.out.println("Enter the value in "+ a);
		int n = scn.nextInt();
		if(a!=10&&b!=10){

			n=atb(a,10,n);
			System.out.println(n);
			int n1=atb(10,b,n);
		
			System.out.println(n1);
		}
		else{
			int n1=atb(a,b,n);
		
			System.out.println(n1);
		}
		


}
public static int atb(int a ,int b,int n){
	int ten=1;
	int n1=0;
	while(n>0){
		n1=n1+ten*(n%b);
		n=n/b;
		ten*=a;
	}
	return n1;
}
	
}