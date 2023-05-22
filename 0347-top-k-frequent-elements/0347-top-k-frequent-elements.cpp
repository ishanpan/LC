class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //using bucket sort 
        unordered_map<int,int>m;
        for(auto itr:nums){
            m[itr]++;
        }
        int n = nums.size();
        vector<vector<int>>bucket(n+1,vector<int>());
        
        for(auto x:m){
            bucket[x.second].push_back(x.first);
        }
        int bucketIdx = n;
        vector<int>ans;
        while(k>0 && bucketIdx>0){
            if(bucket[bucketIdx].size()==0){
                bucketIdx--;   
            }
            else{
               for(auto x:bucket[bucketIdx]){
                   ans.push_back(x);
                   k--;
                   if(k==0){
                       break;
                   }
                    
               }
                bucketIdx--;
            }
        }
        return ans;
        
        
    }
};