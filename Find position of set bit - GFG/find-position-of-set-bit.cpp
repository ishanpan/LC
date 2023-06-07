//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        // code here
        
        int pos = 1;
        int ans = -1;
        bool Nfound = true;
        while(N!=0){
            
            if((N&1)==1 && Nfound){
                ans = pos;
                Nfound = false;
            }
            else if((N&1)==1 && !Nfound){
                return -1;
            }
            pos++;
            N>>=1;
            
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends