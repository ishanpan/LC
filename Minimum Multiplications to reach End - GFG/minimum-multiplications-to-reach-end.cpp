//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  typedef pair<int,int>p;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        vector<int>vec(100000,INT_MAX);
        queue<p>q;
        vec[start] = 0;
        q.push({0,start});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            int steps = temp.first;
            int vertex = temp.second;
            
            for(auto x:arr){
                int product = ((x*vertex)%100000);
                if(steps+1<vec[product]){
                    if(product==end){
                        return steps+1;
                    }
                    q.push({steps+1, product});
                    vec[product] = steps+1;
                }
            }
        }
        return -1;
        
        
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends