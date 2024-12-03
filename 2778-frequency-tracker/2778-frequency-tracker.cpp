#include <map>
#include <set>

class FrequencyTracker {
private:
    std::map<int, int> numfreq; // stores the frequency of each number
    std::map<int, std::set<int>> freqnum; // stores the set of numbers for each frequency

public:
    FrequencyTracker() {
        // Constructor
    }
    
    void add(int number) {
        int f = numfreq[number];
        freqnum[f].erase(number);
        if (freqnum[f].empty()) {
            freqnum.erase(f);
        }
        freqnum[f + 1].insert(number);
        numfreq[number] = f + 1;
    }
    
    void deleteOne(int number) {
        int f = numfreq[number];
        if (f == 0) return;
        freqnum[f].erase(number);
        if (freqnum[f].empty()) {
            freqnum.erase(f);
        }
        if (f != 1) {
            freqnum[f - 1].insert(number);
        }
        numfreq[number] = f - 1;
    }
    
    bool hasFrequency(int frequency) {
        return !freqnum[frequency].empty();
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
