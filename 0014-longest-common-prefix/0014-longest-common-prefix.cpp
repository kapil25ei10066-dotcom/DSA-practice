class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    int n=strs[0].size();
    int m=strs.size();
    string ans;
    
    for(int j=0;j<n;j++){
        char ch=strs[0][j];
        for(int i=1;i<m;i++){
            if(strs[i][j]!=ch || j>=strs[i].size()){
                return ans;
            }
        }
        ans+=ch;
    }
    return ans;
    }
};