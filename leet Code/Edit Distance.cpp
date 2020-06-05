class Solution {
    static int ConfigureFastIO() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}


    
public:
    
    int minDistance(string word1, string word2) {
        static const int unused = ConfigureFastIO();
        if(word1==word2)
             return 0;
        
        int n=word1.size();
        
        int m=word2.size();
        
        vector<vector<int> > dp(n,vector<int> (m,-1));
        
        return HelpMeSenpai(dp,word1,word2,n-1,m-1);
    }
    
    int HelpMeSenpai(vector<vector<int> >& dp,string s1,string s2,int n,int m)
    {
       
       
        
        if(n==-1)                         // s1 null
            return m+1;
        if(m==-1)                         // s2 null
            return n+1;
        if(dp[n][m]!=-1)                 //  if previously calculated
            return dp[n][m];
        if(s1[n]==s2[m]) 
            return HelpMeSenpai(dp,s1,s2,n-1,m-1);
        
        return dp[n][m]=1+min(HelpMeSenpai(dp,s1,s2,n-1,m),           //   remove
                                                                          
                              min(HelpMeSenpai(dp,s1,s2,n,m-1),        //   add
                                  
                                  HelpMeSenpai(dp,s1,s2,n-1,m-1)));     //   replace
    }
};
