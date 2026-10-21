class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
       unordered_map<char,int>mp; 
       unordered_map<char,int>cs;
       for(int i=0;i<tasks.size();i++){
        mp[tasks[i]]++;
        cs[tasks[i]]=1;
       }
       struct cmp{
        bool operator()(pair<int,char>&a,pair<int,char>&b){
            return a.first<b.first;
        }
       };
       priority_queue<pair<int,char>,vector<pair<int,char>>,cmp>pq;
       for(auto i:mp){
        pq.push({i.second,i.first});
       }
         int seat=1;
       while(!pq.empty()){
        vector<pair<int,char>>pulled;
       
        while(!pq.empty()){
          if(cs[pq.top().second]<=seat){
            cs[pq.top().second]= seat+n+1;
            char child=pq.top().second;
            int count=pq.top().first;
            pq.pop();
            if(count>1){
            pq.push({count-1,child});}
            
            break;
          }
          else{
             pulled.push_back(pq.top());
             pq.pop();
          }
        }
        for(int i=0;i<pulled.size();i++){
           pq.push(pulled[i]); 
        }
        seat++;
       }
       return seat-1;

    }
};