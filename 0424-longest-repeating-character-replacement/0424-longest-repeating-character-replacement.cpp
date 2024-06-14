class Solution {
    
    /*
        Time Complexity : O(N)
        Space Complexity : O(26) == O(1) 
    */
    
public:
    int characterReplacement(string s, int k) {
        int n = s.length(), res = 0;
        int start = 0, end = 0, maxFreq = 0;
        map<int, int> freq;
        
        for(end=0; end<n; end++){
            freq[s[end]]++;
            maxFreq = max(maxFreq, freq[s[end]]);
            
            // len-maxFreq <= k, we have to find if the substring has atmost k different characters which we alter to make all the characters of the string equal
            while(end-start+1 - maxFreq > k){
                freq[s[start]]--;
                start++;
            }
            
            res = max(res, end-start+1);
        }
        
        return res;
    }
};