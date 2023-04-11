class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        string ans = "";
        for(int i=0;i<s.size();i++){
            if(s[i]=='*' && st.size()>0){
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
            while(st.size()>0){
                ans.push_back(st.top());
                st.pop();
            }
            
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};