#include<iostream>
#include<vector>
#include<climits>
using namespace std; 

int solve(vector<vector<int>>&res, int b,int l){
    if(l<=0||b<=0)
        return 0;
    if(l==b)
        return 0;
    if(res[b][l]!=INT_MAX)
        return res[b][l];
        
    for(int i =1;i<=min(b,l);i++){
        int p1v=solve(res,b-i,i);
        int p2v=solve(res,b,l-i);
        int p1h=solve(res,i,l-i);
        int p2h=solve(res,b-i,l);
        res[b][l]=min((p1h+p2h+1),(p1v+p2v+1));

    }
    return res[b][l];
}

int solve2(vector<vector<int>>&res, int b,int l){
    if(l==0||b==0)
        return 0;
    if(l==b)
        return 1;
    if(res[b][l]!=0)
        return res[b][l];
    int mymin=INT_MAX;
    for(int i =1;i<=min(b,l);i++){
        int p1v=solve(res,b-i,i);
        int p2v=solve(res,b,l-i);
        int c1=p1v+p2v+1;

        int p1h=solve(res,i,l-i);
        int p2h=solve(res,b-i,l);
        int c2 =p1h+p2h+1;
        mymin=min(mymin,min(c1,c2));
    }
    res[b][l]=mymin;
    return mymin;
}


int main(){
    vector<vector<int>>res(31,vector<int>(36+1,INT_MAX));

    cout<<solve(res,30,36);
}