class Solution {
    string find(string& text1,string &text2,int** res,int n ,int m,string asf)
    {
        if(res[n][m]==0)
            return asf;
        if(text1[n-1]==text2[m-1])
        {
            asf=text1[n-1]+asf;
           return  find(text1,text2,res,n-1,m-1,asf);
        }
        return res[n][m-1]>res[n-1][m]?find(text1,text2,res,n,m-1,asf):find(text1,text2,res,n-1,m,asf);
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        int res[n+1][m+1];
        for(int i =0;i<=n;i++)
        {
            for(int j = 0;j<=m;j++)
            {
                if(i==0||j==0)
                    res[i][j]=0;
                else{
                    if(text1[i-1]==text2[j-1])
                    {
                        res[i][j]=res[i-1][j-1]+1;    
                    }
                    else{
                            res[i][j]=max(res[i-1][j],res[i][j-1]);
                    }
                }
            }
        }
        for(int i =0;i<=n;i++)
            for(int j =0;j<=m;j++)
                cout<<res[i][j]<<" \n"[j==m];
        
        int** resp = new int*[n+1];
        for(int i =0;i<=n;i++)
        {
            resp[i]=new int[m+1];
            resp[i]=res[i];
        }
        string lcs = find(text1,text2,resp,n,m,"");
        cout<<lcs<<endl;
        return res[n][m];
    }
};