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
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,int>m;
        int n = accounts.size();
        vector<int>rank(n,0);
        vector<int>parents(n);
        for(int i=0;i<n;i++){
            parents[i] = i;
        }
        for(int i=0;i<accounts.size();i++){
            for(int j=1;j<accounts[i].size();j++){
                if(m.find(accounts[i][j])!=m.end()){
                    unionn(parents,rank,m[accounts[i][j]],i);
                }
                else{
                    m[accounts[i][j]] = i;
                }
            }
        }
        
        vector<string>mergedMails[n];
        for(auto mails:m){
            string s = mails.first;
            int indexs = mails.second;
            int parent = getParent(parents,indexs);
            if(parent!=indexs){
                mergedMails[parent].push_back(s);
            }
            else{
                mergedMails[indexs].push_back(s);
            }
        }
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            if(mergedMails[i].size()==0){
                continue;
            }
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            sort(mergedMails[i].begin(),mergedMails[i].end());
            for(auto x:mergedMails[i]){
                temp.push_back(x);          
            }
            ans.push_back(temp);
        }
        return ans;
        
        
        
        
        
    }
};