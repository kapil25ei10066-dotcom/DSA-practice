class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>v(26,0);
        for(int i:text){
            v[i-'a']++;
        }
        int b=v['b'-'a'];
        int a=v['a'-'a'];
        int l=v['l'-'a']/2;
        int o=v['o'-'a']/2;
        int n=v['n'-'a'];
        int minvalue=min({b,a,l,o,n});
        return minvalue;
    }
};