#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<vector<int>> goldMine(vector<vector<int>>&mat,int &sti)
{
    int r = mat.size();
    int c = mat[0].size();
    vector<vector<int>>res(r,vector<int>(c));
    for(int j=0;j<res.size();j++)
        res[j][c-1]=mat[j][c-1];
    for(int j=c-2;j>=0;j--)
    {
        for(int i=0;i<r;i++)
        {
            //checking for all the valid moves
            int a =INT_MIN; 
            int b = res[i][j+1];
            int c= INT_MIN;
            if(i>0)
                a=res[i-1][j+1];
            if(i<r-1)
                c=res[i+1][j+1];
            res[i][j]=max(a,max(b,c))+mat[i][j];    // selecting max of them
        }
    }
    int maxx=INT_MIN;   // there can be more than one cell with same maximum value thus all of them should be haddle on 
                    // printing the path
    for(int i =0;i<res.size();i++)
    {
        if(res[i][0]>maxx)
        {
            maxx=res[i][0];
            sti=i;
        }
    }
    return res;
}

 void printPath(vector<vector<int>>&res,vector<vector<int>>&mat,int i,int j,string psf)
 {
     if(j==mat[0].size()-1)
        {
            cout<<psf<<endl;
            return;
        }
        // printing all possible values that mean there can be more than one ans
    if(i>0 && res[i][j]-mat[i][j]==res[i-1][j+1])
        printPath(res,mat,i-1,j+1,psf+" d1");
    if(res[i][j]-mat[i][j]==res[i][j+1])
        printPath(res,mat,i,j+1,psf+" d2");
    if(i<mat.size()-1 &&res[i][j]-mat[i][j]==res[i+1][j+1])
        printPath(res,mat,i+1,j+1,psf+" d3");
 }
 int main(){
     vector<vector<int>> mat{
         {2,5,0,1,3},
         {3,5,4,2,9},
         {4,2,0,1,7},
         {0,1,3,5,4},
         {3,4,8,2,4},
         {2,0,6,3,7},
     };
     int st=0;
     vector<vector<int>> res = goldMine(mat,st);
     for(auto x:res)
     {
         for(auto y:x)
         cout<<y<<" ";
        cout<<endl;
     }
     printPath(res,mat,st,0,string()+to_string(st));
 }