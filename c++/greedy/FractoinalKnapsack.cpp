#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class helper{
	public:
	int value;
	int wt;
	float ratio;
	helper(int i,int j)
	{
		value=i;
		wt=j;
		ratio=value*1.0/wt;			// so that the ratio can become a decimal value.
	}
	bool operator>(const helper& other)const
	{
		return this->ratio > other.ratio;
	}
};

int main(){
	vector<int>value{60,40,100,120};
	vector<int>wt{10,40,20,30};

	vector<helper> ar;
	for(int i =0;i<value.size();i++)
	{
		ar.push_back(helper(value[i],wt[i]));
	}
	sort(ar.begin(),ar.end(),greater<helper>());
	int limit = 50;
	float maxv=0;

	for(int i=0;i<ar.size();i++)
	{
		if(limit<=ar[i].wt)
		{
			maxv+=limit*ar[i].ratio;
			limit=0;
			break;
		}
		else
		{
			maxv+=ar[i].value;
			limit-=ar[i].wt;
		}
	}
	cout<<maxv<<endl;
}