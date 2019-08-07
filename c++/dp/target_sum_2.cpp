class Solution {
    
public:   
    bool canPartition(vector<int>& nums) {
        int s=0;
        for(auto x:nums) s+=x;
        if(s&1)
            return false;
        s=s/2;
        int res[s+1];
        memset(res,0,sizeof(res));
        res[0]=1;
        for(int x:nums)
        {
            for(int i =s;i>=x;i--)
            {
                    res[i]=res[i]||res[i-x];    
            }
        }
        for(auto x:res)cout<<x<<" ";
        
        return res[s]==1;
    }
};