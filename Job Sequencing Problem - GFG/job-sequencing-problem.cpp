//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    int findPar(int node,vector<int>&parent){
    if(node == parent[node]){
        return node;
    }

        return parent[node] = findPar(parent[node],parent);
    }

void  unionfn(int node1, int node2, vector<int>&parent){

    
        
    parent[node2] = node1;
    

}

    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
            auto temp = arr[i];
            vec.push_back({temp.profit,temp.dead});
        }
        
        sort(vec.rbegin(),vec.rend());
        int maxD = INT_MIN;
        for(int i=0;i<n;i++){
            maxD = max(maxD, vec[i].second);
        }
        vector<int>parent(maxD+1);
        for(int i=0;i<maxD+1;i++){
            parent[i] = i;
        }

        int profit = 0;
        int k=0;
        for(int i=0;i<n;i++){
            int deadL = vec[i].second;
            int nn = findPar(deadL,parent);
            if(nn>0){
                unionfn(nn-1,nn,parent);
                profit+=vec[i].first;
                k++;
            }
        }
        
        return {k,profit};
        
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends