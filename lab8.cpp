#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Muchie {
    int a, b, cost;
};

bool cmp(Muchie& a, Muchie& b){
    return a.cost < b.cost;
}

struct DSU{
    vector<int> parinte;

    DSU(int n){
        parinte.resize(n+1);
        iota(parinte.begin(), parinte.end(), 0);
    }

    int findP(int i){
        if(parinte[i] == i)
            return i;
        parinte[i] = findP(parinte[i]);
        return parinte[i];
    }

    void unite(int i, int j){
        int root_i = findP(i);
        int root_j = findP(j);

        if(root_i != root_j){
            parinte[root_i] = root_j;
        }
    }
};

int INF = 1e9;

void Prim(vector<vector<int>>& w, int n, int r){
    vector<int> cost(n);
    vector<int> parinte(n);
    vector<bool> inMST(n);

    for(int i = 0; i < n; i++){
        cost[i] = INF;
        parinte[i] = -1;
        inMST[i] = false;
    }

    cost[r] = 0;

    for(int i = 0; i < n; i++){
        int u = -1;
        int best = INF;

        for(int j = 0; j < n; j++){
            if(!inMST[j] && cost[j] < best){
                best = cost[j];
                u = j;
            }
        }

        if(u == -1)
            break;

        inMST[u] = true;

        for(int v = 0; v < n; v++){
            if(!inMST[v] && w[u][v] < cost[v]){
                cost[v] = w[u][v];
                parinte[v] = u;
            }
        }
    }

    int costTotal = 0;
    for(int i = 0; i < n; i++)
        if(parinte[i] != -1)
            costTotal += cost[i];

    cout << "Cost total: " << costTotal << endl;

}

int main() {

    int n = 5;
    vector<Muchie> muchii = {
        {0,1,10},
        {0,2,6},
        {0,3,5},
        {1,3,15},
        {2,3,4}
    };

    sort(muchii.begin(), muchii.end(), cmp);

    DSU dsu(n);
    int costTotal = 0;
    vector<Muchie> mst;

    for(int i = 0; i < n; i++){
        if(dsu.findP(muchii[i].a) != dsu.findP(muchii[i].b)){
            dsu.unite(muchii[i].a, muchii[i].b);
            costTotal += muchii[i].cost;
            mst.push_back(muchii[i]);
        }
    }

    cout << "Cost total: " << costTotal << endl;
    cout << "Muchii: " << endl;
    for(int i = 0; i < n; i++)
        cout << muchii[i].a << " - " << muchii[i].b << endl;


    vector<vector<int>> w(n , vector<int>(n, INF));

    for(int i = 0; i < n; i++){
        int u, v, cost;
        cin >> u >> v >> cost;
        w[u][v] = cost;
        w[v][u] = cost;
    }

    Prim(w, n, 0);

    return 0;
}
