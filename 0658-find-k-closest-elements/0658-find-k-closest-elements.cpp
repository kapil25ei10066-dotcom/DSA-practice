class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        struct cmp{
        bool operator()(pair<int,int>&a,pair<int,int>&b){
           if(a.first!=b.first){
                return a.first<b.first;}
            return a.second<b.second;
           
        }
      };

      priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
      for(int i=0;i<arr.size();i++){
        int dist=abs(x-arr[i]);
        pq.push({dist,arr[i]});
        if(pq.size()>k){
            pq.pop();
        }
      }
      vector<int>ans;
      while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
      }
      sort(ans.begin(), ans.end());
      return ans;
    }
};