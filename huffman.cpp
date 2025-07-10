#include "huffman.h"
#include <sstream>

Node* buildHuffmanTree(const string& text) {
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* sum = new Node('\0', left->freq + right->freq);
        sum->left = left;
        sum->right = right;
        pq.push(sum);
    }

    return pq.top();
}

void generateCodes(Node* root, const string& str, unordered_map<char, string>& huffmanCode) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    generateCodes(root->left, str + "0", huffmanCode);
    generateCodes(root->right, str + "1", huffmanCode);
}

void freeTree(Node* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

// Serialize tree using preorder traversal
void serializeTree(Node* root, ostream& out) {
    if (!root) return;
    if (!root->left && !root->right) {
        out.put('1');       // Leaf marker
        out.put(root->ch);  // Character
    } else {
        out.put('0');       // Internal node marker
        serializeTree(root->left, out);
        serializeTree(root->right, out);
    }
}

// Deserialize tree from preorder traversal
Node* deserializeTree(istream& in) {
    char marker = in.get();
    if (marker == '1') {
        char ch = in.get();
        return new Node(ch, 0);
    } else if (marker == '0') {
        Node* left = deserializeTree(in);
        Node* right = deserializeTree(in);
        Node* parent = new Node('\0', 0);
        parent->left = left;
        parent->right = right;
        return parent;
    }
    return nullptr; // Invalid marker
}

// Write bits to file as bytes
void writeBits(ofstream& out, const string& bits) {
    unsigned char byte = 0;
    int bitCount = 0;
    for (char bit : bits) {
        byte <<= 1;
        if (bit == '1')
            byte |= 1;
        bitCount++;
        if (bitCount == 8) {
            out.put(byte);
            byte = 0;
            bitCount = 0;
        }
    }
    if (bitCount > 0) {
        byte <<= (8 - bitCount);
        out.put(byte);
    }
}

// Read bits from file, return as string of '0'/'1'
string readBits(ifstream& in) {
    string bits;
    char byte;
    while (in.get(byte)) {
        for (int i = 7; i >= 0; --i) {
            bits.push_back((byte & (1 << i)) ? '1' : '0');
        }
    }
    return bits;
}

// Decode bits using Huffman tree (with original length)
string decode(Node* root, const string& bits, size_t originalLength) {
    string decoded;
    Node* curr = root;
    for (char bit : bits) {
        curr = (bit == '0') ? curr->left : curr->right;
        if (!curr->left && !curr->right) {
            decoded.push_back(curr->ch);
            curr = root;
            if (decoded.size() == originalLength) break;  // stop at original length
        }
    }
    return decoded;
}


// Overload decode without original length (calls above)
string decode(Node* root, const string& bits) {
    return decode(root, bits, bits.size());
}


// Compress input file and write to output file
void compress(const string& inputPath, const string& outputPath) {
    ifstream inFile(inputPath, ios::binary);
    ofstream outFile(outputPath, ios::binary);

    if (!inFile || !outFile) {
        cerr << "Error opening files for compression.\n";
        return;
    }

    stringstream buffer;
    buffer << inFile.rdbuf();
    string text = buffer.str();

    unordered_map<char, string> huffmanCode;
    Node* root = buildHuffmanTree(text);
    generateCodes(root, "", huffmanCode);

    size_t len = text.length();
    outFile.write(reinterpret_cast<const char*>(&len), sizeof(size_t));  // original length


    string encoded;
    for (char ch : text) {
        encoded += huffmanCode[ch];
    }

    writeBits(outFile, encoded);
    freeTree(root);
}

// Decompress input file and write to output file
void decompress(const string& inputPath, const string& outputPath) {
    ifstream inFile(inputPath, ios::binary);
    ofstream outFile(outputPath, ios::binary);

    if (!inFile || !outFile) {
        cerr << "Error opening files for decompression.\n";
        return;
    }

    size_t originalLength;
    inFile.read(reinterpret_cast<char*>(&originalLength), sizeof(size_t));
    Node* root = deserializeTree(inFile);
    string bits = readBits(inFile);
    string decoded = decode(root, bits, originalLength);

    outFile.write(decoded.c_str(), decoded.size());
    freeTree(root);
}
