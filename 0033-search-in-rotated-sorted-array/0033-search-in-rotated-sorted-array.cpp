class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0; int high= n-1; int ans=-1; 
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[n-1]){
                low=mid+1;
            }
            else {
                ans=mid;
                high=mid-1;
            }
            
        }
        if(target>nums[n-1]){
         int l=0; int h=ans-1;
         while(l<=h){
             int mid=l+(h-l)/2;
             if(nums[mid]==target){
                return mid;
             }
             if(nums[mid]>target){
                h=mid-1;
             }
             else{
                l=mid+1;
             }
         }
        }
        else{
             int l=ans; int h=n-1;;
         while(l<=h){
             int mid=l+(h-l)/2;
             if(nums[mid]==target){
                return mid;
             }
             if(nums[mid]>target){
                h=mid-1;
             }
             else{
                l=mid+1;
             }
        }
        }
        return -1;
    }
};