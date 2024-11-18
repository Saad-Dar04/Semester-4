#include<iostream>
using namespace std;
#include "myStack.h"


#include <iostream>
using namespace std;

// Structure to represent a cell in the maze
struct Cell {
    int x, y;
};

// Function to check if a move is valid
bool isValidMove(int** maze, int** visited, int n, int x, int y) {
    return (x >= 0 && x < n&& y >= 0 && y < n&& maze[x][y] == 1 && visited[x][y] == 0);
}

// Solve the maze using a stack
bool solveMaze(int** maze, int** solution, int n) {
    int** visited = new int* [n]; // Visited matrix
    for (int i = 0; i < n; i++) {
        visited[i] = new int[n]();
    }

    // Stack to store the path
    Cell* stack = new Cell[n * n]; // Stack array
    int top = -1; // Stack pointer

    // Push starting position to stack
    stack[++top] = { 0, 0 };
    visited[0][0] = 1;
    solution[0][0] = 1;

    // Possible moves: down, up, right, left
    int dx[] = { 1, -1, 0, 0 };
    int dy[] = { 0, 0, 1, -1 };

    while (top != -1) {
        Cell current = stack[top];

        // If the rat reaches the destination
        if (current.x == n - 1 && current.y == n - 1) {
            // Clean up visited matrix
            for (int i = 0; i < n; i++) {
                delete[] visited[i];
            }
            delete[] visited;
            delete[] stack;
            return true;
        }

        bool moved = false;
        for (int i = 0; i < 4; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];

            if (isValidMove(maze, visited, n, newX, newY)) {
                // Mark as visited and push to stack
                visited[newX][newY] = 1;
                solution[newX][newY] = 1;
                stack[++top] = { newX, newY };
                moved = true;
                break;
            }
        }

        // If no valid move, backtrack
        if (!moved) {
            solution[stack[top].x][stack[top].y] = 0; // Remove from solution path
            top--; // Pop the stack
        }
    }

    // Clean up visited matrix
    for (int i = 0; i < n; i++) {
        delete[] visited[i];
    }
    delete[] visited;
    delete[] stack;

    return false; // No path found
}

int main() {
    int n;
    cout << "Enter the size of the maze (N x N): ";
    cin >> n;

    // Dynamically allocate maze and solution matrices
    int** maze = new int* [n];
    int** solution = new int* [n];
    for (int i = 0; i < n; i++) {
        maze[i] = new int[n];
        solution[i] = new int[n]();
    }

    cout << "Enter the maze (1 for open, 0 for dead end):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    if (solveMaze(maze, solution, n)) {
        cout << "Solution:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << solution[i][j] << " ";
            }
            cout << endl;
        }
    }
    else {
        cout << "PATH NOT FOUND\n";
    }

    // Clean up dynamically allocated memory
    for (int i = 0; i < n; i++) {
        delete[] maze[i];
        delete[] solution[i];
    }
    delete[] maze;
    delete[] solution;

    return 0;
}
