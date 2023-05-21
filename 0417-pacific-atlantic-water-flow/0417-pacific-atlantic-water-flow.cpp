class Solution {
public:
    bool valid(vector<vector<int>>& heights, int x,int y,int m,int n, int myH){
        if(x<0 || y<0 || x>=m || y>=n || heights[x][y]<myH){
            return false;
        }
        return true;
    }


        void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int x,int y,int m,int n){
        visited[x][y] = true;
        int row[4] = {1,-1,0,0};
        int col[4] = {0,0,1,-1};

        for(int i=0;i<4;i++){
            int rowI = row[i] + x;
            int colI = col[i] + y;
            if(valid(heights,rowI,colI,m,n,heights[x][y]) && !visited[rowI][colI]){
                dfs(heights,visited,rowI,colI,m,n);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
      
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>>pacific(m,vector<bool>(n,false));
        vector<vector<bool>>atlantic(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            dfs(heights,pacific,i,0,m,n);
            dfs(heights,atlantic,i,n-1,m,n);
        }
        for(int i=0;i<n;i++){
            
            dfs(heights,pacific,0,i,m,n);
            dfs(heights,atlantic,m-1,i,m,n);
        }
        
        vector<vector<int>>ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(atlantic[i][j] && pacific[i][j]){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
        

        
    }
};