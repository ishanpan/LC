class Solution {
public:
    bool valid( int x,int y,int m,int n){
        if(x<0 || y<0 || x>=m || y>=n ){
            return false;
        }
        return true;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
         int m = mat.size();
        int n  = mat[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                }
            }
        }

       vector<vector<int>>dist(m,vector<int>(n,-1));
        int levels = 0;
        int row[4] = {0,0,-1,1};
        int col[4] = {1,-1,0,0};
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                auto temp = q.front();
                q.pop();
                int x = temp.first;
                int y = temp.second;
                for(int i=0;i<4;i++){
                    int rowX = x + row[i];
                    int colY = y  + col[i];
                    if(valid(rowX,colY,m,n) && mat[rowX][colY]==1 && dist[rowX][colY]==-1){
                        dist[rowX][colY] = levels+1;
                        q.push({rowX,colY});
                    }
                }

            }
            levels++;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dist[i][j]==-1){
                    dist[i][j] = 0;
                }
            }
        }
        return dist;
        
        
    }
    
};