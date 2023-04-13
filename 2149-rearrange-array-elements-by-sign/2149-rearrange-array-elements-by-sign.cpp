class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        int i=0;
        int j=0;
        
        bool flag = true;
        while(i<n && j<n){
            if(flag){
                while(nums[i]<0 && i<n){
                    i++;
                }
                ans.push_back(nums[i]);
                i++;
            }
            else{
                 while(nums[j]>0 && j<n){
                    j++;
                }
                ans.push_back(nums[j]);
                j++;
            }
            flag = !flag;
        }
        
             while(j<n && nums[j]>0){
                    j++;
                }
        
        if(j<n){
            ans.push_back(nums[j]);
        }
        return ans;
        
        
    }
};