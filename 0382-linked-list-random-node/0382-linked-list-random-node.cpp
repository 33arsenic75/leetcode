#include <vector>
#include <cstdlib> // for rand()
using namespace std;

class Solution {
public:
    vector<int> q;
    int n;

    Solution(ListNode* head) {
        while (head) {
            q.push_back(head->val);
            head = head->next;
        }
        n = q.size();
    }
    
    int getRandom() {
        int idx = rand() % n;
        return q[idx];
    }
};
