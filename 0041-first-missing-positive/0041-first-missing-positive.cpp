class Solution {
public:
    vector<int>num;
    int n;
    void help(int i){
        /// i is the index
        if(num[i]==i+1)return;
        int value = num[i];
        if(value <= 0 || value>n)return;
        int replace = num[value-1];
        if(replace==value)return;
        num[i]=replace;
        num[value-1]=value;
        // cout<<i<<'\n';
        // for(int i = 0 ; i < n ; i++)cout<<num[i]<<' ';
        // cout<<'\n';
        help(i);
    }
    int firstMissingPositive(vector<int>& nums) {
        this->num = nums;
        n = num.size();
        for(int i = 0 ; i < n; i++)help(i);
        // for(int i = 0 ; i < n ; i++)cout<<num[i]<<' ';
        for(int i = 0 ; i < n ; i++){
            if(num[i]!=i+1)return i+1;
        }
        return n+1;
    }
};
/// 1 2 3 4