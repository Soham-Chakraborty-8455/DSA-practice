/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL) return NULL;
        Node* temp= head;
        Node* temp2= head;
        Node* temp3= head;
        Node* node= new Node(head->val);
        Node* cpy= node;
        while(temp!=NULL){
            Node* copy= new Node(temp->val);
            Node * ptr= temp->next;
            temp->next=copy;
            copy->next=ptr;
            temp= copy->next;
        }
        while(temp2!= NULL){
            Node* rdm= temp2->random;
            if(rdm==NULL) temp2->next->random=NULL;
            else{
                temp2->next->random= rdm->next;
            }
            temp2= temp2->next->next;
        }
        while(temp3!=NULL){
            Node* ptr= temp3->next->next;
            Node* ptr2= temp3->next;
            temp3->next= ptr;
            cpy->next= ptr2;
            cpy= cpy->next;
            temp3= temp3->next;
        }
        return node->next;


    }
};