//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    
    
    void dfs(vector<pair<int,int>>adj[],int node, int &weight,int &end,vector<int> &vis){
        vis[node]=1;
        for(auto x:adj[node]){
            if(!vis[x.first]){
                 weight = min(weight,x.second);
                 end = x.first;
                dfs(adj,x.first,weight,end,vis);
            }
        }    
    }
    
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        vector<pair<int,int>>adj[n+1];
        vector<int>indegree(n+1,0);
        vector<int>outdegree(n+1,0);
        for(int i=0;i<p;i++){
            adj[a[i]].push_back({b[i],d[i]});
            indegree[b[i]]++;
            outdegree[a[i]]++;
        }
        vector<int>visited(n+1,false);
         vector<vector<int>>ans;
        for(int i=1;i<=n;i++){
            if(indegree[i]==0 && outdegree[i]>=1){
                if(!visited[i]){
                    int end = -1;
                    int minW = INT_MAX;
                    dfs(adj,i,minW,end,visited);
                    ans.push_back({i,end,minW});

                }
                
            }
            
        }
        sort(ans.begin(),ans.end());
        return ans;
        
        
        
        
    } 
};


//{ Driver Code Starts.
int main()
{
	int t,n,p;
	cin>>t;
	while(t--)
    {
        cin>>n>>p;
        vector<int> a(p),b(p),d(p);
        for(int i=0;i<p;i++){
            cin>>a[i]>>b[i]>>d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n,p,a,b,d);
        cout<<answer.size()<<endl;
        for(auto i:answer)
        {
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends