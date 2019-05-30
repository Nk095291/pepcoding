import java.util.*;
public class graph{
	static class edge{
		int n;
		int w;
		edge(int a, int b)
		{
			n =a;
			w=b;
		}
	}
	public static void addEdge(ArrayList<ArrayList<edge>> graph, int v1,int v2, int w)
	{
		graph.get(v1).add(new edge(v2,w));
		graph.get(v2).add(new edge(v1,w));
		// System.out.println("b");
	}
	public static void display(ArrayList<ArrayList<edge>> graph)
	{
		int i =0;
		for(ArrayList<edge> x:graph)
		{
			System.out.print(i+" ->");
			for(edge y:x)
			{
				System.out.print("{"+y.n+" "+y.w+"} ");
			}
			System.out.println();
			i++;
		}
	}
	public static boolean hasPath(ArrayList<ArrayList<edge>> graph, int start, int end, boolean[] hasVisit)
	{
		if(start == end)
			return true;
		hasVisit[start]=true;
		for(int i =0;i<graph.get(start).size();i++)
		{
			boolean res=false ;
			if(hasVisit[graph.get(start).get(i).n]==false)
				res = hasPath(graph,graph.get(start).get(i).n,end,hasVisit);
			if(res==true)
				return true;
		}
		return false;
	}
	public static void allPath(ArrayList<ArrayList<edge>> graph, int start, int end, boolean[] hasVisit,String asf)
	{
		if(start == end)
			{
				asf=asf+" "+start;
				System.out.println(asf);
				return;
			}
		hasVisit[start]=true;
		for(int i =0;i<graph.get(start).size();i++)
		{
			if(hasVisit[graph.get(start).get(i).n]==false)
				 allPath(graph,graph.get(start).get(i).n,end,hasVisit,asf + " "+ start);
		}
		hasVisit[start]=false;

	}
	static class helper{
		int min =Integer.MAX_VALUE;
		String ans="no path find";
		// helper(){
		// 	int min =Integer.MAX_VALUE;
		// 	String ans = "no path find";	
		// }
	}
	static class helper2{
		int max = Integer.MIN_VALUE;
		String ans = "no path find";
	}
	public static void minPaths(ArrayList<ArrayList<edge>> graph, int start, int end, boolean[] hasVisit,String asf,helper result,int vsf)
	{
		if(start == end)
		{
			asf=asf+" "+start;
			if(vsf<result.min)
			{
				result.min = vsf;
				result.ans= asf;
			}
			return;
		}
		hasVisit[start]=true;
		for(int i =0;i<graph.get(start).size();i++)
		{
			boolean res=false ;
			if(hasVisit[graph.get(start).get(i).n]==false)
				 minPaths(graph,graph.get(start).get(i).n,end,hasVisit,asf + " "+ start,result,vsf+graph.get(start).get(i).w);
		}
		hasVisit[start]=false;	
	}

	public static void maxPaths(ArrayList<ArrayList<edge>> graph, int start, int end, boolean[] hasVisit,String asf,helper2 result,int vsf)
	{
		if(start == end)
		{
			asf=asf+" "+start;
			if(vsf>result.max)
			{
				result.max = vsf;
				result.ans= asf;
			}
			return;
		}
		hasVisit[start]=true;
		for(int i =0;i<graph.get(start).size();i++)
		{
			boolean res=false ;
			if(hasVisit[graph.get(start).get(i).n]==false)
				 maxPaths(graph,graph.get(start).get(i).n,end,hasVisit,asf + " "+ start,result,vsf+graph.get(start).get(i).w);
		}
		hasVisit[start]=false;	
	}

	public static void ceilPaths(ArrayList<ArrayList<edge>> graph, int start, int end, boolean[] hasVisit,String asf,helper result,int vsf,int k)
	{
		if(start == end)
		{
			asf=asf+" "+start;
			if(vsf>k&&vsf<result.min)
			{
				result.min = vsf;
				result.ans= asf;
			}
			return;
		}
		hasVisit[start]=true;
		for(int i =0;i<graph.get(start).size();i++)
		{
			boolean res=false ;
			if(hasVisit[graph.get(start).get(i).n]==false)
				 ceilPaths(graph,graph.get(start).get(i).n,end,hasVisit,asf + " "+ start,result,vsf+graph.get(start).get(i).w,k);
		}
		hasVisit[start]=false;	
	}
	public static void floorPaths(ArrayList<ArrayList<edge>> graph, int start, int end, boolean[] hasVisit,String asf,helper2 result,int vsf,int k)
	{
		if(start == end)
		{
			asf=asf+" "+start;
			if(vsf<k&&vsf>result.max)
			{
				result.max = vsf;
				result.ans= asf;
			}
			return;
		}
		hasVisit[start]=true;
		for(int i =0;i<graph.get(start).size();i++)
		{
			boolean res=false ;
			if(hasVisit[graph.get(start).get(i).n]==false)
				 floorPaths(graph,graph.get(start).get(i).n,end,hasVisit,asf + " "+ start,result,vsf+graph.get(start).get(i).w,k);
		}
		hasVisit[start]=false;	
	}

	static class bfshelper
	{
		int v;
		String psf;
		int w;
		bfshelper(int v,String asf, int w)
		{
			this.v = v;
			psf = asf;
			this.w = w;
		}
	}
	public static boolean bfs(ArrayList<ArrayList<edge>> graph , int start , int end)		// bsf search using "grmwa" algo
	{
		LinkedList<bfshelper> li = new LinkedList<>();
		boolean [] hasVisit  = new boolean[7];

		li.add(new bfshelper(start,""+start,0));
		while(li.size()>0)
		{
			//grmwa
			bfshelper rem = li.getFirst();		//g
			li.removeFirst();				//r
			System.out.println(rem.v +" "+rem.psf+" "+rem.w);
			if(hasVisit[rem.v]==true)
				continue;
			else
				hasVisit[rem.v]=true;
			if(rem.v == end)
				return true;

			for(int i =0;i<graph.get(rem.v).size();i++)
			{
				edge nn = graph.get(rem.v).get(i);
				bfshelper nn2 = new bfshelper(nn.n,rem.psf+nn.n,rem.w+nn.w);
				li.add(nn2); 
			}


		}
		return false;
	}

	public static ArrayList<String> gcc(ArrayList<ArrayList<edge>> graph)
	{
		boolean[] hasVisit = new boolean[7];
		LinkedList<edge> li= new LinkedList<>();
		ArrayList<String> res = new ArrayList<>();
		for(int i =0 ;i<7 ;i++)
		{
			if(hasVisit[i]==true)
				continue;
			String connected="";
			li.add(new edge(i,0));
			while(li.size()>0)
			{
				edge rem = li.removeFirst();

				if(hasVisit[rem.n]==true)
					continue;
				else
					hasVisit[rem.n]=true;
				
				connected+=rem.n;

				for(int ii =0;ii<graph.get(rem.n).size();ii++)
				{
					if(hasVisit[graph.get(rem.n).get(ii).n]==false)
						li.add(graph.get(rem.n).get(ii)); 
				}
			}
			res.add(connected);

		}
		return res;
	}

	static class dhelper implements Comparable<dhelper>{
		int v1;
		int v2;
		int w;
		dhelper(int a, int b,int c)
		{
			v1=a;
			v2=b;
			w=c;
		}
		public int compareTo(dhelper o)
		{
			return this.w - o.w;
		}
	}
	public static int findl(int[] pa, int index)
	{
		if(pa[index]==index)
			return index;
		return findl(pa,pa[index]);
	}
	public static void merge(int[] pa , int[] ra, int v1l,int v2l)
	{
		if(ra[v1l]<ra[v2l])
		{
			pa[v1l]=v2l;
		}
		else if(ra[v1l]>ra[v2l])
		{
			pa[v2l]=v1l;
		}
		else
		{
			pa[v1l]=v2l;
			ra[v2l]++;
		}
	}

	public static ArrayList<ArrayList<edge>> krushkal(ArrayList<ArrayList<edge>> graph)
	{
		int[]pa = new int[graph.size()];
		int[]ra = new int[graph.size()];
		ArrayList<ArrayList<edge>> res= new ArrayList<>();
		PriorityQueue<dhelper> pq = new PriorityQueue<>();
		for(int i=0;i<graph.size();i++){
			res.add(new ArrayList<>());
		}
		for(int i =0;i<graph.size();i++)
		{
			pa[i]=i;
			ra[i]=1;
		}
		for(int i=0;i<graph.size();i++)
		{
			for(int j =0;j<graph.get(i).size();j++)
			{
				edge nn  = graph.get(i).get(j);
				if(i<nn.n)
				{
					pq.add(new dhelper(i,nn.n,nn.w));
				}
			}
		}
		while(pq.size()>0)
		{
			// System.out.println("a");
			dhelper rem = pq.remove();
			int v1l = findl(pa,rem.v1);
			int v2l = findl(pa,rem.v2);
			// System.out.println(v1l);

			if(v1l != v2l)
			{
				addEdge(res,rem.v1,rem.v2,rem.w);
				merge(pa,ra,v1l,v2l);
			}
		}

		return res;
	}

	public static void hamiltonian(ArrayList<ArrayList<edge>> graph, int start)
	{
		boolean hasVisit[]= new boolean[graph.size()];
		ArrayList<Integer> psf = new ArrayList<>();
		hamiltonianhelper(graph,start,hasVisit,psf);
	}
	public static void hamiltonianhelper(ArrayList<ArrayList<edge>> graph, int start, boolean[] hasVisit, ArrayList<Integer> psf )
	{
		if(psf.size()==graph.size()-1)
		{
			for(int i:psf)
				System.out.print(i+" ");
			System.out.print(start);

			boolean cyclic = false;
			for(int i =0;i<graph.get(start).size();i++)
			{
				edge nn = graph.get(start).get(i);
				if(psf.get(0) == nn.n)
				{
					cyclic=true;
					break;
				}
			}

			if(cyclic)
			{
				System.out.println("*");
			}
			else
				System.out.println(".");

		}

		hasVisit[start]= true;
		psf.add(start);
		for(int i =0;i<graph.get(start).size();i++)
		{
			edge nn = graph.get(start).get(i);
			if(hasVisit[nn.n]==false)
				hamiltonianhelper(graph,nn.n,hasVisit,psf);
		}
		hasVisit[start]=false;
		psf.remove(psf.size()-1);
	}


	public static void main(String[] args)
	{
		ArrayList<ArrayList<edge>> graph = new ArrayList<>();
		for(int i =0;i<7;i++)
			graph.add(new ArrayList<>());
		addEdge(graph,0,1,10);
		addEdge(graph,1,2,10);
		addEdge(graph,0,3,40);
		addEdge(graph,2,3,10);
		addEdge(graph,3,4,2);
		addEdge(graph,4,6,8);
		addEdge(graph,4,5,3);
		addEdge(graph,5,6,3);
		addEdge(graph,2,5,10);
		hamiltonian(graph,2);
		// display(graph);
		// boolean a[]= new boolean[7];
		// // System.out.println(hasPath(graph,0,6,a));
		// helper res = new helper();
		// minPaths(graph,0,6,a,"",res,0);
		// helper2 res2 = new helper2();
		// maxPaths(graph,0,6,a,"",res2,0);
		// System.out.println(res.ans +"  ->"+res.min);
		// System.out.println(res2.ans +"  ->"+res2.max);
		// helper2 res22 = new helper2();
		// helper res1 = new helper();
		// ceilPaths(graph,0,6,a,"",res1,0,40);
		// System.out.println(res1.ans +"  ->"+res1.min);
		// floorPaths(graph,0,6,a,"",res22,0,40);
		// System.out.println(res22.ans +"  ->"+res22.max);
		// System.out.println(bfs(graph,0,6));

		// ArrayList<String> res =gcc(graph); 
		// for(String x:gcc(graph))
			// System.out.println(x);
		// display(krushkal(graph));
	}
}