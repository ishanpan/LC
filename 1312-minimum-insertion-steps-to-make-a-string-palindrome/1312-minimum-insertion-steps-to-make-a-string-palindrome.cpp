class Solution {
public:
    int minInsertions(string s) {
        string srev = s;
        reverse(srev.begin(),srev.end());
        int l = s.size();
        int dp[l+1][l+1];
        
        for(int i=0;i<l+1;i++){
            for(int j=0;j<l+1;j++){
                if(i==0 || j==0){
                    dp[i][j] = 0;
                }
            }
        }
        
        for(int i=1;i<l+1;i++){
            for(int j=1;j<l+1;j++){
                if(s[i-1]==srev[j-1]){
                    dp[i][j] = 1+(dp[i-1][j-1]);
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
                
            }
        }
        return l-dp[l][l];
        
        
        
        
    }
};