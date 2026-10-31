class Solution {
public:
     vector<string> lc(string digits, vector<string>&ans,int idx,string temp, unordered_map<char, string> phoneMap){
       if(idx==digits.length()){
        ans.push_back(temp);
        return ans;
       }
       auto choice=phoneMap[digits[idx]];
       for(int j=0;j<choice.size();j++){
        temp+=choice[j];
        lc(digits,ans,idx+1,temp, phoneMap);
        temp.pop_back();
       }
       return ans;
     }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()==0){
            return ans;
        }
       unordered_map<char, string> phoneMap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        int idx=0; string temp="";

        return  lc(digits,ans,idx,temp, phoneMap);
       
    }
};