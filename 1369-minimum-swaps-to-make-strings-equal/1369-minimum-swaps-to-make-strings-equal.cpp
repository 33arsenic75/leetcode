class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int xy = 0;
        int yx = 0;
        for(int i = 0; i < s1.size() ; i++){
            if(s1[i]=='x' && s2[i]=='y')xy++;
            else if(s1[i]=='y' && s2[i]=='x')yx++;
        }
        int ans = xy/2 + yx/2;
        if((xy-yx)%2!=0)return -1;
        ans+=2*(xy%2);
        return ans;
    }
};
// x x -> xy -> 1
// y y    xy

// x y -> 2
// y x
// yx = 2
// xy