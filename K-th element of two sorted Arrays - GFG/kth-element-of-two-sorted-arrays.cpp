//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i=0;
        int j=0;
        int flag = 0;
        vector<int>arr;
        while(i<n && j<m && flag<k ){
            if(arr1[i]<=arr2[j]){
                arr.push_back(arr1[i]);
                i++;
            }
            else if(arr1[i]>arr2[j]){
                arr.push_back(arr2[j]);
                j++;
            }
            flag++;

        }
        if(flag==k){
            return arr[flag-1];
        }
        else{
            if(i==n){
                while(j<m && flag<k){
                    j++;
                    flag++;
                }
                return arr2[j-1];
                
            }
            else{
             while(i<n && flag<k){
                    i++;
                    flag++;
                }
                return arr1[i-1];
                
            }
            
        }
        
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends