class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int pivet=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                pivet=i;
                break;
            }}
            if(pivet!=-1){
            for(int i=n-1;i>pivet;i--){
                if(nums[i]>nums[pivet]){
                    swap(nums[pivet],nums[i]);
                    break;
                }

            }}
            reverse(nums.begin()+pivet+1,nums.end());




        
        return ;
    }
};