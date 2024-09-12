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
private:
    void f(ListNode* l1, ListNode* l2, int& carry){
        if(l1==NULL && l2==NULL){
            return;
        }
        if(l2==NULL){
            int sum= l1->val+carry;
            l1->val= sum%10;
            carry= sum/10;
            f(l1->next, l2, carry);
        }
        else{
            int sum= l1->val+l2->val+carry;
            l1->val= sum%10;
            carry= sum/10;
            f(l1->next, l2->next, carry);
        }
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1= l1;
        ListNode* temp2 = l2;
        while(temp1!=NULL && temp2!=NULL){
            temp1= temp1->next;
            temp2= temp2->next;
        }
        int carry=0;
        if(temp1==NULL){
            ListNode* head= l2;
            ListNode*temp=head;
            while(temp->next!=NULL){
                temp= temp->next;
            }
            f(l2, l1, carry);
            if (carry!=0){
                ListNode* l= new ListNode(carry);
                temp->next= l;
            }
            return head;
        }
        else{
            ListNode* head= l1;
            ListNode*temp=head;
            while(temp->next!=NULL){
                temp= temp->next;
            }
            f(l1, l2, carry);
            if (carry!=0){
                ListNode* l= new ListNode(carry);
                temp->next= l;
            }
            return head;
        }
        return NULL;
    }
};