#include <iostream>
#include<vector>
#include<list>
using namespace std;

bool isvalid(vector<vector<int>>& ar,int i ,int j)
{
	if(i<0||j<0||i>=ar.size()||j>=ar[0].size())
		return false;
	if(ar[i][j]!=0)
		false;
	return true;
}


int countIsland(vector<vector<int>>& ar)
{
	list<pair<int,int>>li;
	int count=0;				// no of islands
	for(int i =0;i<ar.size();i++)
	{
		for(int j=0;j<ar[0].size();j++)
		{
			if(ar[i][j]!=0)
				continue;
			count++;
			li.push_back(make_pair(i,j));			// store the first part of the island 
			while(li.size()>0)							// check it's connections and change them to their respective island
			{
				//_____________________________"grmwa" algo______________________________
				pair<int,int> rem = li.front();
				li.pop_front();
				if(ar[rem.first][rem.second]!=0)
					continue;
				else
					ar[rem.first][rem.second]=count;

				if(isvalid(ar,rem.first+1,rem.second))
					li.push_back(make_pair(rem.first+1,rem.second));
				if(isvalid(ar,rem.first-1,rem.second))
					li.push_back(make_pair(rem.first-1,rem.second));
				if(isvalid(ar,rem.first,rem.second+1))
					li.push_back(make_pair(rem.first,rem.second+1));
				if(isvalid(ar,rem.first,rem.second-1))
					li.push_back(make_pair(rem.first,rem.second-1));
			}
		}
	}
	return count;
}
int main(){
	vector<vector<int>> ar{
		{0,0,-1,0,0},
		{0,-1,-1,-1,-1},
		{-1,0,0,0,0},
		{0,-1,0,-1,0},
		{0,-1,-1,-1,0}
	};
	cout<<countIsland(ar)<<endl;
	for(auto x:ar)
	{
		for(auto y:x)
			cout<<y<<" ";
		cout<<endl;
	}
}