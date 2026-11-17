import sys
class Graph:
   def __init__(self, vertices, names):
      self.V = vertices            
      self.names = names           
      self.graph = [[0 for _ in range(vertices)] for _ in range(vertices)]   
   
   def add_edge(self, u, v, w):
      self.graph[u][v] = w         
      self.graph[v][u] = w    

   def display_graph(self):
      print("Adjacency Matrix of Campus Graph:")
      for i in range(self.V):
         print(f"{self.names[i]:15}", self.graph[i])
   
   def min_key(self, key, mstSet):
      min_val = sys.maxsize
      min_index = -1
      for v in range(self.V):
         if key[v] < min_val and not mstSet[v]:
            min_val = key[v]
            min_index = v
      return min_index
   
   def prim_mst(self):
      key = [sys.maxsize] * self.V
      parent = [None] * self.V
      key[0] = 0
      parent[0] = -1
      mstSet = [False] * self.V
      for _ in range(self.V):
         u = self.min_key(key, mstSet)
         if u == -1:   
            break
         mstSet[u] = True
         for v in range(self.V):
            if self.graph[u][v] > 0 and not mstSet[v] and key[v] > self.graph[u][v]:
               key[v] = self.graph[u][v]
               parent[v] = u
      
      print("\nMinimum Spanning Tree Edges:")
      total_cost = 0
      for i in range(1, self.V):
         if parent[i] is not None and parent[i] != -1:
            u = parent[i]
            v = i
            w = self.graph[u][v]
            print(self.names[u], "--", self.names[v], "=", w)
            total_cost = total_cost + w
      print("\nTotal Cost of MST =", total_cost)
# ---------------- Main Program ---------------
# Department Numbers
# 0 = Main Gate
# 1 = Computer Department
# 2 = IT Department
# 3 = Library
# 4 = Hostel
names = ["Main Gate", "Computer Dept", "IT Dept", "Library", "Hostel"]

g = Graph(5, names)

g.add_edge(0, 1, 10)   
g.add_edge(0, 2, 8)    
g.add_edge(1, 2, 5)    
g.add_edge(1, 3, 3)    
g.add_edge(2, 3, 7)    
g.add_edge(2, 4, 6)    
g.add_edge(3, 4, 4)    

g.display_graph()

g.prim_mst()