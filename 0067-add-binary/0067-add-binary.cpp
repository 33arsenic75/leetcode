class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size();
        int m=b.size();
        string str="";
        int i=n-1,j=m-1;
        int c=0;
        while(i>=0&&j>=0){
            int a1=a[i]-'0',a2=b[j]-'0';
            a1=a1+a2+c;
            if(a1==2){
                str+='0';
                c=1;
            }
            else if(a1==3){
                str+='1';
                c=1;
            }
            else{
                str+=a1+'0';
                c=0;
            }
            i--;j--;
        }
        while(i>=0){
            int a1=a[i]-'0';
            a1+=c;
            if(a1==2){
                str+='0';
                c=1;
            }else{
                str+=a1+'0';
                c=0;
            }
            i--;
        }
        while(j>=0){
            int a1=b[j]-'0';
            a1+=c;
            if(a1==2){
                str+='0';
                c=1;
            }else{
                str+=a1+'0';
                c=0;
            }
            j--;
        }
        if(c){
            str+='1';
        }
        reverse(str.begin(),str.end());
        return str;
    }
};