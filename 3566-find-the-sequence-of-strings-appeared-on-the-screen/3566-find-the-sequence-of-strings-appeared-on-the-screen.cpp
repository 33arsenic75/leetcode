class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string>ans;
        vector<string>prev,curr;
        int n = target.size();
        for(int i = 0 ; i < n ; i++){
            string s = target.substr(0,i);
            for(int j = 0 ; j <= target[i] - 'a' ; j++){
                ans.push_back(s + std::string(1, 'a' + j));
            }
        }
        return ans;
    }
};