//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	int dp[100001][2];
	const int MOD= 1e9+7;
	ll fn(int i, int n, bool flag){
	    if(i>n){
	        return 1;
	    }
	    
	    if(dp[i][flag]!=-1){
	        return dp[i][flag];
	    }
	    
	    if(flag==false){
	     ll c1 = fn(i+1,n,false);
	     ll c2 = fn(i+1,n,true);
	        return dp[i][flag] = (c1%MOD+c2%MOD)%MOD;
	    }
	    
	    else{
	        return dp[i][flag] = fn(i+1,n,false)%MOD;
	    }

	    
	}
	
	ll countStrings(int n) {
	    // code here
	    
	    memset(dp,-1,sizeof(dp));
	    return fn(1,n,false);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends