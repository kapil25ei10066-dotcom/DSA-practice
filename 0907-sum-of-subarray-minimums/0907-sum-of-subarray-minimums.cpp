class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
      stack<pair<int,int>>lst;
       stack<pair<int,int>>rst;
      vector<int>left(arr.size());
      vector<int>right(arr.size());
      for(int i=arr.size()-1;i>=0;i--){
        int cnt=1;
        while(!rst.empty() && arr[i]<rst.top().first){
            cnt+=rst.top().second;
            rst.pop();
        }
        
         right[i]=cnt;
         rst.push({arr[i],cnt});
      } 
        for(int i=0;i<arr.size();i++){
        int cnt=1;
        while(!lst.empty() && arr[i]<=lst.top().first){
            cnt+=lst.top().second;
            lst.pop();
        }
       
         left[i]=cnt;
         lst.push({arr[i],cnt});
      } 
      long long  sum=0;
      int mod = 1e9 + 7;
      for(int i=0;i<arr.size();i++){
        sum=(sum+(arr[i]*(long long)(left[i]*right[i])%mod)%mod)%mod;
      }
      
      return sum;
    }
};