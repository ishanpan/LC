class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q;
        for(auto x:stones){
            q.push(x);
        }
        while(q.size()>1){
            int s1 = q.top();
            q.pop();
            int s2 = q.top();
            q.pop();
            if(s1!=s2){
                int wt = s1-s2;
                q.push(wt);
            }
            
        }
        int ans = 0;
        if(q.size()!=0){
             ans = q.top();
        }
        
        return ans;
    }
};