import java.util.*;
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------
public class stack{
//Q- give the smallest no that follows the given pattern (d and i mean decrease and increase  and no number can be used twice) ,(size of the sequence can't be more than 9)
	
	public static void disSmallestNo(String q)
	{
		Stack<Integer> st = new Stack<>();
		int j=1;
		int i =0;
		while(i<q.length())
		{
			char ch = q.charAt(i);
				st.push(j);
				j++;
			if(ch =='i')
			{
				while(st.size()>0)
				{
					System.out.print(st.pop()+" ");
				}
			}
			i++;
		}
		st.push(j);
		while(st.size()>0)
				{
					System.out.print(st.pop()+" ");
				}
	}
	//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

	// Q - given an array , return a array whose ith element contain the nearest greater no on the right side of the ith element of the given array
	
	public static void nge(int[] ar)			//finding using right to left
	{
		Stack<Integer> st = new Stack<>();
		 st.push(ar[ar.length-1]);
		ar[ar.length-1]=-1;
		for(int i=ar.length-2;i>=0;i--)
		{
			while(  st.size()>0 && st.peek()<ar[i])
			{
				st.pop();
			}
			int t = ar[i];
			if(st.size()==0)
			{
				ar[i]=-1;
			}else{
				ar[i]=st.peek();
			}
			st.push(t);
		}
		
	}
	public static void nge2(int[] ar)		// left to right
	{
		Stack<Integer> st = new Stack<>();
		for(int i =0;i<ar.length;i++)
		{
			while(st.size()>0 && ar[i]>ar[st.peek()])
			{
				ar[st.pop()]=ar[i];
			}
			st.push(i);
		}
		while(st.size()>0)
		{
			ar[st.pop()]=-1;
		}

	}
	//--------------------------------------------------------------------------------------------------------------------------------------------------------------------

	
	//Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars.
	//questoin link :- https://www.geeksforgeeks.org/largest-rectangle-under-histogram/#_=_
	
	
	public static int[] findl(int[] ar)		// find the no of nos greater than the no till a lesser no comes out on the left side
	{
		int[] left = new int[ar.length];
		Stack<Integer> st = new Stack<>();
		for(int i = ar.length-1;i>=0;i--)
		{
			while(st.size()>0 && ar[i]<=ar[st.peek()])
			{
				st.pop();
			}
			if(st.size()==0)
			{
				left[i]=ar.length-i;
			}else
			{
				left[i]=st.peek()-i;
			}
			st.push(i);
		}
		return left;
	}

	public static int[] findr(int[] ar)	// on the left side
	{
		int[] left = new int[ar.length];
		Stack<Integer> st = new Stack<>();
		for(int i = 0;i<ar.length;i++)
		{
			while(st.size()>0 && ar[i]<=ar[st.peek()])
			{
				st.pop();
			}
			if(st.size()==0)
			{
				left[i]=i+1;
			}else
			{
				left[i]=i-st.peek();
			}
			st.push(i);
		}
		return left;
	}
	public static void gra(int [] ar)	// find the greatest area
	{
		int[] left = findl(ar);
		int[] right = findr(ar);
		int m = Integer.MIN_VALUE;
		for(int i =0;i<ar.length;i++)
		{
			int curArea= ar[i]*(left[i]+right[i]-1);
			if(curArea > m)
				m = curArea;
		}
		
		System.out.println(m);
	}
	
	
	
	public static void main(String[] args)
	{
//		disSmallestNo("dididdd");
//		int ar[]={1,2,3,4,9,5,8};
		int ar[]={6,2,5,4,5,1,6};
//		nge2(ar);
//		for(int x:ar)
//			System.out.print(x+" ");
		gra(ar);
	}
}