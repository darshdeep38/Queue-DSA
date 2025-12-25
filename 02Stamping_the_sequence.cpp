class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        int n = target.size(), m = stamp.size();
        vector<int> result;
        vector<bool> visited(n, false);
        int replaced = 0;

        // Try stamping until all characters are replaced
        while (replaced < n) {
            bool progress = false;

            for (int i = 0; i <= n - m; i++) {
                if (visited[i]) continue;

                // Check if we can stamp at position i
                bool canStamp = true;
                int newlyReplaced = 0;

                for (int j = 0; j < m; j++) {
                    if (target[i + j] == '?') continue;
                    if (target[i + j] != stamp[j]) {
                        canStamp = false;
                        break;
                    }
                    newlyReplaced++;
                }

                // If stamping is valid and replaces something
                if (canStamp && newlyReplaced > 0) {
                    for (int j = 0; j < m; j++) {
                        if (target[i + j] != '?') {
                            target[i + j] = '?';
                            replaced++;
                        }
                    }
                    visited[i] = true;
                    result.push_back(i);
                    progress = true;
                }
            }

            // No progress → impossible
            if (!progress) return {};
        }

        // Reverse because we removed in reverse order
        reverse(result.begin(), result.end());
        return result;
    }
};
