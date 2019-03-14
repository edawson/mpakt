#include <cstdio>
#include <cstdint>
#include <fstream>
#include <cstring>
#include <string>
#include <iostream>
#include "mpakt.hpp"


using namespace std;
using namespace mpakt;
int main(){
    string s = "A c string";
    
    string testWrite = "testOut.txt";
    string testRead = "testIn.txt";

    ofstream ofi;
    ofi.open(testWrite.c_str(), ios::binary);
    char* scopy;
    if (ofi.good()){
        mpakt::write_c_string(ofi, strlen(s.c_str()), s.c_str());
    }
    else{
        cerr << "Error: could not open output stream" << endl;
    }
    ofi.close();
    
    

    ifstream ifi;
    ifi.open(testWrite.c_str(), ios::binary);
    char* x;
    mpakt::read_c_string(ifi, x);
    cerr << "Read the following from binary file: " << x << endl;
    ifi.close();


    
    
}
