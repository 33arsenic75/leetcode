class Solution {
public:

/// XXX
/// XOO
/// OO_
    bool validTicTacToe(vector<string>& board) {
        int xcount = 0;
        int ocount = 0;
        int x, o;
        for(string s: board){
            xcount += count(s.begin(), s.end(), 'X');
            ocount += count(s.begin(), s.end(), 'O');
        }
        if((xcount>ocount+1) || (ocount>xcount))return false;
        
        bool xwin = false;
        bool owin = false;

        for(int i = 0; i < 3 ; i++){
            x = 0;
            o = 0;
            for(int j = 0; j < 3 ;j++){
                x += (board[i][j]=='X');
                o += (board[i][j]=='O');
            }
            if(x==3)xwin=true;
            if(o==3)owin=true;

            x = 0;
            o = 0;
            for(int j = 0; j < 3 ;j++){
                x += (board[j][i]=='X');
                o += (board[j][i]=='O');
            }
            if(x==3)xwin=true;
            if(o==3)owin=true;
        }
        x = 0;
        o = 0;
        for(int i = 0; i < 3 ; i++){
            x += (board[i][i]=='X');
            o += (board[i][i]=='O');
        }
        if(x==3)xwin=true;
        if(o==3)owin=true;

        x = 0;
        o = 0;
        for(int i = 0; i < 3 ; i++){
            x += (board[i][2-i]=='X');
            o += (board[i][2-i]=='O');
        }
        if(x==3)xwin=true;
        if(o==3)owin=true;

        if(xwin && ocount==xcount)return false;
        if(owin && xcount==ocount+1)return false;
        return !xwin || !owin;



    }
};