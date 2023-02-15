//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

bool is(int V, vector<int>adj[],vector<int>&colours,int i){
	    // Code here
	    queue<int>q;
	    q.push(i);
	    
	    colours[0] = 0;
	    while(!q.empty()){
	        auto temp = q.front();
	        q.pop();
	        int elem = temp;

	        
	        for(auto x:adj[elem]){
	            if(colours[x]==-1){
	                colours[x] = !colours[elem];
	                q.push(x);
	            }
	            else if(colours[x]==colours[elem]){
	                return false;
	            }

	        }

	    }
	    return true;
	    
	    
	    
	}



	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    vector<int>colours(V,-1);
	    
	    for(int i=0;i<V;i++){
	        if(colours[i]==-1 && is(V,adj,colours,i)==false){
	            return false;
	        }
	    }
	    return true;
	    
	    
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends