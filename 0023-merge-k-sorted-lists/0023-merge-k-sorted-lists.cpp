/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    class compare{
        public:
            bool operator()(ListNode* a, ListNode* b){
                return a->val > b->val;
            }
    }
    ;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        

     
        priority_queue<ListNode*,vector<ListNode*>, compare> min_heap;

        



        for(int i = 0; i < lists.size();i++){
            if(lists[i] != NULL){
            min_heap.push(lists[i]);
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(min_heap.size() >0){
            ListNode* top = min_heap.top();
            min_heap.pop();

            if(head == NULL){
                head = top;
                tail = top;
                
            }
            else{
                tail->next = top;
                tail = top;
            }

            if(tail->next != NULL){
                    min_heap.push(tail->next);
                }

        }

        return head;


        
    }
};