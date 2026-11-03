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
            if(i>st && candidates[i]==candidates[i-1]){
                continue;
            }
            temp.push_back(candidates[i]);
         
            solve(candidates,ans,target,temp,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
         vector<vector<int>>ans;
        vector<int>temp; int st=0; 
        sort(candidates.begin(),candidates.end());
        solve(candidates,ans,target,temp,0);
        return ans;
    }
};