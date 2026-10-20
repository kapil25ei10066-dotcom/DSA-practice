class Solution {
public:
    int kthSmallest(vector<vector<int>>& nums, int k) {
        int m=nums.size();
        int n=nums[0].size();
        class node{
            public:
            int value;
            int row;
            int col;
            node(int v, int i, int j){
                value=v;
                row=i;
                col=j;
            }
            };
            struct cmp{
                bool operator()(const node &a,const node &b){
                    return a.value>b.value;
                }
            };
            priority_queue<node,vector<node>,cmp>pq;
            for(int i=0; i<m;i++){
             pq.push({nums[i][0],i,0});
            }
            vector<int>ans;
            while(!pq.empty()){
                ans.push_back(pq.top().value);
                int col=pq.top().col;
                int row=pq.top().row;
                pq.pop();
                if(col+1==n){
                    continue;
                }
                pq.push({nums[row][col+1],row,col+1});
            }

        return ans[k-1];
    }
};