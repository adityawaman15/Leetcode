/* Structure of a Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
  
    int find(vector<int> inorder,int root,int left_index, int right_index){
        for(int i = left_index; i <= right_index;i++){
            if(inorder[i] == root){
                return i;
            }
        }
        return -1;
    }
    TreeNode* construct(vector<int> inorder, vector<int> postorder, int &index, int left_index, int right_index){
        
        if(left_index > right_index || index >= inorder.size()){
            return NULL;
        }
        
        int element = postorder[index--];
        TreeNode* root = new TreeNode(element);
        int root_index = find(inorder, element,left_index,right_index);
        
        
  
        root->right = construct(inorder,postorder,index,root_index+1,right_index);
        root->left = construct(inorder,postorder,index,left_index,root_index -1);
        
        return root;
        
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int index = inorder.size()-1;
        TreeNode* root =construct(inorder,postorder,index,0,inorder.size()-1);
        return root;
    }
};