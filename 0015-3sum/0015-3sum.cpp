class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>>ans;
        
        int n = nums.size();
        
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            int sum = nums[i];
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j = i+1;
            int k = n-1;
            
            while(j<k){
                if(nums[j]+nums[k]+sum>0){
                    k--;
                }
                else if(nums[j]+nums[k]+sum<0){
                    j++;
                }
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    while (j<k && nums[j]==nums[j-1] ){
                        j++;
                    }
                    
                }
                
                
            }
             
        }
        return ans;
        
        
        
    }
};