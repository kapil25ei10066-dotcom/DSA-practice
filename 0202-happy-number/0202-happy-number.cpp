class Solution {
public:
int sqsum(int x){
    int sum=0;
    while(x!=0){
    int lastdig=x%10;
   
    sum+=lastdig*lastdig;
    x=x/10;
    }
    return sum;

};
    bool isHappy(int n) {
        if(sqsum(n)==1){return true;}
       int fast=n; int slow=n;
        while(fast!=1 ){
          slow=sqsum(slow);
          fast=sqsum(sqsum(fast));
         
          if(slow==fast){
            return false;
          }
        }
        return true;
    }
};