class Solution {
public:
    

//     int numsS(string s, int sizes, int i){
        
//         if(t[i]!=-1){
//             return t[i];
//         }
//         if(i==sizes){
//             return 1;
//         }
//         if(s[i]=='0'){
//             return 0;
//         }
//         t[i] = numsS(s,sizes,i+1);
//         if(i<sizes-1 && (s[i]=='1'|| (s[i]=='2' && s[i+1]<'7'))){
//             t[i] += numsS(s,sizes,i+2);
//         }
        
//         return t[i];
        

//     }
    
    
    int numDecodings(string s) {
        int n = s.size();
        int t[n+1];
        
        for(int i=0;i<n+1;i++){
            t[i] = 0;
        }
        t[0]=1;
        for(int i=1;i<n+1;i++){
            
            
            if(s[i-1]>='1' && s[i-1]<='9'){
                t[i] +=t[i-1];
            }
            if(i==1){
                continue;
            }
            
             if((s[i-2]=='1'|| (s[i-2]=='2' && s[i-1]<'7'))){
                t[i] +=t[i-2];
            }
            
        }
        
        return t[n];
        
        
        
        
      
        
    }
};