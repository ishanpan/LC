class Solution {
public:
    
    int t[101][101];
    bool valid(int m,int n,int i,int j){
        if(i>=0 && j>=0 && i<m && j<n){
            return true;
        }
        return false;
        
    }
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
        
        
        t[i][j]=recur(m,n,i+1,j);
        
         t[i][j] += recur(m,n,i,j+1);
        
        return t[i][j];
        
    }
    
    int uniquePaths(int m, int n) {
        memset(t,-1,sizeof(t));
        return recur(m,n,0,0);
        
        
    }
};