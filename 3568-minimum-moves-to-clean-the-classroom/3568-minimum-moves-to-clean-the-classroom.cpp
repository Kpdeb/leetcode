class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        // Give every litter cell a bit number
        vector<vector<int>> id(m, vector<int>(n, -1));

        int sr = 0, sc = 0;
        int litterCount = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = litterCount++;
                }
            }
        }

        // No litter
        if (litterCount == 0)
            return 0;

        int totalMasks = 1 << litterCount;

        /*
            State:
            row
            col
            energy
            mask
        */

        queue<array<int, 4>> q;

        int fullMask = totalMasks - 1;

        q.push({sr, sc, energy, fullMask});

        // visited[row][col][energy][mask]
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(totalMasks, false)
                )
            )
        );

        visited[sr][sc][energy][fullMask] = true;

        int moves = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int size = q.size();

            while (size--) {

                auto [r, c, currEnergy, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == 0)
                    return moves;

                // Cannot move without energy
                if (currEnergy == 0)
                    continue;

                for (int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    // Outside grid
                    if (nr < 0 || nr >= m ||
                        nc < 0 || nc >= n)
                        continue;

                    // Wall
                    if (classroom[nr][nc] == 'X')
                        continue;

                    int newEnergy;
                    int newMask = mask;

                    // Recharge cell
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }
                    else {
                        newEnergy = currEnergy - 1;
                    }

                    // Collect litter
                    if (classroom[nr][nc] == 'L') {
                        int bit = id[nr][nc];

                        newMask &= ~(1 << bit);
                    }

                    // Already visited this exact state
                    if (visited[nr][nc][newEnergy][newMask])
                        continue;

                    visited[nr][nc][newEnergy][newMask] = true;

                    q.push({
                        nr,
                        nc,
                        newEnergy,
                        newMask
                    });
                }
            }

            moves++;
        }

        return -1;
    }
};