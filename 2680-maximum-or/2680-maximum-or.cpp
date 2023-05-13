class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        
        long long po = 1;
        for(int i=0;i<k;i++){
            po *= 2;
        }
        int n = nums.size();
        vector<long long>prefix(n+1,0);
        vector<long long>suffix(n+1,0);
        prefix[0] = 0;
        suffix[0] = 0;
        
        for(int i=0;i<n;i++){
            prefix[i+1] = prefix[i] | nums[i];
        }
        for(int i=n-1;i>0;i--){
            suffix[i] = suffix[i+1] | nums[i];
        }
        
        long long ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans, (prefix[i] | nums[i]*po | suffix[i+1]));
        }
        return ans;
    }
    
};