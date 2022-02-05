class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int s=0,e=n-1,m=0;
        while(m<=e){
            if(nums[m]==2){
                swap(nums[m],nums[e]);
                e--;
            }
            else if(nums[m]==0){
                swap(nums[m],nums[s]);
                s++;
                m++;
            }
            else{
                m++;
            }
        }
    }
};