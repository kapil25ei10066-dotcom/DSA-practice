class Solution {
public:
    int minEatingSpeed(vector<int>& nums, int k) {
      int low =1;int  high=1; int ans=0;
      for(int i=0; i<nums.size();i++) {
        high=max(high,nums[i]);
      }
      while(low<=high){
        int mid=low+(high-low)/2;
         long long  h=0;
         for(int i=0;i<nums.size();i++){
            h=h+nums[i]/mid;
            if(nums[i]%mid){
                h++;
            }
           
         }
          if(h>k){
            low=mid+1;
          }
          else {
            ans=mid;
            high=mid-1;

          }
      } 
      return ans;
    }
};