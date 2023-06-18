//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  int dp[100001];
  
    int minimize(vector<int>& height, int n, int k, int s){
        
        if(s>=n){
            return 10e6;
        }
        if(s==n-1){
            return 0;
        }
        if(dp[s]!=-1){
            return dp[s];
        }
        int minCost = 10e6;
        
        for(int i=1;i<=k;i++){
            if(s+i<n){
                minCost = min(minCost, abs(height[s+i]-height[s])+minimize(height,n,k,s+i));
            }
        }
        
        return dp[s] = minCost;
        
    }
  
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        memset(dp,-1,sizeof(dp));
        return minimize(height,n,k,0);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends