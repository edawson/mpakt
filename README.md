mpakt: a simple C++ API for packing arbitrary data to binary
------------------------------------------------------------
Eric T Dawson  
March 2019

## Background
mpakt provides a succinct API for reading and writing
binary data to/from disk. It doesn't do any fancy handling
(a la [bitsery](https://github.com/fraillt/bitsery));
it just reads/writes individual values
or arrays. It is up to users to define how to use such values,
and to define the full schema of their binary files.

## Installation
mpakt is a single header-only library; just place it in your
include path and add it as a makefile dependency.

## API Example
```
#include <fstream>
#include <string>
#include "mpakt.hpp"

// use the strcopy function
// from https://github.com/edawson/pliib
#include "pliib/pliib.hpp"

struct person{
    uint64_t left;
    uint64_t right;
    char* name;

    std::ostream& write_to_binary_stream(std::ostream& os){
        mpakt::write_c_string(os, strlen(name), name);
        mpakt::write_field(os, left);
        mpakt::write_field(os, right);
        return os;
    }
    std::istream& from_stream(std::istream& is){
        mpakt::read_c_string(is, name);
        mpakt::read_field(is, left);
        mpakt::read_field(is, right);
        return is;
    }
}

int main(){
    
    Person p;
    p.left = 1;
    p.right = 2;

    string s = "Bob";
    pliib::strcopy(s.c_str(), p.name);

    // Write p to stream
    ofstream ofi;
    ofi.open("binary_in.txt", ios::binary);
    p.write_to_stream(ofi);
    ofi.close();

    // Read from our binary file into a new Person (b)
    Person b;
    ifstream ifi;
    ifi.open("binary_in.txt", ios::binary);
    b.from_stream(ifi);
    ifi.close();

}
```

## Getting Help
Please post [on the github](https://github.com/edawson/mpakt)
for help or questions.
