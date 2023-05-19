class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<int>dist(n,10e5);
        dist[src] = 0;
        
        for(int i=0;i<k+1;i++){
            vector<int>temp = dist;
                for(auto itr:flights){
                    if(dist[itr[0]]+itr[2]<temp[itr[1]]){
                        temp[itr[1]]=dist[itr[0]]+itr[2];
                    }
                }
            
            dist = temp;
            
        }
        
        if(dist[dst]!=10e5){
            return dist[dst];
        }
        return -1;
        
        
        
        
    }
};