#include<iostream>
#include<vector>
#include<list>
#include<climits>
#include<queue>
using namespace std;

 class edge{	
	public:
		int n;
		int w;
		edge(int a, int b)
		{
			n =a;
			w=b;
		}
	};
	void addEdge(vector<vector<edge* > > &graph,int v1, int v2, int w)
	{
		edge* nn1 = new edge(v2,w);
		edge* nn2 = new edge(v1,w);
		graph[v1].push_back(nn1);
		graph[v2].push_back(nn2);
	}
	 void display(vector<vector<edge* > > &graph)
	{
		int i =0;
		for(auto &x:graph)
		{
			cout<<i<<" ->"<<" ";
			for(auto y:x)
			{
				string st ="{"+to_string(y->n)+" "+to_string(y->w)+"} ";
				cout<<st;
				// cout<<"{"<<(y->n)<<" "<<(y->w)<<"} ";
			}
			cout<<endl;	
			i++;
		}
	}

	bool isCyclic2(vector<vector<edge*>> & graph,int start,vector<bool>& hasvisit)
	{	
		list<int> li;
		li.push_back(start);
		while(li.size()>0)
		{
			int rem = li.front();
			li.pop_front();

			if(hasvisit[rem])
				return true;
			else
				hasvisit[rem]=true;
			for(int i = 0 ;i <graph[rem].size();i++)
			{
				if(hasvisit[graph[rem][i]->n]==false)
					li.push_back(graph[rem][i]->n);
			}
		}
		return false;
	}
	bool isCyclic(vector<vector<edge*>> & graph)
	{
		vector<bool> hasvisit(7,false);
		for(int i =0;i<graph.size();i++)
		{
			if(hasvisit[i]==false)
				if(isCyclic2(graph,i,hasvisit))
					return true;
		}
		return false;
	}

	void addInGraph(vector<vector<int>>&graph,int i ,int j)
	{
		graph[i].push_back(j);
		graph[j].push_back(i);
	}
	int getcc(vector<vector<int>>&graph, vector<bool>&hasvisit,int i)
	{
		list<int>li;
		int count=0;
		li.push_back(i);
		while(li.size()>0){
			int rem = li.front();
			li.pop_front();

			if(hasvisit[rem])
				continue;
			else
			{
				hasvisit[rem]=true;
				count++;
			}

			for(int i =0;i<graph[rem].size();i++)
			{
				if(!hasvisit[graph[rem][i]])
					li.push_back(graph[rem][i]);
			}
		}
		return count;
	}
	int coun_astro(vector<vector<int>>&graph)
	{
		vector<bool>hasvisit(graph.size(),false);
		vector<int> ar;
		for(int i =0;i<graph.size();i++)
		{
			if(!hasvisit[i])
				ar.push_back(getcc(graph,hasvisit,i));
		}
		int sum=0;
		for(int i =0;i<ar.size();i++)
			for(int j=i+1;j<ar.size();j++)
				sum+=ar[i]*ar[j];
		cout<<sum<<endl;
	}
	int solve2(vector<vector<pair<int,int>>>& graph,int & maxx,int i)
	{
		vector<bool>hasvisit(graph.size());
		list<pair<int,int>>li;
			li.push_back(make_pair(i,0));
			auto rem = li.front();
			while(li.size()>0)
			{
				 rem = li.front();
				li.pop_front();

				if(hasvisit[rem.first])
					continue;
				else
					hasvisit[rem.first]=true;

				if(rem.second>maxx)
					maxx=rem.second;

				for (int i = 0; i < graph[rem.first].size(); ++i)
				{
					if(!hasvisit[i]){
						graph[rem.first][i].second=rem.second+1;
						li.push_back(make_pair(graph[rem.first][i].first,rem.second+1));
					}

				}
			}
		return rem.first;
	}
	void solve(vector<vector<pair<int,int>>>& graph)
	{
		int maxx = INT_MIN;
		int firstEnd = solve2(graph,maxx,0);
		maxx =INT_MIN;
		solve2(graph,maxx,firstEnd);
		int t1,t2;
		t1=maxx/2;
		t2=maxx%2==0?t1:t1+1;

		for(int i=0;i<graph.size();i++)
		{
			for(int j=0;j<graph[i].size();j++)
			{
				if(graph[i][j].second==t1||graph[i][j].second==t2)
					cout<<graph[i][j].first<<"  ";
			}
		}
		cout<<endl;
	}

	void makegraph(vector<vector<pair<int,int>>>& graph)
	{
		vector<int>a{0,1,0,2,3,4,4};
		vector<int>b{1,2,3,3,4,6,5};
		for(int i =0;i<a.size();i++)
		{
			graph[a[i]].push_back(make_pair(b[i],0));
			graph[b[i]].push_back(make_pair(a[i],0));

		}
	}

	bool isbiPartbale(vector<vector<pair<int,int>>>& graph)
	{
		list<pair<int,int>> li;
		li.push_back(make_pair(0,0));
		vector<int> hasvisit(graph.size(),-1);
		while(li.size()>0)
		{
			auto rem = li.front();
			li.pop_front();

			if(hasvisit[rem.first]!=-1)
			{
				if(hasvisit[rem.first]!=rem.second%2)
					return false;
			}
			else
			{
				hasvisit[rem.first]=rem.second%2;
			}

			for(int i=0;i<graph[rem.first].size();i++)
			{
				if(hasvisit[graph[rem.first][i].first]==-1)
					li.push_back(make_pair(graph[rem.first][i].first,rem.second+1));
			}

		}	
		return true;
	}

	class helper
	{
	public:
		int v;
		string psf;
		int w;
		helper(int v, string psf, int w)
		{
			this->v=v;
			this->psf=psf;
			this->w=w;
		}
		bool operator<(const helper& o)const{
			return this->w > o.w;
		}
	};
	class helpercomp
	{
	public:
		bool operator()(const helper& a, const helper& b)const
		{
			return a.w >b.w;
		}
		
	};

	void shortestPathFromS(vector<vector<edge*>> & graph,int start)
	{
		priority_queue<helper,vector<helper>,helpercomp>pq;
		pq.push(helper(start,"",0));
		vector<bool> hasvisit(graph.size(),false);
		while(pq.size()>0)
		{
			helper rem = pq.top();pq.pop();
			
			if(hasvisit[rem.v]==true)
				continue;
			else
				hasvisit[rem.v]=true;

			cout<<rem.v<<" via "<<rem.psf<<"   "<<rem.w<<endl;

			for(int i =0;i<graph[rem.v].size();i++)
			{
				edge* nn=graph[rem.v][i];
				if(hasvisit[nn->n]==false)
					pq.push(helper(nn->n,rem.psf+to_string(nn->n),rem.w+nn->w));
			}
		}
	}

	class helper2{
	public:
		int v;
		int a;
		int c;
		helper2(int v,int a,int c)
		{
			this->v=v;
			this->a=a;
			this->c=c;
		}
		bool operator<(const helper2& o)const
		{
			return this->c > o.c;
		}
	};

	void primsAlog(vector<vector<edge*>> &graph,vector<vector<edge*>> &graph2)
	{
		priority_queue<helper2>pq;
		vector<bool> hasvisit(graph.size(),false);
		pq.push(helper2(1,-1,0));
		while(pq.size()>0)
		{
			helper2 rem = pq.top();pq.pop();

			if(hasvisit[rem.v])
				continue;
			else
				hasvisit[rem.v]=true;

			if(rem.a!=-1 )
			{
				graph2[rem.v].push_back(new edge(rem.a,rem.c));
				graph2[rem.a].push_back(new edge(rem.v,rem.c));

			}

			for(int i=0;i<graph[rem.v].size();i++)
			{
				edge* nn = graph[rem.v][i];
				if(hasvisit[nn->n]==false)
					pq.push(helper2(nn->n,rem.v,nn->w));
			}
		}

	}

void floyed_warshallImplement(vector<vector<edge>>& graph)
{
	vector<vector<int>> res (graph.size(),vector<int>(graph.size(),INT_MAX));
	vector<vector<string>> res2 (graph.size(),vector<string>(graph.size(),"x"));

	for(int i =0;i<graph.size();i++)
	{
		for(int j =0;j<graph[i].size();j++)
		{
			edge nn = graph[i][j];
			res[i][nn.n]=nn.w;
			res2[i][nn.n]=to_string(nn.w);
		}
		res[i][i]=0;
		res2[i][i]="0";
	}


	for(int i =0;i<graph.size();i++)
	{
		for(int s=0;s<graph.size();s++)
		{
			for(int d=0;d<graph.size();d++)
			{
				if(i==s||i==d||s==d)
					continue;
				else if(res[s][i]==INT_MAX|| res[i][d]==INT_MAX)
					continue;
				else
				{

					if(res[s][i]+res[i][d]<res[s][d]){
						res[s][d]=res[s][i]+res[i][d];
						res2[s][d]+=","+to_string(res[s][i]+res[i][d])+"("+to_string(i)+")";

					}
				}
			}
		}
	}


	for(auto x:res2)
	{
		for(auto y:x)
			cout<<y<<" \t";
		cout<<endl;
	}
}



void floyed_warshall()
{
	vector<vector<edge>> graph(4);
	graph[0].push_back(edge(1,2));
	graph[0].push_back(edge(3,8));
	graph[0].push_back(edge(2,4));
	graph[1].push_back(edge(2,1));
	graph[1].push_back(edge(3,5));
	graph[2].push_back(edge(3,1));
	floyed_warshallImplement(graph);

}

int main(){
	// vector<vector<edge*>> graph(12);
	// addEdge(graph,0,1,10);
	// addEdge(graph,1,2,10);
	// addEdge(graph,0,3,40);
	// addEdge(graph,2,3,10);
	// addEdge(graph,3,4,2);
	// addEdge(graph,4,6,8);
	// addEdge(graph,4,5,3);
	// addEdge(graph,5,6,3);
	// vector<vector<edge*>> graph2(7);

	// // // display(graph);
	// // cout<<isCyclic(graph)<<endl;
	// // int n = 12;								// no of astro.
	// // vector<vector<int>> graph(n);
	// // vector<int>a {1,6,8,2,9,10,0};
	// // vector<int>b {2,9,3,5,5,3,11};
	// // for(int i =0;i<a.size();i++)
	// // {
	// // 	addInGraph(graph,a[i],b[i]);
	// // }
	// // coun_astro(graph);

	// // vector<vector<pair<int,int>>>graph(7);
	// // makegraph(graph);
	// // // solve(graph);
	// // cout<<isbiPartbale(graph)<<endl;


	// // shortestPathFromS(graph,0);
	// display(graph);
	// cout<<"_________________________________________________________________________________\n";
	// primsAlog(graph,graph2);
	// display(graph2);
	floyed_warshall();
}