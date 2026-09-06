class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        
       int n=nums.size();
       if(n==0){
        return nums;
       }
       vector<int>res(n);
       stack<int>st;
       for(int i=n-1;i>=0;i--){
       st.push(nums[i]);
       } 
       for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[i]>=st.top()){
            st.pop();
        }
        if(st.empty()){
            res[i]=-1;
            st.push(nums[i]);
        }
        else{
            res[i]=st.top();
             st.push(nums[i]);
        }
       }
       return res;
    }
};