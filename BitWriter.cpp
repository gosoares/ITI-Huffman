//
// Created by gabriel on 23/03/18.
//

#include "BitWriter.h"

BitWriter::BitWriter(string fileName) : file(fileName, ofstream::binary), buffer(0), bitCount(0) {}

void BitWriter::writeBit(bool bit) {
    buffer = ((buffer << 1) | bit);
    bitCount++;

    if(bitCount == 8){
        file.put(buffer);
        bitCount = 0;
    }
}

void BitWriter::writeCode(string& code) {
    for(auto& c : code) writeBit(c == '1');
}

void BitWriter::close() {
    if(bitCount > 0) {
        buffer = (buffer << 8 - bitCount);
        file.put(buffer);
    }
    file.close();
}
