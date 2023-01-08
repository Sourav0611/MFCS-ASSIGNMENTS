#!/bin/env python3
#
# @agxpro
#

"""
  QUESTION 10 : ( Program to find cycle components in an undirected graph. )
"""

edges = [] # List to store all the edges
routes = [] # List to store all possible paths
vertex = [] # List to store all vertices
graph_type = '' # Type of graph, directed or undirected

# Check if there's a edge between two vertices
def isPath(start, x):
    if graph_type == 'd':
        return [f"{start}", f"{x}"] in edges
    else:
        return [f"{start}", f"{x}"] in edges or [f"{x}", f"{start}"] in edges

# Method to find all cycle components
def findCycleComponent(pathSet, vertex_list, end):
    # Set starting point
    p = pathSet.split('-')
    start = int(p[-1])

    if (start == end or len(vertex_list) == 0) and len(p) > 3:
        # if start is equal to end then we'are already at our destination
        routes.append(pathSet)
    else:
        for x in vertex_list:
            # Check if there is a path between start and x
            if isPath(start, x) and (f"{x}" not in pathSet or len(pathSet) > 3):
                # If there is edge between x and start then
                # make copy of vertex_list excluding x from it
                new_vl = vertex_list.copy()
                new_vl.remove(x)

                # Find if there's a path between x and other vertices
                findCycleComponent(pathSet + f"-{x}", new_vl, end)

# Take required info from user
print("\tCycle components in Graph Finder\n")
print("Enter no. of vertices: ", end="")
vert = int(input()) - 1

# Exit if vertices are less than one
if vert < 0:
    print("No. of vertices cannot be less than one.")
    exit()

print("Enter edges: Eg. 1-2 3-4: ", end="")
paths = input()
# Set edges
edges = paths.split()
for i in range(len(edges)):
    edges[i] = edges[i].split('-')

# Take type of graph form the user. Eg. Directed or Undirected
print("Type of graph: (U)ndirected or (D)irected: ", end="")
graph_type = input() or 'U'
graph_type = graph_type.lower()

# Set vertex
for x in range(0, vert + 1):
        vertex.append(x)

# Find all possible cycle components
for x in range(0, vert + 1):
    findCycleComponent("{}".format(x), vertex, x)

# Remove redundant cycle components
new_routes = []
if (len(routes) > 0):
    for x in routes:
        y = x.split('-')
        y.pop()
        flag = False

        # Rotate component vertx and check it exists in list of components
        for x in range(len(y)):
            y_ = y[x:] + y[:x]
            if ("-".join(y_) + f"-{y_[0]}") in new_routes:
                # Set flag to true if exist
                flag = True
                break

        # If rotated copy of copy exists in the components list
        # then don't add it to the final components list
        if not flag:
            new_routes.append("-".join(y) + f"-{y[0]}")

# Remove more redundant cycle components
for nr in new_routes:
    # Check if reverse copy of component exists or not
    # if exist then remove it.
    # Eg. 0-1-3-2-0 is same as 0-2-3-1-0
    r = nr.split('-')
    if "-".join(r[::-1]) in new_routes:
        new_routes.remove(nr)

# Print cycle components if exist
if len(new_routes) > 0:
    print("Cycle component/s: ", end="")
    print(", ".join(new_routes))
else:
    print("No cycle component exist.")