//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        // code here
        int count = 0;
       int pos = 0;
       while(N){
           if(N & 1){
               count++;
           }
           N = N>>1;
           pos++;
       }
        if(count==1){
            return pos;
        }
        else{
            return -1;
        }
        

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