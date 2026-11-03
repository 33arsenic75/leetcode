class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        vector<vector<int>> ans;

        for(int i = 0; i < min(k, n1); i++){
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        while(k-- && !pq.empty()){
            auto [sum, i, j] = pq.top();
            pq.pop();

            ans.push_back({nums1[i], nums2[j]});

            if(j + 1 < n2){
                pq.push({nums1[i] + nums2[j+1], i, j+1});
            }
        }

        return ans;
    }
};