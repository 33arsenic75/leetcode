class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j=numbers.size()-1;int sum;
        while(i<j){
            sum=numbers[i]+numbers[j];
            if(sum<target)i++;
            else if(sum>target)j--;
            else return vector<int>{i+1,j+1};
        }
        return vector<int>{0,0};
    }
};