// huffman.h

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

// Function declarations
Node* buildHuffmanTree(const string& text);
void generateCodes(Node* root, const string& str, unordered_map<char, string>& huffmanCode);
void freeTree(Node* root);
void serializeTree(Node* root, ostream& out);
Node* deserializeTree(istream& in);
void writeBits(ofstream& out, const string& bits);
string readBits(ifstream& in);

// Declare BOTH decode overloads
string decode(Node* root, const string& bits, size_t originalLength);
string decode(Node* root, const string& bits);

// Wrapper functions for file-based compression and decompression
void compress(const std::string& text, const std::string& outputFile);
void decompress(const std::string& inputFile, const std::string& outputFile);

#endif
