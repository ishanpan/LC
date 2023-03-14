//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	void dfss(stack<int>&order,vector<int>&visited, int V,vector<vector<int>>& adj){
	    visited[V] = 1;
	    for(auto x: adj[V]){
	        if(!visited[x]){
	            dfss(order,visited,x,adj);
	        }
	    }
	    order.push(V);
	}
	
	void dfsv(vector<int>&visited, int V,vector<vector<int>>& adj){
	    visited[V] = 1;
	    for(auto x: adj[V]){
	        if(!visited[x]){
	        dfsv(visited,x,adj);
	        }
	    }
	    
	}
	
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int>visited(V,0);
        
        stack<int>order;
        vector<vector<int>>adj2(V);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfss(order,visited,i,adj);
            }
        }
        
        for(int i=0;i<V;i++){
            visited[i] = 0;
            for(auto x:adj[i]){
                adj2[x].push_back(i);
            }
        }
        int count = 0;
        while(!order.empty()){
            auto temp = order.top();
            order.pop();
            if(!visited[temp]){
                count++;
                dfsv(visited,temp,adj2);
            }
            
        }
        return count;
        
        
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends