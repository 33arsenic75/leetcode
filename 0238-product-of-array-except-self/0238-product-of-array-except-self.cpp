class Solution
{
    public:
        vector<int> productExceptSelf(vector<int> &nums)
        {

            int n = nums.size();
            int zero = 0;
            int tmp = 1;
            for (int i = 0; i < n; i++)
            {
                if (nums[i] != 0)
                {
                    tmp *= nums[i];
                }
                else
                {
                    zero++;
                }
            }

            for (int i = 0; i < n; i++)
            {
                if (zero == 1)
                {

                    if (nums[i] != 0){
                        nums[i] = 0;
                    }
                    else{
                        nums[i] = tmp;
                    }
                }else if(zero>1){
                    nums[i]=0;
                }else{
                    nums[i]=tmp/nums[i];
                }
            }
            return nums;
        }
};