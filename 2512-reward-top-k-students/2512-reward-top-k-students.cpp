class Solution {
public:
    
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_map<string,int>posi;
        unordered_map<string,int>negi;
        for(auto s:positive_feedback){
            posi[s] = 1;
        }
        for(auto s:negative_feedback){
            negi[s] = 1;
        }
        map<int,int>score;
        for(int i=0;i<student_id.size();i++){
            score[student_id[i]] = 0;
        }
        
        for(int i=0;i<report.size();i++){
            int reps = report[i].size();
            string word = "";
            for(int j=0;j<reps;j++){
                if(report[i][j]==' '){
                    if(posi.find(word)!=posi.end()){
                        score[student_id[i]] += 3;
                    }
                    if(negi.find(word)!=negi.end()){
                        score[student_id[i]] -= 1;
                    }
                    word="";
                    continue;
                }
                word.push_back(report[i][j]);
                if(j==reps-1){
                    if(posi.find(word)!=posi.end()){
                        score[student_id[i]] += 3;
                    }
                    if(negi.find(word)!=negi.end()){
                        score[student_id[i]] -= 1;
                    }
                }
                
            }
        }
        vector<int>ans;
        vector<pair<int,int>>pq;
        for(auto mm:score){
            pq.push_back({mm.second,mm.first});
            
            cout<<mm.first<<"\t"<<mm.second<<'\n';
        }
        sort(pq.begin(),pq.end(),[](pair<int,int> a,pair<int,int> b){
            if(a.first < b.first) return true;
            else if(a.first == b.first) return a.second>b.second;
            return false;
        });
        reverse(pq.begin(),pq.end());
        for(int i=0;i<k;i++){
            ans.push_back(pq[i].second);
        }
        return ans;
        
        
    }
};