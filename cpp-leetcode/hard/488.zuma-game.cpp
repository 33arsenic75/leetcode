/*
 * @lc app=leetcode id=488 lang=cpp
 *
 * [488] Zuma Game
 */

// @lc code=start
using namespace std;
#include<string>
#include<stack>
#include<map>
class Solution {
public:
    int r,y,g,b,w;
    string hand; string board;
    stack<char>stk;
    map<char,int>mp;
    void initialize(){
        for(char c:hand){
            if(c=='R')r++;
            else if(c=='Y')y++;
            else if(c=='B')b++;
            else if(c=='G')g++;
            else w++;
        }
        mp['R']=r;mp['Y']=y;mp['B']=b;mp['G']=g;mp['W']=w;
        int i = 0;int j;char c;
        while(i < board.size()){
            c = board[i];
            if(stk.empty()){stk.push(c);i++;}
            else if(c==stk.top() && mp[c]>0){
                mp[c]--;
                stk.pop();
                while(i < board.size() && board[i]==c)i++;
            }
        }
    }
    int findMinStep(string board, string hand) {
            r=0;g=0;y=0;b=0;w=0;
            this->hand = hand;
            this->board = board;
            initialize();
    }
};
// @lc code=end

