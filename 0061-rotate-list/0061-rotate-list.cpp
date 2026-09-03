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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL){
            return head;
        }
       ListNode* size=head; int count=1;
       while(size->next!=  NULL){
        size=size->next;
        count++;
       }
       k=k % count;
       if(k==0){
        return head;
       }
      /* ListNode* dummy =new ListNode(0);
       dummy->next=head;
       ListNode* temp=dummy;*/
       ListNode* newhead=head;
      
      for(int i=0;i<count-k-1;i++){
      
      newhead=newhead->next;

      }
      ListNode* kapil=newhead->next;
      newhead->next=NULL;
      size->next=head;
     return kapil;
    }
};