class Solution {
public:
    int dp[101];
    int knap(vector<int>nums, int i, int n){
        if(i>=n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ans = 0;
        ans += nums[i] + knap(nums,i+2,n);
        int notPick = knap(nums,i+1,n);

        return dp[i]=max(ans,notPick);
    }
    
    int rob(vector<int>& nums) {
        
        memset(dp,-1,sizeof(dp));
        return knap(nums,0,nums.size());
        
    }
};