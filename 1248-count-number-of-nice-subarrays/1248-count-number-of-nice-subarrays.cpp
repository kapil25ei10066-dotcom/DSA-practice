class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
      int n=nums.size(); 
        for(int i=0;i<n;i++){
           if(nums[i]%2!=0){
            nums[i]=1;

        }
           else{
            nums[i]=0;
        }
      } 
         int sum=0;  unordered_map<int,int>mpp;  mpp[0]=1;  int ans=0; int sumarray=0;
        for(int i=0;i<n;i++){
            sumarray+=nums[i];
        }
        if(sumarray==0){
            return 0;
        }
      for(int i=0;i<n;i++){
        sum+=nums[i];
        if(mpp.find(sum-k)!=mpp.end()){
            ans+=mpp[sum-k];

        }
        mpp[sum]++;
      }
       return ans; 
    }
};