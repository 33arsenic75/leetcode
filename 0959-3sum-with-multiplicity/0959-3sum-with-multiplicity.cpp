class Solution {
public:
    int mod = 1e9+7;
    int threeSumMulti(vector<int>& arr, int target) {
        int n = arr.size();
        sort(arr.begin(),arr.end());

        int count = 0;
        for(int i=0;i<n;i++){
            int req = target - arr[i];
            int l=i+1, h=n-1;
            while(l<h){
                if(arr[l]+arr[h]>req)   h--;
                else if(arr[l]+arr[h]<req)  l++;
                else if(arr[l]!=arr[h]){
                    int c1 = 1, c2 = 1;
                    while(l+1<h && arr[l]==arr[l+1]){
                        c1++;
                        l++;
                    }    
                    while(h-1>l && arr[h]==arr[h-1]){
                        c2++;
                        h--;
                    }   
                    count = (count + (c1*c2)%mod)%mod; 
                    l++;
                    h--;
                }
                else{
                    int m = h-l+1;
                    // mC2 pairs
                    count = (count + (m*(m-1)/2)%mod)%mod;
                    break;
                }
            }
        }
        return count%mod;
    }
};