#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        string s;
        cin >> s;

        sort(s.begin(), s.end());

        queue<string> q;
        q.push("");

        while (!q.empty()) {
            string current = q.front();
            q.pop();

            if (current.size() == s.size()) {
                
                cout << current << endl;
                continue;
            }

            for (char c : s) {
                if (current.find(c) == string::npos) {
                    q.push(current + c);
                }
            }
        }
    }

    return 0;
}