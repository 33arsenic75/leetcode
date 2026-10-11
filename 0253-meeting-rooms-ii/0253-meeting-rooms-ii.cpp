class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& itv) {
        int freerooms = 0;
        int usedrooms = 0;
        int n = itv.size();
        vector<vector<int>>time(2*n,vector<int>(2,0));
        for(int i = 0 ; i < n ; i++){
            time[2*i][0] = itv[i][0];
            time[2*i][1] = 1;
            time[2*i+1][0] = itv[i][1];
            time[2*i+1][1] = -1;
        }
        sort(time.begin(), time.end());

        for(vector<int>&r: time){
            if(r[1]==1){
                if(freerooms == 0){
                    usedrooms ++;
                }
                else{
                    freerooms --;
                }
            }
            else{
                freerooms ++;
            }
        }
        return usedrooms;
    }
};