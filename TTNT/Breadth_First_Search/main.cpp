/*Max edges: 15
Enter (u v uWeight edgeWeight):
A D 0 7
A F 0 20
D H 7 8
D E 7 4
F E 20 9
F G 20 4
H C 8 6
H K 8 5
E A 13 0
E K 9 4
E I 9 3
K B 4 6
I K 3 9
I F 3 6
I B 3 5

Adjacency List (Parent -> Child [Weight]):
A (0): D[7] F[20]
D (7): H[8] E[4]
E (13): A[0] K[4] I[3]
F (20): E[9] G[4]
H (8): C[6] K[5]
I (3): K[9] F[6] B[5]
K (4): B[6]

Start/End point: A B
*/

#include <bits/stdc++.h>

struct Edge {
    int to, weight;
};

// Breadth-First Search with path tracking and total weight calculation
void BFS(std::vector<std::vector<Edge>>& ke, char start, char end, std::unordered_map<int, int>& nodeWeights) {
    std::queue<int> open;
    std::vector<bool> visited(26, false);
    std::vector<int> parent(26, -1);
    std::vector<int> totalWeight(26, INT_MAX); // Track the minimum weight to reach each node

    int startIndex = start - 'A';
    int endIndex = end - 'A';

    visited[startIndex] = true;
    totalWeight[startIndex] = nodeWeights[startIndex]; // Assign starting weight
    open.push(startIndex);

    while (!open.empty()) {
        int u = open.front();
        open.pop();

        std::cout << char(u + 'A') << " ";

        if (u == endIndex) {
            std::cout << "\n";

            // Construct the path
            std::vector<char> path;
            for (int at = endIndex; at != -1; at = parent[at]) {
                path.push_back(at + 'A');
            }
            std::reverse(path.begin(), path.end());

            // Print the path
            std::cout << "Path: ";
            for (size_t i = 0; i < path.size(); i++) {
                std::cout << path[i];
                if (i + 1 < path.size()) std::cout << " -> ";
            }
            std::cout << "\nTotal Weight: " << totalWeight[endIndex] << std::endl;
            return;
        }

        for (const Edge& edge : ke[u]) {
            int neighbor = edge.to;
            int newWeight = totalWeight[u] + edge.weight;

            if (!visited[neighbor] || newWeight < totalWeight[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = u;
                totalWeight[neighbor] = newWeight;
                open.push(neighbor);
            }
        }
    }

    std::cout << "No path found!" << std::endl;
}

// Directed graph with edge weights
void addedge(std::vector<std::vector<Edge>>& ke, char u, char v, int uWeight, int edgeWeight, std::unordered_map<int, int>& nodeWeights) {
    int uIndex = u - 'A';
    int vIndex = v - 'A';

    // Assign the weight to the parent node (only once)
    if (nodeWeights.find(uIndex) == nodeWeights.end()) {
        nodeWeights[uIndex] = uWeight;
    }

    // Add directed edge u -> v with weight
    ke[uIndex].push_back({vIndex, edgeWeight});
}

int main() {
    std::vector<std::vector<Edge>> adj(26); // Graph for A-Z (26 nodes)
    std::unordered_map<int, int> nodeWeights; // Store starting weights of nodes
    int V;
    char u, v, start, end;
    int uWeight, edgeWeight;

    std::cout << "Max edges: ";
    std::cin >> V;

    std::cout << "Enter (u v uWeight edgeWeight): " << std::endl;
    for (int i = 0; i < V; i++) {
        std::cin >> u >> v >> uWeight >> edgeWeight;
        addedge(adj, u, v, uWeight, edgeWeight, nodeWeights);
    }

    // Print adjacency list
    std::cout << "\nAdjacency List (Parent -> Child [Weight]):\n";
    for (int i = 0; i < 26; i++) {
        if (!adj[i].empty()) {
            std::cout << char(i + 'A') << " (" << nodeWeights[i] << "): ";
            for (const Edge& edge : adj[i]) {
                std::cout << char(edge.to + 'A') << "[" << edge.weight << "] ";
            }
            std::cout << std::endl;
        }
    }

    std::cout << "\nStart/End point: ";
    std::cin >> start >> end;

    BFS(adj, start, end, nodeWeights);
}
