//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    
    
    bool fn(vector<int> &stalls, int n, int k, int dist){
            int co = k;
            co--;
            int lastPos = stalls[0];
            for(int i=1;i<n;i++){
                    
                if(abs(stalls[i]-lastPos)>=dist){
                    co--;
                    lastPos = stalls[i];
                }

            }
            
            if(co<=0){
                return true;
            }
        
        return false;
        
        
    }
    
    int solve(int n, int k, vector<int> &stalls) {
    
        // Write your code here
        
        int left = 0;
        sort(stalls.begin(),stalls.end());
        int right =  stalls[n-1]-stalls[0];
        int maxAns = INT_MIN;
        while(left<=right){
            
            int mid = left+(right-left)/2;
            if(fn(stalls,n,k,mid)){
                maxAns = max(maxAns,mid);
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        
            
        }
        return maxAns;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends