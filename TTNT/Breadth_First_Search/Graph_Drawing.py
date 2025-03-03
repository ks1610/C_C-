import networkx as nx
import matplotlib.pyplot as plt

# Create a directed graph
G = nx.DiGraph()

# Define edges with corrected values
edges = [
    ('A', 'D', 7, 0), ('A', 'F', 20, 0),
    ('D', 'H', 8, 7), ('D', 'E', 4, 7),
    ('F', 'E', 9, 20), ('F', 'G', 4, 20),
    ('H', 'C', 6, 8), ('H', 'K', 5, 8),  
    ('E', 'A', 13, 0),
    ('E', 'K', 4, 9), ('E', 'I', 3, 9),
    ('K', 'B', 6, 4), ('I', 'K', 9, 3), ('I', 'F', 6, 3), ('I', 'B', 5, 3)
]

# Add edges with labels (past price, current price)
for u, v, h, k in edges:
    G.add_edge(u, v, label=f"{h}")

# Manually set node positions to match the given layout
pos = {
    'A': (1, 5), 'F': (4, 5), 'G': (6, 5),
    'D': (1, 3), 'E': (3, 3), 'H': (0, 1),
    'C': (1, 0), 'K': (4, 1), 'I': (5, 2),
    'B': (6, 0)
}

# Draw the graph with fixed positions
plt.figure(figsize=(8, 6))
nx.draw(G, pos, with_labels=True, node_color="slategray", edge_color="black", 
        node_size=2000, font_size=10, font_color="white", arrowsize=15)

# Draw edge labels (past price / current price)
edge_labels = {(u, v): f"{h}" for u, v, h, k in edges}
nx.draw_networkx_edge_labels(G, pos, edge_labels=edge_labels, font_size=10)

plt.title("Fixed Layout Directed Graph")
plt.show()
