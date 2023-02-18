//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    bool isCycle(int V, vector<int> adj[], vector<int>&vis, vector<int>&pathVis, vector<int>&check){
        vis[V] = 1;
        pathVis[V] = 1;
        check[V] = 0;
        for(auto x:adj[V]){
            
            if(!vis[x] ){
                if(isCycle(x,adj,vis,pathVis,check)==true){
                    check[V] = 0;
                    return true;
                }
            }
            else if(pathVis[x]){
                check[V] = 0;
                return true;
                
            }
        }
        
        check[V] = 1;
        pathVis[V] = 0;
        return false;
    }
  
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<int>visited(V,0);
        vector<int>pathVis(V,0);
        vector<int>check(V,0);
        vector<int>ans;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                isCycle(i,adj,visited,pathVis,check);
            }
        }
        for(int i=0;i<V;i++){
            if(check[i]==1){
                ans.push_back(i);
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

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends