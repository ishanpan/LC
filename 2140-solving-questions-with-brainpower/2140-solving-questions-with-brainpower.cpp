class Solution {
public:
    long long dp[100001];
    
    long long solve(vector<vector<int>>& questions, int idx, int n){
        
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        long long dontSolve = solve(questions, idx+1,n);
        long long solvedCurr = questions[idx][0];
        int brainP = questions[idx][1];
        int i=idx+brainP+1;
        solvedCurr+=solve(questions,i,n);

        return dp[idx]=max(dontSolve, solvedCurr);
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        memset(dp,-1,sizeof(dp));
        return solve(questions, 0,questions.size());
    }
};