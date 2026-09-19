class Solution {
public:
    int maxArea(vector<int>& nums) {
        int st=0; int end=nums.size()-1;int maxarea=0; int area=0;
        while(st<end){
            int height=min(nums[st],nums[end]);
            int base=end-st;
            area=height*base;
             maxarea=max(maxarea,area);
            if(nums[st]<nums[end]){
                st++;
            }
            else{
                end--;
            }
        }
        return maxarea;
    }
};