class Graph:
   def __init__(self, vertices, names):
      self.V = vertices            
      self.names = names           
      self.edges = []              
      self.adj = []               

      for i in range(vertices):
         self.adj.append([])

   def add_edge(self, u, v, w):
      self.edges.append([u, v, w])   
      self.adj[u].append([v, w])     
      self.adj[v].append([u, w])     

   def display_graph(self):
      print("Adjacency List of Campus Graph:")

      for i in range(self.V):
         print(self.names[i], "->", end=" ")

         for v, w in self.adj[i]:
            print(self.names[v] + "(" + str(w) + ")", end="  ")
         print()

   def find_parent(self, parent, node):
      if parent[node] == node:
         return node
      return self.find_parent(parent, parent[node])

   def union(self, parent, x, y):
      x_parent = self.find_parent(parent, x)
      y_parent = self.find_parent(parent, y)
      parent[y_parent] = x_parent

   def kruskal_mst(self):
      self.edges.sort(key=lambda edge: edge[2])
      mst = []
      parent = []
      for i in range(self.V):
         parent.append(i)
      for edge in self.edges:

         u = edge[0]
         v = edge[1]
         w = edge[2]
         parent_u = self.find_parent(parent, u)
         parent_v = self.find_parent(parent, v)

         if parent_u != parent_v:
            mst.append(edge)
            self.union(parent, parent_u, parent_v)

      print("\nMinimum Spanning Tree Edges:")

      total_cost = 0

      for u, v, w in mst:
         print(self.names[u], "--", self.names[v], "=", w)
         total_cost = total_cost + w

      print("\nTotal Cost of MST =", total_cost)


# ---------------- Main Program ----------------

# Department Numbers
# 0 = Main Gate
# 1 = Computer Department
# 2 = IT Department
# 3 = Library
# 4 = Hostel

names = ["Main Gate", "Computer Dept", "IT Dept", "Library", "Hostel"]

g = Graph(5, names)

g.add_edge(0, 1, 10)   # Gate to Computer Dept
g.add_edge(0, 2, 8)    # Gate to IT Dept
g.add_edge(1, 2, 5)    # Computer Dept to IT Dept
g.add_edge(1, 3, 3)    # Computer Dept to Library
g.add_edge(2, 3, 7)    # IT Dept to Library
g.add_edge(2, 4, 6)    # IT Dept to Hostel
g.add_edge(3, 4, 4)    # Library to Hostel

g.display_graph()
g.kruskal_mst()
