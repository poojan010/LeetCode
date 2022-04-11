class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        
        --k;    // bcoz 1-indexed 
        
        ListNode* fast = head;
        
        while(k--) fast = fast->next;
        
        ListNode* node1 = fast;  // found kth node from start
        
        ListNode* slow = head;
        
        while(fast->next != NULL){   // finding kth node from end
            fast = fast->next;
            slow = slow->next;
        }
        
        int a = node1->val;
        node1->val = slow->val;
        slow->val = a;
        
        
        return head;
    }
};