package feb10;

public class subset {

	public static void main(String[] args) {
		int a[] ={1,2,3};
		int end = 1<<(a.length);
		for(int i=0;i<end;i++){
			for(int j=a.length;j>=0;j--){
				int k=1<<j;
				if((i&k)>0){
					System.out.print(a[a.length-1-j]);
				}
			}
			System.out.println();
		}
		
	}

}
