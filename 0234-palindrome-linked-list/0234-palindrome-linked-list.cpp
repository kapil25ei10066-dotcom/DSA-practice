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
     ListNode* reversenode(ListNode* newhead){
        ListNode* prev=NULL;
         ListNode* curr=newhead;
         

         while(curr!=NULL){
          ListNode*  nextt=curr->next;
            
            curr->next=prev;
            prev=curr;
           
            curr=nextt;
         
         }
         return prev;

    };
    bool isPalindrome(ListNode* head) {
       ListNode* slow=head;
       ListNode* fast=head;
       while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
       }
        ListNode* temp2=reversenode(slow);
      // slow->next=NULL;
       
       ListNode* temp1=head;
      
       while(temp2!=NULL){
        if(temp1->val!=temp2->val){
            return false;
            
        }
         temp1=temp1->next;
            temp2=temp2->next;

       }
       return true;
  
    }
};