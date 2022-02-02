class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        if(nums.size()==0)
            return ans;
        int l=0,r=nums.size()-1,mid=0;
        while(l<r){
            mid=l+(r-l)/2;
            if(target>nums[mid])
                l=mid+1;
            else
                r=mid;
        }
        if(nums[l]!=target)
            return ans;
        else
            ans[0]=l;
        
        r=nums.size()-1;
        while(l<r){
            mid=l+(r-l)/2+1;
            if(nums[mid]>target)
                 r=mid-1;
            else
                l=mid;
               
        }
        ans[1]=r;
        return ans;
    }
};