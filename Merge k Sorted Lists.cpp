class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // corrected comparison
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        
        // step 1
        for(ListNode* head : lists) {
            if(head != NULL) {
                minHeap.push(head);
            }
        }
        
        ListNode* dummy = new ListNode(0); // dummy node
        ListNode* tail = dummy; // tail pointer
        
        while(!minHeap.empty()) {
            ListNode* top = minHeap.top();
            minHeap.pop();
            
            if(top->next != NULL) {
                minHeap.push(top->next);
            }
            
            tail->next = top;
            tail = tail->next;
        }
        
        return dummy->next;
    }
};
