class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int result = 0;
        int n = events.size();
        vector<int>best(n);
        best[n-1]=events[n-1][2];
        for(int i = n - 2 ; i >= 0 ; i--){
            best[i] = max(best[i+1],events[i][2]);
        }
        // for(int i = 0 ; i < n ; i++){
        //     cout<<events[i][0]<<" "<<events[i][1]<<" "<<events[i][2]<<" "<<best[i]<<'\n';
        // }
        for(int i = 0 ; i < n ; i++){
            int low = i+1 , high = n-1 , mid = 0 , ans = i;
            while(low<=high){
                mid = low + (high-low)/2;
                if(events[mid][0]>events[i][1]){
                    ans = mid;
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            // cout<<i<<" "<<ans<<"\n";
            if(ans!=i){
                result = max(result,events[i][2]+best[ans]);
            }
            else{
                result = max(result,events[i][2]);
            }
        }
        return result;
    }
};