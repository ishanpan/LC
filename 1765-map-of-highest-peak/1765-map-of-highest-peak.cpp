class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        
        queue<pair<int,pair<int,int>>>q;
        
        
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>>heights(m,vector<int>(n,INT_MIN));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(isWater[i][j]==1){
                    heights[i][j] = 0;
                    q.push({0,{i,j}});
                }
            }
        }
        
        int col [4] = {0,0,1,-1};
        int row[4] = {1,-1,0,0};
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int height = temp.first;
            int x = temp.second.first;
            int y = temp.second.second;
            
            for(int i=0;i<4;i++){
                int rowX = row[i]+x;
                int colY = col[i]+y;
                if(rowX>=0 && colY>=0 && rowX<m && colY<n && isWater[rowX][colY]==0 && heights[rowX][colY]==INT_MIN){
                    heights[rowX][colY] = height+1;
                    q.push({height+1,{rowX,colY}});
                }
                    
            }

        }
        return heights;
        
        
    }
};