class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>a(26,0);
        for(int i=0;i<s1.size();i++){
            a[s1[i]-'a']++;
        }
        
        int i=0;int j=0;
        int sizes2 = s2.size();
        int sizes1 = s1.size();
        vector<int>b(26,0);
        while(j<sizes2){
            b[s2[j]-'a']++;
            
            if(j-i+1<sizes1){
                j++;
            }
            else{
                if(a==b){
                    return true;
                }
                else{
                    b[s2[i]-'a']--;
                    i++;
                    j++;
                }
            }
            
            
        }
        
           
        return false;
        
        
    }
};