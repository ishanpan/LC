class Solution {
public:
    
    void solve(vector<int>& nums,vector<int>&temp, int n, set<vector<int>>&setV,vector<int>&visi){
        
        if(temp.size()==n){
            setV.insert(temp);
        }
        
        for(int i=0;i<n;i++){
            if(visi[i]!=1){
                temp.push_back(nums[i]);
                visi[i] = 1;
                solve(nums,temp,n,setV,visi);
                visi[i] = 0;
                temp.pop_back();
            }

        }
            
    
        
    }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>temp;
        set<vector<int>>setV;
        int n = nums.size();
        vector<int>visi(n,0);
        vector<vector<int>>ans;
        solve(nums,temp,n,setV,visi);
        for(auto x:setV){
            ans.push_back(x);
        }
        return ans;
    }
};