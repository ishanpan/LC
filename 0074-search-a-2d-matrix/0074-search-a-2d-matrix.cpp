class Solution {
public:
    

    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        
        int m = matrix[0].size();
        int n = matrix.size();
       int l = 0;
        int r = (m*n)-1;
        
        while(l<=r){
            
            
            int mid = l+(r-l)/2;
            
            if(target==matrix[mid/m][mid%m]){
                return true;
            }
            else if(target>matrix[mid/m][mid%m]){
                l = mid + 1;
                
            }
            else {
                r = mid - 1;
            }
            
            
        }

        return false;

    }
};