class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        int prevdiff = 0;
        
        for(int i=1;i<n;i++){
            int currdiff = nums[i]-nums[i-1];
            if(currdiff>0 && prevdiff<=0 || currdiff<0 && prevdiff>=0){
                
                ans++;
                prevdiff = currdiff;
            }
        }
        return ans;
        

    }
};