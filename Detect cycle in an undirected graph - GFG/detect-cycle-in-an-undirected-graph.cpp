//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool is(int V, vector<int> adj[],int src,int visited[]) {
        // Code here
        queue<pair<int,int>>q;
        
        q.push({src,-1});
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            
            int elem = temp.first;
            
            int parent = temp.second;
            visited[elem] = 1;
            for(auto it:adj[elem]){
                
                if(visited[it]==0){
                    q.push({it,elem});
                }
                else if(parent!=it){
                    
                    return true;
                }
 
            }
            
            
        }
        return false;
        
        
    }
    
    bool isCycle(int V, vector<int> adj[]) {
        int visited[V] = {0};
        for(int i=0;i<V;i++){
            if(visited[i]==0){
                if(is(V,adj,i,visited)){
                    return true;
                }
            }
        }
        return false;
           
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends