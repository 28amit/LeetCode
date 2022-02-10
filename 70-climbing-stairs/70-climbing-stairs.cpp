class Solution {
public:
    int climbStairs(int n) {
        int a=1,b=2;
        if(n==1)
            return a;
        if(n==2)
            return b;
        int ans;
        for(int i=3;i<=n;i++){
            ans=a+b;
            a=b;
            b=ans;
        }
        return ans;
    }
};