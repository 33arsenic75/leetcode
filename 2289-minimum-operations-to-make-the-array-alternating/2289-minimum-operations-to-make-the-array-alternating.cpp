class Solution
{
public:
    int minimumOperations(vector<int> &nums)
    {
        int mark[100001][2] = {}, i, j, k, res = 0;
        for (i = 0; i < nums.size(); i++)
            mark[nums[i]][i & 1]++;
        for (i = 1, j = k = 0; i <= 100000; i++)
            res = max(res, max(mark[i][0] + k, mark[i][1] + j)), j = max(j, mark[i][0]), k = max(k, mark[i][1]);
        return nums.size() - res;
    }
};