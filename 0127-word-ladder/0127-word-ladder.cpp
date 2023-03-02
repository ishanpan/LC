class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>wordset(wordList.begin(),wordList.end());
        queue<pair<string,int>>q;
        q.push({beginWord,0});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            string word = temp.first;
            int step = temp.second;
            if(word==endWord){
                return step+1;
            }
            for(int i=0;i<word.size();i++){
                char org = word[i];
                for(char j='a';j<='z';j++){
                    word[i] = j;
                    if(wordset.find(word)!=wordset.end()){
                        q.push({word,step+1});
                        wordset.erase(word);
                    }
                }
                word[i] = org;   
            }   
        }
        return 0;
        
        
        
    }
};