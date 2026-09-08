class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n=s.size();
        string ans;
        stack<pair<char,int>>st;
        for(int i=0;i<n;i++){
          if(st.empty()){
            st.push({s[i],1});
            continue;
          }
          if(st.top().first!=s[i]){
            st.push({s[i],1});
            continue;
          }
          else if(st.top().first==s[i] && st.top().second==k-1){
            st.pop();
            continue;
          }
          else{
            st.top().second++;
            continue;
          }
        }
        while(!st.empty()){
            ans.push_back(st.top().first);
            st.top().second--;
            if(st.top().second==0){
                st.pop();
            }
          
        }
         reverse(ans.begin(),ans.end());
         return ans;
    }
};