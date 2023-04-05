class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        priority_queue<int>q;
        int t[n];
        for(int i=n-1;i>=0;i--){
            if(q.size()==0){
                t[i] = -1;
            }
            else{
                t[i] = q.top();
            }
            q.push(prices[i]);
        }
        
        int maxans = 0;
        for(int i=0;i<n;i++){
            if(t[i]-prices[i]>maxans){
                maxans = t[i]-prices[i];
            }
        }
        return maxans;
    }
};