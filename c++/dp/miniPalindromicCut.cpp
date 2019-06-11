#include<iostream>
#include<vector>
#include<climits>
using namespace std;
void solve(string &str)
{
    vector<vector<int>>res(str.size(),vector<int>(str.size()));
    for(int gap=1;gap<res.size();gap++)
    {
        for(int i=0,j=i+gap;j<res.size();j++,i++)
        {
            if(gap==1)
            {
                if(str[i]!=str[j])
                    res[i][j]=1;
            }
            else
            {
                if(str[i]==str[j]&&res[i+1][j-1]==0)
                {
                    res[i][j]==0;
                }
                else
                {
                    res[i][j]=INT_MAX;
                    for(int x=i+1,y=j-gap;x<res.size();x++,y++)// y =i;
                    {
                        res[i][j]=min((res[i][y]+res[x][j]),res[i][j]);
                    }
                    res[i][j]++;   
                }
                
       
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
    // minimum cuts that has to be made to make a string palindromic
    string str="abccbc";
    solve(str);
}