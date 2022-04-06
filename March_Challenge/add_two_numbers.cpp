class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode ans(0); 
        ListNode *t = &ans;
        
        int carry = 0;
        
        while(l1 || l2 || carry){
            
            int sum = (l1?l1->val:0) + (l2?l2->val:0) + carry;
            
            carry = sum/10;
            
            t->next= new ListNode(sum % 10);
            
            t = t->next;
            
            l1 = (l1?l1->next:l1);
            l2 = (l2?l2->next:l2);
        }
        
        return ans.next;
    }
};