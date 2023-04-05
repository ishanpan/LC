class Solution {
public:
    
    int t[101][101];

    int recur(int m,int n,int i,int j){
        if(t[i][j]!=-1){
            return t[i][j];
        }
        if(!(i>=0 && j>=0 && i<m && j<n)){
            return 0;
        }
        if(i==m-1 && j==n-1){
            return 1;
        }

        t[i][j]=recur(m,n,i+1,j)+recur(m,n,i,j+1);
        
        return t[i][j];
    }
    
    int uniquePaths(int m, int n) {
        //tabulation only one way reach cell[0][0] and cell[i][0] and cell[0][j];
        
        int t[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0){
                    t[i][j] = 1;
                }
                if(j==0){
                    t[i][j] = 1;
                }
            }
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                t[i][j] = t[i-1][j] + t[i][j-1];
            }
        }
        
        return t[m-1][n-1];
        
        
        
        
        
        
        
        
    }
};