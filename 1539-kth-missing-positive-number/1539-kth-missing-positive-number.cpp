class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size(); int miss=arr[0]-1;
       if(k<arr[0]){
        return k;
       }
       for(int i=1;i<n;i++){
        int x=arr[i]-arr[i-1]-1;
        int prevmiss=miss;
        miss=miss+x;
        if(miss==k){
            return arr[i]-1;
        }
        else if(miss>k){
          return arr[i-1]+ k - prevmiss;

        }
       }  
      
        return arr[arr.size()-1]+k-miss;
       
    }
};