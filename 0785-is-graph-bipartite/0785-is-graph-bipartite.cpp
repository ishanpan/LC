class Solution {
public:
    
    bool solve(vector<vector<int>>& graph, vector<int>&colourM, int node,int colour){
        
        colourM[node] = colour;
        
        
        for(auto itr:graph[node]){
            
            if(colourM[itr]==-1 ){
                if(!solve(graph,colourM,itr,!colour)){
                    return false;
                }
            }
            else if(colour==colourM[itr]){
                return false;
            }
            
        }
        
        return true;

        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>colourM(n,-1);
        for(int i=0;i<n;i++){
            if(colourM[i]==-1){
                if(!solve(graph,colourM,i,1)){
                    return false;
                }
            }
        }
        return true;
            
        
       
        
        
    }
};