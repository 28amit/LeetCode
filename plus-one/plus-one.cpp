class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int sum=0,carry=1,curr=0;
        vector<int> ans;
        for(int i=digits.size()-1;i>=0;i--){
            curr=digits[i]+carry;
            curr%=10;
            ans.push_back(curr);
            carry=(digits[i]+carry)/10;
        }
        if(carry!=0)
            ans.push_back(carry);
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};