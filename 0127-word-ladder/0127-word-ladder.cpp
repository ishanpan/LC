class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //hit
        queue<pair<string,int>>q;
        q.push({beginWord,0});
        unordered_map<string,int>m;
        for(auto x:wordList){
            m[x]++;
        }
        int count = 0;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            string word = temp.first;
            int change = temp.second;
            if(word==endWord){
                return change+1;
            }
            for(int i=0;i<word.size();i++){
                char templetter = word[i];
                
                for(int j=0;j<26;j++){
                    word[i] = 'a'+j;
                    if(m.find(word)!=m.end()){
                        q.push({word,change+1});
                        m.erase(word);
                    }
                }
                word[i] = templetter;
            }
        }
        return 0;
        
        
        
    }
};