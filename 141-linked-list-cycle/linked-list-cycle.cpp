/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL) return false;
        ListNode* temp= head;
        map<ListNode*, int> mp;
        while(temp->next!=NULL){
            mp[temp]++;
            temp=temp->next;
            if(mp[temp]==2) return true;
        }
        return false;
    }
};