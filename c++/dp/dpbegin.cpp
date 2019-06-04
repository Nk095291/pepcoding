#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> steps ={1,2,3};
int counter=0;
int counter2=0;
void climestair(int n)		// without DP  , it runs 97 times
{	
	if(n<0)
		return;
	if(n==0)
		counter++;
	cout<<++counter2<<"normal"<<n<<endl;
	for(auto step:steps)
		climestair(n-step);
}

int climestairDP(int n,vector<int>& ar)		// with DP , it run 7 times
{	
	if(n<0)
		return 0;
	if(n==0)
		return 1;
	if(ar[n]!=0)
		return ar[n];
	cout<<++counter2<<"dp"<<n<<endl;

	int s=0;
	for(auto step:steps)
		s+=climestairDP(n-step,ar);
	ar[n]=s;
	return s;
}


int climbstair2(int n, vector<int>&upto,vector<int> &ar)
{
	if(n==0)
		return 1;
	if(n<0 || upto[n]==0)
		return 0;
	if(ar[n]!=-1)
		return ar[n];
	int res =0;
	for(int i =1;i<=upto[n];i++)
		res+=climbstair2(n-i,upto,ar);
	ar[n]=res;
	return res;
}
int climbstair22(int n, vector<int>&upto,vector<int> &ar,int psf,string p)
{
	if(n==0){
		cout<<p<<endl;
		return psf;
	}
	if(n<0 || upto[n]==0)-
		return INT_MAX;
	if(ar[n]!=-1)
		return ar[n];
	int res =INT_MAX;
	for(int i =1;i<=upto[n];i++){
		int t =climbstair22(n-i,upto,ar,psf+1,p+to_string(n));
		if(res>t)
			res=t;
	}
	ar[n]=res;
	return res;
}
int minsteps(vector<int>&upto)
{
	vector<int> res (upto.size(),INT_MAX);
	res[0]=0;
	for(int i=1;i<upto.size();i++)
	{
		int minn = INT_MAX;
		for(int j=1;j<=upto[i];j++)
		{	
			int inter = i-j;
			if(inter>=0)
			{
				if(minn>res[inter])
					minn=res[inter];
			}else{
				break;
			}
		}
		res[i]=minn==INT_MAX?INT_MAX:minn+1;
		cout<<i<<" "<<res[i]<<endl;
	}
	return res[res.size()-1];
}

void climestairwala(){
	int n=7;
	climestair(n);
	cout<<counter<<endl;
	vector<int>ar(n+1,0);
	counter2=0;
	cout<<climestairDP(n,ar)<<endl;
}
void tabulatoin(){
	vector<int>upto{0,2,3,1,0,2,0,2,4};
	cout<<minsteps(upto)<<endl;
}

int main()
{
tabulatoin()	
}