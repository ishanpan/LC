//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    if(n==1){
	        return arr[0];
	    }
	    int maxSum = 0;
	    for(int i=0;i<n;i++){
	        maxSum+=arr[i];
	    }
	    bool t[n+1][maxSum+1];
	    for(int i=0;i<n+1;i++){
	        t[i][0] = true;
	    }
	    for(int i=1;i<maxSum+1;i++){
	        t[0][i] = false;
	    }
	    for(int i=1;i<n+1;i++){
	        for(int j=1;j<maxSum+1;j++){
	            if(arr[i-1]<=j){
	                t[i][j] = t[i-1][j]||t[i-1][j-arr[i-1]];
	            }
	            else{
	                t[i][j] = t[i-1][j];
	            }
	        }
	    }
	    vector<int>possible;
	    for(int i=1;i<maxSum/2+1;i++){
	        if(t[n][i]==true){
	            possible.push_back(i);
	        }
	    }
	    
	    int minAns = INT_MAX;
	    for(auto x:possible){
	        minAns = min(minAns, maxSum - 2*x);
	    }
	    return minAns;
	    
	    
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

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends