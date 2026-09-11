class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        //minimumarray
      
        int n=nums.size();
        stack<pair<int,int>>lst;
        stack<pair<int,int>>rst;
        vector<int>minleft(n);
        vector<int>minright(n);
        vector<int>minarray(n);
        //rightminimum of evry element
        for(int i=n-1;i>=0;i--){
           int cnt=1;
           while(!rst.empty() && nums[i]<=rst.top().first){
             cnt=cnt+rst.top().second;
               rst.pop();
               
           }
           minright[i]=cnt;
           rst.push({nums[i],cnt});

        }
        //leftminimum of every element
        for(int i=0;i<n;i++){
            int cnt=1;
            while(!lst.empty() && nums[i]<lst.top().first){
                 cnt=cnt+lst.top().second;
                lst.pop();
               
            }
            minleft[i]=cnt;
            lst.push({nums[i],cnt});
        }
        //min array
       for(int i=0;i<n;i++){
        minarray[i]=minleft[i]*minright[i];
       }


       //maximumarray
        stack<pair<int,int>>l2st;
        stack<pair<int,int>>r2st;
        vector<int>maxleft(n);
        vector<int>maxright(n);
        vector<int>maxarray(n);
         //rightmax of evry element
        for(int i=n-1;i>=0;i--){
           int cnt=1;
           while(!r2st.empty() && nums[i]>=r2st.top().first){
             cnt=cnt+r2st.top().second;
               r2st.pop();
              
           }
           maxright[i]=cnt;
           r2st.push({nums[i],cnt});

        }
         //leftmax of every element
        for(int i=0;i<n;i++){
            int cnt=1;
            while(!l2st.empty() && nums[i]>l2st.top().first){
                 cnt=cnt+l2st.top().second;
                l2st.pop();
                
            }
            maxleft[i]=cnt;
            l2st.push({nums[i],cnt});
        }
          //max array
       for(int i=0;i<n;i++){
        maxarray[i]=maxleft[i]*maxright[i];
       }
      long long minsum = 0;
        long long maxsum = 0;

        for (int i = 0; i < n; i++) {
            minsum += (long long)nums[i] * minarray[i];
            maxsum += (long long)nums[i] * maxarray[i];
        }

        long long ans = maxsum - minsum;
        return ans;

    }
};