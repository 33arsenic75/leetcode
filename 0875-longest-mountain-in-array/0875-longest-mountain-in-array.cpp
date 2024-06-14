class Solution {
public:
    int longestMountain(vector<int>& a) {
        if(a.empty())return 0;
        int l=0,h=0,m=0;
        for(int i=0;i<a.size()-1;i++){
            if(a[i]<a[i+1]){
                if(l&&h){
                    m=max(m,l+h+1);
                    l=0; h=0;
                }
                l++;
            }
            else if(a[i]>a[i+1]){
                if(l)h++;
            }
            else {
                if(l&&h)m=max(m,l+h+1);
                l=0; h=0;
            }
        }
        if(l&&h)m=max(m,l+h+1);
        return m;
    }
};