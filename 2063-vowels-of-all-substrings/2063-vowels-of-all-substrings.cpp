class Solution {
public:
    
    bool isVowel(char a){
        if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u'){
            return true;
        }
        return false;
    }
    long long countVowels(string word) {
        int n = word.size();
        long long vowel[n];
        vowel[0] = 0;
        if(isVowel(word[0])){
             vowel[0] = 1;
        }
         long long ans = vowel[0];
        for(int i=1;i<n;i++){
            if(isVowel(word[i])){
               vowel[i] = vowel[i-1]+1+i; 
            }
            else{
                vowel[i] = vowel[i-1];
            }
            ans+=vowel[i];
            
        }
       
        return ans;
        
        
    }
};