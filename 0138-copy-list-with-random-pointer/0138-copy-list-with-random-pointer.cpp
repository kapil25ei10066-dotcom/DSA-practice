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
        if(head==NULL){
            return NULL;
        }
        unordered_map<Node*,Node*>mpp;
       Node* newhead=new Node(head->val);
       Node* newtemp=newhead;
       Node* oldtemp=head;
       mpp[head]=newhead;
       mpp[NULL]=NULL;
       oldtemp=oldtemp->next;
       while(oldtemp!=NULL){
           Node* copynode= new Node(oldtemp->val);
           newtemp->next=copynode;
          
           newtemp=newtemp->next;
           mpp[oldtemp]=newtemp;
            oldtemp=oldtemp->next;
       }
       oldtemp=head;
       newtemp=newhead;
       while(oldtemp!=NULL){
        newtemp->random=mpp[oldtemp->random];
        oldtemp=oldtemp->next;
        newtemp=newtemp->next;
       }
       return newhead;

    }
};