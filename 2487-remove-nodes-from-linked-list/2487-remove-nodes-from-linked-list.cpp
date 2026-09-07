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
    ListNode* removeNodes(ListNode* head) {
        stack<int>st;
        ListNode* temp=head;
        while(temp!=NULL){
            st.push(temp->val);
            temp=temp->next;
        }
        
        int max=st.top();
        ListNode* newhead=new ListNode(max);
        st.pop();
       //ListNode* curr=newhead;
        while(!st.empty()){
            if(max<=st.top()){
                ListNode* makenode=new ListNode(st.top());
                makenode->next=newhead;
                newhead=makenode;
               
                max=st.top();
              
            }
           
                st.pop();
            
        }
            return newhead;
    }
};