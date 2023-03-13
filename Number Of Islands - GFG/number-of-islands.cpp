//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
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
  
  bool isValid(int n,int m,int x,int y){
      if(x>=0 && y>=0 && x<n  && y<m ){
         return true; 
      }
      return false;
  }
  
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        vector<int>parents(n*m);
        vector<int>rank(n*m,0);
        vector<vector<int>>visited(n,vector<int>(m,0));
        int count = 0;
        for(int i=0;i<m*n;i++){
                parents[i] = count++;
        }
        vector<int>ans;
        int cnt = 0;
        int xmoves[] = {-1,0,1,0};
        int ymoves[] = {0,1,0,-1};
        for(int i=0;i<operators.size();i++){
            int xcor = operators[i][0];    
            int ycor = operators[i][1];
            if(visited[xcor][ycor]==1){
                ans.push_back(cnt);
                continue;
            }
            
            visited[xcor][ycor] = 1;
            cnt++;
            for(int j=0;j<4;j++){
                int row = xcor + xmoves[j];
                int column = ycor + ymoves[j];
                if(isValid(n,m,row,column) && visited[row][column]==1){
                   int actualindex1 = m*row + column;
                   int actualindex2  = m*xcor + ycor;
                   if(getParent(parents,actualindex1)!=getParent(parents,actualindex2)){
                       unionn(parents,rank,actualindex1,actualindex2);
                       cnt--;
                   }
                }
            }
            
            ans.push_back(cnt);
            
            
        }
        return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,k; cin>>n>>m>>k;
        vector<vector<int>> a;
        
        for(int i=0; i<k; i++){
            vector<int> temp;
            for(int j=0; j<2; j++){
                int x; cin>>x;
                temp.push_back(x);
            }
            a.push_back(temp);
        }
    
        Solution obj;
        vector<int> res = obj.numOfIslands(n,m,a);
        
        for(auto x : res)cout<<x<<" ";
        cout<<"\n";
    }
}

// } Driver Code Ends