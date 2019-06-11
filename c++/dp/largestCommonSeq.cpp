#include<iostream>
#include<vector>
using namespace std;
void solve(string &a, string &b)
{
    vector<vector<int>>res(a.size()+1,vector<int>(b.size()+1));
    for(int i=res.size()-2;i>=0;i--)
    {
        for(int j=res.size()-2;j>=0;j--)
        {
            if(a[i]==b[j])
            {
                res[i][j]=res[i+1][j+1]+1;              // mid plus one
            }
            else
            {
                res[i][j]=max(res[i][j+1],res[i+1][j]);         // max of the left and right
            }
        }
    }
    for(auto x:res)
    {
        for(auto y:x)
            cout<<y<<" ";
        cout<<endl;
    }
}
int main(){
string a="abcd";
string b="aebd";
solve(a,b);
}
