#include <iostream>
#include <string>
using namespace std;

struct Node {
    Node* child[26];
    Node() { for(int i=0; i<26; i++) child[i] = nullptr; }
};

void bruteForceSuffixTrie(string T, Node* root) {
    int n = T.length();
    for (int i = n - 1; i >= 0; i--) {
        Node* node = root;
        int j = i;
        while (j < n && node->child[T[j] - 'a'] != nullptr) {
            node = node->child[T[j] - 'a'];
            j++;
        }
        for (int k = j; k < n; k++) {
            Node* newNode = new Node();
            node->child[T[k] - 'a'] = newNode;
            node = newNode;
        }
    }
}

int main() {
    Node* root = new Node();
    bruteForceSuffixTrie("caracas", root);
    return 0;
}
