class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
     
        stack<int>st;
        int i=0;
        int j=0;
        int n=pushed.size();
        while(i<n && j<n){
            st.push(pushed[i]);
            if(st.top()==popped[j]){
                st.pop();
                j++;
                while(!st.empty() && st.top()==popped[j] ){
                    st.pop();
                    j++;
                }
            }
            i++;
        }
        
        while(j<n){
           if(st.top()!=popped[j]){
                return false;
            } 
            st.pop();
            j++;
        }
        
        return true;
        
    }
};