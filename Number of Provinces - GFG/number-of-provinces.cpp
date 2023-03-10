//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
  void unionn(vector<int>&parent, vector<int>&rank,int u, int v){
      
      int parentU = getParent(parent,u);
      int parentV = getParent(parent,v);
      if(parentU==parentV){
          return;
      }
      
      if(rank[parentU]<rank[parentV]){
          parent[parentU] = parentV;
      }
      else if(rank[parentU]>rank[parentV]){
          parent[parentV] = parentU;
      }
      else{
          parent[parentV] = parentU;
          rank[parentU]++;
      }
      
  }
  
  int getParent(vector<int>&parent, int u){
      
      if(parent[u]==u){
          return u;
      }
      
      return parent[u] = getParent(parent, parent[u]);
      
  }
  
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        //union every possible vertex;
        vector<int>parent(V);
        for(int i=0;i<V;i++){
            parent[i]=i;
        }
        vector<int>rank(V,0);
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                 if(adj[i][j]==1){
                   unionn(parent,rank,i,j); 
                }
                
            }
        }
        
        int cnt = 0;
        for(int i=0;i<V;i++){
            if(getParent(parent,i)==i){
                cnt++;
            }
        }
        return cnt;
        
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