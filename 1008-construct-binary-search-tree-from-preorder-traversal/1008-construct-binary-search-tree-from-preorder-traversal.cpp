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

    TreeNode* solve (vector<int> &preorder, int &index, int mini, int maxi, int &n){

        if(index > n || preorder[index] > maxi || preorder[index] < mini){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[index++]);
        root->left = solve(preorder,index, mini,root->val,n);
        root->right = solve(preorder,index, root->val,maxi,n);

        return root;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int n = preorder.size()-1;
        int i = 0;

        
        return solve(preorder,i,INT_MIN,INT_MAX,n);
        
    }
};