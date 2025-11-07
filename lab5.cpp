#include <iostream>
#include <vector>

using namespace std;

void printV(vector<int>& arr){
    for(int x : arr)
        cout << x << " ";
    cout << endl;
}

// Implementare stiva

//empty
bool isEmptyS(vector<int>& arr){
    return arr.size() == 0;
}

//pop
void popS(vector<int>& arr){
    if(isEmptyS(arr))
        cout << "Stiva este deja goala." << endl;
    else
        arr.pop_back();
}

//push
void pushS(vector<int>& arr, int value){
    arr.push_back(value);
}

//top
int topS(vector<int>& arr){
    if(isEmptyS(arr))
        return -1;
    return arr.back();
}

//Implementare coada

//isEmptyC
bool isEmptyC(vector<int>& arr){
    return arr.size() == 0;
}

//enqueue
void cEnqueue(vector<int>& arr, int value){
    arr.push_back(value);
}

//dequeue
void cDequeue(vector<int>& arr){
    if(isEmptyC(arr))
        cout << "Coada este deja goala." << endl;
    else
        arr.erase(arr.begin());
}

//first
int cFirst(vector<int>& arr){
    if(isEmptyC(arr))
        return -1;
    return arr.front();
}

//last
int cLast(vector<int>& arr){
    if(isEmptyC(arr))
        return -1;
    return arr.back();
}

int main() {

    vector<int> s;
    cout << "Stiva este goala ? : " << isEmptyS(s) << endl;
    pushS(s, 10);
    pushS(s, 20);
    pushS(s, 30);
    pushS(s, 40);
    printV(s);
    popS(s);
    printV(s);
    cout << "Elementul din varf = " << topS(s) << endl;
    while(!isEmptyS(s)){
        cout << topS(s) << " ";
        popS(s);
    }

    vector<int> c;

    cEnqueue(c, 100);
    cEnqueue(c, 200);
    cEnqueue(c, 300);
    cEnqueue(c, 400);
    cEnqueue(c, 500);
    cout << "Este coada goala ? : " << isEmptyC(c) << endl;
    cDequeue(c);
    printV(c);
    cout << "Primul element: " << cFirst(c) << endl;
    cout << "Ultimul element: " << cLast(c) << endl;

    return 0;
}
