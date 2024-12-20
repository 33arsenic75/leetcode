class Solution {
private:
    vector<int> addStrings(vector<int> num1, vector<int>& num2) {
        vector<int> ans;
        int carry = 0;
        for (int i = 0; i < num1.size() || i < num2.size() || carry; ++i) {
            int digit1 = i < num1.size() ? num1[i] : 0;
            int digit2 = i < num2.size() ? num2[i] : 0;
            int sum = digit1 + digit2 + carry;
            carry = sum / 10;
            ans.push_back(sum % 10);
        }

        return ans;
    }
    vector<int> multiplyOneDigit(string& firstNumber, char& secondNumberDigit,
                                 int numZeros) {
        vector<int> currentResult(numZeros, 0);
        int carry = 0;
        for (char firstNumberDigit : firstNumber) {
            int multiplication =
                (secondNumberDigit - '0') * (firstNumberDigit - '0') + carry;
            carry = multiplication / 10;
            currentResult.push_back(multiplication % 10);
        }
        if (carry) {
            currentResult.push_back(carry);
        }
        return currentResult;
    }

public:
    string multiply(string firstNumber, string secondNumber) {
        if (firstNumber == "0" || secondNumber == "0") {
            return "0";
        }
        reverse(firstNumber.begin(), firstNumber.end());
        reverse(secondNumber.begin(), secondNumber.end());
        vector<int> ans(firstNumber.size() + secondNumber.size(), 0);
        for (int i = 0; i < secondNumber.size(); ++i) {
            ans = addStrings(multiplyOneDigit(firstNumber, secondNumber[i], i),
                             ans);
        }
        if (ans[ans.size() - 1] == 0) {
            ans.pop_back();
        }
        string answer;
        for (int i = ans.size() - 1; i >= 0; --i) {
            answer.push_back(ans[i] + '0');
        }

        return answer;
    }
};