class Solution {
public:
    int n = 0;
    int m = 0;
    int maxT = 0;
    bool validIsland(vector<vector<int>>& grid, int i,int j){
        if(i>=0 && i<n && j>=0 && j<m && grid[i][j]==1){
            return true;
        }
        return false; 
    }
    
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        n = grid.size();
        m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        
        int maxa = 0;
        int row[4] = {-1,0,1,0};
        int col[4] = {0,1,0,-1};
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int x = temp.first.first;
            int y = temp.first.second;
            int t = temp.second;
            maxa = max(maxa,t);
            for(int i=0;i<4;i++){
                    if(validIsland(grid,x+row[i],y+col[i])){
                        q.push({{x+row[i],y+col[i]},t+1});
                        grid[x+row[i]][y+col[i]] = 2;
                    }
            }

        }
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        
        return maxa;
        
    }
};