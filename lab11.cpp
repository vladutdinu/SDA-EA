#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void siftUp(vector<int>& heap, int index){
    while(index > 0) {
        int parent = (index - 1) / 2;
        if(heap[index] > heap[parent]){
            int temp = heap[index];
            heap[index] = heap[parent];
            heap[parent] = temp;
            index = parent;
        } else {
            break;
        }
    }
}

void add(vector<int>& heap, int val){
    heap.push_back(val);
    siftUp(heap, heap.size() - 1);
}

int main() {

    vector<int> heap;

    add(heap, 15);
    add(heap, 40);
    add(heap, 30);
    add(heap, 50);
    add(heap, 10);
    add(heap, 3);
    add(heap, 8);
    add(heap, 7);
    add(heap, 5);
    add(heap, 4);

    for(int val : heap)
        cout << val << " ";
    cout<<endl;

    return 0;
}
