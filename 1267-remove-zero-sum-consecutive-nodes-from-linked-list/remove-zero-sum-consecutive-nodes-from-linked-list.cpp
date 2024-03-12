class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* front = new ListNode(0, head);
        ListNode* current = front;
        int prefixSum = 0;
        unordered_map<int, ListNode*> prefixSumToNode;
        prefixSumToNode[0] = front;

        while (current != nullptr) {
            prefixSum += current->val;
            prefixSumToNode[prefixSum] = current;
            current = current->next;
        }
        prefixSum = 0;
        current = front;

        while (current != nullptr) {
            prefixSum += current->val;
            current->next = prefixSumToNode[prefixSum]->next;
            current = current->next;
        }
        return front->next;
    }
};