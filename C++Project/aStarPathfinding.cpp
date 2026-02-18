/*
╔═══════════════════════════════════════════════════════════════╗
║                                                               ║
║    ░█████╗░██╗     ███████╗██╗  ██╗  ██████╗ ░█████╗░████████╗█████╗░ ███╗   ██╗    ║
║    ██╔══██╗██║     ██╔════╝╚██╗██╔╝  ██╔══██╗██╔══██╗╚══██╔══╝██╔══██╗████╗  ██║    ║
║    ███████║██║     █████╗   ╚███╔╝   ██████╔╝███████║   ██║   ██║  ██║██╔██╗ ██║    ║
║    ██╔══██║██║     ██╔══╝   ██╔██╗   ██╔═══╝ ██╔══██║   ██║   ██║  ██║██║╚██╗██║    ║
║    ██║  ██║███████╗███████╗██╔╝ ╚██╗ ██║     ██║  ██║   ██║   ╚█████╔╝██║ ╚████║    ║
║    ╚═╝  ╚═╝╚══════╝╚══════╝╚═╝   ╚═╝ ╚═╝     ╚═╝  ╚═╝   ╚═╝    ╚════╝ ╚═╝  ╚═══╝    ║
║                                                               ║
║                    ⚡ A* Pathfinding Project ⚡               ║
║                                                               ║
╚═══════════════════════════════════════════════════════════════╝
*/
#include "aStarPathfinding.h"
#include <iostream>
#include <algorithm>

std::vector<std::vector<int>> CreateGrid(int rows, int cols) {
    return std::vector<std::vector<int>>(rows, std::vector<int>(cols, 0));
}

void PrintGrid(const std::vector<std::vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int cell : row) {
            std::cout << (cell == 1 ? "# " : ". ");
        }
        std::cout << "\n";
    }
}

float Heuristic(Node* a, Node* b) {
    return std::abs(a->x - b->x) + std::abs(a->y - b->y);
}

std::vector<Node*> AStar(std::vector<std::vector<int>>& grid, Node* start, Node* goal) {
    std::priority_queue<Node*, std::vector<Node*>, CompareNode> openSet;
    std::vector<Node*> closedSet;

    start->h = Heuristic(start, goal);
    start->f = start->h;
    openSet.push(start);

    int dx[] = { 0, 1, 0, -1 };
    int dy[] = { -1, 0, 1, 0 };

    while (!openSet.empty()) {
        Node* current = openSet.top();
        openSet.pop();

        if (current->x == goal->x && current->y == goal->y) {
            std::vector<Node*> path;
            while (current) {
                path.push_back(current);
                current = current->parent;
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        closedSet.push_back(current);

        for (int i = 0; i < 4; i++) {
            int nx = current->x + dx[i];
            int ny = current->y + dy[i];

            if (nx < 0 || ny < 0 || nx >= grid.size() || ny >= grid[0].size() || grid[nx][ny] == 1)
                continue;

            Node* neighbor = new Node(nx, ny);
            neighbor->g = current->g + 1;
            neighbor->h = Heuristic(neighbor, goal);
            neighbor->f = neighbor->g + neighbor->h;
            neighbor->parent = current;

            bool skip = false;
            for (Node* closed : closedSet) {
                if (closed->x == nx && closed->y == ny) {
                    skip = true;
                    break;
                }
            }

            if (!skip) openSet.push(neighbor);
        }
    }

    return {};
}
