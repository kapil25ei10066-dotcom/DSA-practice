class Solution {
public:
    int hIndex(vector<int>&nums) {
        int low=0; int high=nums.size()-1; int ans=-1;
        if(nums.size()==1 && nums[0]==0){
            return 0;
        }
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>=nums.size()-mid){
                ans=mid;
                high=mid-1;
            }
            else if(nums[mid]<nums.size()-mid){
                low=mid+1;
            }
        }
        if(ans!=-1){
        return nums.size()-ans;}
        else{
            return 0;
        }
    }
};