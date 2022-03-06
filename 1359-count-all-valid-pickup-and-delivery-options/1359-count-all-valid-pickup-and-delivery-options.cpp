class Solution {
public:
    int countOrders(int n) {
        long long mod = 1000000007;
        long long dp[n+5];
        dp[1]=1;
        dp[2]=6;
        for(long long i=3;i<=n;i++) {
            long long fm = (i*dp[i-1])%mod;
            long long onex = i-1;
            long long allx = (onex*i)%mod;
            int nn = (dp[i-1]*2)%mod;
            long long sm = (allx*nn)%mod;
            dp[i] = ((fm%mod)+(sm%mod))%mod;
        }
        return dp[n];
    }
};