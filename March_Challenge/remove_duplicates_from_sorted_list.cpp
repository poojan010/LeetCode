class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode root(0);
        ListNode* node = &root;
        
        ListNode* temp = head;
 
        
        while(temp != NULL && temp->next != NULL){
            if(temp->val != temp->next->val){
               node->next = new ListNode(temp->val);
               node = node->next;
            }
            else{
                while(temp->next != NULL && temp->val == temp->next->val)
                    temp = temp->next;
            }
            temp = temp->next;
        }
        if(temp != NULL) node->next = new ListNode(temp->val);
        return root.next;
    }
};