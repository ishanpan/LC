class Solution {
public:
    
    int dp [50001];
    bool solve(vector<int>& arr, int ind, vector<bool>&visited, int n){
        
        if(arr[ind]==0){
            return true;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int jumpB = ind-arr[ind];
        int jumpF = ind+arr[ind];
        visited[ind] = true;
        if(jumpB>=0 && !visited[jumpB] && solve(arr,jumpB,visited,n)){
            return dp[ind] = true;
        }
        if(jumpF<n && !visited[jumpF] && solve(arr,jumpF,visited,n)){
            return dp[ind] = true;
        }
        return dp[ind] = false;
        
    }
    
    
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();
        vector<bool>visited(n,false);
        memset(dp,-1,sizeof(dp));
        return solve(arr, start,visited,n);
        
    }
};