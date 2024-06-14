class TreeAncestor {
public:
    int n;

    vector<int>belong;
    vector<int>ind;
    vector<bool>leaf;
    vector<vector<int>>path_leaf;

    TreeAncestor(int n, vector<int>& parent) {
        this->n=n;
        path_leaf.resize(n);
        belong.resize(n,-1);
        ind.resize(n,-1);
        leaf.resize(n,1);

        for(int i=0;i<n;i++){
            if(parent[i]!=-1)   
            leaf[parent[i]]=0;
        }
        
        for(int i=0;i<n;i++){
            if(!leaf[i]) continue;
            int curr=i;
            belong[curr]=curr;
            while(curr!=-1){
                curr=parent[curr];
                path_leaf[i].push_back(curr);
                if(curr!=-1){
                    belong[curr]=i;
                    ind[curr]=path_leaf[i].size()-1;
                }
            }
        }

    }
    
    int getKthAncestor(int node, int k) {
        return path_leaf[belong[node]][min(k+ind[node],(int)path_leaf[belong[node]].size()-1)];
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */