
public class pdi {

	public static void main(String[] args) {
		pdis(6);
	}
	// ----------------------------ip-------------- ex - 1,2,3,4,5,6
	private static void ip(int n){
		if(n==0)
		{
			return;
		}
		ip(n-1);
		System.out.println(n);
	}
	//-------------------pi-------------- ex - 6,5,4,3,2,1
	private static void pi(int n){
		if(n==0)
			return;
		System.out.println(n);
		pi(n-1);
		
	}
	//-------------------------pd----------------ex - 6,5,4,3,2,1,1,2,3,4,5,6
	private static void pdi(int n ){
		if(n==0)
			return;
		System.out.println(n);
		pdi(n-1);
		System.out.println(n);
		
	}
	//-------------pdis---------------- ex- 5,3,1,2,4,6
	private static void pdis(int n){
		if(n==0)
			return;
		if(n%2!=0){
		System.out.print(n+" ");
		pdis(n-1);}
		else{
			pdis(n-1);
			System.out.print(n+" ");
			
		}
		
	}
	

}
