class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0]; int high=matrix[n-1][n-1]; int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int count=0;
            int row=0; int col=n-1;
            while(row<=n-1 && col>=0){
              if(matrix[row][col]<=mid){
                count=count+(col+1);
                row++;
              }
              else{
                col--;
              }
            }
            if(count>=k){
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