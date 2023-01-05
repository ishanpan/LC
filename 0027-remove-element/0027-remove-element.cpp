class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        
        
        int l = 0;
        int r = nums.size()-1;
        
        while(l<r){
            if(nums[l]==val){
                while(nums[r]==val && l<r){
                    r--;
                }
                swap(nums[l],nums[r]);
                l++;
                r--;
                
            }
            else{
                l++;
            }
            
            
        }
        
        
        int ans = nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]==val){
                ans = i;
                break;
            }
        }
        return ans;
        
        
        
    }
};