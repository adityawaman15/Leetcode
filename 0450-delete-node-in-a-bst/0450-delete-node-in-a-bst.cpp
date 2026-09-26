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

    int minimum(TreeNode* root){
        while(root->left != NULL){
            root = root->left;
        }

        return root->val;
    }

    
    TreeNode* DeleteFromBst(TreeNode* root, int val){
        if(root == NULL){
            return NULL;
        }
        else if(root->val == val){
            // 0 node
            if(root->left == NULL && root->right == NULL){
                root = NULL;
                delete root;
                return NULL;
            }

            //1 node

            if(root->left != NULL && root->right == NULL){
                TreeNode* temp = root->left;
                root = NULL;
                delete root;
                return temp;
            }

            if(root->right != NULL && root->left == NULL){
                TreeNode* temp = root->right;
                root = NULL;
                delete root;
                return temp;
            }
            
            // 2 node

            if(root->right != NULL && root->left != NULL){
             int mini = minimum(root->right);
             root->val = mini;
             root->right = DeleteFromBst(root->right,mini);
             return root;
            }
        }
        else if(root->val < val){
            root->right = DeleteFromBst(root->right,val);
            return root;
           
        }
        else{
            root->left = DeleteFromBst(root->left,val);
            return root;
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {

        root = DeleteFromBst(root,key);
        return root;
        
    }
};