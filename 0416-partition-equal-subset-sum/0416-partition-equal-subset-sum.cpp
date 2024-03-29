class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int maxSum = 0;
        for(auto x:nums){
            maxSum+=x;
        }
        if(maxSum%2!=0){
            return false;
        }
        maxSum = maxSum / 2;
        bool t[n+1][maxSum+1];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<maxSum+1;j++){
                if(i==0){
                    t[i][j] = false;
                }
                if(j==0){
                    t[i][j] = true;
                }
                
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<maxSum+1;j++){
                if(nums[i-1]<=j){
                    t[i][j] = t[i-1][j-nums[i-1]] || t[i-1][j];
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        return t[n][maxSum];
        
        
        
    }
};