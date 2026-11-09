class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& arr) {
        sort(nums.begin(),nums.end());   vector<int>ans;
       for(int i=0;i<arr.size();i++){
         int count=0; int sum=0;
        for(int j=0;j<nums.size();j++){
           sum+=nums[j];
           count++;
           if(sum>arr[i]){
            count--;
            break;

           }
        }
        ans.push_back(count);
       }
        return ans;
    }
};