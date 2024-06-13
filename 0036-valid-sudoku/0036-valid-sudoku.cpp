class Solution {
public:
    bool help(int x, int y,vector<vector<char>>&board){
        vector<int>a(10,0);
        char c;
        for(int i = x ; i < x+3 ; i++){
            for(int j = y ; j < y + 3; j++){
                c = board[i][j];
                if(c=='.')continue;
                a[c-'0']++;
            }
        }
        for(int i:a){
            if(i>1)return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int>a(10,0);
        char c;
        for(int i = 0; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                c = board[i][j];
                if(c=='.')continue;
                a[c-'0']++;
            }
            for(int i:a){
                if(i>1)return false;
            }
            a = vector<int>(10,0);
        }
        for(int i = 0; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++){
                c = board[j][i];
                if(c=='.')continue;
                a[c-'0']++;
            }
            for(int i:a){
                if(i>1)return false;
            }
            a = vector<int>(10,0);
        }
        for(int i = 0 ; i < 9 ; i+=3){
            for(int j = 0 ; j < 9 ; j+=3){
                if(!help(i,j,board))return false;
            }
        }
        return true;
    }
};