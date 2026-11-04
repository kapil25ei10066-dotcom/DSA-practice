class Solution {
public:
    void solve(vector<int> & nums,vector<vector<int>> & ans,vector<int> & temp,int st){
        ans.push_back(temp);
        for(int i=st;i<nums.size();i++){
            if(i>st && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            solve(nums,ans,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
       vector<vector<int>> ans;   vector<int> temp;  int st=0;
        solve(nums,ans,temp,st);
        return ans;
    }
};