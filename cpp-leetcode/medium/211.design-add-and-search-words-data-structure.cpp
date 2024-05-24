/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 */

// @lc code=start
class WordDictionary {
public:
    int count;
    vector<WordDictionary*>mp;
    WordDictionary() {
        mp = vector<WordDictionary*>(26, nullptr);
        count = 0;
    }
    
    void addWord(string word) {
        addWord(word,0);        
    }
    void addWord(string word, int i){
        if(word.size() == i)count++;
        else{
            if(mp[word[i]-'a']!=nullptr)mp[word[i]-'a']->addWord(word,i+1);
            else{ 
                mp[word[i]-'a']=new WordDictionary();
                mp[word[i]-'a']->addWord(word,i+1);
            }
        }
    }
    bool search(string word, int i) {
        if (word.size() == i)
            return (count > 0);
        
        if (mp[word[i] - 'a'] == nullptr) {
            mp[word[i] - 'a'] = new WordDictionary();
        } else if (word[i] != '.') {
            return mp[word[i] - 'a']->search(word, i + 1);
        }

        bool f = false;
        for (int j = 0; j < 26; ++j) {
            if (mp[j] != nullptr) {
                f |= mp[j]->search(word, i + 1);
            }
        }
        return f; 
    }

    bool search(string word) {
        return search(word,0);
    }
};


/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end

