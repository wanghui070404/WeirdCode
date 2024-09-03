#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

vector<int> adj[1000];
bool visited[1000];
vector<int> a;
void input(int vertise, int edge)
{
    for (int i = 1; i <= edge; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}
vector<int> dfs(int u)
{
    a.push_back(u);
    visited[u] = true;
    for (int v : adj[u])
    {
        if (visited[v] == false)
            dfs(v);
    }
    return a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int vertise, edge;
    cin >> vertise >> edge;
    input(vertise, edge);
    int u;
    cin >> u;
    vector<int> result = dfs(u);
    cout << result.size() << '\n';
    sort(result.begin(), result.end());
    for (auto v : result)
        cout << v << " ";
    return 0;
}

/* Tối ưu:
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

const int MAX_VERTEX = 100000;

vector<int> adj[MAX_VERTEX];
bool visited[MAX_VERTEX];

void input(int vertices, int edges) {
    for (int i = 1; i <= edges; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    fill(visited, visited + vertices + 1, false);
}

vector<int> dfs(int u) {
    vector<int> result;
    stack<int> stk;
    stk.push(u);
    visited[u] = true;

    while (!stk.empty()) {
        int v = stk.top();
        stk.pop();
        result.push_back(v);

        for (int next : adj[v]) {
            if (!visited[next]) {
                stk.push(next);
                visited[next] = true;
            }
        }
    }

    return result;
}

int main() {
    int vertices, edges;
    cin >> vertices >> edges;
    input(vertices, edges);

    int u;
    cin >> u;
    vector<int> result = dfs(u);

    cout << result.size() << '\n';
    sort(result.begin(), result.end());
    for (int v : result)
        cout << v << " ";
    cout << endl;

    return 0;
}

*/