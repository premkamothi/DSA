#include <iostream>
#include <vector>

using namespace std;

// Function to flatten matrix and map index to (row, col)
void flattenAndMap(const vector<vector<int>>& matrix) {
    int m = matrix.size();
    if (m == 0) {
        cout << "Empty matrix.\n";
        return;
    }

    int n = matrix[0].size();
    vector<int> flat;

    // Flattening the matrix
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            flat.push_back(matrix[i][j]);
        }
    }

    // Printing index to coordinate mapping
    cout << "Flattened vector with coordinates:\n";
    for (int idx = 0; idx < flat.size(); ++idx) {
        int row = idx / n;
        int col = idx % n;
        cout << "Index: " << idx << ", Value: " << flat[idx]
             << " => Coordinates: (" << row << ", " << col << ")\n";
    }
}

// Main function to test
int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };

    flattenAndMap(matrix);

    return 0;
}
