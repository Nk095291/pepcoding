#include<iostream>
#include<vector>
using namespace std;
int startingpoint(vector<int> &a,vector<int> &b)
{
	vector<int>n(a.size());
	for(int i=0;i<a.size();i++)
		n[i]=a[i]-b[i];
	int st =0;
	int end=0;
	int sum=n[0];
	// bool flag =true;
	// int intialstart=-1;
	while(st<a.size())
	{	
		end++;
		cout << st << " - " << end << " - " << sum << endl;
		if(sum>=0)
		{	
			if(end==a.size())
				end=0;
			if(end==st)
				return st;
			
			sum+=n[end];
		
		}
		else{
			if(st>=end)
				return -1;
			st = end;
			if(st>=a.size())
				return -1;
			sum=n[end];
			// if(flag)
			// {
			// 	flag=false;
			// 	intialstart=st;
			// }
			

		}
	}
}
int main(){
	vector<int>a{6,4,8,2,3,3,1,7,2};
	vector<int>b{5,5,2,4,4,6,2,8,1};
	cout<<startingpoint(a,b)<<endl;

}