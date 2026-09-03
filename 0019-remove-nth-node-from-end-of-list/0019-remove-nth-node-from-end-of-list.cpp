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
        if(head==NULL){
            return head;
        }
      
      int count =1;
      ListNode* size=head;
      while(size->next!=NULL){
        size=size->next;
        count++;
      } 
      if(n==count){
        return head->next;
      }
     
      ListNode* tail=head;
      ListNode* prev=head;
      for(int i=0;i<count-n;i++){
           prev=tail;
        tail=tail->next;
      } 
      ListNode* next=tail->next;
      prev->next=NULL;
      tail->next=NULL;
      prev->next=next;
      return head;
    }
};