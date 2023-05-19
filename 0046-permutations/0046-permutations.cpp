class Solution {
public:
    
   void solve(vector<int> nums, int ind, int n,vector<vector<int>>&ans){
        if(ind==n){
            vector<int>temp;
            for(auto x:nums){
                temp.push_back(x);
            }
            ans.push_back(temp);
            return;
        }
       
       for(int i = ind;i<n;i++){
           swap(nums[i],nums[ind]);
           solve(nums,ind+1,n,ans);
           swap(nums[i],nums[ind]);
       }
                          

    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        
        int n = nums.size();
        
        solve(nums,0,n,ans);
        return ans;
    }
};