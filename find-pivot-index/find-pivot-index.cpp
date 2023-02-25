class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int size=nums.size(),sum=0,curr_sum=0;
        if(size==1){
            return 0;
        }
        for(int i=0;i<size;i++){
            sum+=nums[i];
        }
        for(int i=0;i<size;i++){
            sum-=nums[i];
            if(curr_sum==sum)
                return i;
            curr_sum+=nums[i];
        }
        return -1;
    }
};