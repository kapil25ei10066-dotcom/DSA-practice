class Solution {
public:
    vector<int> asteroidCollision(vector<int>& nums) {
        stack<int>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
          
           if(nums[i]>0){
            st.push(nums[i]);
            continue;
           }
           while(!st.empty()&&st.top()>0&& nums[i]<0&& -nums[i]>st.top()){
            st.pop();
           }
           if(!st.empty()&&-nums[i]==st.top()){
            st.pop();
            continue;
           }
           if(st.empty()&&nums[i]<0){
           st.push(nums[i]);
           continue;
           }
           else if(st.top()<0&&nums[i]<0){
            st.push(nums[i]);
            continue;
           }
           
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};