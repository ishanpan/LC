//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
 
  void dfs(vector<int>adjL[], int V, int visited[], int i){
      visited[i] = 1;
      for(auto it:adjL[i]){
          if(!visited[it]){
              dfs(adjL,V,visited,it);
          }
      }
      
  }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int visited[V+1] = {0};
        int ans = 0;
        
        vector<int>adjL[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1 && i!=j){
                    adjL[i].push_back(j);
                    adjL[j].push_back(i);
                }
            }
        }
        

        for(int i=0;i<V;i++){
            if(!visited[i]){
                ans++;
                dfs(adjL,V,visited,i);
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
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends