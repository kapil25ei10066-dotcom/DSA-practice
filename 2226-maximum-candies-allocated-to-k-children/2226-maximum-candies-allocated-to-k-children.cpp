class Solution {
public:
    int maximumCandies(vector<int>& nums, long long k) {
        long long n=nums.size();
        long long low=1; long long high=0; long long ans=0;
        for(long long  i=0;i<n;i++){
            high=max(high,(long long)nums[i]);
        }
        while(low<=high){
            long long mid=low+(high-low)/2;
            long long sum=0;
            for(long long i=0;i<n;i++){
              sum+=nums[i]/mid;
            }
            if(sum>=k){
                ans=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return ans;
    }
};