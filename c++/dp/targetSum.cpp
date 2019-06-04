#include<vector>
#include<iostream>
using namespace std; 
vector<vector<bool>> targetSum(vector<int>& s, int n )
{
    vector<vector<bool>> res(s.size()+1,vector<bool>(n+1,false));   // making 2D array that will help us prevent duplicacy
    res[0][0]=true;
    for(int i =1;i<res.size();i++)
    {
        for(int j=0;j<res[0].size();j++)
        {
            res[i][j]=res[i-1][j];  // wihtout including the current value
            if(j>=s[i-1] && res[i][j]==false)   // after inlcuding the current value
            {
                res[i][j]=res[i-1][j-s[i-1]];
            }
        }
    }
     return res;
}

void pritnPath(vector<vector<bool>>&res, vector<int>&s,int i ,int j,string psf)
{
    if(j==0)
    {
        cout<<psf<<endl;
        return;
    }
    if(res[i][j]==true)
    {
        if(res[i-1][j]==true)
            pritnPath(res,s,i-1,j,psf); // if the no can be still form without including the current value
        if(j>=s[i-1]&&res[i-1][j-s[i-1]]==true)
             pritnPath(res,s,i-1,j-s[i-1],psf+to_string(s[i-1])+" ");   // if the no can be form using this no 
    }
     
}


int main(){
    vector<int>s{2,5,3,1,6};
    vector<vector<bool>> res = targetSum(s,9);
    // for(auto x:res)
    // {
    //     for(auto y:x)
    //     cout<<y<< " ";
    //     cout<<endl;
    // }
    pritnPath(res,s,res.size()-1,res[0].size()-1,"");
}