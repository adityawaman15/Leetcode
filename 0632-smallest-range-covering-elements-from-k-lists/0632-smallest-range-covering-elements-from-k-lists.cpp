class Solution {
public:
    class Node{
        public:
            int data;
            int row;
            int col;

            Node(int d, int r, int c){
                data  = d;
                row = r;
                col = c;
            }
    };

    class compare{
        public:
        bool operator()(Node* a, Node*b){
            return a->data > b->data;
        }
    };


    vector<int> smallestRange(vector<vector<int>>& nums) {

        int mini = INT_MAX;
        int maxi = INT_MIN;

        priority_queue<Node*,vector<Node*>,compare> min_heap;

        //creating heap of first elements of k lists;

        for(int i = 0; i < nums.size();i++){
            if(nums[i].size() > 0){
                Node* temp = new Node(nums[i][0], i ,0);
                min_heap.push(temp);
                mini = min(mini,nums[i][0]);
                maxi = max(maxi,nums[i][0]);
            }
        }

        int start = mini;
        int end = maxi;

        while(!min_heap.empty()){
            Node* top = min_heap.top();
            min_heap.pop();

            mini = top->data;

            if(maxi - mini < end - start){
                start = mini;
                end = maxi;
            }

            int row = top->row;
            int col = top->col;
            int data = top->data;

            

            //add next node to heap
            if(col+1 < nums[row].size()){
                maxi = max(maxi,nums[row][col +1]);
                min_heap.push(new Node(nums[row][col + 1], row,col+1));
            }
            else{
                break;
            }


            
        }

        vector<int> ans;
        ans.push_back(start);
        ans.push_back(end);

        return ans;


        
    }
};