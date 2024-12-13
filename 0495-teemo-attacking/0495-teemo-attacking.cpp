class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        
        int c=0;

        for (int i = 0; i < timeSeries.size()-1; i++) {
            int t=timeSeries[i];
            for(int k=t;k<t+duration;k++)
            {
                if(k<timeSeries[i+1])
                   c++;
                else
                  break;
               
            }
          
        }

        return c+duration;
    }
};