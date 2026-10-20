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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>ans;
       int k= lists.size();
        for(int i=0;i<k;i++){
            ListNode* curr=lists[i];
            while(curr!=NULL){
                ans.push_back(curr->val);
                curr=curr->next;
            }
        }
        sort(ans.begin(),ans.end());
        ListNode* dummy=new ListNode(0);
        ListNode* tails=dummy;
        for(int i=0;i<ans.size();i++){
           tails->next=new ListNode(ans[i]);
           tails=tails->next;
        }
        tails->next=NULL;
        return dummy->next;
    }
};