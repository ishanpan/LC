class Solution {
public:
    
    int dp[1001][2];
    int wigglewiggle(int i, int n, bool flag, vector<int>arr){
        if(i==n-1){
            return 1;
        }
        if(dp[i][flag]!=-1){
            return dp[i][flag];
        }
        int ans = 0;
        if(flag){
            if(arr[i+1]>arr[i]){
                ans = max(ans,1+wigglewiggle(i+1,n,false,arr));
            }
            else{
                ans = max(ans,wigglewiggle(i+1,n,true,arr));
            }
        }
        else{
            if(arr[i+1]<arr[i]){
                ans = max(ans,1+wigglewiggle(i+1,n,true,arr));
            }
            else{
                ans = max(ans,wigglewiggle(i+1,n,false,arr));
            }
        }
        return dp[i][flag]=ans;
    }
    
    
    int wiggleMaxLength(vector<int>& nums) {
     
        memset(dp,-1,sizeof(dp));
        
        int posi = wigglewiggle(0,nums.size(),true,nums);
        int negi = wigglewiggle(0,nums.size(),false,nums);
        return max(posi,negi);
        
        
    }
};