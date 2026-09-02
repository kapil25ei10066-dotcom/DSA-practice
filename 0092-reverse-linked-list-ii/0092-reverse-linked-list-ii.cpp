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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prev=dummy;
        for(int i=0;i<left-1;i++){
            prev=prev->next;
        }
        ListNode* leftnode=prev->next;
       
        ListNode* rightnode=head;
        for(int i=0;i<right-1;i++){
            rightnode=rightnode->next;
        }
        ListNode* next=rightnode->next;
        ListNode* pre=NULL;
        rightnode->next=NULL;
        ListNode* curr=leftnode;
         while(curr!=NULL){
            ListNode* after=curr->next;
            curr->next=pre;
            pre=curr;
            curr=after;
         }
         prev->next=rightnode;
         leftnode->next=next;
         return dummy->next; 
         
    }
};