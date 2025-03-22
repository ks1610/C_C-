import networkx as nx
import matplotlib.pyplot as plt

# Define the directed weighted graph
graph = {
    'A': [('B', 19), ('C', 17), ('D', 20)],
    'B': [('I', 13), ('G', 15)], 
    'C': [('E', 14), ('F', 16)],
    'D': [('C', 21), ('F', 9), ('M', 14)],
    'E': [('G', 4), ('K', 6)],
    'F': [('K', 5)],
    'G': [('K', 11)],
    'I': [('G', 9)],
    'K': [],
    'M': []
}

# Heuristic values for each node
heuristics = {
    'A': 24, 'B': 15, 'C': 8, 'D': 7, 
    'E': 9, 'F': 8, 'G': 10, 'I': 6, 
    'K': 0, 'M': 17
}

# Create a directed graph in NetworkX
G = nx.DiGraph()

# Add edges
for node, edges in graph.items():
    for neighbor, weight in edges:
        G.add_edge(node, neighbor, weight=weight)

# Define manual positions for better layout
pos = {
    'A': (2, 4),
    'B': (0.5, 3.5),
    'C': (1.5, 3),
    'D': (3.5, 3.5),
    'E': (1.8, 1.8),
    'F': (3.5, 2),
    'G': (1, 1),
    'I': (0, 2),
    'K': (3, 0),
    'M': (5, 2)
}

# Get edge labels
labels = nx.get_edge_attributes(G, 'weight')

# Modify node labels to include heuristic values
node_labels = {node: f"{node}-{heuristics[node]}" for node in G.nodes()}

# Draw the graph with custom positions
plt.figure(figsize=(8, 6))
nx.draw(G, pos, with_labels=True, labels=node_labels, node_size=3000, node_color='lightblue', font_size=12, font_weight='bold', edge_color='gray', arrows=True)
nx.draw_networkx_edge_labels(G, pos, edge_labels=labels)

plt.show()
