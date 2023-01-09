class Solution {
public:
    
    vector<vector<int>>ans;
    
    void chk(vector<int>& candidates,int si, int target, int i, vector<int>ss){
        if(target<0 || i>si){
            return;
        }
        else if(target==0){
            ans.push_back(ss);
            return;
        }
        
        if(target-candidates[i]>=0){
            vector<int>sb = ss;
            sb.push_back(candidates[i]);
            chk(candidates,si,target-candidates[i],i,sb);
        }
        
        
        chk(candidates,si,target,i+1,ss);
        
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<int>a;
        int si = candidates.size()-1;
        chk(candidates,si,target,0,a);
        
        return ans;
        
        
    }
};