#include <vector>
#include <queue>
#include <algorithm>

#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define pb push_back
#define mp make_pair
#define INF 1e18

using namespace std;

class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        if (n == 1) {
            return 0;
        }

        ll maxWeight = 0;
        for (auto& edge : edges) {
            maxWeight = max(maxWeight, (ll)edge[2]);
        }

        ll low = 0, high = maxWeight, answer = -1;
        while (low <= high) {
            ll mid = (low + high) / 2;

            vvll graph(n);
            for (auto& edge : edges) {
                if (edge[2] <= mid) {
                    graph[edge[1]].pb(edge[0]); 
                }
            }

            vi visited(n, 0);
            queue<int> q;
            q.push(0);
            visited[0] = 1;
            ll count = 1; 

            while (!q.empty()) {
                ll u = q.front();
                q.pop();
                for (auto& v : graph[u]) {
                    if (!visited[v]) {
                        visited[v] = 1;
                        count++;
                        q.push(v);
                    }
                }
            }

            if (count == n) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return answer;
    }
};