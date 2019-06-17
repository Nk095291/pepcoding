#include<iostream>
#include<vector>
#include<queue>
using namespace std; 
void klar(vector<int>ar,int k )
{
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i =0;i<k;i++)
        pq.push(ar[i]);
    for(int i =k;i<ar.size();i++)
        if(pq.top()<ar[i])
        {
            pq.pop();
            pq.push(ar[i]);
        }
    
    while(pq.size()>0)
        {
            cout<<pq.top()<<" ";
            pq.pop();
        }
        cout<<endl;
}
void almostSortedArray(vector<int>ar,int k)
{
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i =0;i<k;i++)
        pq.push(ar[i]);
    for(int i =k;i<ar.size();i++)
    {
        pq.push(ar[i]);
        cout<<pq.top()<<" ";
        pq.pop();
    }
    while (pq.size())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
}
class helepr{
    public:
    int value;
    int i;
    int j;
    helepr(int value,int i, int j)
    {
        this->value=value;
        this->i=i;
        this->j=j;
    }
    bool operator<(const helepr o)const{
        return  o.value < this->value ;
    }
};
void mergeKsort(vector<vector<int>>& ar)
{
    priority_queue<helepr>pq;
    for(int i =0;i<ar.size();i++)
    {
        pq.push(helepr(ar[i][0],i,0));
    }
    while (pq.size())
    {
        helepr rem = pq.top();
        pq.pop();
        cout<<rem.value<<" ";
        if(rem.j+1<ar[rem.i].size())
            pq.push(helepr(ar[rem.i][rem.j+1],rem.i,rem.j+1));
        
    }
    
}
int main(){
    // vector<int>ar{2,8,14,5,6,1,9,4,20,3,11};
    // klar(ar,4);
    // vector<int> ar{20,40,10,30,50,80,60,90,70,120,110,100};
    // almostSortedArray(ar,2);
    vector<vector<int>>ar{
        {2,5,9,18},
        {3,7,8,15,22},
        {0,4,6,12},
        {1,10,16,21,28}
    };
    mergeKsort(ar);
}