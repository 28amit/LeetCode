class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(mp[nums[i]-1]<=0){
                int tmp=nums[i];
                int anstmp=0;
                while(mp[tmp]>=1){
                    anstmp++;
                    tmp++;
                }
                ans=max(ans,anstmp);
            }
        }
        return ans;
    }
};