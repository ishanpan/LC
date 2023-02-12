//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int  n=0;
    int m=0;
    bool validIsland(vector<vector<char>>& grid, int i,int j){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]=='1'){
            return true;
        }
        return false; 
    }
    void visit(vector<vector<char>>& grid, int i,int j,int n,int m){
        grid[i][j] = '0';
        
        if(validIsland(grid,i+1,j)){
            visit(grid,i+1,j,n,m);
        }
        if(validIsland(grid,i-1,j)){
            visit(grid,i-1,j,n,m);
        }
        if(validIsland(grid,i+1,j+1)){
            visit(grid,i+1,j+1,n,m);
        }
        if(validIsland(grid,i-1,j-1)){
            visit(grid,i-1,j-1,n,m);
        }
        if(validIsland(grid,i,j+1)){
            visit(grid,i,j+1,n,m);
        }
        if(validIsland(grid,i,j-1)){
            visit(grid,i,j-1,n,m);
        }
        if(validIsland(grid,i+1,j-1)){
            visit(grid,i+1,j-1,n,m);
        }
        if(validIsland(grid,i-1,j+1)){
            visit(grid,i-1,j+1,n,m);
        }
        
        
    }
    
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        n = grid.size();
        m = grid[0].size();
        
        int visited[500][500] = {0};
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    visit(grid,i,j,n,m);
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends