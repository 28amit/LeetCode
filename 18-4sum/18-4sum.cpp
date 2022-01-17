class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int target2=target-(nums[i]+nums[j]);
                int front=j+1;
                int back=n-1;
                while(front<back){
                    if(nums[front]+nums[back]==target2){
                        ans.push_back({nums[i],nums[j],nums[front],nums[back]});
                        int tmp1=nums[front];
                        int tmp2=nums[back];
                        while(front<back&&nums[front]==tmp1)
                            front++;
                        while(front<back&&nums[back]==tmp2)
                            back--;
                    }
                    else if(nums[front]+nums[back]<target2)
                        front++;
                    else
                        back--;
                }
                while(j+1<n&&nums[j+1]==nums[j])j++;
            }
            while(i+1<n&&nums[i+1]==nums[i])i++;
        }
        return ans;
    }
};