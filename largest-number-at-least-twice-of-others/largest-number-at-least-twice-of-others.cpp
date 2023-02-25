class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int size=nums.size(),largest=0,ans=0;
        for(int i=0;i<size;i++){
            if(nums[i]>=nums[largest])
                largest=i;
        }
        for(int i=0;i<size;i++){
            if(2*nums[i]>nums[largest]&&nums[i]!=nums[largest])
                return -1;
        }
        return largest;
    }
};