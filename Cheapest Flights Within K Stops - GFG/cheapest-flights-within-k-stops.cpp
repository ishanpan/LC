//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        //build graph
        vector<pair<int,int>>adj[n];
        for(auto x:flights){
            adj[x[0]].push_back({x[1],x[2]});
        }
        vector<int>cost(n,INT_MAX);
        
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int vertexCost = temp.second.second;
            int vertex = temp.second.first;
            int stops = temp.first;
            for(auto x:adj[vertex]){
                if(stops<=K && vertexCost+x.second<cost[x.first]){
                    cost[x.first]=vertexCost+x.second;
                    q.push({stops+1,{x.first,cost[x.first]}});
                }
            }
            
        }
        
        if(cost[dst]==INT_MAX){
            return -1;
        }
        return cost[dst];
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends