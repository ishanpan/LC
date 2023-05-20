//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    
        typedef pair<int,int> pi;
        int edgesRev(vector<pair<int,int>>adj[], int src, int dst,int n){
            
            priority_queue<pi, vector<pi>, greater<pi>>pq;
            pq.push({0,src});
            
            vector<int>dist(n+1,INT_MAX);
            dist[src] = 0; 
            while(!pq.empty()){
                auto temp = pq.top();
                int  vertex = temp.second;
                pq.pop();
                int wt = temp.first;
                for(auto itr:adj[vertex]){
                    int nodeWt = itr.second;
                    int node = itr.first;
                    if(dist[vertex]+nodeWt<dist[node]){
                        dist[node] = dist[vertex]+nodeWt;
                        pq.push({dist[node],node});
                    }
                }
            }
            
             if(dist[dst]==INT_MAX){
                return -1;
            }
            return dist[dst];
            
        }
        
        
        int minimumEdgeReversal(vector<vector<int>> &edges,int n,int src,int dst)
        {
            vector<pair<int,int>>adj[n+1];
            for(auto itr:edges){
                adj[itr[0]].push_back({itr[1],0});
                adj[itr[1]].push_back({itr[0],1});
            }
            return edgesRev(adj,src,dst,n);
            
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<vector<int>> edges(m,vector<int> (2));
        for(auto &j:edges)
            for(auto &i:j)
                cin>>i;
        int src,dst;
        cin>>src>>dst;
        Solution s;
        cout<<s.minimumEdgeReversal(edges,n,src,dst)<<endl;
    }
    return 0;
}
// } Driver Code Ends