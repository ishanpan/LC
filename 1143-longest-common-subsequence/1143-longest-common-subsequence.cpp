class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
       int n1 = text1.size();
        int n2 = text2.size();
        int t[n1+1][n2+1];
        for(int i=0;i<n1+1;i++){
            for(int j=0;j<n2+1;j++){
                if(i==0 || j==0){
                    t[i][j] = 0;
                }
            }
        }
        for(int i=1;i<n1+1;i++){
            for(int j=1;j<n2+1;j++){
                if(text1[i-1]==text2[j-1]){
                    t[i][j] = 1+t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[n1][n2];
    }
};