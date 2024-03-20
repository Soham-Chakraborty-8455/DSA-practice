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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        if(list1==NULL) return NULL;
        int cnt1=0, cnt2=0;
        ListNode* temp= list1;
        ListNode* ptr= list1;
        ListNode* head= list2;
        ListNode* tail= list2;
        while(cnt1<a-1){
            temp= temp->next;
            cnt1++;
        }
        while(cnt2<b){
            ptr= ptr->next;
            cnt2++;
        }
        // cout<<ptr->val;
        while(tail->next!=NULL){
            tail= tail->next;
        }
        temp->next=head;
        tail->next=ptr->next;

        return list1;
    }
};