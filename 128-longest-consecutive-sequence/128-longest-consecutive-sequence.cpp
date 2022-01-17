class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]=1;
        }
        
        int ans=0;
        for(auto i : mp){
            int num=i.first;
            int parent=num-1;
            if(mp.find(parent)==mp.end()){
                int next=num+1;
                int cnt=1;
                while(mp.find(next)!=mp.end()){
                    next++;
                    cnt++; 
                }
                if(cnt>ans){
                    ans=cnt; 
                }
            }
        }
        return ans;
    }
};