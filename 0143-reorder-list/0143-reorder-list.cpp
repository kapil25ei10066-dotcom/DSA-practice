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
   /* ListNode* reverse(ListNode* newhead){
        ListNode* prev=NULL;
        ListNode* curr=newhead;
        while(curr!=NULL){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    };*/

    void reorderList(ListNode* head) {
        if (head==NULL || head->next==NULL|| head->next->next==NULL){
            return ;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=NULL;
        while(fast!=NULL&& fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;

        }
       
        if(prev!=NULL){
            prev->next=NULL;
        }
        ListNode* pre=NULL;
        ListNode* curr=slow;
        while(curr!=NULL){
            ListNode* next=curr->next;
            curr->next=pre;
            pre=curr;
            curr=next;
        }
        ListNode* temp2=pre;
       ListNode* temp1=head;
      
      // ListNode* next1=temp1->next;
      // ListNode* next2=temp2->next;
       while(temp2!=NULL && temp1!=NULL){
        ListNode* next1=temp1->next;
        ListNode* next2=temp2->next;
        
        temp1->next=temp2;
                if(next1==NULL){
           
            return ;
        }
       temp2->next=next1;
         temp1=next1;
        temp2=next2;
       
       }
       return ;
    }
};