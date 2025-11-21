#include <iostream>
#include <vector>

using namespace std;

const int INF = 1000000;

int main() {
    int n, m, s; //Nr. Noduri, Nr. Muchii, Nodul de start
    cin >> n >> m >> s;

    vector<vector<int>> w(n+1, vector<int>(n+1, INF));

    for(int i = 0; i < m; i++){
        int u, v, cost;
        cin >> u >> v >> cost;
        w[u][v] = cost;
        w[v][u] = cost;
    }

    vector<int> dist(n+1);
    vector<bool> viz(n+1);
    // initializare vectori distanta si vizitat
    for(int i = 0; i <= n; i++){
        dist[i] = INF;
        viz[i] = 0;
    }
    //initializare distanta nod de start
    dist[s] = 0;

    for(int k = 0; k <= n; k++){
        int u = -1;
        int best = INF;

        for(int i = 0; i <= n; i++){
            if(!viz[i] && dist[i] < best){
                best = dist[i];
                u = i;
            }
        }

        if(u == -1)
            break;

        viz[u] = 1;

        for(int v = 0; v <= n; v++){
            if(!viz[v] && w[u][v] < INF){
                if(dist[v] > dist[u] + w[u][v])
                    dist[v] = dist[u] + w[u][v];
            }
        }
    }

    for(int i = 1; i<=n; i++){
        if(dist[i] == INF)
            cout << i << "=> " << "Infinit" << endl;
        else
            cout << i << "=> " << dist[i] << endl;
    }

    return 0;
}
