class Solution {
public:
    int longestPalindrome(string s) {
       vector<int> freq(52, 0);

    for (char c : s) {
        if (c >= 'A' && c <= 'Z') {
            freq[c - 'A']++;
        } else if (c >= 'a' && c <= 'z') {
            freq[c - 'a' + 26]++;
        }
    }
    int fuck=0;
    for(int i=0;i<52;i++){
       if(freq[i]%2!=0){
        freq[i]--;
        fuck++;
       }
    }
    int count=0; 
    for(int i=0;i<52;i++){
        count+=freq[i];
    }
    if(fuck!=0){
      return count+1;
    }
    return count;
    
    }
};