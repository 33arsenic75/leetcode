class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
            vector<int>trouble;
            int n = nums.size();
            for(int i = 1 ; i < n ; i++){
                if((nums[i]-nums[i-1])%2==0){
                    trouble.push_back(i);
                }
            }
            trouble.push_back(1e9);
            vector<bool>result;
            // for(int t:trouble)cout<<t<<" ";
            // cout<<'\n';
            for(vector<int>v:queries){
                int from = v[0], to = v[1];
                if(from==to){
                    result.push_back(true);
                    continue;
                }
                int low = 0, high = trouble.size()-1 , ans = 0 , mid = 0;
                while(low<=high){
                    mid = low + (high-low)/2;
                    if(trouble[mid]>from){
                        ans = mid;
                        high = mid - 1;
                    }
                    else{
                        low = mid + 1;
                    }
                }
                // cout<<trouble[ans]<<"\n";
                if(trouble[ans]<=to)result.push_back(false);
                else result.push_back(true);
            }
            return result;
    }
};