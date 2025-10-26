#include <iostream>
#include <vector>

using namespace std;

// searchK(vector, k) - returneaza pozitia pe care se afla k in v
int searchK(vector<int> v, int k){
    for(int i = 0; i < v.size(); i++){
        if(v[i] == k)
            return i;
    }

    return -1;
}
// maxim(vector) - returneaza valoarea maxima din vector
int maxim(vector<int> v){
    int maxi = v[0];
    for(int i = 1; i < v.size(); i++)
        if(v[i] > maxi)
            maxi = v[i];

    return maxi;
}
// minim(vector) - returneaza valoarea minima din vector
int minim(vector<int> v){
    int mini = v[0];
    for(int i = 1; i < v.size(); i++)
        if(v[i] < mini)
            mini = v[i];

    return mini;
}
// avg(vector) - returneaza media aritmentica a elementelor
float avg(vector<int> v){
    if(v.size() == 0)
        return -1;

    float sum = 0;
    for(int i = 0; i < v.size(); i++)
        sum = sum + v[i]; // sum += v[i];

    return sum/v.size();
}

int main() {
    /*
    Avem un vector V, cu o lungime N.
    Sa se introduca pe pozitia Y, valoarea X.
    */
    int N;
    int X, Y;
    vector<int> V;

    cin >> N;

    for(int i = 0; i < N; i++)
        V.push_back(i*3);

    cout << "Vectorul V: " << endl;
    for(int i = 0; i < N; i++)
        cout << V[i] << " ";
    cout << endl;

    cin >> X;
    cin >> Y;

    vector<int> V2;
    int M = N + 1;

    for(int i = 0; i < M; i++)
        if(i == Y)
            V2.push_back(X);
        else{
            if(i > Y)
                V2.push_back(V[i-1]);
            else
                V2.push_back(V[i]);
        }

    cout << "Vectorul V2: " << endl;
    for(int i = 0; i < M; i++)
        cout << V2[i] << " ";
    cout << endl;

    cout << "Elementul 10 se afla pe pozitia: " << searchK(V2, 10) << endl;
    cout << "Elementul 11 se afla pe pozitia: " << searchK(V2, 11) << endl;

    cout << "Maximul din V2: " << maxim(V2) << endl;
    cout << "Minimul din V2: " << minim(V2) << endl;

    cout << "Media din V2: " << avg(V2) << endl;

    vector<int> V3;

    cout << "Media din V3: " << avg(V3) << endl;

    return 0;
}
