// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    struct meet{
        int start;
        int end;
    };
    public:
    static bool comp(struct meet m1, meet m2){
        if(m1.end<m2.end)
            return true;
        else if(m2.end>m1.end)
            return false;
        return false;
    }
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        struct meet m[n];
        for(int i=0;i<n;i++){
            m[i].start=start[i];
            m[i].end=end[i];
        }
        sort(m,m+n,comp);
        int limit=m[0].end;
        int ans=1;
        for(int i=1;i<n;i++){
            if(m[i].start>limit){
                ans++;
                limit=m[i].end;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends