class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int gridSize = grid.size();
        int totalTriangles = gridSize * gridSize * 4;
        vector<int> parentArray(totalTriangles, -1);

        // Initially, each small triangle is a separate region
        int regionCount = totalTriangles;

        for (int row = 0; row < gridSize; row++) {
            for (int col = 0; col < gridSize; col++) {
                // Connect with the cell above
                if (row > 0) {
                    regionCount -= unionTriangles(
                        parentArray,
                        getTriangleIndex(gridSize, row - 1, col, 2),
                        getTriangleIndex(gridSize, row, col, 0));
                }
                // Connect with the cell to the left
                if (col > 0) {
                    regionCount -= unionTriangles(
                        parentArray,
                        getTriangleIndex(gridSize, row, col - 1, 1),
                        getTriangleIndex(gridSize, row, col, 3));
                }

                // If not '/', connect triangles 0-1 and 2-3
                if (grid[row][col] != '/') {
                    regionCount -= unionTriangles(
                        parentArray, getTriangleIndex(gridSize, row, col, 0),
                        getTriangleIndex(gridSize, row, col, 1));
                    regionCount -= unionTriangles(
                        parentArray, getTriangleIndex(gridSize, row, col, 2),
                        getTriangleIndex(gridSize, row, col, 3));
                }

                // If not '\', connect triangles 0-3 and 1-2
                if (grid[row][col] != '\\') {
                    regionCount -= unionTriangles(
                        parentArray, getTriangleIndex(gridSize, row, col, 0),
                        getTriangleIndex(gridSize, row, col, 3));
                    regionCount -= unionTriangles(
                        parentArray, getTriangleIndex(gridSize, row, col, 2),
                        getTriangleIndex(gridSize, row, col, 1));
                }
            }
        }
        return regionCount;
    }

private:
    int getTriangleIndex(int gridSize, int row, int col, int triangleNum) {
        return (gridSize * row + col) * 4 + triangleNum;
    }
    int unionTriangles(vector<int>& parentArray, int x, int y) {
        int parentX = findParent(parentArray, x);
        int parentY = findParent(parentArray, y);

        if (parentX != parentY) {
            parentArray[parentX] = parentY;
            return 1;  
        }

        return 0;  
    }

    // Find the parent (root) of a set
    int findParent(vector<int>& parentArray, int x) {
        if (parentArray[x] == -1) return x;

        return parentArray[x] = findParent(parentArray, parentArray[x]);
    }
};