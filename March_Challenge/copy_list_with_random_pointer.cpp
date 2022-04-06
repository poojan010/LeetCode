class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node ans(0);
        
        map<Node*,pair<int,int>> mp1;
        map<int,Node*> mp2;
        Node* t = head;
        Node* p = &ans;
        int i=0;
        
        while(t != NULL){
            p->next = new Node(t->val);
            mp1[t] = make_pair(i,-1);
            p = p->next;
            mp2[i] = p;
            t = t->next;
            i++;
        }
        
        for(auto &it : mp1){
            
            if(it.first->random == NULL) continue;
            it.second.second = mp1[it.first->random].first;
            // cout << it.first->val << " : " << it.second.first << ", " << it.second.second << "\n";
            
        }
        for(auto it : mp1){
            cout << it.first->val << " : " << it.second.first << ", " << it.second.second << "\n";
        }
        cout << "\n";
        for(auto it : mp2) cout << it.first << " : " << it.second->val << "\n";
        
        
        t = head;
        p = &ans;
        p = p->next;
        while(t != NULL){
            if(mp1[t].second == -1) p->random = NULL;
            else p->random = mp2[mp1[t].second];
            t = t->next;
            p = p->next;
        }
        
        return ans.next;
    }
};