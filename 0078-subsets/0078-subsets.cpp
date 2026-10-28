class Solution {
public:
    void printsubset(vector<int>& nums, vector<int>&ans,int i, vector<vector<int>> &result){
        if(i==nums.size()) {
           result.push_back(ans);
           return;            
      }
        ans.push_back(nums[i]);
        printsubset(nums,ans,i+1,result);
        ans.pop_back();
        printsubset(nums,ans,i+1,result);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> result;
        vector<int>ans;
        int i=0;
    printsubset(nums,ans,i,result);
    return result;
    }
};