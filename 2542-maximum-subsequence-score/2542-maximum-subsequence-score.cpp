class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<pair<int,int>>vec;
        int n = nums1.size();
        for(int i=0;i<n;i++){
            vec.push_back({nums2[i],nums1[i]});
        }
        sort(vec.rbegin(),vec.rend());
       
        long long ans = 0;
        long long totalSum = 0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            totalSum +=vec[i].second;
            pq.push(vec[i].second);
            
            if(pq.size()>k){
                totalSum -= pq.top();
                pq.pop();
            }
            if(pq.size()==k){
                ans = max(ans,totalSum*vec[i].first);
            }
            
        }
        return ans;

    }
};