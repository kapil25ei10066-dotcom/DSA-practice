class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& arr) {
        sort(nums.begin(),nums.end());
       
        vector<int>prefix; int sum=0; vector<int>result; 
        for(int i=0;i<nums.size();i++){
         sum+=nums[i];
            prefix.push_back(sum);

        }
        for(int j=0;j<arr.size();j++){
            int low=0; int high=prefix.size()-1; int ans=0;
            while(low<=high){
                int mid=low+(high-low)/2;
                if(prefix[mid]<=arr[j]){
                    ans=mid+1;
                    low=mid+1;
                }
                else{
                   high=mid-1;
                }
               
            }
             result.push_back(ans);
        }
        return result;

    }
};