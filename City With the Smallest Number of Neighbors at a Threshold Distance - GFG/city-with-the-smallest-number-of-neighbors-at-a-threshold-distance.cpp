//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
                     
            vector<vector<int>>adj(n,vector<int>(n,INT_MAX));
            
            for(auto x:edges){
                adj[x[0]][x[1]]=x[2];
                adj[x[1]][x[0]]=x[2];
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j){
                        adj[i][j]=0;
                    }
                }
            }
            for(int k=0;k<n;k++){
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if (adj[i][k] == INT_MAX || adj[k][j] == INT_MAX)
						continue;
                        adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
                    }
                }
            }
            
            int minCity = n;
            int ans = -1;
            
            for(int i=0;i<n;i++){
                int count = 0;
                for(int j=0;j<n;j++){
                    if(adj[i][j]<=distanceThreshold){
                        count++;
                    }
                }
                if(count<=minCity){
                    minCity = count;
                    ans = i;
                }
            }
            return ans;
                     
                     
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends