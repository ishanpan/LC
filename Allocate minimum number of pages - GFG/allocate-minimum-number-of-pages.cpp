//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    
    bool fn(int A[], int N, int M, int totalS){
        
        
        int count = 1;
        int sum = 0;
            
        for(int i=0;i<N;i++){
            
            sum+=A[i];
            
            if(sum>totalS){
                count++;
                sum=A[i];
            }
            if(count>M){
                return false;
            }
            
        }
        
        return true;
        
        
    }
    
    
    
    int findPages(int A[], int N, int M) 
    {
        
        if(M>N){
            return -1;
        }
        // sort(A,A+N);
        
        vector<int>pre(N);
        int largestE = INT_MIN;
        int sum = 0;
        for(int i=0;i<N;i++){
                largestE=max(largestE,A[i]);
                sum+=A[i];
        }
        
        int left = largestE;
        int right = sum;
        
        int minPages = INT_MAX;
        while(left<=right){
            int mid = left+(right-left)/2;
            
            if(fn(A,N,M,mid)){
                minPages = min(minPages,mid);
                
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
            
  
            
        }
        
        return minPages;
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends