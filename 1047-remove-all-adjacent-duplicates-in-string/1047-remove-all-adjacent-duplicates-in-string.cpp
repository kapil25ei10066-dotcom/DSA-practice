class Solution {
public:
    string removeDuplicates(string s) {
      if(s==""){
        return "";
      }
        
        int n=s.length();
        if(n==1){
            return s;
        }
        string res="";
        stack<char>st;
        
        for(int i=0;i<n;i++){
            if(!st.empty() && st.top()==s[i]){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};