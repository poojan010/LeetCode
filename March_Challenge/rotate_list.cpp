class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        int length = 0;
        ListNode* t = head;
        while(t != NULL){
            length++;
            t = t->next;
        }
        
        if(k%length == 0) return head;
        
        k = k%length;
        
        ListNode* slow = head; 
        ListNode* fast = head;
        
        while(k--) fast = fast->next;
        
        while(fast->next != NULL){
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode* root = slow->next;
        slow->next = NULL;
        fast->next = head;
        
        return root;
    }
};