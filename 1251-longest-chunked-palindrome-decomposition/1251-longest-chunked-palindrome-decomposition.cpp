class Solution {
public:
    int longestDecomposition(string text) {
        int i=0, j=text.size()-1;
        int last=text.size();
        int ctr=0;
        int half=text.size()/2;
        while(i<=j && j>=half){
            if(i==j){
                ctr++;
                break;
            }
            
          
            if(text[i]==text[j]){
                int x=i;
                int y=j;
                int flag=0;
                while(y<last){
                    if(text[x]!=text[y]){
                        flag=1;
                        break;
                    }
                    x++;
                    y++;
                }
               
                if(flag==0){
                    ctr+=2;
                    last=j;
                    i=x;
                }
            }
            j--;
            
        }
        if(j<half && i>=half) return ctr;
        
        if(j<half && i<half)return ctr+1;
        return ctr;
    }
};