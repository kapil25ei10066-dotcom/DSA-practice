class Solution {
public:
    int reqdays(vector<int>& nums, int cap){
        int days=1; int load=0;
        for(int i=0;i<nums.size();i++){
            /*if(nums[i]>cap){
                return INT_MAX;
            }*/
            if(load+nums[i]>cap){
                days++;
                load=nums[i];
            }
            else{
                load+=nums[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& nums, int days) {
       int low=0; int n=nums.size(); 
       for(int i=0;i<n;i++){
        low=max(low,nums[i]);
       } 
       long long  high=0;
       for(int i=0;i<n;i++){
        high+=(long long )nums[i];
       }
       int ans=high;
       while(low<=high){
        int mid=low+(high-low)/2;
        int nodays=reqdays(nums,mid);
        if(nodays<=days){
            ans=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
   
       }
    return ans;
    }
};