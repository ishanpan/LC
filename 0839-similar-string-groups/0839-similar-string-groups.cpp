class Solution {
public:
    
    
    int findPar(int node,vector<int>&parent){
    if(node == parent[node]){
        return node;
    }

    return parent[node] = findPar(parent[node],parent);
}

void  unionfn(int node1, int node2, vector<int>&rank,vector<int>&parent ){

     node1 = findPar(node1,parent);
     node2 = findPar(node2,parent);

    if(rank[node1]<rank[node2]){
        parent[node1] = node2;
    }
    else if(rank[node2]<rank[node1]){
        parent[node2] = node1;
    }
    else{
        parent[node2] = node1; 
        rank[node1]++;
    }

}
    
    int numSimilarGroups(vector<string>& strs) {
        
        unordered_map<string,int>m;
        int n = strs.size();
        vector<int>parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        for(int i=0;i<n;i++){
            
            if(m.find(strs[i])!=m.end()){
                unionfn(i,m[strs[i]],rank,parent);
            }
            else{
                 m[strs[i]] = i;
            }
           
        }
       

        for(int i=0;i<n;i++){
            string w = strs[i];
            int wsize = w.size();
            for(int j=0;j<wsize;j++){
                for(int k=j+1;k<wsize;k++){
                    swap(w[j],w[k]);
                    if(m.find(w)!=m.end()){
                       unionfn(i,m[w],rank,parent);
                    }
                    swap(w[j],w[k]);
                }
            }
            
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(i==parent[i]){
                ans++;
            }
        }
        return ans;

    }
};