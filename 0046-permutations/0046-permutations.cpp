class Solution {
public:
    
   void solve(vector<int> nums,  int n,vector<vector<int>>&ans, vector<int>&temp, vector<int>&picked){
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++){
            if(picked[i]!=1){
                picked[i] = 1;
                temp.push_back(nums[i]);
                solve(nums,n,ans,temp,picked);
                 picked[i] = 0;
                temp.pop_back();
            }
           
            
        }                                   

    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n = nums.size();
        vector<int>picked(n,0);
        solve(nums,nums.size(),ans,temp,picked);
        return ans;
    }
};