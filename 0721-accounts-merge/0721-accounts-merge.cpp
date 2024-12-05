class Solution {
public:
    string findParent(unordered_map<string,string> &parent,string str){
        if(parent[str]==str)
        return str;

        return parent[str]=findParent(parent,parent[str]);
    }
    void update(unordered_map<string,string> &parent,map<string,vector<string>> &m,string p1,string p2,string name){
        parent[p2]=p1;
        if(m.find(p1)!=m.end()){
            if(m.find(p2)!=m.end()){
                m[p1].insert(m[p1].end(),m[p2].begin()+1,m[p2].end());
                m.erase(p2);
            }
            else
                m[p1].push_back(p2);
            }
        else{
            m[p1].push_back(name);
            m[p1].push_back(p1);
            m[p1].push_back(p2);
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,string> parent;
        unordered_map<string,int> degree;
        map<string,vector<string>> m;

        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                parent[accounts[i][j]]=accounts[i][j];
                degree[accounts[i][j]]=0;
            }
        }

        for(int i=0;i<n;i++){
            int k=accounts[i].size();
            if(k>2){
                for(int j=1;j<k-1;j++){
                string p1=findParent(parent,accounts[i][j]);
                string p2=findParent(parent,accounts[i][j+1]);
                if(accounts[i][j]==accounts[i][j+1]){
                    if(m.find(p1)==m.end()){
                        m[accounts[i][j]].push_back(accounts[i][0]);
                        m[accounts[i][j]].push_back(accounts[i][j]);
                        degree[accounts[i][j]]++;
                    }
                }
                else if(degree[p1]>degree[p2]){
                   update(parent,m,p1,p2,accounts[i][0]); 
                   degree[p1]++;
                }
                else if(degree[p1]<=degree[p2] && p1!=p2){
                    update(parent,m,p2,p1,accounts[i][0]); 
                    degree[p2]++;
                }
            }
            }
            else{
                if(m.find(accounts[i][1])==m.end()){
                    m[accounts[i][1]].push_back(accounts[i][0]);
                    m[accounts[i][1]].push_back(accounts[i][1]);
                }
            }
        }
        vector<vector<string>> ans;
        for(auto x:m){
            sort(x.second.begin()+1,x.second.end());
            ans.push_back(x.second);
        }
        return ans;

    }
};