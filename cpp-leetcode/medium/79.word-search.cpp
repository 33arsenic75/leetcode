/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
class Solution {
public:
    int n,m;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    vector<vector<bool>>vis;
    string s;
    int sz;
    vector<vector<char>>brd;
    bool ans;
    bool inbound(int i,int j){
        return (i>=0)&&(i<m)&&(j>=0)&&(j<n);
    }
    void bt(int i,int j,int idx){
        if(idx == sz){
            ans = true;
            return;
        }
        for(int k = 0;k<4;k++){
            if(inbound(i+dx[k],j+dy[k]) && brd[i+dx[k]][j+dy[k]]==s[idx] && !vis[i+dx[k]][j+dy[k]]){
                vis[i+dx[k]][j+dy[k]]=true;
                bt(i+dx[k],j+dy[k],idx+1);
                vis[i+dx[k]][j+dy[k]]=false;
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board[0].size();
        m = board.size();
        ans = false;
        brd = board;
        vis = vector<vector<bool>>(m,vector<bool>(n,false));
        s = word;
        sz = s.size();
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(brd[i][j]==s[0]){
                    vis[i][j]=true;
                    bt(i,j,1);
                    vis[i][j]=false;
                }
            }
            if(ans)break;
        }
        return ans;
    }
};
// @lc code=end

