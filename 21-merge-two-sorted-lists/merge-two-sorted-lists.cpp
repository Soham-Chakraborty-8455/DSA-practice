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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return NULL;
        if(!list1) return list2;
        if(!list2) return list1;
        ListNode* temp1= list1;
        ListNode* temp2 = list2;
        ListNode* head= new ListNode(-1);
        ListNode* temp= head;
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->val <= temp2->val){
                ListNode* node= new ListNode(temp1->val);
                temp->next= node;
                temp= temp->next;
                temp1= temp1->next;
            }
            else{
                ListNode* node= new ListNode(temp2->val);
                temp->next= node;
                temp= temp->next;
                temp2= temp2->next;
            }
        }
        if(temp1) temp->next= temp1;
        if(temp2) temp->next = temp2;
        ListNode* ans= head->next;
        delete(head);
        return ans;

    }
};