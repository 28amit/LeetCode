class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=nums[0];
        int cnt=1;
        for(int i=1;i<nums.size();i++){
            if(cnt==0){
                ans=nums[i];
                cnt++;
            }
            else{
                if(nums[i]==ans)
                    cnt++;
                else
                    cnt--;
            }
        }
        if(cnt==0)
            return -1;
        cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ans){
                cnt++;
            }
        }
        if(cnt>nums.size()/2)
            return ans;
        return -1;
    }
};