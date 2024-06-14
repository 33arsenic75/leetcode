class Solution {
public:
    int rotatedDigits(int n) {
       if(n==1)
       return 0;
       if(n==2)
       return 1;

       string str=to_string(n);
       string temp=str;
       

      int s=str.size();
       bool valid=1;
       for(int i=0;i<s;i++){
        if(str[i]=='0'||str[i]=='1'||str[i]=='8'){
            continue;
        }
        else if(str[i]=='2'){
            str[i]='5';
        }
        else if(str[i]=='5'){
            str[i]='2';
        }
         else if(str[i]=='6'){
            str[i]='9';
        }
         else if(str[i]=='9'){
            str[i]='6';
        }
        else {
            valid=0;
            break;
        }
       }

       return (valid&(str!=temp))+rotatedDigits(n-1);
    }
};