#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
using namespace std;

void printArr(vector<int>& arr){
    for(int x : arr)
        cout << x << " ";
    cout << endl;
}

// Gasirea urmatorului numar mai mare decat cel curent intr-o lista
vector<int> urmElement(vector<int>& arr){
    int n = arr.size();
    vector<int> result(n);

    for(int i = 0; i < n; i ++){
        result[i] = -1;
        for(int j = i + 1; j < n; j++)
        {
            if(arr[j] > arr[i]){
                result[i] = arr[j];
                break;
            }
        }
    }

    return result;
}

vector<int> urmElementS(vector<int>& arr){
    int n = arr.size();
    vector<int> result(n);
    stack<int> s;

    for(int i = n - 1; i>=0; i--){
        while(!s.empty() && s.top() <= arr[i]) s.pop();

        if(s.empty()){
            result[i] = -1;
        } else {
            result[i] = s.top();
        }

        s.push(arr[i]);
    }

    return result;
}

vector<int> slidingWindow(vector<int>& arr, int k){
    int n = arr.size();
    vector<int> result;
    for(int i = 0 ; i<=n-k; i++){
        int maxi = arr[i];
        for(int j = i; j < i + k; j++)
            maxi = max(maxi, arr[j]);
        result.push_back(maxi);
    }

    return result;
}

vector<int> slidingWindowC(vector<int>& arr, int k){
    deque<int> dq;
    vector<int> result;
    int n = arr.size();

    for(int i = 0; i < n; i++){
        while(!dq.empty() && dq.front() <= i - k)
            dq.pop_front();
        while(!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();

        dq.push_back(i);

        if(i >= k - 1){
            result.push_back(arr[dq.front()]);
        }
    }
    return result;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    printArr(arr);

    vector<int> r1 = urmElement(arr);
    printArr(r1);

    vector<int> r2 = urmElementS(arr);
    printArr(r2);

    vector<int> r3 = slidingWindow(arr, 3);
    printArr(r3);

    vector<int> r4 = slidingWindowC(arr, 3);
    printArr(r4);

    return 0;
}
