class Solution {
public:
    string rotateUp(string s, int i) {
        s[i] = (s[i] == '9') ? '0' : s[i] + 1;
        return s;
    }

    string rotateDown(string s, int i) {
        s[i] = (s[i] == '0') ? '9' : s[i] - 1;
        return s;
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> q;
        int steps = 0;

        string start = "0000";
        if (dead.count(start)) return -1;

        q.push(start);
        visited.insert(start);

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string current = q.front();
                q.pop();

                if (current == target) return steps;

                for (int i = 0; i < 4; ++i) {
                    string up = rotateUp(current, i);
                    string down = rotateDown(current, i);

                    if (!dead.count(up) && !visited.count(up)) {
                        q.push(up);
                        visited.insert(up);
                    }
                    if (!dead.count(down) && !visited.count(down)) {
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            ++steps;
        }

        return -1;
    }
};
