class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size(),s=0,e=n-1,mid=0;
        vector<int>ans(2,-1);
        while(s<=e){
            mid=s+(e-s)/2;
            if(nums[mid]==target){
                e=mid-1;
                ans[0]=mid;
            }
            else if(nums[mid]>target)
                e=mid-1;
            else
                s=mid+1;
        }
        if(ans[0]==-1)
            return ans;
        s=0;
        e=n-1;
        mid=0;
        while(s<=e){
            mid=s+(e-s)/2;
            if(nums[mid]==target){
                s=mid+1;
                ans[1]=mid;
            }
            else if(nums[mid]>target)
                e=mid-1;
            else
                s=mid+1;
        }
        return ans;
        
    }
};