class Solution {
public:
    int magnificentSets(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adjList(n);
        vector<int> parent(n, -1);
        vector<int> depth(n, 0);
        for (auto edge : edges) {
            adjList[edge[0] - 1].push_back(edge[1] - 1);
            adjList[edge[1] - 1].push_back(edge[0] - 1);
            Union(edge[0] - 1, edge[1] - 1, parent, depth);
        }
        unordered_map<int, int> numOfGroupsForComponent;
        for (int node = 0; node < n; node++) {
            int numberOfGroups = getNumberOfGroups(adjList, node, n);
            if (numberOfGroups == -1) return -1;
            int rootNode = find(node, parent);
            numOfGroupsForComponent[rootNode] =
                max(numOfGroupsForComponent[rootNode], numberOfGroups);
        }
        int totalNumberOfGroups = 0;
        for (auto [rootNode, numberOfGroups] : numOfGroupsForComponent) {
            totalNumberOfGroups += numberOfGroups;
        }
        return totalNumberOfGroups;
    }

private:
    int find(int node, vector<int> &parent) {
        while (parent[node] != -1) node = parent[node];
        return node;
    }
    void Union(int node1, int node2, vector<int> &parent, vector<int> &depth) {
        node1 = find(node1, parent);
        node2 = find(node2, parent);
        if (node1 == node2) return;
        if (depth[node1] < depth[node2]) swap(node1, node2);
        parent[node2] = node1;
        if (depth[node1] == depth[node2]) depth[node1]++;
    }
    int getNumberOfGroups(vector<vector<int>> &adjList, int srcNode, int n) {
        queue<int> nodesQueue;
        vector<int> layerSeen(n, -1);
        nodesQueue.push(srcNode);
        layerSeen[srcNode] = 0;
        int deepestLayer = 0;
        while (!nodesQueue.empty()) {
            int numOfNodesInLayer = nodesQueue.size();
            for (int i = 0; i < numOfNodesInLayer; i++) {
                int currentNode = nodesQueue.front();
                nodesQueue.pop();
                for (int neighbor : adjList[currentNode]) {
                    if (layerSeen[neighbor] == -1) {
                        layerSeen[neighbor] = deepestLayer + 1;
                        nodesQueue.push(neighbor);
                    } else {
                        if (layerSeen[neighbor] == deepestLayer) {
                            return -1;
                        }
                    }
                }
            }
            deepestLayer++;
        }
        return deepestLayer;
    }
};