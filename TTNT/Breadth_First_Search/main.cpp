/*Max edges: 15
Enter (u v uWeight edgeWeight):/*
Nhap So Canh Lon Nhat Cua Do Thi: 15
Nhap u v g(u) k(u,v):
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

Chon Diem Bat Dau / Ket Thuc: A B
*/


#include <bits/stdc++.h>

struct Edge {
    int hu, kuv;
};

// Breadth-First Search that strictly follows BFS order and calculates total cost after reaching the end
void BFS(std::vector<std::vector<Edge>>& ke, char start, char end, std::unordered_map<int, int>& nodePrice) {
    std::queue<int> open;
    std::vector<bool> visited(26, false); // Check each visited node 
    std::vector<int> parent(26, -1); // Track parent nodes to reconstruct the path
    std::vector<int> level(26, -1);  // Track level of each node

    // Characters to integers conversion 
    int startIndex = start - 'A'; 
    int endIndex = end - 'A';

    visited[startIndex] = true;
    level[startIndex] = 0; // Start node is at level 0
    open.push(startIndex);

    int maxBranch = 0; // Track the maximum branch factor

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
            std::cout << "Duong Di: ";
            for (size_t i = 0; i < path.size(); i++) {
                std::cout << path[i];
                if (i + 1 < path.size()) std::cout << " -> ";
            }

            // Compute the total price of the found path
            int totalPrice = 0;
            for (size_t i = 0; i < path.size() - 1; i++) {
                int uIdx = path[i] - 'A';
                int vIdx = path[i + 1] - 'A';

                for (const Edge& edge : ke[uIdx]) {
                    if (edge.hu == vIdx) {
                        totalPrice += edge.kuv;
                        break;
                    }
                }
            }

            // Print the total price from Start to End point  
            std::cout << "\nTong Chi Phi: " << totalPrice << std::endl;

            //Calcualate the time running of algorithm according to theory 
            std::cout << "Thoi Gian Chay Thuat Toan: " << "O(" << ((maxBranch == 0) ? maxBranch : maxBranch + 1 ) << "^" << ((level[endIndex] == 0) ? level[endIndex] : level[endIndex] + 1) << ")" <<std::endl;
            
            /*std::cout << "Maximum Branch Factor: " << ((maxBranch == 0) ? maxBranch : maxBranch + 1 )<< std::endl;
            std::cout << "Level Of Graph: " << ((level[endIndex] == 0) ? level[endIndex] : level[endIndex] + 1);*/

            return;
        }

        int childCount = 0; // Track number of children for current node
        for (const Edge& edge : ke[u]) {
            int neighbor = edge.hu;

            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = u;
                level[neighbor] = level[u] + 1;
                open.push(neighbor);
                childCount++;
            }
        }
        maxBranch = std::max(maxBranch, childCount);
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

    std::cout << "Nhap So Canh Lon Nhat Cua Do Thi: ";
    std::cin >> V;

    std::cout << "Nhap u v g(u) k(u,v):" << std::endl;
    for (int i = 0; i < V; i++) {
        std::cin >> u >> v >> uWeight >> edgeWeight;
        addedge(adj, u, v, uWeight, edgeWeight, nodeWeights);
    }

    /*
    // Print adjacency list
    std::cout << "\nAdjacency List (Parent -> Child [Weight]):\n";
    for (int i = 0; i < 26; i++) {
        if (!adj[i].empty()) {
            std::cout << char(i + 'A') << " (" << nodeWeights[i] << "): ";
            for (const Edge& edge : adj[i]) {
                std::cout << char(edge.hu + 'A') << "[" << edge.kuv << "] ";
            }
            std::cout << std::endl;
        }
    }
    */

    std::cout << "\nChon Diem Bat Dau / Ket Thuc: ";
    std::cin >> start >> end;

    std::cout << "\nDuyet Duong Di Tim Kiem Theo Chieu Rong: ";
    BFS(adj, start, end, nodeWeights);
}

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
