#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;
class x{
public:
	int first;
	int second;
	x(){}
	x(int a,int b)
	{
		first=a;
		second=b;
	}
	bool operator <(const x& a) const{
		return this->first < a.first;
	}
};
void mergeactivity(vector<int> &a,vector<int> &b)
{
	vector<x>res(a.size());
	stack<x> st;
	for(int i =0;i<a.size();i++)
	{
		x nn(a[i],b[i]);
		res[i]=nn;
	}
	sort(res.begin(),res.end());
	st.push(res[0]);
	for(int i =1;i<res.size();i++)
	{
		if(res[i].first <= st.top().second)
		{
			st.top().second=max(res[i].second,st.top().second); 
		}
		else
		{
			st.push(res[i]);
		}
	}
	cout<<st.size()<<endl;
}
int main()
{
vector<int> ar{22,17,19,2,6,12,3};
vector<int> ar2{26,20,23,4,8,15,9};
mergeactivity(ar,ar2);

}