#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;

#include <openssl/sha.h>

void printHex(unsigned char* hexVal, int length){
    for (int i = 0; i < length; i++) {
        cout << hex << (*(hexVal+i) & 0xff);
    }
    cout << endl;
}

int main(){
    const char chars[] = {0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x20, 0x77, 0x6f, 0x72, 0x6c, 0x64, 0x21, 0x00};

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, chars, strlen(chars));
    SHA256_Final(hash, &sha256);

    printHex(hash, 32);
    
    return 0;
}