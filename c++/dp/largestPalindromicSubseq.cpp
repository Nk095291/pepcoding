#include<iostream>
#include<vector>
using namespace std;
void solve(string &str)
{
    vector<vector<bool>>res(str.size(),vector<bool>(str.size(),true));
    for(int i =0;i<res.size();i++)
        res[i][i]=true;
    int largest=0;
    int count= res.size();
    for(int gap=1;gap<res.size();gap++)
    {
        for(int i =0,j=i+gap;j<res.size();j++,i++)
        {
            if(str[i]==str[j])
            {
                res[i][j]=res[i+1][j-1];
                if(res[i][j]==true){
                  count++;
                  largest=j-i+1;
                }
            }
            else
            {
                res[i][j]=false;
            }
        }
    }
    for(auto x:res)
    {
        for(auto y:x)
        cout<<y<<" ";
    cout<<endl;
    }
    cout<<"---------------------------------\n";
    cout<<largest<<endl;
    cout<<count<<endl;
}

int main(){
    // give the length of the largest palindromic seq. i.e., a,ab,abc,b,bc,c(these all are seq)(n*(n+1)/2) subset are(a,ac,....2^n)
    string str="abccbc";
    solve(str);
}