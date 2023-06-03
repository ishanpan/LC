class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
      //build graph then bfs??
      vector<int>adj[n];
        for(int i=0;i<manager.size();i++){
            if(i==headID){
                continue;
            }
            adj[manager[i]].push_back(i);
        }

        queue<pair<int,int>>q;
        q.push({headID,0});
        int maxTime = 0;
        while(!q.empty()){

            auto current = q.front();
            q.pop();
            
            int currMan = current.first;
            int  time = current.second;
            maxTime = max(time,maxTime);
            int timeTaken = time+informTime[currMan];
            for(auto x:adj[currMan]){
                q.push({x,timeTaken});
            }

        }

        return maxTime;
    }
};