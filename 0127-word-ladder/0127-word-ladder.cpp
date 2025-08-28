class Solution {
public:
    bool ngh(string s, string j){
        int cnt = 0;
        for(int i = 0 ; i < s.size() ; i++)cnt+=(s[i]!=j[i]);
        return (cnt<=1);
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        int n = wordList.size();
        int idx = - 1;
        vector<vector<int>>adj(n);
        for(int i = 0 ; i < n ; i++){
            if(wordList[i] == endWord)idx = i;
            for(int j = i+1 ; j < n ; j++){
                if(ngh(wordList[i],wordList[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<int>dis(n,INT_MAX);
        dis[n-1]=1;
        queue<int>q;
        q.push(n-1);
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(int to: adj[top]){
                if(dis[to]!=INT_MAX)continue;
                dis[to]=1+dis[top];
                q.push(to);
            }
        }
        // for(int i = 0 ; i < n ; i++){
            // cout<<i<<" : ";
            // for(int to: adj[i])cout<<to<<" ";
            // cout<<'\n';
        // }
        // for(int i = 0 ; i < n ; i++)cout<<dis[i]<<" ";
        return (idx == -1) || (dis[idx]==INT_MAX) ? 0 : dis[idx];
    }
};