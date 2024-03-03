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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slowptr = dummy;
        ListNode* fastptr = dummy;
        
        for (int i = 0; i <= n; i++) {
            if (fastptr == nullptr)
                return nullptr; 
            fastptr = fastptr->next;
        }
        
        while (fastptr != nullptr) {
            fastptr = fastptr->next;
            slowptr = slowptr->next;
        }
        
        ListNode* temp = slowptr->next;
        slowptr->next = slowptr->next->next;
        delete temp; 
        
        ListNode* result = dummy->next;
        delete dummy; 
        return result;
    }
};
