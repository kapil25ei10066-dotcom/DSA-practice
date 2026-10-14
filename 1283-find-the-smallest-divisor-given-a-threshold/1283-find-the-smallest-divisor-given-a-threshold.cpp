class Solution {
public:
    int smallestDivisor(vector<int>& nums, int th) {
        int low=1; int high=INT_MIN; int ans=1;
        for(int i=0;i<nums.size();i++){
            //low=min(low,nums[i]);
            high=max(high,nums[i]);}
            while(low<=high){
                int mid=low+(high-low)/2;
                int count=0;
                for(int i=0;i<nums.size();i++){
                  count += (nums[i] + mid - 1) / mid;
                }
                if(count<=th){
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