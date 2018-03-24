//
// Created by gabriel on 23/03/18.
//

#ifndef HUFFMAN_BITWRITER_H
#define HUFFMAN_BITWRITER_H

#include <iostream>
#include <fstream>

using namespace std;

class HuffmanWriter {
private:
    unsigned char buffer;
    short bitCount;
    ofstream file;
public:
    HuffmanWriter(string fileName, long (&frequencies)[256]);

    void writeBit(bool bit);

    void writeCode(string& code);

    void close();
};


#endif //HUFFMAN_BITWRITER_H
