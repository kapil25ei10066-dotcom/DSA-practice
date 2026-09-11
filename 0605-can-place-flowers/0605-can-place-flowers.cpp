class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        int x=nums.size();
        int cnt=0;
        if(x==1){
            if(nums[0]==0){
                nums[0]=1;
                cnt++;
            }
        }
        if(nums[0]==0){
            if(nums[1]==0){
                nums[0]=1;
                cnt++;
            }
        }
        if(nums[x-1]==0){
            if(nums[x-2]==0){
                nums[x-1]=1;
                cnt++;
            }
        }
        
        for(int i=1;i<x-1;i++){
            if(nums[i]==0){
               if(nums[i-1]==0 && nums[i+1]==0){
                nums[i]=1;
                cnt++;
               }
            }
        }
        if(cnt>=n){
            return true;
        }
       else{return false;}
    }
};