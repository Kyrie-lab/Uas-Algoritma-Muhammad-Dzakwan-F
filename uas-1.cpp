#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// Node Huffman
struct HuffmanNode {
    char character;
    int frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char ch, int freq) : character(ch), frequency(freq), left(nullptr), right(nullptr) {}
};

// Comparator untuk priority queue
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency;
    }
};

// Membuat pohon Huffman
HuffmanNode* buildHuffmanTree(const string& text) {
    unordered_map<char, int> frequencyMap;
    for (char ch : text) frequencyMap[ch]++;

    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
    for (auto& pair : frequencyMap) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();
        HuffmanNode* parent = new HuffmanNode('\0', left->frequency + right->frequency);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }

    return pq.top();
}

// Traversal pohon untuk menghasilkan kode Huffman
void generateHuffmanCodes(HuffmanNode* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    if (root->character != '\0') {
        huffmanCodes[root->character] = code;
    }

    generateHuffmanCodes(root->left, code + "0", huffmanCodes);
    generateHuffmanCodes(root->right, code + "1", huffmanCodes);
}

// Encoding string
string encode(const string& text, unordered_map<char, string>& huffmanCodes) {
    string encodedString = "";
    for (char ch : text) {
        encodedString += huffmanCodes[ch];
    }
    return encodedString;
}

// Decoding string
string decode(HuffmanNode* root, const string& encodedString) {
    string decodedString = "";
    HuffmanNode* current = root;
    for (char bit : encodedString) {
        if (bit == '0') current = current->left;
        else current = current->right;

        if (!current->left && !current->right) {
            decodedString += current->character;
            current = root;
        }
    }
    return decodedString;
}

int main() {
    // Menampilkan informasi Nama, Kelas, dan NIM
    cout << "===============================\n";
    cout << "Nama : Muhammad Dzakwan F\n";
    cout << "Kelas: 03TPLP029\n";
    cout << "Nim  : 231011403237\n";
    cout << "===============================\n\n";

    string text;
    cout << "Masukkan string untuk dikompresi: ";
    cin >> text;

    HuffmanNode* root = buildHuffmanTree(text);

    unordered_map<char, string> huffmanCodes;
    generateHuffmanCodes(root, "", huffmanCodes);

    cout << "Kode Huffman untuk setiap karakter:\n";
    for (auto& pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << endl;
    }

    string encodedString = encode(text, huffmanCodes);
    cout << "\nString terkompresi: " << encodedString << endl;

    string decodedString = decode(root, encodedString);
    cout << "String setelah dekompresi: " << decodedString << endl;

    return 0;
}

