#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

vector<int> secondMinimumTime(int n, const vector<vector<int>>& edges, int time, int change, int start, int destination) {
   
    vector<vector<pii>> graph(n + 1);
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        graph[u].emplace_back(v, time);
        graph[v].emplace_back(u, time);
    }

   
    vector<pair<long long, long long>> dist(n + 1, {LLONG_MAX, LLONG_MAX});
    priority_queue<pii, vector<pii>, greater<pii>> pq;  // (cost, vertex)
    pq.push({0, start});
    dist[start] = {0, LLONG_MAX};

    while (!pq.empty()) {
        long long currTime = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        
        for (const auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int edgeTime = neighbor.second;

            long long waitTime = (currTime % change == 0) ? 0 : change - (currTime % change);
            long long arrivalTime = currTime + edgeTime + waitTime;

            if (arrivalTime < dist[v].first) {
                dist[v].second = dist[v].first;
                dist[v].first = arrivalTime;
                pq.push({arrivalTime, v});
            } else if (arrivalTime < dist[v].second && arrivalTime > dist[v].first) {
                dist[v].second = arrivalTime;
                pq.push({arrivalTime, v});
            }
        }
    }

    
    
    return {static_cast<int>(dist[destination].first), static_cast<int>(dist[destination].second)};
}

int main() {
    int n = 4;
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {2, 4}, {3, 4}};
    int time = 5;
    int change = 10;
    int start = 1;
    int destination = 4;

    vector<int> result = secondMinimumTime(n, edges, time, change, start, destination);
    cout << "The minimum time is: " << result[0] << endl;
    cout << "The second minimum time is: " << result[1] << endl;

    return 0;
}
