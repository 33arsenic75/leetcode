class Solution {
public:
    vector<int> countFreq(string& word){
	vector<int> freq(26);
	for(auto& c : word) freq[c - 'a']++;
	return freq;
}
vector<string> wordSubsets(vector<string>& word1, vector<string>& word2) {
	vector<int> Maxfreq(26); 
	vector<string> ans;
	for(auto& word : word2){
		vector<int> freq = countFreq(word);            
		for(int i = 0; i < 26; i++) Maxfreq[i] = max(Maxfreq[i], freq[i]);
	}        
	for(auto& word : word1){
		vector<int> freq = countFreq(word);            
		int i = 0;
		for(;i < 26; i++) if(freq[i] < Maxfreq[i]) break;
		if(i == 26) ans.push_back(word);
	}
	return ans;
        
    }
};