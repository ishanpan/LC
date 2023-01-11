class Solution {
public:
    string simplifyPath(string path) {
        
        stack<string>ss;
        string ans = "";
        for(int i=0;i<path.size();i++){
            
            if(path[i]=='/'){
                continue;
            }
            string temp;
            while(i<path.size() && path[i]!='/'){
                temp.push_back(path[i++]);
            }
            if(temp=="."){
                continue;
            }
            else if(temp==".."){
                if(!ss.empty()){
                    ss.pop();
                }
                
            }
            else{
                ss.push(temp);
            }

        }
        
        while(!ss.empty() && ss.size()>0){
            ans =  "/" + ss.top()  + ans;
            ss.pop();
        }
        
        if(ans.size()==0){
            return "/";
        }
        
        return ans;
    }
};