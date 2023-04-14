class Solution {
public:
    int longestPalindromeSubseq(string s) {
        //implement lcs 
        
        string sre = s;
        reverse(sre.begin(),sre.begin()+sre.length());
        int l1 = s.length();
        int l2 = l1;
        
        int t[l1+1][l2+1];
        for(int i=0;i<l1+1;i++){
            for(int j=0;j<l2+1;j++){
                if(i==0 || j==0){
                    t[i][j] = 0;
                }
            }
        }
        for(int i=1;i<l1+1;i++){
            for(int j=1;j<l2+1;j++){
                if(s[i-1]==sre[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];  
                }
                else{
                    t[i][j] = max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        return t[l1][l2];
        
    }
};