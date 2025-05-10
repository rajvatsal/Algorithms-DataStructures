# Algorithms & Data Structures

## Build

### Windows

```code
git clone https://github.com/rajvatsal/Algorithms-DataStructures.git && cd Algorithms-DataStructures && start /wait vendor\bins\windows\premake5.exe vs2022 --file=build.lua && start Algorithms.sln
```

### Linux

```code
git clone https://github.com/rajvatsal/Algorithms-DataStructures.git && cd Algorithms-DataStructures && ./vendor/bins/linux/premake5 gmake2 --file=build.lua && make
```

### MacOS

```code
git clone https://github.com/rajvatsal/Algorithms-DataStructures.git && cd Algorithms-DataStructures && ./vendor/bins/linux/premake5 gmake2 --file=build.lua && make
```

In this repository I try to implement common CS algorithms/data structures in C to get better

## Algorithms implemented

**Sorting**

- Quicksort (median of three, randomized)
- Quicksort(middle)
- Mergesort
- Insertion sort

**NSA**

- Bisection Method
- Regula Falsi Method
- Newton Raphson
- Gauss Elimintation
- Gauss Siedel
- LU Decomposition using Gauss Elimination
- Euler's method
- Secant
- Jacobi

## Algorithms to be implemented

 **Sorting**

- Radix sort
- Bubblesort
- Perfect sort -> an algorihtm that uses above algorithms to get the best result based on the dataset size

**Data Structures**

- Linked List (circular and linear)
- Tree
- Graph

**Search**

- Binary Search (Recursive and Non-Recursive)
- BFS
- DFS

**Algorithms**
- Minmax
- Shuffling
- Knight Travails (TOP)
- Get max and min number in int array
- Get operation count of a given pseudo code
