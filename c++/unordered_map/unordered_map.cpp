#include<iostream>
#include<unordered_map>
#include<climits>
#include<set>
#include<vector>
#include<unordered_set>
using namespace std;
char hfc(string &word)			// highest frequency no
{
	unordered_map<char,int> mp;
	for(char x:word)
	{
		mp[x]++;
	}
	int max=INT_MIN;
	char ans ;
	for(auto it =mp.begin();it!=mp.end();it++)
	{
		if(it->second > max)
		{
			max=it->second;
			ans = it->first;
		}
	}
	return ans;
}

void gce1(vector<int> &one, vector<int> &two)			// a- 1 1 1 2 2 3 b- 1 2 3 4 5  ans == 1 2 3 i.e., print commen no in both the array
{
	unordered_set<int> s;
	for(int x:one)
	{
		s.insert(x);
	}
	for(int x:two)
	{
		if(s.count(x))
		{
			s.erase(x);
			cout<<x<<" ";
		}
	}
	cout<<endl;
}

void gce2(vector<int> &one, vector<int> &two)			// a- 1 1 1 2 2 3 b- 1 2 2 3 4 5  ans == 1 2 2 3  i.e., print common no with fre
{
	unordered_map<int,int> mp;
	for(int x:one)
	{
		mp[x]++;
	}
	for(int x:two)
	{
		if(mp.count(x) && mp[x]!=0)
		{
			mp[x]--;
			cout<<x<<" ";
		}
	}
	cout<<endl;
}

void longestS(vector<int> &ar)		// longest consecutive no seq.
{
	unordered_map<int,int> mp;
	for(int x: ar)
	{
		mp[x]=1;
	}

	for(auto it = mp.begin();it!=mp.end();it++)
	{
		
		if(mp.count((it->first)-1)==0){
			int j = (it->first)+1;
			while(mp.count(j))
			{
				it->second=it->second+1;
				j++;
			}	
		}
	}

	int max=INT_MIN;
	auto ans=mp.begin() ;
	for(auto it =mp.begin();it!=mp.end();it++)
	{
		if(it->second > max)
		{
			max=it->second;
			ans = it;
		}
	}
	cout<<ans->first<<" "<<ans->second<<endl;
}

class helper{
public:
	int st;
	int end;
	helper()
	{
		st=-1;
		end=-1;
	}
};
void largestSubArray(vector<int> &ar,int k)  // largest subarray which is divisible by k    in O(n)
{
	vector<int> rem;
	unordered_map<int,helper> m;
	int csum=0;
	for(int x:ar)
	{
		csum+=x;
		rem.push_back(csum%k);
	}
	m[0].st=0;
	for(int i=0;i<rem.size();i++)
	{
		if(m[rem[i]].st==-1)
		{
			m[rem[i]].st=i;	
		}
		else
		{
			m[rem[i]].end=i;
		}
	}

	int len=0;
	int st = -1;
	int end = -1;

	for(auto it = m.begin();it!=m.end();it++)
	{
		int clen = (it->second).end-(it->second).st;
		if(clen>len)
		{
			len = clen;
			st=(it->second).st +1;
			end = (it->second).end;
		}
	}
	cout<< ar[st]<< "  "<< ar[end]<<"   "<<len<<endl;
}

int main()
{
	string a ="nitin kumar";
	cout<<hfc(a)<<endl;
	vector<int> ar {5,1,3,2,2,1,2};
	vector<int> ar2 {1,4,1,2,2,1,5};
	gce1(ar,ar2);
	gce2(ar,ar2);
	vector<int> arr {2,12,9,16,10,5,3,20,25,11,1,8,6};
	longestS(arr);
	vector<int> st{2,5,7,9,3,-6,8,2,15,7,3,12};
	vector<int> st2{1,2,3,4,2};
	largestSubArray(st,3);
}