import networkx as nx
import matplotlib.pyplot as plt
from collections import deque

# Create a directed graph
G = nx.DiGraph()

# Define edges with corrected values
edges = [
    ('A', 'D', 7, 0), ('A', 'F', 20, 0),
    ('D', 'H', 8, 7), ('D', 'E', 4, 7),
    ('F', 'E', 9, 20), ('F', 'G', 4, 20),
    ('H', 'C', 6, 8), ('H', 'K', 5, 8),  # ✅ H directly links to K
    ('E', 'A', 13, 0),
    ('E', 'K', 4, 9), ('E', 'I', 3, 9),
    ('K', 'B', 6, 4), ('I', 'K', 9, 3), ('I', 'F', 6, 3), ('I', 'B', 5, 3)
]

# Add edges with labels (cost)
for u, v, h, k in edges:
    G.add_edge(u, v, weight=h)  # Store edge cost

# Manually set node positions to match the given layout
pos = {
    'A': (1, 5), 'F': (4, 5), 'G': (6, 5),
    'D': (1, 3), 'E': (3, 3), 'H': (1, 0),
    'C': (0, 1), 'K': (4, 1), 'I': (5, 2),
    'B': (6, 0)
}

def bfs_path(graph, start, end):
    """Find the shortest path using BFS and return it as a list of edges."""
    queue = deque([start])
    visited = {start}
    parent = {}

    while queue:
        node = queue.popleft()

        if node == end:
            # Reconstruct the path
            path = []
            while node in parent:
                path.append((parent[node], node))
                node = parent[node]
            return path[::-1]  # Reverse to start -> end

        for neighbor in graph.neighbors(node):
            if neighbor not in visited:
                visited.add(neighbor)
                parent[neighbor] = node
                queue.append(neighbor)

    return []  # No path found

# Run BFS to find the path from A to B
start, end = 'A', 'B'
path_edges = bfs_path(G, start, end)

# Draw the graph with fixed positions
plt.figure(figsize=(8, 6))

# Draw all edges in black
edge_labels = {(u, v): G[u][v]['weight'] for u, v in G.edges()}
edge_colors = ['red' if (u, v) in path_edges else 'black' for u, v in G.edges()]

nx.draw(G, pos, with_labels=True, node_color="slategray", edge_color=edge_colors, 
        node_size=2000, font_size=10, font_color="white", arrowsize=15)

# Draw edge labels
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_size=10)

plt.title(f"BFS Path from {start} to {end} (Highlighted in Red)")
plt.show()
