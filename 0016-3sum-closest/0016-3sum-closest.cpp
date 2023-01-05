class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
       
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans = INT_MIN;
        int diff = INT_MAX;
        for(int i=0;i<n;i++){
            int s = nums[i];
            
            int l = i+1;
            int r = n-1;
            
            while(l<r){
                int sum = s+nums[l]+nums[r];
                int ss = sum-target;
                if(ss>0){                    
                    r--;
                }
                else if(ss<0){
                    l++;
                }
                
                else{
                    return sum;
                }
                
                 if(abs(ss)<diff){
                        diff = abs(ss);
                        ans = sum;
                 }
                
            }
            
            
        }
        return ans;
        
    }
};