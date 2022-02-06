// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

//Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
	// Your code here
	vector<string>ans(N);
	queue<string>q;
	q.push("1");
	int i=0;
	while(i<N){
	    string tmp=q.front();
	    q.pop();
	    ans[i]=tmp;
	    q.push(tmp+"0");
	    q.push(tmp+"1");
	    i++;
	}
	return ans;
}


// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<string> ans = generate(n);
		for(auto it:ans) cout<<it<<" ";
		cout<<endl;
	}
	return 0;
}  // } Driver Code Ends