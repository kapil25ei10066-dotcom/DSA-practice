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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
       ListNode* dummy=new ListNode(0);
    dummy->next=head;
    ListNode* temp=dummy;
    ListNode* first=temp->next;
   // ListNode* second=first->next;
    while(first!=NULL && first->next!=NULL){
        ListNode* second=first->next;
        ListNode* third=second->next;
        first->next=NULL;
        second->next=NULL;
        second->next=first;
        first->next=third;
        temp->next=second;
        temp=first;
        first=third;
       
    }
    return dummy->next;
    }
};