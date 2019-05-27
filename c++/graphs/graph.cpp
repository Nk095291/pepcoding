#include<iostream>
#include<vector>
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



int main(){
	vector<vector<edge*>> graph(7);
		addEdge(graph,0,1,10);
		addEdge(graph,1,2,10);
		addEdge(graph,0,3,40);
		addEdge(graph,2,3,10);
		addEdge(graph,3,4,2);
		addEdge(graph,4,6,8);
		addEdge(graph,4,5,3);
		addEdge(graph,5,6,3);
		display(graph);

}