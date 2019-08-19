package feb5;

public class subtractingin2 {
	public static void main(String[] args) {
		//Scanner scn = new Scanner(System.in);
		int a =10262;
		int b=367;
		int ra,rb;
		int sub;
		int ans=0;
		int p=1;
		int bb=0;
		while(a>0||b>0){
			ra=a%10;
			rb=b%10;
			a/=10;
			b/=10;
			sub=ra-rb-bb;
			if(sub<0){
				
				ra+=8;		//if we replace *8* with 'x' then this will become answer for substraction in any base
				sub=ra-rb-bb;		//sub+=8 is okay too...
				bb=1;
			}
			else
				bb=0;
			
			ans+=sub*p;
			//a+=sub/8;
			p*=10;
		}
		System.out.println(ans);
	}

}
