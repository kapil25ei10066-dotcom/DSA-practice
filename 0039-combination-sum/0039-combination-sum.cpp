class Solution {
public:
    void solve(vector<int>& candidates,vector<vector<int>>&ans,int target,vector<int>&temp,int st){
       
        int sum = 0;

for (int i = 0; i < temp.size(); i++) {
    sum += temp[i];
}
        if(sum==target){
            ans.push_back(temp);
            return;
        }
        if(sum>target){
            return;
        }
        for(int i=st;i<candidates.size();i++){
            temp.push_back(candidates[i]);
            solve(candidates,ans,target,temp,i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp; int st=0;
        solve(candidates,ans,target,temp,0);
        return ans;
    }
};