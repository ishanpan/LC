class Solution {
public:
    // int dp[1001][2];
    // int wigglewiggle(int i, int n, bool flag, vector<int>arr){
    //     if(i==n-1){
    //         return 1;
    //     }
    //     if(dp[i][flag]!=-1){
    //         return dp[i][flag];
    //     }
    //     int ans = 0;
    //     if(flag){
    //         if(arr[i+1]>arr[i]){
    //             ans = max(ans,1+wigglewiggle(i+1,n,false,arr));
    //         }
    //         else{
    //             ans = max(ans,wigglewiggle(i+1,n,true,arr));
    //         }
    //     }
    //     else{
    //         if(arr[i+1]<arr[i]){
    //             ans = max(ans,1+wigglewiggle(i+1,n,true,arr));
    //         }
    //         else{
    //             ans = max(ans,wigglewiggle(i+1,n,false,arr));
    //         }
    //     }
    //     return dp[i][flag]=ans;
    // }

    int wiggleMaxLength(vector<int>& nums) {
        int posi = 1;
        int negi = 1;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                posi = 1+negi;
            }
            else if(nums[i]<nums[i-1]){
                negi = 1+posi;
            }
        }
        return max(posi,negi);
    }
};