class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int a = arr[0];
        int d = arr[1]-arr[0];
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=a+i*d)return false;
        }
        return true;
    }
};