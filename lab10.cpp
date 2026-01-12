#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int freq;
    char data;
    Node *left, *right;

    Node(int f, char d){
        freq = f;
        data = d;
        left = right = nullptr;
    }

    Node(int f){
        freq = f;
        data = '\0';
        left = right = nullptr;
    }
};

void printCodes(Node* root, string code){
    if(!root) return;

    if(root->data != '\0')
        cout << root->data << ": " << code << " (freq: " << root->freq << ")" << endl;

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");

}

bool compare(Node* a, Node* b){
    return a->freq < b->freq;
}

int main() {
    vector<char> chars = {'a', 'b', 'c', 'd', 'e', 'f'};
    vector<int> freq = {5, 9, 12, 13, 16, 45};

    vector<Node*> nodes;
    for(int i = 0; i < chars.size(); i++)
        nodes.push_back(
            new Node(freq[i], chars[i])
        );

    while(nodes.size() > 1){
        sort(nodes.begin(), nodes.end(), compare);

        Node* leftN = nodes[0];
        Node* rightN = nodes[1];

        Node* parent = new Node(leftN->freq + rightN->freq);
        parent->left = leftN;
        parent->right = rightN;

        nodes.erase(nodes.begin(), nodes.begin() + 2);

        nodes.push_back(parent);

    }

    printCodes(nodes[0], "");

    return 0;
}
