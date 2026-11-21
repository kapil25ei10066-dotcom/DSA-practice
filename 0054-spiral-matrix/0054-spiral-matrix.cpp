class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(); int n=matrix[0].size();
        int srow=0; int scol=0;
        int erow=m-1; int ecol=n-1;
        vector<int>result;
        while(srow<=erow && scol<=ecol){
        for(int i=scol;i<=ecol;i++){
            result.push_back(matrix[srow][i]);
        }
        for(int j=srow+1;j<=erow;j++){
            result.push_back(matrix[j][ecol]);
        }
        for(int l=ecol-1;l>=scol;l--){
            if(srow==erow){
                break;
            }
            result.push_back(matrix[erow][l]);
        }
        for(int k=erow-1;k>=srow+1;k--){
            if(scol==ecol){
                break;
            }
            result.push_back(matrix[k][scol]);
        }
        srow++;
        scol++;
        erow--;
        ecol--;
        }
        return result;
    }
};