#include<iostream>
#include<vector>
#include<climits>
using namespace std; 
void solve(vector<int>&value,vector<int>&f,vector<int>&sum)
{
    vector<vector<int>>res(value.size()+1,vector<int>(value.size()+1,0));

    for(int i =1;i<res.size();i++)
    {
        res[i][i]=f[i-1];
    }

    for(int gap =1;gap<res.size();gap++)
    {
        for(int i =1,j=i+gap;j<res.size();i++,j++)
        {
            int mmin=INT_MAX;
            for(int k=-1;k<gap;k++)
            {
                int left = res[i][i+k];
                int right = i+2+k>=res.size()?0:res[i+2+k][j];

                mmin = min((left+right),mmin);
            }
            res[i][j]=mmin+sum[j]-sum[i-1];
        }
    }
    for(auto x:res)
    {
        for(auto y:x)
            cout<<y<<" ";
        cout<<endl;
    }
}

int main()
{
    vector<int>value{5,7,8,17,20};
    vector<int>f{4,7,5,1,2};
    vector<int>sum(f.size()+1);
    sum[0]=0;
    for(int i =1;i<=f.size();i++)
        sum[i]=sum[i-1]+f[i-1];
    for(auto x:sum)
        cout<<x<<" ";
    cout<<endl;
    
    solve(value,f,sum);
}