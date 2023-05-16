class Solution {
public:
    int dp[10001];
    bool solve(vector<int>& nums, int i){
       if(i>nums.size()){
            return false;
        }
        if(i==nums.size()-1){
            return true;
        }
         if(dp[i]!=-1){
             return dp[i];
         } 
       
        
        if(nums[i]==0){
            return false;
        }
        
        for(int j=i+1;j<=i+nums[i];j++){
            if(solve(nums,j)){
                return nums[i] = true;
            }
        }
        
        return nums[i]=false;
        
    }
    
    bool canJump(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0);
    }
};