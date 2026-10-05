class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int n=arr.size();
        int low=0; int high=n-1;  int first=-1; int second=-1;
        vector<int>ans;
        while(low<=high){
              int mid=low+(high-low)/2;
              if(arr[mid]<target){
                low=mid+1;
              }
              else if(arr[mid]>target){
                high=mid-1;
              }
              else{
                first =mid;
                high=mid-1;
              }
             
        }
        int low1=0; int high1=n-1;
        while(low1<=high1){
              int mid=low1+(high1-low1)/2;
              if(arr[mid]<target){
                low1=mid+1;
              }
              else if(arr[mid]>target){
                high1=mid-1;
              }
              else{
                second =mid;
               low1=mid+1;
              }
             
        }
      ans.push_back(first);
      ans.push_back(second);
        return ans;
    }
};