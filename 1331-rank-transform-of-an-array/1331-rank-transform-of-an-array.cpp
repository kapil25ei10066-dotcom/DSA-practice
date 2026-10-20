class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        struct cmp{
            bool operator()(pair<int,int>&a,pair<int,int>&b){
               return  a.first>b.first;
            }
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp>pq;
        for(int i=0;i<arr.size();i++){
            pq.push({arr[i],i});
        }
        if(pq.empty()){
            return arr;
        }
        int prev=pq.top().first;  arr[pq.top().second]=1;int index=1; pq.pop();
       for(int i=1;i<arr.size();i++){
        if(pq.top().first==prev){
         arr[pq.top().second]=index;
         pq.pop();
       }
       else{
        arr[pq.top().second]=index+1;
        prev=pq.top().first;
        index++;
        pq.pop();

       }

       }
       return arr;
    }
};