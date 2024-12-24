class Solution {
public:
    bool checkIfPangram(string s) {
        return set(s.begin(),s.end()).size() == 26;
    } 
};