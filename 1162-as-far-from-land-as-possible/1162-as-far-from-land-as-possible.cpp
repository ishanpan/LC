class Solution {
public:
    
    bool valid(int n,int x,int y){
        if(x<0 || y<0 || x>=n || y>=n){
            return false;
        }
        
        return true;
        
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int n = grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        if(q.size()==0 || q.size()==n*n){
            return -1;
        }
        int levels = 0;
        int row [4] = {0,0,1,-1};
        int col [4] = {1,-1,0,0};
        vector<vector<bool>>visited(n,vector<bool>(n, false));
        while(!q.empty()){
            int s = q.size();
            while(s--){
            auto temp = q.front();
            q.pop();
            int x = temp.first;
            int y = temp.second;
            
            for(int i=0;i<4;i++){
                int rowx = x+row[i];
                int coly = y+col[i];
                if(valid(n,rowx,coly) && !visited[rowx][coly] && grid[rowx][coly]==0){
                    visited[rowx][coly]=true;
                    q.push({rowx,coly});
                }
            }
        }
            levels++;        
        }
     
        return levels-1;
        
    }
};