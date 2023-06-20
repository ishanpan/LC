//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	public:
	
	
// 	void rotateByOne(int arr[], int n){
// 	    int last = arr[0];
// 	    for(int i=0;i<n-1;i++){
// 	       arr[i]=arr[i+1];
// 	    }

// 	    arr[n-1]=last;
	    
// 	}
	void leftRotate(int arr[], int k, int n) 
	{ 
	   // Your code goes here
	   
	   k=k%n;
	   reverse(arr,arr+n);
	   reverse(arr,arr+n-k);
	   reverse(arr+n-k,arr+n);
	   
	} 
		 

};

//{ Driver Code Starts.

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin >> n;
	    int k;
	    cin >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	        // um[a[i]]++;
	    }


       

        Solution ob;
        ob.leftRotate(a,k,n);
        
        for (int i = 0; i < n; i++) 
        	cout << a[i] << " "; 

	    cout << "\n";
	     
    }
    return 0;
}



// } Driver Code Ends