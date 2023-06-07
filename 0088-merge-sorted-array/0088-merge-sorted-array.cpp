class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0){
            return;
        }
        if(m==0){
            nums1 = nums2;
            return;
        }
        
        int i = m-1;
        int j = n-1;
        int k = m+n-1;
        
        
        while(k>=0 && i>=0 && j>=0){
            if(nums2[j]>nums1[i]){
                nums1[k] = nums2[j];
                j--;
                k--;
            }
            else{
                nums1[k] = nums1[i];
                i--;
                k--;
            }
        }
        
        if(k>=0){
            if(j>=0){
                while(j>=0){
                    nums1[k]=nums2[j];
                    j--;
                    k--;
                    
                }
            }
        }
        
    }
};