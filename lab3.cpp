#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;
using chrono::high_resolution_clock;
using chrono::duration;
using chrono::milliseconds;

void mergeV(vector<int>& v, int stanga, int mijloc, int dreapta){
    int n1 = mijloc - stanga + 1;
    int n2 = dreapta - mijloc;

    vector<int> L(n1);
    vector<int> R(n2);

    for(int i = 0; i < n1; i++)
        L[i] = v[stanga+i];

    for(int j = 0; j < n2; j++)
        R[j] = v[mijloc + j + 1];

    int i = 0, j = 0, k = stanga;
    while( i < n1 && j < n2){
        if(L[i] <= R[j]){
            v[k] = L[i];
            k++; i++;
        } else {
            v[k] = R[j];
            k++; j++;
        }
    }

    while(i < n1) v[k++] = L[i++];
    while(j < n2) v[k++] = R[j++];

}

void mergeSort(vector<int>& v, int stanga, int dreapta){
    if(stanga >= dreapta) return;

    int mijloc = stanga + (dreapta - stanga)/2;

    mergeSort(v, stanga, mijloc);
    mergeSort(v, mijloc + 1, dreapta);

    mergeV(v, stanga, mijloc, dreapta);
}

int main() {
    int N;
    cin >> N;

    vector<int> v;
    srand(time(0));

    for(int i = 0; i < N; i++) {
        int nr = rand() % N + 1;
        v.push_back(nr);
    }

    // O(N)
    long long suma = 0;
    auto t1 = high_resolution_clock::now();

    for(int i = 0; i < N; i++)
        suma += v[i];

    auto t2 = high_resolution_clock::now();

    duration<double, std::milli> timp_final = t2-t1;
    cout << "Suma numerelor = " << suma << endl;
    cout << "Timp executie = " << timp_final.count() << " ms" <<endl;


    //O(N^2)
    vector<int> v1;

    for(int i = 0; i < N; i++) {
        int nr = rand() % N + 1;
        v1.push_back(nr);
    }
    int cnt = 0;
    t1 = high_resolution_clock::now();

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j ++)
            if(v[i] == v1[j])
                cnt++;

    t2 = high_resolution_clock::now();

    timp_final = t2-t1;
    cout << "Numere comune = " << cnt << endl;
    cout << "Timp executie = " << timp_final.count() << " ms" <<endl;

    t1 = high_resolution_clock::now();

    mergeSort(v, 0, N);

    t2 = high_resolution_clock::now();

    timp_final = t2-t1;
    cout << "Timp executie sortare = " << timp_final.count() << " ms" <<endl;

    return 0;
}
