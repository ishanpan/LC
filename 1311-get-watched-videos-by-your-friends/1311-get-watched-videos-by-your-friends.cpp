class Solution {
public:
    

 

    
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        map<string,int>m;
        int n = friends.size();
        vector<int>visited(n,0);
        queue<int>q;
        q.push(id);
        visited[id] = 1;
        while(level>0){
            int size = q.size();
            for(int i=0;i<size;i++){
                int temp = q.front();
                q.pop();
                
                
                for(auto x:friends[temp]){
                    if(!visited[x]){
                        visited[x] = 1;
                        q.push(x);
                    }
                    
                }
                
                
            }
            level--;
        }
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            for(auto x:watchedVideos[temp]){
                m[x]++;
            }
        }
        vector<pair<int,string>>a;
        
       
        for(auto x:m){
            a.push_back({x.second,x.first});
        }
        sort(a.begin(),a.end());
        
        vector<string>ans;
        for(auto x:a){
            ans.push_back(x.second);
        }
        return ans;
        
    }
};