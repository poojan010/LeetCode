class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        
        ListNode* slo = head;
        ListNode* fas = head;
        
        while(fas != NULL && fas->next != NULL){
            slo = slo->next;
            fas = fas->next->next;
            
            if(slo == fas) return true;
        }
        
        return false;
    }
};