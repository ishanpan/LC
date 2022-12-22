class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       
        int win = p.size();
        unordered_map<char,int>m;
        unordered_map<char,int>mp;
        for(int z=0;z<win;z++){
            mp[p[z]]++;
        }
        int i = 0;
        int j = 0;
        int n = s.size();
        vector<int>ans;
        while(j<n){
            m[s[j]]++;
            if(j-i+1<win){
                j++;
            }
            else if(j-i+1==win){
                int flag = true;
                for(auto h:mp){
                    if(m.find(h.first)==m.end() || m[h.first]<h.second){
                        flag = false;
                    }
                }
                
                if(flag){
                    ans.push_back(i);
                }
                m[s[i]]--;
                i++;
                j++;
            }

        }
        
        return ans;
        
        
        
    }
};