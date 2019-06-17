#include<iostream>
#include<vector>
#include<climits>
using namespace std; 


int solve( int f , int e,vector<vector<int>>&path)
{
    if(e==1||f==0||f==1)
    {
        return f;
    }
    int worstcase;
    int res = INT_MAX;
    for(int i =1;i<=f;i++)
    {
        int left = solve(i-1,e-1);
        int right = solve(f-i,e);
        cout<<i<<" "<<left<<" "<<right<<endl;
        worstcase=max(left,right);
        res= min(res,worstcase);
    }
    return res+1;
}

int main(){
    int f=10;
    int e =2;
    vector<vector<int>>res(f+1,vector<int>(e+1));
    cout<< solve(f,2,res)<<endl;
}