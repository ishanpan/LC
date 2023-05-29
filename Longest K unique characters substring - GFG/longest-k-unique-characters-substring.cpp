//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    
        unordered_map<char,int>m;
        int i = 0;
        int j = 0;
        int n = s.size();
        int maxWindow = -1;
        
        while(j<n){
            
            m[s[j]]++;
            
            if(m.size()<k){
                j++;
            }
            else if(m.size()==k){
                maxWindow = max(maxWindow, j-i+1);
                j++;
            }
            else{
                   m[s[i]]--;
                   if(m[s[i]]==0){
                       m.erase(s[i]);
                   }
                   i++;
                   j++;
            }
            
        }
        return maxWindow;
    
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends