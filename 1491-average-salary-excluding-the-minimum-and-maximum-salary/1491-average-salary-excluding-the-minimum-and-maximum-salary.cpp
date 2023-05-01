class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        long long salT  = 0;
        
        for(auto x:salary){
            salT+=x;
        }
        salT-=salary[0];
        salT-=salary[salary.size()-1];
        double ans = (double) salT/(double)(salary.size()-2);
        return ans;
        
    }
};