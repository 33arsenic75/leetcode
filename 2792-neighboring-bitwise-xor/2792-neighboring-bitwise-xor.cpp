class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int x = 0;
        for(int n:derived)x^=n;
        return (x==0);
    }
};