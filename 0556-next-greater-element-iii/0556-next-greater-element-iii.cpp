class Solution {
public:
    void reverse(string &s,int l,int h){
        while(l<=h){
            swap(s[l++],s[h--]);
        }
    }
    bool nextPermutation(string &num){
        int n = num.size();

        int i;
        for(i=n-2;i>=0;i--){
            if(num[i]<num[i+1]) break;
        }
        if(i==-1)   return false;

        for(int j=n-1;j>=i;j--){
            if(num[j]>num[i]){
                swap(num[i],num[j]);
                break;
            }
        }
        reverse(num,i+1,n-1);

        if(stol(num)>INT_MAX)   return false;
        return true;
    }
    int nextGreaterElement(int n) {
        string num = to_string(n);
        if(nextPermutation(num))   
            return stol(num);
        return -1;
    }
};