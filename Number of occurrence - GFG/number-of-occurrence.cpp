//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
		
		
		    
    int BSs(int v[], int x,int n){
        
        
        
        int left = 0;
        int right = n-1;
        
        int lastOcc = -1;
        while(left<=right){
            
            int mid = left + (right-left)/2; 
            if(v[mid]==x){
                lastOcc  = mid;
                right = mid - 1;
            }
            else if(v[mid]<x){
                left = mid + 1;
            }
            
            else{
                right = mid - 1;
            }
            
        }
        return lastOcc;
        
        
        
    }
    
        int BSl(int v[], int x, int n){
        
        
        
        int left = 0;
        int right = n-1;
        
        int lastOcc = -1;
        while(left<=right){
            
            int mid = left + (right-left)/2; 
            if(v[mid]==x){
                lastOcc  = mid;
                left = mid + 1;
            }
            else if(v[mid]<x){
                left = mid + 1;
            }
            
            else{
                right = mid - 1;
            }
            
        }
        return lastOcc;
        
        
    }
	int count(int arr[], int n, int x) {
	    // code here
	    
	    int first = BSs(arr,x,n);
	    int last = BSl(arr,x,n);
	    if(first==-1){
	        return 0;
	    }
	    return last-first+1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends