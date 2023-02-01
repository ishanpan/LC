/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    
    
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0){
            return NULL;
        }
        
        
        int mid = nums.size()/2;
        TreeNode* temp = new TreeNode;
        temp->val = nums[mid];
        vector<int>left;
        vector<int>right;
        for(int i=0;i<mid;i++){
            left.push_back(nums[i]);
        }
        for(int i=mid+1;i<nums.size();i++){
            right.push_back(nums[i]);
        }
        
        temp->left = sortedArrayToBST(left);
        temp->right = sortedArrayToBST(right);
        
        return temp;
        
        
        
    }
};