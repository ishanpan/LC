//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int t[101][101];
    int MCM(int i,int j, int arr[]){
        if(i>=j){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }
        int mn = INT_MAX;
        for(int k=i;k<=j-1;k++){
            int tempans = MCM(i,k,arr) + MCM(k+1,j,arr) + (arr[i-1] * arr[k] * arr[j]);
            mn = min(tempans,mn);
        }
        t[i][j] = mn;
        return mn;

    }

    int matrixMultiplication(int N, int arr[])
    {
        // code here
        memset(t,-1,sizeof(t));
        return MCM(1,N-1,arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends