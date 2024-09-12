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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        
        ListNode* fast= head;
        ListNode* slow= head;
        ListNode* temp= head;
        int len=0;
        while(temp!= NULL){
            temp= temp->next;
            len++;
        }
        k= k%len;
        if(k==0) return head;
        for(int i=0; i<k; i++){
            fast= fast->next;
        }
        while(fast->next!=NULL){
            fast= fast->next;
            slow= slow->next;
        }
        ListNode* root= slow->next;
        slow->next= NULL;
        fast->next= head;
        return root;

    }
};