typedef long long ll;
typedef long long ll;
template <ll MOD=(ll)1e9+7>
struct Modular {
  int value;
  static const int MOD_value = MOD;

  Modular(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
  Modular(long long a, long long b) : value(0){ *this += a; *this /= b;}

  Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
  Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
  Modular& operator*=(Modular const& b) {value = (long long)value * b.value % MOD;return *this;}

  friend Modular mexp(Modular a, long long e) {
    Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
    return res;
  }
  friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }

  Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
  friend Modular operator+(Modular a, Modular const b) { return a += b; }
  friend Modular operator-(Modular a, Modular const b) { return a -= b; }
  friend Modular operator-(Modular const a) { return 0 - a; }
  friend Modular operator*(Modular a, Modular const b) { return a *= b; }
  friend Modular operator/(Modular a, Modular const b) { return a /= b; }
  friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}
  friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
  friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}
};
using Mint = Modular<>;

class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        ll sum = accumulate(nums.begin(), nums.end(), 0LL) + k;

        Mint ans = 1;
        int i = n - 1;

        for (; i >= 0; i--) {
            if (nums[i] > sum / (i + 1)) {
                ans *= nums[i];
                sum -= nums[i];
            } else {
                break;
            }
        }

        ll num1 = sum / (i + 1);
        ll count2 = sum % (i + 1);
        ll num2 = num1 + (count2 > 0);
        ll count1 = (i + 1) - count2;

        while (count1--) ans *= num1;
        while (count2--) ans *= num2;

        return ans.value;
    }
};