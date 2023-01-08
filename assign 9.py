#!/bin/env python3
#
# @agxpro
#

"""
   QUESTION 9: ( Program to find shortest path in a graph. )
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

# Method to find all routes between starting and ending point
def findRoutes(pathSet, vertex_list, end):
    # Set starting point
    p = pathSet.split('-')
    start = int(p[-1])

    if start == end or len(vertex_list) == 0:
        # if start is equal to end then we'are already at our destination
        routes.append(pathSet)
    else:
        for x in vertex_list:
            # Check if there is a path between start and x
            if isPath(start, x):
                # If there is path between x and start then
                # make copy of vertex_list excluding x from it
                new_vl = vertex_list.copy()
                new_vl.remove(x)

                # Find if there's a path between x and other vertices
                findRoutes(pathSet + f"-{x}", new_vl, end)

# Function to print shortest paths
def printShortestPath(routes):
    short = 0 if len(routes) == 0 else len(routes[0]) # Length of shortest path
    nshort = 0 # No. of shortest paths exists
    paths = '' # String to hold all paths together

    # If there is a path then print
    if len(routes) > 0:
        for x in range(len(routes) - 1):
            # Find length of shortest path
            if len(routes[x]) < len(routes[x + 1]):
                short = len(routes[x])
            else:
                short = len(routes[x + 1])

        flag = False
        for x in routes:
            # If shortest path is found then append to paths
            if len(x) == short:
                nshort += 1
                if not flag:
                    paths = paths + x
                    flag = True
                else:
                    paths = paths + ' ' + x
            elif len(x) == 1:
                # Exceptional case when there is only one vertex
                paths = x + '-' + x

        # Print shortest path/s
        print("Shortest path{}".format(" is " if nshort <= 1 else "s are "), end="")
        print(paths.replace(" ", ", "))
        return True
    else:
        return False

# Take required info from user
print("\tShortest Path in Graph Finder\n")
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

print("Enter starting and ending vertex: Eg. 1-4: ", end="")
source_dist = input()
# Set source and destination
source_dist = source_dist.split('-')
startV = int(source_dist[0])
endV = int(source_dist[1])

# Take type of graph form the user. Eg. Directed or Undirected
print("Type of graph: (U)ndirected or (D)irected: ", end="")
graph_type = input() or 'U'
graph_type = graph_type.lower()

# Check for invalid starting and ending point
if startV > vert or endV > vert or startV < 0 or endV < 0:
    print("Starting and ending vertices cannot be greather or less than no. of vertices.")
else:
    # Set vertex
    for x in range(0, vert + 1):
        if x == endV or x == startV:
            # Don't add starting and ending vertex
            continue
        else:
            vertex.append(x)
    # Append ending vertex at the end of vertex list
    vertex.append(endV)

    # Find all possible routes
    findRoutes("{}".format(startV), vertex, endV)

    # Print all shortest routes
    if not printShortestPath(routes):
        print(f"No path exists between {startV} and {endV}")
