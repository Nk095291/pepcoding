package feb9;

public class noOfOnes {

	public static void main(String[] args) {
		int a =-1;
		int rm1;
		int count=0;
		System.out.println();
		while(a!=0){
			rm1=a&(-a);
			count++;
			System.out.println(Integer.toBinaryString(a));
			a-=rm1;
		}
		System.out.println();
		System.out.println(count);

	}

}
