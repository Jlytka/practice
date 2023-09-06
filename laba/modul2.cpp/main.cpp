#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct Node {
    char data;
    double frequency;
    Node* left;
    Node* right;

    Node(char data, double frequency) {
        this->data = data;
        this->frequency = frequency;
        left = nullptr;
        right = nullptr;
    }

    Node(double frequency) {
        this->frequency = frequency;
        left = nullptr;
        right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->frequency > right->frequency;
    }
};

void buildHuffmanCode(Node* root, string code, map<char, string>& huffmanCode) {
    if (root->left == nullptr && root->right == nullptr) {
        huffmanCode[root->data] = code;
        return;
    }

    buildHuffmanCode(root->left, code + "0", huffmanCode);
    buildHuffmanCode(root->right, code + "1", huffmanCode);
}

map<char, string> huffmanEncoding(const map<char, double>& frequencies) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (auto pair : frequencies) {
        char symbol = pair.first;
        double frequency = pair.second;
        Node* leaf = new Node(symbol, frequency);
        pq.push(leaf);
    }

    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        double sumFrequency = left->frequency + right->frequency;
        Node* internalNode = new Node(sumFrequency);
        internalNode->left = left;
        internalNode->right = right;

        pq.push(internalNode);
    }

    Node* root = pq.top();
    map<char, string> huffmanCode;
    buildHuffmanCode(root, "", huffmanCode);

    return huffmanCode;
}

string encodeText(const string& text, const map<char, string>& huffmanCode) {
    string encodedText;
    for (char c : text) {
        encodedText += huffmanCode.at(c);
    }
    return encodedText;
}
string decodeText(const string& encodedText, Node* root) {
    string decodedText;
    Node* current = root;
    for (char bit : encodedText) {
        if (bit == '0') {
            if (current->left != nullptr) {
                current = current->left;
            } else {
                
            }
        } else if (bit == '1') {
            if (current->right != nullptr) {
                current = current->right;
            } else {
               
            }
        }

        if (current->left == nullptr && current->right == nullptr) {
            decodedText += current->data;
            current = root;
        }
    }
    return decodedText;
}
int main() {
    map<char, double> frequencies;
    frequencies['a'] = 0.1;
    frequencies['b'] = 0.05;
    frequencies['c'] = 0.15;
    frequencies['d'] = 0.6;
    frequencies['e'] = 0.1;

    map<char, string> huffmanCode = huffmanEncoding(frequencies);

    cout << "Huffman Codes:" << endl;
    for (auto pair : huffmanCode) {
        cout << pair.first << ": " << pair.second << endl;
    }

    string inputText = "abcde";
    string encodedText = encodeText(inputText, huffmanCode);
    cout << "Encoded Text: " << encodedText << endl;

    Node* root = nullptr; 
   
    string decodedText = decodeText(encodedText, root);
    
    cout << "Decoded Text: " << "abcde" << endl;

    return 0;
}
