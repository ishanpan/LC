class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        
        unordered_map<int,int>m;
        
        for(auto x:tasks){
            m[x]++;
        }
        int ans = 0;
        for(auto x:m){
            
            
            if(x.second==1)return -1;
            
                if(x.second%3==0){
                    ans+=x.second/3;
                }
                else {
                    ans+=(x.second/3) + 1;
                    
                }
                
                
            
           
            
            
        }
        
        return ans;
        
    }
};