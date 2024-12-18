class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        string str = to_string(nums[0]);
        if(nums.size() == 1)
            return str;
        if(nums.size() == 2) {
            str += "/" + to_string(nums[1]);
            return str;
        }
        str += "/(" + to_string(nums[1]);
        for(int i=2; i<nums.size(); i++)
            str += "/" + to_string(nums[i]);
        str += ")";
        return str;
    }
};