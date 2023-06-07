//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    // code here
	    
	    int left  = 0;
	    int right = n-1;
	    
	    
	    while(left<=right){
	        
	           int mid = left + (right-left)/2;
	           
	           
	           if(mid>0 && arr[mid]>arr[mid-1] && mid<n && arr[mid]>arr[mid+1]){
	               return arr[mid];
	           }
	           else if(mid>0 && arr[mid-1]>arr[mid]){
	               right = mid - 1;
	           }
	           else{
	               
	               left = mid + 1;
	               
	           }
	        
	    }
	    return arr[n-1];
	    
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends