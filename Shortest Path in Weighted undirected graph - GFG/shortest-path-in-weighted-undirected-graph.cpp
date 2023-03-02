//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>>adj[n+1];
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,INT_MAX);
        vector<int>parent(n+1);
        dist[1] = 0;
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
        pq.push({0,1});
        
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int vertex = temp.second;
            int distV = temp.first; 
            for(auto x:adj[vertex]){
                int node = x.first;
                int wt = x.second;
                if(distV+wt<dist[node]){
                    parent[node] = vertex;
                    dist[node] = distV+wt;
                    pq.push({dist[node],node});
                }
            }
 
        }
        
        vector<int>ans;
        
        
        int node = n;
        if(dist[node]==INT_MAX){
            ans.push_back(-1);
            return ans;
        }
        while(parent[node]!=node){
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
        
        
        
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends