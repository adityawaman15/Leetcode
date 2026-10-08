/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    TreeNode* solve(TreeNode* root, TreeNode* a, TreeNode* b){
        if(root == NULL){
            return NULL;
        }

        TreeNode* left = solve(root->left,a,b);
        TreeNode* right = solve(root->right,a,b);
        if(root == a || root == b){
            return root;
        }
        else if(!left && !right){
            return NULL;
        }
        else if(left && !right){
            return left;
        }
        else if(!left && right){
            return right;
        }
        else{
            return root;;
        }

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};