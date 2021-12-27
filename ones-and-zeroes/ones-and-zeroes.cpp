class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s=strs.size();
        int one,zero;
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<s;i++){
            one=zero=0;
            for(int j=0;j<strs[i].size();j++){
                if(strs[i][j]=='0')
                    zero++;
                else
                    one++;
            }
            for(int k=n;k>=one;k--){
                for(int l=m;l>=zero;l--){
                    dp[k][l]=max(dp[k][l],dp[k-one][l-zero]+1);
                }
            }
        }
        return dp[n][m];
    }
};