class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int>m;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minH;
            
        for(auto i:m){
                minH.push({i.second,i.first});
            if(minH.size()>k){
                minH.pop();
            }

            }
        
        while(!minH.empty()){
            ans.push_back(minH.top().second);
            minH.pop();
        }
        return ans;
        
    }
};