//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    
	    // just find minimum element using bs;
	    
	    
	     
	    int left = 0;
	    int right = n-1;
	    
	    while(left<=right){
	        if(arr[left]<=arr[right]){
	            return left;
	        }
	        
	        int mid = left + (right-left)/2;
	        int prev = (mid+n-1)%n;
	        int next = (mid+1)%n;
	        if(arr[prev]>=arr[mid] && arr[next]>=arr[mid]){
	 
	            return mid;
	
	        }
	        else if(arr[left]<=arr[mid]){
	            left = mid+1;
	        }
	        else if(arr[mid]<=arr[right]){
	            right = mid-1 ;
	            
	        }
	        
	    }
	    return 0;
	    
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends