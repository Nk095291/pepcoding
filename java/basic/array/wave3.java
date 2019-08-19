// package feb12;

public class wave3 {

	public static void main(String[] args) {
		int a[][] = { 
				{11,12,13,14},
				{21,22,23,24},
				{31,32,33,34},
				{41,42,43,44}};
		int l=0,r=a[0].length-1,t=0,b=a.length-1;
		while(b>=t){
			for(int i=t;i<=b&&r>=l;i++)
				System.out.print(a[i][l]+" ");
			l++;
			for(int i=l;i<=r&&b>=t;i++)
				System.out.print(a[b][i]+" ");
			b--;
			for(int i=b;i>=t&&r>=l;i--)
				System.out.print(a[i][r]+" ");
			r--;
			for(int i=r;i>=l&&b>=t;i--)
				System.out.print(a[t][i]+" ");
			t++;	
			
		}
	}
	

}
