class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        function<bool(long long)>check = [&](long long capacity){
            long long day = 0;
            long long curr = 0;
            for(int load:weights){
                if(curr + load <= capacity){
                    curr += load;
                }
                else{
                    curr = load;
                    day ++;
                }
            }
            day ++;
            return (day<=days);
        };
        long long low = *max_element(weights.begin(),weights.end());
        long long high = accumulate(weights.begin(),weights.end(),0ll);
        long long ans = 0, mid = 0;
        while(low <= high){
            mid = low + (high-low)/2;
            if(check(mid)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};