#include<iostream>
#include<vector>
#include<list>
using namespace std;
void points(vector<vector<float>> &ar,list<pair<int,int>>&li , int i , int j)		// add nei. points in the queue
{
		if(i+1<ar.size() && ar[i+1][j]==0)
 			li.push_back(make_pair(i+1,j));
 		if(i-1>-1 && ar[i-1][j]==0)
 			li.push_back(make_pair(i-1,j));
 		if(j-1>-1 && ar[i][j-1]==0)
 			li.push_back(make_pair(i,j-1));
 		if(j+1<ar[0].size()&& ar[i][j+1]==0)
 			li.push_back(make_pair(i,j+1));
}
void solve(vector<vector<float>>& ar, int si,int sj, int time)
 {	
 	list<pair<int,int>>li;
 	points(ar,li,si,sj);
 	li.push_back(make_pair(-1,-1));
 	for(int i=1;i<=time;i++)
 	{
 		float val = 0.1*i;
 		while(li.front().first!=-1)
 		{
 			if(ar[li.front().first][li.front().second]==0)
 			{
 				ar[li.front().first][li.front().second]=2+val;
 				points(ar,li,li.front().first,li.front().second);
 			}
 			li.pop_front();	
 		}
 		li.pop_front();
 		li.push_back(make_pair(-1,-1));
 	}				// simple level wise travel where time represent level
}
class helper						
{
	public:
		int i;
		int j;
		int t;
		helper(int i , int j, int t)
		{
			this->i=i;
			this->j=j;
			this->t=t;
		}
};
bool isvalid(vector<vector<int>>& ar,int i ,int j)			// tell weather a point is valid or not 
{
	if(i<0||j<0||i>=ar.size()||j>=ar[0].size())
		return false;
	if(ar[i][j]!=0)
		return false;
	return true;
}
void solve2 (vector<vector<int>>& ar)				// same as first solution , just follow the basic "grmwa"(get remove mark* work add*) algo
{
	list<helper>li;
	for(int i=0;i<ar.size();i++)
	{
		for(int j=0;j<ar[i].size();j++)
		{
			if(ar[i][j]==2)
				li.push_back(helper(i,j,0));
		}
	}
	while(li.size()>0 )
	{
		helper rem = li.front();			// get 
		li.pop_front();						// remove

		if(ar[rem.i][rem.j]>2)
			continue;						// mark
		else
			ar[rem.i][rem.j]=2+rem.t;
		if(rem.t==3)						// work
			return;

		if(isvalid(ar,rem.i+1,rem.j))							// adding children
			li.push_back(helper(rem.i+1,rem.j,rem.t+1));

		if(isvalid(ar,rem.i-1,rem.j))
			li.push_back(helper(rem.i-1,rem.j,rem.t+1));

		if(isvalid(ar,rem.i,rem.j+1))
			li.push_back(helper(rem.i,rem.j+1,rem.t+1));

		if(isvalid(ar,rem.i,rem.j-1))
			li.push_back(helper(rem.i,rem.j-1,rem.t+1));

	}
}

int main(){
	vector<vector<int>> ar ={
 		{0,1,1,1,1,0},
 		{0,1,0,0,1,0},
 		{0,0,0,1,0,0},
 		{0,1,0,1,0,1},
 		{2,0,1,1,0,1}
	};
 	// solve(ar,4,0,3);
 	solve2(ar);
 	for(auto x:ar)
 	{
 		for(auto y :x)
 			cout<<y-2<<" |";
 		cout<<endl;
 	}
}