# GraphColoring
This repository contains files and algorithms for graph coloring.

# Description
The graph coloring problem involves assigning colors to vertices of a graph in such a way that no two adjacent vertices share the same color.
The purpose of this repository is for me to have fun doing different implementations on graphs, maybe you can have fun with me too.

# Files so far
**GreedyAlgorithm:** This file contains the implementation of a greedy algorithm for graph coloring. The algorithm iteratively assigns colors to vertices based on a greedy strategy.

**DstaurAlgorithm:** This file contains the implementation of the Dstaur algorithm for graph coloring. The Dstaur algorithm is a heuristic algorithm that aims to find a coloring with a small number of colors.

**NodeClass.h:** This file defines the NodeClass, which is a class representing a vertex in the graph. It contains attributes and methods related to vertices.

**Parser.h**: This file contains functions to parse the information from the Instance.col file and create a graph using the NodeClass defined in NodeClass.h.

**Instance.col:** This file provides the attributes of a specific graph (DSJC250.5) in the format specified in the file. It includes information about the vertices and edges of the graph.

# Usage
To use the algorithms and files in this repository, follow these steps:
**1-** Clone the repository to your local machine using the following command:
 git clone https://github.com/GraphColoring/GraphColoring.git
 
**2-** Run the desired algorithm on a graph by executing the corresponding file. For example, to run the GreedyAlgorithm, execute the GreedyAlgorithm file.

# Credits
The Instance.col file used in this repository was obtained from the DIMACS (Center for Discrete Mathematics and Theoretical Computer Science) benchmark instances collection
DIMACS provides a valuable resource of benchmark instances for combinatorial optimization problems.
