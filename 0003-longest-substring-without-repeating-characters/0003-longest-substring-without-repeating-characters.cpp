class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      int low=0; int high=0; unordered_map<char,int>m;  int n=s.size(); int maxlen=0;
      for(int high=0;high<n;high++){
         m[s[high]]++;
         int k=high-low+1;
         while(m.size()<k){
           m[s[low]]--;
           if(m[s[low]]==0){
            m.erase(s[low]);
           } 
           low++;
           k=high-low+1;

         }
         if(m.size()==k){
            int len=high-low+1;
               maxlen=max(maxlen,len);
         }
      }
      return maxlen;
    }
};