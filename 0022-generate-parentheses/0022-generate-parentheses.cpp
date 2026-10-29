class Solution {
public:
    vector<string>make(int n,int open,int close,vector<string>&ans, string temp){
        if(open==n && close==n){
           ans. push_back(temp);
            return ans; 
        }
      
        // making for open i hope bug will not come ohh plz god
        if(open<n){
            temp.push_back('(');
            make(n,open+1, close,ans,temp);
            temp.pop_back();
        }
        // for close
        if(close<open){
            temp.push_back(')');
            make(n,open, close+1,ans,temp);
        }
        return ans;
    } 
    vector<string> generateParenthesis(int n) {
        int open=0; int close=0; vector<string>ans; string temp="";
         return make(n,open, close,ans,temp);
    }
};