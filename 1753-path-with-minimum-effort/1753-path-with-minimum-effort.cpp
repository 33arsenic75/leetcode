
class Edge{
public:
    int weight;
    int i,j;
    bool operator>(Edge&o){
        return weight>o.weight;
    }
    Edge(){
        i=0;j=0;
        weight=0;
    }
    Edge(int weight,int i,int j){
        this->weight=weight;
        this->i=i;
        this->j=j;
    }

};


class Solution {
public:
    int r,c;
    bool isvalid(int i,int j){
        if(0<=i && i<r && 0<=j && j<c)return true;
        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        r=heights.size();
        c=heights[0].size();
        vector<Edge*> v[r][c];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(isvalid(i+1,j)){
                    int w=abs(heights[i+1][j]-heights[i][j]);
                    v[i][j].push_back(new Edge(w,i+1,j));
                }
                if(isvalid(i-1,j)){
                    int w=abs(heights[i-1][j]-heights[i][j]);
                    v[i][j].push_back(new Edge(w,i-1,j));
                }
                if(isvalid(i,j+1)){
                    int w=abs(heights[i][j]-heights[i][j+1]);
                    v[i][j].push_back(new Edge(w,i,j+1));
                }
                if(isvalid(i,j-1)){
                    int w=abs(heights[i][j]-heights[i][j-1]);
                    v[i][j].push_back(new Edge(w,i,j-1));
                }
            }
        }

        ///priority_queue<Edge*,vector<Edge*>,greater<Edge*>>pq;
        priority_queue< pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>> ,greater<pair<int,pair<int,int>>> >pq;
       ///pq.push(new Edge(0,0,0));
        pq.push({0,{0,0}});///weigh,i,j
        vector<vector<bool>>vis(r,vector<bool>(c,false));
        vector<vector<int>>ans(r,vector<int>(c,INT_MAX));
        ans[0][0]=0;
        while(!pq.empty()){
            pair<int,pair<int,int>>e=pq.top();
            pq.pop();
            if(vis[e.second.first][e.second.second])continue;
            ///cout<<"visiting "<<e.second.first<<" "<<e.second.second<<endl;
            vis[e.second.first][e.second.second]=true;
            for(Edge*x:v[e.second.first][e.second.second]){
                int alt=max(ans[e.second.first][e.second.second],x->weight);
                if(alt<ans[x->i][x->j]){
                    ans[x->i][x->j]=alt;
                    ///cout<<"updating "<<x->i<<' '<<x->j<<" to "<<alt<<endl;
                    pq.push({alt,{x->i,x->j}});
                    if(x->i==r-1 && x->j==c-1)break;
                }
            }
            ///cout<<endl;
        }
        return ans[r-1][c-1];
    }
};

