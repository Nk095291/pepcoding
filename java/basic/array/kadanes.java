// package feb12;
public class maxSubarray {

	public static void main(String[] args) {
	// int ar []={2,3,6,-1,12,3,-4,5,19};
	int ar []={-1,-2,-4,6,-4};

	int max = ar[0];
	int sum=max;
	for(int i=1;i<ar.length;i++){
		if(sum>=0){
			sum+=ar[i];

		}
		else{
			sum=ar[i];
		}
		if(sum>max)
		max=sum;
	}
	System.out.println(max);

	}

}
