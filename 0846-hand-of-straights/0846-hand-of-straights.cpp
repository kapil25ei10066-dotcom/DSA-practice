class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int groupsize) {
        if(groupsize>nums.size()){
            return false;
        }
       unordered_map<int,int>mpp;
       for(int i=0;i<nums.size();i++){
        mpp[nums[i]]++;
       } 
       struct cmp{
        bool operator()(pair<int,int>&a,pair<int,int>&b){
          return a.first>b.first;
        }
       };
    priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
    for(auto i: mpp){
        pq.push({i.first,i.second});
    }
    vector<vector<int>>result; 
    while(!pq.empty()){
        vector<pair<int,int>>store;
        vector<int>temp; int prev=0;
        
        for(int i=0;i<groupsize  ;i++){
            if (pq.empty()) {
                 return false;
                 }
           pair<int,int> pairr=pq.top();
           pq.pop();
            if(i>0 && pairr.first!=prev+1){
                return false;
            }
            else{
                temp.push_back(pairr.first);
                if(pairr.second>1){
                    store.push_back({pairr.first,pairr.second-1});
                }
                prev=pairr.first;
            }

        }
        for(int i=0;i<store.size();i++){
            pq.push({store[i].first,store[i].second});
        }
        result.push_back(temp);
        temp.clear();
    }
         return true;
    }
};