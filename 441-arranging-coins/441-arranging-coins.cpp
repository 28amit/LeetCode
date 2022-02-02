class Solution {
public:
    int arrangeCoins(int n) {
        long l=0,r=n;
        long mid=0,tmp=0;
        while(l<=r){
            mid=l+(r-l)/2;
            tmp=mid*(mid+1)/2;
            if(tmp==n)
                return (int)mid;
            if(tmp>n){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return (int)r;
    }
};