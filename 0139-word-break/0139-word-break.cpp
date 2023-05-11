class Solution {
public:
    
    int dp[301];
    bool solve(unordered_set<string>set, string S, int idx){
        if(S.size()==idx){
            return true;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        for(int i=idx;i<S.size();i++){
            string curr = S.substr(idx,i-idx+1);
            if(set.count(curr)>0 && solve(set,S,i+1)){
                return dp[idx]=true;
            }
            
        }
        return dp[idx]=false;

    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> stringSet(wordDict.begin(),wordDict.end());
        memset(dp,-1,sizeof(dp));
        return solve(stringSet,s,0);
    }
};