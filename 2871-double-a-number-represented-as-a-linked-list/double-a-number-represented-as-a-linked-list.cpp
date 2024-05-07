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
    ListNode* doubleIt(ListNode* head) {
        ListNode* temp = head;
        stack<ListNode*> st;
        while(temp!=NULL){
            st.push(temp);
            temp=temp->next;
        }
        int carry=0;
        while(!st.empty()){
            ListNode* node= st.top();
            st.pop();
            int value= 2*node->val + carry;
            cout<<value<<" ";
            node->val= value%10;
            carry= value/10;
        }
        if(carry!=0){
            ListNode* newhead= new ListNode(carry, head);
            return newhead;
        }
        return head;
    }
};