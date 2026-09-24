/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    vector<vector<int>> traverse(Node* root){
        queue<Node*> q;
        q.push(root);
        vector<vector<int>> ans;

        while(!q.empty()){

            vector<int> sub_ans;
            int size = q.size();

            for(int i = 0; i < size;i++){
            
            
            Node* front = q.front();
            q.pop();

            sub_ans.push_back(front->val);

            for(int i = 0; i < front->children.size();i++){
                if(front->children[i]){
                q.push(front->children[i])
                ;}
            }

            }

            ans.push_back(sub_ans);

        }

        return ans;
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
 
        return traverse(root);
        
    }
};