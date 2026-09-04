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
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            return NULL;
        }
        if(head->next->next==NULL){
            head->next=NULL;
            return head;
        }
       ListNode* slow=head;
       ListNode* fast=head;
       ListNode* prevslow=head;
       while(fast!=NULL && fast->next!=NULL){
        prevslow=slow;
        slow=slow->next;
        fast=fast->next->next;

       } 
       ListNode* next=slow->next;
       prevslow->next=NULL;
       slow->next=NULL;
       prevslow->next=next;
       return head;
    }
};