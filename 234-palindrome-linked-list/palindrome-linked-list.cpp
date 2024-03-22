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
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp= temp->next;
        }
        // for(int i=0; i<arr.size(); i++){
        //     cout<<arr[i]<<" ";
        // }
        int start= 0;
        int end= arr.size()-1;
        while(end>=start){
            if(arr[end]==arr[start]){
                end--;
                start++;
            }
            else{
                return false;
            }
        }
        return true;

    }
};