class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode newList(0);
        ListNode* tHead = &newList;
        
        while(list1 && list2){
            if(list1->val < list2->val){
                tHead->next = list1;
                list1 = list1->next;
            }
            else{
                tHead->next = list2;
                list2 = list2->next;
            }
            tHead = tHead->next;
        }
        
        tHead->next = list1 ? list1 : list2;
        
        return newList.next;
    }
};