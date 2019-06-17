#include<iostream>
#include<vector>
#include<climits>
using namespace std;

void solve(vector<int>&ar)
{
    vector<vector<int>>res(ar.size()-1,vector<int>(ar.size()-1,0));
    for(int gap=1;gap<res.size();gap++)
    {
        for(int i=0,j=i+gap;j<res.size();j++,i++)
        {
            if(gap==1)
            {
                    res[i][j]=ar[i]*ar[i+1]*ar[j+1];
            }
            else
            {

                res[i][j]=INT_MAX;
                for(int x=i+1,y=j-gap;x<res.size();x++,y++)// y =i;
                {
                    res[i][j]=min((res[i][y]+res[x][j]+ar[i]*ar[y+1]*ar[j+1] ),res[i][j]);
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


// void solve2(vector<int>&ar)
// {
//     vector<vector<int>>res(ar.size()-1,vector<int>(ar.size()-1,0));
//     for(int gap=1;gap<res.size();gap++)
//     {
//         for(int i=0,j=i+gap;j<res.size();j++,i++)
//         {
//             if(gap==1)
//             {
//                     res[i][j]=ar[i]*ar[i+1]*ar[j+1];
//             }
//             else
//             {

//                 res[i][j]=INT_MAX;
//                 for(int k =0;k<gap;)// y =i;
//                 {
//                     int lc = res[i][j-gap+k];
//                     int rc = res[i+1][j];
//                     res[i][j]=min((res[i][y]+res[x][j]+ar[i]*ar[y+1]*ar[j+1] ),res[i][j]);
//                 }
//             }
//         }
//     }

//         for(auto x:res)
//         {
//             for(auto y:x)
//                 cout<<y<<" ";
//             cout<<endl;
//         }
// }

int main(){
    vector<int>ar{10,20,30,40,50,60};
    solve(ar);
}