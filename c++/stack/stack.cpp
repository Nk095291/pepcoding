#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;
// void disSmallestNo(string &st)
// {
// 	stack<int>st;
// 	int res[st.size()+1];
// 	int j=1;

// 	for(char ch :st)
// 	{
// 		if(ch == 'i')
// 			while(st.size()){
// 				cout<<st.top()<<" ";
// 				st.pop();
// 			}
// 		st.push(j++);
// 	}
// }
class x{
public:
	int b;
	bool operator <(const x &a)const{
		return this->b < a.b;
	}
}
void mergeactivity(vector<int> &a,vector<int> &b)
{
	vector<pair<int,int>>res(a.size());
	stack<pair<int,int>> st;
	for(int i =0;i<a.size();i++)
	{
		res[i]=make_pair(a[i],b[i]);
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