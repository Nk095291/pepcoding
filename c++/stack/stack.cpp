#include<iostream>
#include<stack>
#include<algorithm>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;
unordered_set<char>closing_set{')','}',']'};
unordered_map<char,char>map{make_pair(')','('),make_pair('}','{'),make_pair(']','[')};
unordered_set<char>opening_set{'(','{','['};

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
//-----------------------------------------------------------------------------------------------------

// tell weather the given sequence has balance backets or not?

bool isBalanceBackets(string s)
{
	stack<char> st;
 	for(char ch :s)
	{ 	
	 	if(closing_set.count(ch)==1)
	 	{
	 		if(st.size()==0)
	 			return false;
	 		while(st.top()!=map[ch])
	 		{
	 			if(opening_set.count(st.top())==1) 												// wrong starting backet
	 				return false;
	 			st.pop();
	 			if(st.size()==0	)															 // left braket is extra (one ending braket is extra)
	 				return false;
	 		}
	 		st.pop(); 																		//  to remove the starting backet
	 	}
	 	else
	 		st.push(ch);
	}
	if(st.size()!=0)																	// right bracket is extra(one staring backet is extra)
	 	return false; 
	return true;
}
int main()
{
// vector<int> ar{22,17,19,2,6,12,3};
// vector<int> ar2{26,20,23,4,8,15,9};
// mergeactivity(ar,ar2);
	// for(auto it = set2.begin();it!=set2.end();it++)
	// 	cout<<it->first<<" "<<it->second<<endl;
cout<<isBalanceBackets("[{(a+b)+(b+c}}]")<<endl;
}