//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    
    int n=0;
    int m=0;
    
    
    bool validIsland(vector<vector<int>>& grid, int i,int j){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==0){
            return true;
        }
        return false; 
    }
    
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    n = grid.size();
	    m = grid[0].size(); 
	    vector<vector<int>>visited(n,vector<int>(m,0));
	    vector<vector<int>>ans(n,vector<int>(m,0));
	
	     queue<pair<pair<int,int>,int>>q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                visited[i][j] = 1;
	                q.push({{i,j},0});
	            }
	            else{
	                ans[i][j] = 0;
	            }
	        }
	    }
	    
	    int row[4] = {-1,0,1,0};
        int col[4] = {0,1,0,-1};
       
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int x = temp.first.first;
            int y = temp.first.second;
            int dis = temp.second;
            ans[x][y] = dis;
            for(int i=0;i<4;i++){
                int roww = x+row[i];
                int coll = y+col[i];
                if(validIsland(grid,roww,coll) && visited[roww][coll]!=1){
                    visited[roww][coll] = 1;
                    q.push({{roww,coll},dis+1});
                }
                
            }
            
            

        }
	    return ans;
	    
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends