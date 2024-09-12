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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL) return NULL;
        if(head->next==NULL) return head;
        map<int, int> mp;
        ListNode* temp= head; 
        while(temp!=NULL){
            mp[temp->val]++;
            temp= temp->next;
        }
        ListNode* root= new ListNode(-1);
        ListNode* ptr= root;
        temp= head;
        while(temp!=NULL){
            if(mp[temp->val]==1){
                ListNode* node= new ListNode(temp->val);
                ptr->next= node;
                ptr= ptr->next;
                temp= temp->next;
            }
            else temp= temp->next;
        }
        return root->next;
    }
};