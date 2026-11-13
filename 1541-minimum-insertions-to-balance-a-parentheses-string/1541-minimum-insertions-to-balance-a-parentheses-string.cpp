class Solution {
public:
    int minInsertions(string s) {
        int r=0; int ans=0;
        stack<int>st;

        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                if(r==1 && !st.empty()){
                    if(st.top()=='('){
                        st.pop();
                        ans++;
                        r=0;
                    }}
                   else if(r==1 && st.empty()){
                    ans+=2;
                    r=0;
                   }
                   
                
                st.push('(');
                continue;
            }
            if(s[i]==')'){
                r++;

                if(r==2 && !st.empty()){
                    if(st.top()=='('){
                        st.pop();
                        r=0;
                    }}
                    else if(r==2 && st.empty()){
                        ans++;
                        r=0;
                    }
                
                
                continue;
            }

        }
     if(r == 1) {
    if(!st.empty()) {
        ans++;
        st.pop();
    }
    else {
        ans += 2;
    }
}

        int count=0;
        while(!st.empty()){
           st.pop();
           count++; 
        }
        ans+=count*2;
        return ans;
    }
};