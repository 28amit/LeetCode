class Solution {
public:
    bool dfs(int n, vector<vector<int>>&adj,vector<bool>&vis,vector<bool>&dvis){
        vis[n]=1;
        dvis[n]=1;
        for(int i=0;i<adj[n].size();i++){
            if(!vis[adj[n][i]]){
                if(dfs(adj[n][i],adj,vis,dvis))
                    return 1;
            }
            else if(dvis[adj[n][i]])
                return 1;
        }
        dvis[n]=0;
        return 0;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<bool>vis(numCourses,0);
        vector<bool>dvis(numCourses,0);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfs(i,adj,vis,dvis))
                    return 0;
            }
        }
        return 1;
    }
};