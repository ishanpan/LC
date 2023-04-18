class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans = "";
        
        int n1 = word1.size();
        int n2 = word2.size();
        int i=0,j=0;
        bool w1 = true;
        while(i<n1 && j<n2){
            if(w1){
                ans.push_back(word1[i++]);
            }
            else{
                ans.push_back(word2[j++]);
            }
            w1 = !w1;
        }
        while(i<n1){
             ans.push_back(word1[i++]);
        }
        while(j<n2){
             ans.push_back(word2[j++]);
        }
        return ans;
    }
};