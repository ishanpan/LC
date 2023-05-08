class Solution {
public:
   int dp[20001];
    int del (vector<int>&nums, int i, int n){
        if(i>=n){
            return 0;
        }
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        int currValue = nums[i];
        int totalSumForward = currValue;
        
        int indexNew = i+1;
        while(indexNew<n && currValue == nums[indexNew]){
            totalSumForward += currValue;
            indexNew++;
        }
        while(indexNew<n && currValue+1 == nums[indexNew]){
            indexNew++;
        }
        
        return dp[i]  = max(del(nums,i+1,n), totalSumForward+del(nums,indexNew,n));
        
    }
    
    int deleteAndEarn(vector<int>& nums) {
        
         memset(dp,-1,sizeof(dp));
        sort(nums.begin(),nums.end());
        
        return del(nums,0,nums.size());
        
    }
};