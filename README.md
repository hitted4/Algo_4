# Algo_4
This is a divide and conquer algorithm in C, where we take a single dimension table of size n (power of 2), break it into two parts and retroactively call the function until we reach the base case where we can no longer break the table. During this time we create a binary tree, the leaves of which represent every point of breaking the table. When we reach the base case, we make the first "two dimensional" table 1x1 which, as is obvious, only has one element. After that, the retroactive function "goes up" and checks the next leaf. When the function finally reaches a non-base case node, it take the tables of each descendant and merges them corsswise in the table of the node. Since this happens retroactively, at some point we will have the final stage of the two dimensional table which will be what we will return to the main function. The point of this programm is to matchmake contestants into fixtures so that everyone can have a game with everyone, and not themselves.
