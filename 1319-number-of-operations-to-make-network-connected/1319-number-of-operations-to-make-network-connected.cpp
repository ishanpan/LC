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
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size()<n-1){
            return -1;
        }
        vector<int>parents(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++){
            parents[i] = i;
        }
        for(auto x:connections){
            unionn(parents,rank,x[0],x[1]);
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(getParent(parents,i)==i){
                cnt++;
            }
        }
        return cnt-1;
        
        
        
    }
};