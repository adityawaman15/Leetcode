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
    bool Check_CBT(TreeNode* root, int node_count, int value){
        if(root == NULL){
            return true;
        }
        
        if(value >= node_count){
            return false;
        }
        
        bool left = Check_CBT(root->left,node_count, 2*value+1);
        bool right = Check_CBT(root->right, node_count,2*value+2);
        
        return left && right;
    }

    void Inorder(TreeNode* root, int &count){
        if(root == NULL){
            return;
        }
        
        Inorder(root->left,count);
        count++;
        Inorder(root->right,count);
        
        
    }
    bool isCompleteTree(TreeNode* root) {
        int count = 0;
        Inorder(root,count);
        if(Check_CBT(root,count,0)){
            return true;
        }
        return false;
    }
};