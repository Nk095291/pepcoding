#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
 void noduplication(vector<int>&wt, vector<int>&p, int n){
     vector<vector<int>>res(p.size()+1,vector<int>(n+1,0));
     for(int i=1;i<res.size();i++)
     {
         for(int j=0;j<=n;j++)
         {
             int without= res[i-1][j];
             res[i][j]=without;
             if(j>=wt[i-1])
             {
                 int with = p[i-1]+res[i-1][j-wt[i-1]];
                 res[i][j]=max(with,without);
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
 void duplicatoin(vector<int>&wt, vector<int>&p, int n)
 {
     vector<int>res(n+1);
     res[0]=0;
     for(int i =1;i<res.size();i++)
     {
         for(int j=0;j<=wt.size();j++)
         {
             if(i>=wt[j])
                res[i]=max(res[i],res[i-wt[j]]+p[j]);
         }
     }
     for(auto x:res)
        cout<<x<<" ";
    cout<<endl;
 }

 void rodcutting(vector<int>&wt, vector<int>&p){
 	vector<int>res(wt.size());
 	for(int i =1;i<res.size();i++)
 	{
 		int left = 1;
 		 int right = i-1;
 		 res[i]=p[i];
 		 while(left<=right)
 		 {
 		 	// res[i]=max(p[left]+res[right],res[i]);	//using [1*][4*]
 		 	res[i]=max(res[left]+res[right],res[i]);	//using [1][4*]

 		 	left++;
 		 	right--;
 		 }
 	}

 	for(auto x:res)
 		cout<<x<<" ";
 	cout<<endl;
 }
 int main()
 {
     vector<int>wt{0,1,2,3,4,5,6,7,8};
     vector<int>p{0,3,5,6,15,10,25,12,24};
    //  noduplication(wt,p,7);
    rodcutting(wt,p);
 }