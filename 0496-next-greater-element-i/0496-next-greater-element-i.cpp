class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()==0||nums2.size()==0){
            return {};
        }
        vector<int>res(nums2.size());
        vector<int>ans(nums1.size());
       stack<int>st;
       unordered_map<int,int>mpp;
       st.push(nums2[nums2.size()-1]);
       res[nums2.size()-1]=-1;
       mpp[nums2[nums2.size()-1]]=res[nums2.size()-1];
       for(int i=nums2.size()-2;i>=0;i--){
         while(!st.empty() && nums2[i]>=st.top()){
           st.pop();
         }
         if(st.empty()){
            res[i]=-1;
            mpp[nums2[i]]=res[i];
            st.push(nums2[i]);
         }
         else{
            res[i]=st.top();
             mpp[nums2[i]]=res[i];
              st.push(nums2[i]);
         }

        
       }
      for(int i=0;i<nums1.size();i++){
        ans[i]=mpp[nums1[i]];
      }

      
         return ans;
    }
};