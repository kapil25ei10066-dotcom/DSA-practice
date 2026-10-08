class Solution {
public:
    int minDays(vector<int>& nums, int m, int k) {
        int low=INT_MAX; int high=nums[0]; int n=nums.size(); int result=0;
        for(int i=0;i<n;i++){
            low=min(low,nums[i]);
            high=max(high,nums[i]);
        }
        if(n/k<m){
            return -1;
        }
        
        while(low<=high){
            int mid=low+(high-low)/2; int count=0; int bouquet=0;
            for(int i=0;i<n;i++){
              if(nums[i]<=mid){
                count++;
              }
              else{
                bouquet=bouquet+count/k;
                count=0;

              }
            }
            bouquet+=count/k;
            if( bouquet>=m){
                result=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return result;
    }
};