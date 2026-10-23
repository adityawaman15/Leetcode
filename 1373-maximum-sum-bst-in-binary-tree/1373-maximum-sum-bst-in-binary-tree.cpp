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
    class info{
        public:
            int size;
            bool isBST;
            int mini;
            int maxi;
            
    }
    ;
    info solve(TreeNode* root, int &max_size){
        if(root == NULL){
            return {0,true,INT_MAX,INT_MIN};
        }
        
        info left = solve(root->left,max_size);
        info right = solve(root->right,max_size);
        
        info curr;
        
        curr.size = left.size + right.size + root->val;
        curr.maxi = max(root->val,right.maxi);
        curr.mini = min(root->val,left.mini);
        
        if(root->val > left.maxi && root->val <  right.mini && (left.isBST && right.isBST)){
            curr.isBST = true;
            max_size = max(max_size,curr.size);
        }
        else{
            curr.isBST = false;
            curr.size = 0;
        }
        
        
        
        return curr;
        
    }
    int maxSumBST(TreeNode* root) {

        int max_size = 0;
        
        info ans = solve(root, max_size);
        return max_size;
        
    }
};