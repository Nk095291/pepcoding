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
	
	
	//---------------------------------------------------------------------------------------------------------------------------------------------------
	// sliding window :- find the greatest element inside the window
	public static int[] slidingWindow(int ar[],int k)
	{
		int nge[]= new int[ar.length];
		Stack<Integer> st =  new Stack<>();
		for(int  i= ar.length-1 ; i>=0;i--)
		{
			while(st.size()>0&&ar[st.peek()]<ar[i])
			{
				st.pop();
			}
			nge[i]=st.size()==0?ar.length:st.peek();
			st.push(i);
		}
		int res[]=new int[ar.length-k+1];
		int j =0;
		for(int i =0;i<res.length;i++)
		{
			if(j<i)
				j=i;
			while(nge[j]<i+k)
				j=nge[j];
			res[i]=ar[j];
		}
		return res;
	}

	//--------------------------------------------------------------------------------------------------------
	// tell weather the given expression has needless brackets or not
	public static boolean hasUselessB(String str)
	{
		Stack<Character> st = new Stack<>();
		for(int i =0;i<str.length();i++)
		{
			char x = str.charAt(i);
			if(x==')')
			{

				if(st.peek()=='(')
					return true;
				while(st.peek()!='(')
					st.pop();
				st.pop();
			}
			else
				st.push(x);

		}
		return false;
	}
	//--------------------------------------------------------------------------------------------------------
	// find the celebrity , a celebrity is one who is known by everyone and he don't know anyone
	public static int celebrity(int ar[][])
	{
		int i =0 ;
		int j = ar.length-1;
		while(i!=j)
		{
			if(ar[i][j]==1)
			{
				i++;
			}
			else
			{
				j--;
			}
		}
		for(int k =0;k<ar.length;k++)
		{
			if(ar[i][k]==1)
				return -1;
			if(i!=j && ar[k][i]!=1)
				return -1;
		}
		return i;
	}
	//--------------------------------------------------------------------------------------------------------
	// find the new internvals after merging the intervals whose time conflicts with each other 
	public static class interval implements Comparable<interval>{
		int first;
		int second;
		public interval(int a, int b)
		{
			first = a;
			second = b;
		}
		public int compareTo(interval a)
		{
			return this.first - a.first;
		}
	}

	public static void margeactivity(int a[],int b[])
	{
		interval res[] = new interval[a.length];
		Stack<interval> st= new Stack<>();
		for(int i =0;i<a.length;i++)
		{
			res[i]=new interval(a[i],b[i]);
		}
		Arrays.sort(res);
		st.push(res[0]);
		for(int i =1;i<res.length;i++)
		{
			if(res[i].first <= st.peek().second)
			{
				st.peek().second=Math.max(res[i].second,st.peek().second); 
			}
			else
			{
				st.push(res[i]);
			}
		}
		while(st.size()>0)
		{
			System.out.println(st.peek().first+" "+ st.peek().second);
			st.pop();
		}
	}

	public static void main(String[] args)
	{
//		disSmallestNo("dididdd");
		// int ar[]={1,2,3,4,9,5,8};
		// int[] res = slidingWindow(ar,3);
		// for(int x:res)
		// 	System.out.print(x+" ");
		// System.out.println();
		// int ar[]={6,2,5,4,5,1,6};
//		nge2(ar);
//		for(int x:ar)
//			System.out.print(x+" ");
		// gra(ar);
		// System.out.println(hasUselessB("((a+b)+((c+a))"));
		int ar[][]={
			{0,1,1},
			{0,0,0},
			{0,1,1}
		};
		System.out.println(celebrity(ar));
		// int a[]={22,17,19,2,6,12,3};
		// int b[]={26,20,23,4,8,15,9};
		// margeactivity(a,b);
	}
}