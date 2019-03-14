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
    
    string testWrite = "testOut.bin";

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

    string field_test = "fieldtest.bin";
    uint64_t bigint = 31415619;
    uint32_t smallerint = 42;

    uint64_t* p3 = new uint64_t[3];
    p3[0] = 720;
    p3[1] = 360;
    p3[2] = 180;



    ofi.open(field_test.c_str(), ios::binary);
    if (ofi.good()){
        mpakt::write_field(ofi, bigint);
        mpakt::write_field(ofi, smallerint);
        mpakt::write_array(ofi, 3, p3);
    }
    ofi.close();

    ifi.open(field_test, ios::binary);
    uint64_t ret_big;
    uint32_t ret_small;
    uint64_t* ret_arr = new uint64_t[3];
    mpakt::read_field(ifi, ret_big);
    mpakt::read_field(ifi, ret_small);
    mpakt::read_array(ifi, ret_arr);
    cerr << "Read a large int: " << ret_big << endl;
    cerr << "Read a small int: " << ret_small << endl;
    cerr << "Read an array: " << ret_arr[0] << " " << ret_arr[1] << " " << ret_arr[2] << endl;


    
    
}
