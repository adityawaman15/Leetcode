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

    void inorder(TreeNode* root, vector<TreeNode*> &Nodes){
        if(root == NULL){
            return;
        }

        inorder(root->left, Nodes);
        Nodes.push_back(root);
        inorder(root->right,Nodes);
    }

    TreeNode* balance(vector<TreeNode*> &Nodes,int s, int e){
        if(s>e){
            return NULL;
        }
        int mid = s + (e-s)/2;
        TreeNode* root = Nodes[mid];
        root->left = balance(Nodes,s,mid-1);
        root->right = balance(Nodes,mid+1,e);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> Nodes;
        inorder(root,Nodes);


        return balance(Nodes,0, Nodes.size()-1);

    }
};