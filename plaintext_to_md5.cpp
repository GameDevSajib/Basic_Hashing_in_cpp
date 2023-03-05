#include <iostream>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <openssl/md5.h>
#include<bits/stdc++.h>
using namespace std;
string md5_digest(const string& str) {
    if(str.empty()) return "";

    MD5_CTX ctx;
    MD5_Init(&ctx);
    MD5_Update(&ctx, str.c_str(), str.length());

    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5_Final(digest, &ctx);

    stringstream ss;
    for(int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << static_cast<int>(digest[i]);
    }

    return ss.str();
}

int main() {
    string input = "hello world";
    string output = md5_digest(input);
    cout << "MD5 hash of \"" << input << "\" is: " << output << endl;
    return 0;
}
