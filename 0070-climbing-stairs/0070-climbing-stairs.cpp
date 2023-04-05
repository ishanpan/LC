class Solution {
public:

    
    int t[46];
    int climb(int n){
        
        if(n<0){
            return 0;
        }
        if(t[n]!=-1){
            return t[n];
        }
        
        if(n==0){
            return 1;
        }
        
        t[n] = climb(n-1) + climb(n-2);

        return t[n];
        
    }
    
    int climbStairs(int n) {
        memset(t,-1,sizeof(t));
        return climb(n);
        
        
    }
};