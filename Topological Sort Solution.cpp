class Solution {
public:
    // Function to perform topological sort using Kahn's Algorithm
    vector<int> topological(unordered_map<int, vector<int>>& mp, int n) {
        vector<int> indegree(n, 0);

        // Calculate indegree for each node
        for (auto& [node, neighbors] : mp) {
            for (int neighbor : neighbors) {
                indegree[neighbor]++;
            }
        }

        // Add all nodes with 0 indegree to the queue
        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topoOrder;

        // Perform Kahn's algorithm (BFS-based topological sort)
        while (!q.empty()) {
            int node = q.front(); q.pop();
            topoOrder.push_back(node);

            for (int neighbor : mp[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                    q.push(neighbor);
            }
        }

        // If we couldn't include all nodes, a cycle exists
        if (topoOrder.size() < n)
            return {};

        return topoOrder;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        unordered_map<int, vector<int>> mpRow, mpCol;

        // Build graph from row conditions
        for (auto& row : rowConditions) {
            int u = row[0] - 1, v = row[1] - 1;  // Convert to 0-based
            mpRow[u].push_back(v);
        }

        // Build graph from column conditions
        for (auto& col : colConditions) {
            int u = col[0] - 1, v = col[1] - 1;  // Convert to 0-based
            mpCol[u].push_back(v);
        }

        // Perform topological sort on both row and column conditions
        vector<int> rowOrder = topological(mpRow, k);
        vector<int> colOrder = topological(mpCol, k);

        // If a cycle is detected in either row or column conditions, return empty matrix
        if (rowOrder.empty() || colOrder.empty())
            return {};

        // Map each number to its row and column index
        unordered_map<int, int> rowIndex, colIndex;
        for (int i = 0; i < k; i++) {
            rowIndex[rowOrder[i]] = i;
            colIndex[colOrder[i]] = i;
        }

        // Build the answer matrix
        vector<vector<int>> ans(k, vector<int>(k, 0));
        for (int num = 0; num < k; num++) {
            int r = rowIndex[num];
            int c = colIndex[num];
            ans[r][c] = num + 1;  // Convert back to 1-based
        }

        return ans;
    }
};
