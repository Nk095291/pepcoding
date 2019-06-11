#include<iostream>
#include<vector>
using namespace std;

void solve(string & str)
{
    vector<vector<int>>res(str.size(),vector<int>(str.size()));
    for(int i =0;i<res.size();i++)
        res[i][i]=1;

    for(int gap =1 ;gap<res[0].size();gap++)
    {
        for(int i=0;i+gap<res.size();i++)
        {
            int j = i+gap;
            if(str[i]==str[j])
            {
                res[i][j]=res[i+1][j-1]+2;
            }
            else
            {
                res[i][j]=max(res[i][j-1],res[i+1][j]);
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

void count(string &str)
{
    vector<vector<int>>res(str.size(),vector<int>(str.size(),0));
    for(int i =0;i<res.size();i++)
        res[i][i]=1;
    for(int gap =1;gap<res[0].size();gap++)
    {
        for(int i =0,j=i+gap;j<res.size();j++,i++)
        {
            if(str[i]==str[j])
            {
                res[i][j]=res[i+1][j]+res[i][j-1]+1;
            }
            else
            {
                res[i][j]=res[i+1][j]+res[i][j-1]-res[i+1][j-1];
            }
        }
    }
    for(auto x:res)
        {
            for(auto y:x)
            {
                cout<<y<<" ";
            }
            cout<<endl;
        }
}
int main(){
    string str = "abgcckyb";
    // solve(str);

    count(str);
}