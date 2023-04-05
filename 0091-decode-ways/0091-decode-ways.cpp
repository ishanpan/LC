class Solution {
public:
    
    int t[101];
    int numsS(string s, int sizes, int i){
        
        if(t[i]!=-1){
            return t[i];
        }
        if(i==sizes){
            return 1;
        }
        if(s[i]=='0'){
            return 0;
        }
        t[i] = numsS(s,sizes,i+1);
        if(i<sizes-1 && (s[i]=='1'|| (s[i]=='2' && s[i+1]<'7'))){
            t[i] += numsS(s,sizes,i+2);
        }
        
        return t[i];
        

    }
    
    
    int numDecodings(string s) {
        
        
        
        if(s.size()==0){
            return 0;
        }
        memset(t,-1,sizeof(t));
        return numsS(s,s.size(),0);
        
    }
};