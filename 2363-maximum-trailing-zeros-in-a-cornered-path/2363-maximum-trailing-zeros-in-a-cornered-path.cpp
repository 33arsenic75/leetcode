class Solution {
public: 
    int numberoffives(int n){ //calculates k if n = p1 *p2* (5^k)
        int cnt=0;
        while(n%5==0){
            n/=5;
            cnt++;
        }
        return cnt;
    }
    int numberoftwos(int n){
        int cnt=0;
        while(n%2==0){
            n/=2;
            cnt++;
        }
        return cnt;
    }
public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<pair<int, int>>> five(m+1, vector<pair<int, int>>(n+1, {0, 0})); // pair.first represents rows prefix sum of number of fives and pair.second represents columns prefix sum of number of fives 
        vector<vector<pair<int, int>>> two(m+1, vector<pair<int, int>>(n+1, {0, 0}));
        
        for(int i=0; i<m; i++){
            for(int j=1; j<n+1; j++){
                
                    five[i][j].first= five[i][j-1].first+ numberoffives(grid[i][j-1]);
                    two[i][j].first= two[i][j-1].first+ numberoftwos(grid[i][j-1]);
               
            }
        } // calculate row prefix
        
        for(int j=0; j<n; j++){
            for(int i=1; i<m+1; i++){
                
                    five[i][j].second= five[i-1][j].second+ numberoffives(grid[i-1][j]);
                    two[i][j].second= two[i-1][j].second+ numberoftwos(grid[i-1][j]);
               
            }
        }// calculate col prefix

        int maxi=INT_MIN;
        for(int i=0; i<m; i++){ //                                                                                                       
            for(int j=0; j<n; j++){//                                                                                                     
			// Try all L shapes possible at a given joint(o) we can have at max 6 shapes  ----- o -------
			                                                                                                            
                //route1
                int f= numberoffives(grid[i][j]);
                int t= numberoftwos(grid[i][j]);
                int ans= min(two[i][j].first+ two[i][j].second+t,  five[i][j].first+ five[i][j].second+f);   
                //route 2
                int temp=0;
                temp= min(two[i][j].first+ (two[m][j].second-two[i][j].second), five[i][j].first+ (five[m][j].second-five[i][j].second));
                 ans=max(ans, temp);
                 // route 3
               temp= min(two[i][n].first-two[i][j].first+ (two[m][j].second-two[i][j].second)-t, five[i][n].first-five[i][j].first+ (five[m][j].second-five[i][j].second)-f);
                ans=max(ans, temp);
                // route 4
                  temp= min(two[i][n].first-two[i][j].first+ (two[i][j].second), five[i][n].first-five[i][j].first+ (five[i][j].second));
                ans=max(ans, temp);
                //route 5 && 6
                temp=min(two[i][n].first,  five[i][n].first);
                ans=max(ans, temp);
                temp=min(two[m][j].second,  five[m][j].second);
                ans=max(ans, temp);
                // cout<<ans<<" ";
                maxi= max(ans, maxi);       
            }
            // cout<<endl;
        }
        return maxi;
        
        
    }
};