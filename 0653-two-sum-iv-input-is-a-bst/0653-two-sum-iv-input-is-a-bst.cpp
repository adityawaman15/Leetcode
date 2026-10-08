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
    vector<int> arr;
    void traverse(TreeNode* root){

        if(root == NULL){
            return;
        }
        traverse(root->left);
        arr.push_back(root->val);
        traverse(root->right);
    }
    bool findTarget(TreeNode* root, int target) {

        traverse(root);
        int i = 0;
        int j = arr.size()-1;

        while(i<j){

            int sum = arr[i] + arr[j];

            if(sum == target){
                return true;
            }
            else if(sum > target){
                j--;
            }
            else {
                i++;}
           
        }
        return false;
        
    }
};