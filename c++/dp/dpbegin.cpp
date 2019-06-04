#include<iostream>
#include<vector>
#include<climits>
#include<queue>
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

vector<vector<int>> minPrice(vector<vector<int>>&mat)
{
	vector<vector<int>>res(mat.size(),vector<int>(mat[0].size()));
	res[0][0]=mat[0][0];
	for(int i=0;i<mat.size();i++)
	{
		for(int j=0;j<mat[0].size();j++)
		{
			if(i==0&&j==0)
				continue;
			int a =INT_MAX;
			int b =INT_MAX;
			if(i>0)
				a=res[i-1][j];
			if(j>0)
				b=res[i][j-1];
			res[i][j]=min(a,b)+mat[i][j];
		}
	}
	return res;
}
class helper{
	public:

	int i; 
	int j;
	string psf;
	helper(int a,int b,string s){
		i=a;
		j=b;
		psf=s;
	}
};
void printMinPath(vector<vector<int>>& res, vector<vector<int>>& mat)
{
	queue<helper>q;
	q.push(helper(mat.size()-1,mat[0].size()-1,""));
	while(q.size()>0)
	{
		helper rem = q.front();
		q.pop();
		
		if(rem.i==0 && rem.j==0)
			{
				cout<<rem.psf+to_string(mat[rem.i][rem.j])<<endl;
			}
		else{

			if(rem.i>0&&res[rem.i][rem.j]-mat[rem.i][rem.j]==res[rem.i-1][rem.j])
				q.push(helper(rem.i-1,rem.j,rem.psf+to_string(mat[rem.i][rem.j])+" ") );
			if(rem.j>0&&res[rem.i][rem.j]-mat[rem.i][rem.j]==res[rem.i][rem.j-1])
				q.push(helper(rem.i,rem.j-1,rem.psf+to_string(mat[rem.i][rem.j])+" "));
		}
	}
}
void tabulatoin(){
	// vector<int>upto{0,2,3,1,0,2,0,2,4};
	// cout<<minsteps(upto)<<endl;
	vector<vector<int>>maze {{2,6,5,1,3,4},
                             {0,4,9,2,9,0},
                             {4,8,1,0,6,5},
                             {3,3,3,1,5,4},
                             {1,2,7,0,6,9},
                             {5,7,1,3,8,2}
                             };
    vector<vector<int>>res = minPrice(maze);
	printMinPath(res,maze);

}



int main()
{
tabulatoin();
}