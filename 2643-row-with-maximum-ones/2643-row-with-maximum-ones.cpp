class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int ans=0;  int maxsum=0;
        for(int i=0;i<m;i++){
            int sum=0;
            for(int j=0;j<n;j++){
                sum+=mat[i][j];
            }
          if(sum>maxsum){
            maxsum=sum;
            ans=i;
          }
          maxsum=max(maxsum,sum);
        }
       return {ans,maxsum};
    }
};