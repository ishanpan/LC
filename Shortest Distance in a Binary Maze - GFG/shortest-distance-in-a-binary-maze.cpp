//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  typedef pair<int,pair<int,int>> p;
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
            int m = grid.size();
            int n = grid[0].size();
            
            vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
            dist[source.first][source.second]=0;
            //<int, vector<int>, greater<int> >
            queue<p>pq;
            pq.push({0,{source.first,source.second}});
            int movex[] = {-1,0,1,0};
            int movey[] = {0,-1,0,1};
            
            while(!pq.empty()){
                auto temp = pq.front();
                pq.pop();
                int distv = temp.first;
                int x = temp.second.first;
                int y=temp.second.second;
                
                for(int i=0;i<4;i++){
                    int amovex = x+movex[i];
                    int amovey = y+movey[i];
                    if(amovex>=0 && amovex<m && amovey>=0 && amovey<n &&  grid[amovex][amovey]==1 && distv+1<dist[amovex][amovey]){
                        pq.push({distv+1,{amovex,amovey}});
                        dist[amovex][amovey] = distv+1;
                    }
                }

            }
            if(dist[destination.first][destination.second]==INT_MAX){
                return -1;
            }
            return dist[destination.first][destination.second];
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends