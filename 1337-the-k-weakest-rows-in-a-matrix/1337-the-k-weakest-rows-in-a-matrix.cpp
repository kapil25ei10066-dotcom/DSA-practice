class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& nums, int k) {
        int n=nums.size();
        struct cmp{
            bool operator()(pair<int,int>&a,pair<int,int>&b){
               if(a.first!=b.first){
                return a.first<b.first;
               }
               return a.second<b.second;}
        };
        priority_queue<pair<int,int >,vector<pair<int,int>>,cmp>pq;
        for(int i=0;i<nums.size();i++){
            int sum=0;
            for(int j=0;j<nums[0].size();j++){
                sum+=nums[i][j];
            }
            pq.push({sum,i});
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        
        }
       // sort(ans.begin(),ans.end());
       reverse(ans.begin(),ans.end());
        return ans;

    }
};