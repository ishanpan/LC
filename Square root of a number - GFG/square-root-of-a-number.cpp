//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

  

// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        // Your code goes here
        
        long long int left = 1;
        long long int right = x;
        long long int poss = -1;
        while(left<=right){
            long long int mid = left+(right-left)/2;
            long long int pro = mid*mid;
            
            if(pro==x){
                return mid;
            }
            else if(pro>x){
                
                right = mid - 1;
                
            }
            else{
                poss = mid;
                left = mid+1;
            }
        }
        
        return poss;
        
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}

// } Driver Code Ends