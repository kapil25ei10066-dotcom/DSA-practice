class Solution {
public:
    vector<vector<int>> per(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp, unordered_set<int>st){
       
       
      if(temp.size()==nums.size()){
        ans.push_back(temp);
        return ans;
      }
      for(int i=0;i<nums.size();i++){
        if(st.find(nums[i])==st.end()){
      temp.push_back(nums[i]);
      st.insert(nums[i]);
      per(nums,ans,temp,st);
      st.erase(nums[i]);
      temp.pop_back();}}
      return ans;

    }
    vector<vector<int>> permute(vector<int>& nums) {
         vector<int>temp; vector<vector<int>>ans;  unordered_set<int>st;
        return per(nums,ans,temp,st);
    }
};