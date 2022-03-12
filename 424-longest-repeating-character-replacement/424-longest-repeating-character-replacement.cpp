class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int>mp;
        int curr=0,maxx=INT_MIN;
        int ans=-1;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            maxx=max(maxx,mp[s[i]]);
            while((i-curr+1)-maxx>k){
                mp[s[curr]]--;
                curr++;
            }
            ans=max(ans,(i-curr+1));
        }
        return ans;
    }
};