class Solution {
struct val{
    int x, y;
    string s;
};
private:
    string move = "ULDR";
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};
    bool isValidDirection(int X, int Y, int n, int m){
        return  (X >= 0 && Y >= 0 && X < n && Y < m);
    }
public:
    void bfs(char &ch,int &x, int &y, vector<vector<char>> &key, string &res){
        vector<vector<bool>> vis(6, vector<bool>(5, 0));
        queue<val> q1;
        q1.push({x, y, ""});
        vis[x][y] = 1;

        while(!q1.empty()){
            int X = q1.front().x;
            int Y = q1.front().y;
            string S = q1.front().s;
            q1.pop();

            if(key[X][Y]==ch){
                S += '!';
                res += S, x = X, y = Y;
                return;
            }

            for(int i = 0; i < 4; i++){
                int XD = dx[i] + X;
                int YD = dy[i] + Y;
                if(isValidDirection(XD, YD, 6, 5) and !vis[XD][YD] and key[XD][YD]!='#'){
                    vis[XD][YD] = 1;
                    S += move[i];
                    q1.push({XD,YD,S});
                    S.pop_back();
                }
            }
        }
    }
    string alphabetBoardPath(string &target) {
        string res = "";
        int x = 0, y = 0;
        vector<vector<char>> key = {
            {'a', 'b', 'c', 'd', 'e'},
            {'f', 'g', 'h', 'i', 'j'},
            {'k', 'l', 'm', 'n', 'o'},
            {'p', 'q', 'r', 's', 't'},
            {'u', 'v', 'w', 'x', 'y'},
            {'z', '#', '#', '#', '#'}   };
        for(char &ch: target){
            bfs(ch, x, y, key, res);
        }
        return res;
    }
};