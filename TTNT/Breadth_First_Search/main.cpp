#include <bits/stdc++.h>

void BFS(std::vector<std::vector<int>>& adj, char start, char end/*, int g1, int g2*/) {
    std::queue<int> q;
    std::vector<bool> visited(26, false); // Assume at most 26 uppercase letters
    std::vector<int> parent(26, -1); // To track the parent of each node

    int startIndex = start - 'A';
    int endIndex = end - 'A';

    visited[startIndex] = true;
    q.push(startIndex);

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        std::cout << char(curr + 'A') << " ";
		
        if (curr == endIndex) {
            //std::cout << "Reached " << end << std::endl;
			std::cout<<std::endl;

			std::vector<char> path;
			for(int at = endIndex; at != -1; at = parent[at]){
				path.push_back(at + 'A');

			}
			//std::reverse(path.begin(), path.end());

			std::cout<<"Path: ";
			for(char node : path){
				std::cout<< node << " <- ";
			}
			std::cout<<std::endl;
            return;
        }
	
        for (int neighbor : adj[curr]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = curr; // Track parent
                q.push(neighbor);
            }
        }
    }
	std::cout<<std::endl;

    std::cout << "No path found!" << std::endl;
}

void addedge(std::vector<std::vector<int>>& adj, char u, char v/*, int g1, int g2*/) {
    int uIndex = u - 'A';
    int vIndex = v - 'A';
    
    adj[uIndex].push_back(vIndex);
    adj[vIndex].push_back(uIndex); // Assuming undirected graph
/*
	g2 = g2 + g1;
	std::cout << g1 << g2 << std::endl; */
}

int main() {
    std::vector<std::vector<int>> adj(26); // Supports A-Z (26 letters)
    int V, g1, g2;
    char u, v, start, end;

    std::cout << "Max edge: ";
    std::cin >> V;

    std::cout << "Enter u and v: " << std::endl;
    for (int i = 0; i < V; i++) {
        std::cin >> u >> v;
		//std::cin >> g1 >> g2;
        addedge(adj, u, v/*, g1, g2*/);
    }

    std::cout << "Start/End point: ";
    std::cin >> start >> end;

    BFS(adj, start, end/*, g1, g2*/);
}
