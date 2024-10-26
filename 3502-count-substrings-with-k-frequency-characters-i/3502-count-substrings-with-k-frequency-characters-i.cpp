class Solution {
public:
    
    int numberOfSubstrings(string s, int threshold) {
        int n = s.size();
        vector<vector<int>>a(n+1,vector<int>(26,0));
        for(int i = 0 ; i < n ; i++){
            for(char c = 'a' ; c <= 'z' ; c++){
                a[i+1][c-'a'] = a[i][c-'a'] + (c == s[i]);
            }
        }   
        int total = 0;
        for(int i = 1 ; i <= n ; i++){
            int low = i , high = n , mid = i , ans = i - 1;
            while(low<=high){
                mid = low + (high-low)/2;
                bool possible = false;
                for(int k = 0 ; k < 26 ; k++){
                    if(a[mid][k] - a[i-1][k] >= threshold)possible = true;
                }
                if(possible){
                    high = mid - 1;
                }
                else{
                    ans = mid;
                    low = mid + 1;
                }
            }
            total += n - ans;
        }
        return total;
    }
};