//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  typedef pair<int,pair<int,int>>p;
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
            int m = heights.size();
            int n = heights[0].size();
            vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
            dist[0][0]=0;
            priority_queue<p,vector<p>,greater<p>>pq;
            pq.push({0,{0,0}});
            int movex[] = {-1,0,1,0};
            int movey[] = {0,-1,0,1};
            
            while(!pq.empty()){
                auto temp = pq.top();
                pq.pop();
                int distv = temp.first;
                int x = temp.second.first;
                int y=temp.second.second;
                
                if(x==m-1 && y == n-1){
                    return distv;
                }
                for(int i=0;i<4;i++){
                    int amovex = x+movex[i];
                    int amovey = y+movey[i];
                    if(amovex>=0 && amovex<m && amovey>=0 && amovey<n ){
                        
                        int newEffort = max((abs(heights[amovex][amovey]-heights[x][y])),distv);
                        if(newEffort<dist[amovex][amovey]){
                            pq.push({newEffort,{amovex,amovey}});
                            dist[amovex][amovey] = newEffort;
                        }
                        
                    }
                }

            }
            return 0;
            
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends