class Solution {
public:
    vector<string> letterCombinations(string digits) {
      unordered_map<char, string> mpp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        vector<string>ans={""};
       for(int i=0;i<digits.length();i++){
           auto choice=mpp[digits[i]];
           vector<string>temp;
           for(int j=0;j<ans.size();j++){
            for(int k=0;k<choice.length();k++){
               temp.push_back(ans[j]+choice[k]);
            }
           }
           ans=temp;
       }
      return ans;
    }
};