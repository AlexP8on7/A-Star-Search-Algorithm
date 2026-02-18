#pragma once
#include <vector>
#include <queue>
#include <cmath>

struct Node {
    int x, y;
    float g, h, f;
    Node* parent;
    
    Node(int x, int y) : x(x), y(y), g(0), h(0), f(0), parent(nullptr) {}
};

struct CompareNode {
    bool operator()(Node* a, Node* b) { return a->f > b->f; }
};

std::vector<std::vector<int>> CreateGrid(int rows, int cols);
void PrintGrid(const std::vector<std::vector<int>>& grid);
std::vector<Node*> AStar(std::vector<std::vector<int>>& grid, Node* start, Node* goal);
