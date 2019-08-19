class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        long long res[n][n];
        memset(res,0,n*sizeof(res[0]));
        
        
        int count=n;
        
        for(int g =0;g<n;g++)
        {
            for(int i=0;i+g<n;i++)
            {
                int j = i+g;
                if(g==0)
                {
                    res[i][j]=1;
                }
                else if(s[i]==s[j]&&(res[i+1][j-1]||g==1)){
                    res[i][j]=1;
                    count++;
                }
                else{
                    res[i][j]=0;
                }
            }
        }
        for(int j=0;j<n;j++)
            for(int i =0;i<n;i++)
                cout<<res[j][i]<<" \n"[i==n-1];

    
        return count;
    }
};