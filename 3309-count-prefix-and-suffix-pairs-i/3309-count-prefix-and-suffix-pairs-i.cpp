const int MAX_SIZE = 2e5 + 5, BASE1 = 29, BASE2 = 31, MOD_A = 1e9 + 7, MOD_B = 1e9 + 9;
int power1[MAX_SIZE], inverse1[MAX_SIZE], power2[MAX_SIZE], inverse2[MAX_SIZE];
int add(int a, int b, int mod) {
    return (a + b) % mod;
}
int sub(int a, int b, int mod) {
    return ((a - b) % mod + mod) % mod;
}
int mul(int a, int b, int mod) {
    return 1ll * a * b % mod;
}
int fp(int base, int exp, int mod) {
    if (!exp) return 1;
    int result = fp(base, exp >> 1, mod);
    result = mul(result, result, mod);
    if (exp & 1)
        result = mul(result, base, mod);
    return result;
}
struct StringHash {
    vector <pair<int, int>> hashPrefix;
    StringHash(const string &s) {
        hashPrefix.resize(s.size() + 1);
        for (int i = 0; i < int(s.size()); ++i)
            hashPrefix[i + 1] = make_pair(add(hashPrefix[i].first, mul(power1[i], s[i] - 'a' + 1, MOD_A), MOD_A),
                                         add(hashPrefix[i].second, mul(power2[i], s[i] - 'a' + 1, MOD_B), MOD_B));
    }
    pair<int, int> getHash() const {
        return hashPrefix.back();
    }
    pair<int, int> getRange(int left, int right) const {
        return make_pair(mul(inverse1[left], sub(hashPrefix[right + 1].first, hashPrefix[left].first, MOD_A), MOD_A),
                         mul(inverse2[left], sub(hashPrefix[right + 1].second, hashPrefix[left].second, MOD_B), MOD_B));
    }
    static void prepare() {
        power1[0] = inverse1[0] = power2[0] = inverse2[0] = 1;
        int inv1 = fp(BASE1, MOD_A - 2, MOD_A);
        int inv2 = fp(BASE2, MOD_B - 2, MOD_B);
        for (int i = 1; i < MAX_SIZE; ++i) {
            power1[i] = mul(power1[i - 1], BASE1, MOD_A);
            inverse1[i] = mul(inverse1[i - 1], inv1, MOD_A);
            power2[i] = mul(power2[i - 1], BASE2, MOD_B);
            inverse2[i] = mul(inverse2[i - 1], inv2, MOD_B);
        }
    }
};
struct TrieNode {
    TrieNode *next[26]{};
    int wordEndCount = 0;
    long long insert(const string &s, set<int>& validLengths) {
        long long result = 0;
        TrieNode *currentNode = this;
        int length = 1;
        for (auto ch : s) {
            int idx = ch - 'a';
            if (currentNode->next[idx] == nullptr) currentNode->next[idx] = new TrieNode;
            currentNode = currentNode->next[idx];
            if (validLengths.count(length)) result += currentNode->wordEndCount;
            length++;
        }
        currentNode->wordEndCount++;
        return result;
    }
};

class Solution {
public:
    long long countPrefixSuffixPairs(vector<string>& strings) {
        StringHash::prepare();
        long long answer = 0;
        TrieNode rootNode;
        for (auto& str : strings) {
            StringHash hashInstance(str);
            int len = str.size();
            set<int> validLengths;
            for (int l = 1; l <= len; l++) {
                if (hashInstance.getRange(0, l - 1) == hashInstance.getRange(len - l, len - 1)) {
                    validLengths.insert(l);
                }
            }
            answer += rootNode.insert(str, validLengths);
        }
        return answer;
    }
};