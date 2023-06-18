//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    int dp[100001][3];
    int maxPts(vector<vector<int>>& points, int n, int notAllowed){
        
        
        if(n==0){
            return 0;
        }
        
        if(dp[n][notAllowed]!=-1){
            return dp[n][notAllowed];
        }
        
        int pts = INT_MIN;
        
        if(notAllowed!=0){
            pts = max(pts,points[n-1][0]+maxPts(points,n-1,0));
        }
         if(notAllowed!=1){
            pts = max(pts,points[n-1][1]+maxPts(points,n-1,1));
        }
         if(notAllowed!=2){
            pts = max(pts,points[n-1][2]+maxPts(points,n-1,2));
        }
        
        return dp[n][notAllowed] = pts;
        
    }
  
    int maximumPoints(vector<vector<int>>& points, int n) {
        // Code here
        memset(dp,-1,sizeof(dp));
        int maxAns = INT_MIN;
        for(int i=0;i<3;i++){
            maxAns =  max(maxAns,points[n-1][i]+maxPts(points,n-1,i));
        }
        return maxAns;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends