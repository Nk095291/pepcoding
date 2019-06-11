#include<iostream>
#include<vector>
#include<stack>
using namespace std; 
void printPath(vector<int>&ar,vector<int>&res,int index,string psf)
{
    if(res[index]==1)
    {   
        cout<<psf<<ar[index]<<endl;
        return;
    }
    for(int i=index-1;i>=0;i--)
        if(res[i]==res[index]-1 && ar[i]<ar[index])
            printPath(ar,res,i,psf+to_string(ar[index])+" ");
}



void printPath2(vector<int>&ar,vector<int>&res,int index)
{
    stack<pair<int,string>>st;
    st.push(make_pair(res[index],to_string(ar[index])+" "));
    while(st.size()>0)
    {
        pair<int,string> rem = st.top();
        st.pop();
        if(rem.first==1)
        {
            cout<<rem.second<<rem.first<<endl;
        }
        else{
            for(int i =0;i<res.size();i++)
            {
                if(res[i]-1==res[rem.first]&&ar[i]<ar[rem.first])
                    st.push(make_pair(res[i],rem.second+to_string(ar[i])+" "));
            }
        }
    }
}

void solve(vector<int>&ar)
{
    vector<int>res(ar.size());
    res[0]=1;
    for(int i=1;i<ar.size();i++)
    {
        res[i]=0;
        for(int j=0;j<i;j++)
        {
            if(ar[j]<ar[i])
                res[i]=max(res[i],res[j]);
        }
        res[i]++;
    }
    for(auto x:res)
        cout<<x<<" ";
        cout<<endl;

    printPath2(ar,res,res.size()-2);
}
int main()
{   
    // length of the largest incresing sequence from the index =i
    vector<int>ar{10,22,9,33,21,50,41,60,80,1};
    solve(ar);
}