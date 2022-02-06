class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=cost.size();
        int tank=0,total=0,ans=0;
        for(int i=0;i<n;i++){
            total+=gas[i]-cost[i];
            tank+=gas[i]-cost[i];
            if(tank<0){
                tank=0;
                ans=i+1;
            }
        }
        if(total<0)
            return -1;
        return ans;
    }
};