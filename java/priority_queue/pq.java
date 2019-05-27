import java.util.*;
public class pq{
	static class yoyo implements Comparable<yoyo>{			// required
		int x;
		int y ;
		yoyo(int a , int y){
			this.x = a;
			this.y = y;
		}
		public int compareTo(yoyo b)			//priority queue will use this to arrange the elements
		{
			return this.x-(b.x);
		}
	}
	public static void main(String[] args){
		PriorityQueue<yoyo> ar= new PriorityQueue<>(); // by defalut smallest element has more prio
		ar.add(new yoyo(23,46));
		ar.add(new yoyo(4,456));
		ar.add(new yoyo(213,26));
		ar.add(new yoyo(234,234));
		ar.add(new yoyo(-23,26));
		ar.add(new yoyo(243,4234));
		for(yoyo xx:ar)
		{
			System.out.println(xx.x+"  "+xx.y);
		}
		System.out.println("----------------------------------------");
		for(int i=0;i<3;i++)
		{
			ar.remove();
		}
		System.out.println(ar.peek().x+"  "+ar.peek().y);



		// for(Integer x:ar)
		// {
		// 	System.out.print(x+"  ");	this will work too!!!
		// }
		System.out.println();
	}
}