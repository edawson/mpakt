mpakt: a simple C++ API for packing arbitrary data to binary
------------------------------------------------------------
Eric T Dawson  
March 2019

## Background
mpakt provides a succinct API for reading and writing
binary data to/from disk. It doesn't do any fancy handling
(a la [bitsery]()); it just reads/writes individual values
or arrays. It is up to users to define how to use such values,
and to define the full schema of their binary files.

## Installation
mpakt is a single header-only library; just place it in your
include path and add it as a makefile dependency.

## API Example
```
#include "mpakt.hpp"

struct person{
    uint64_t left;
    uint64_t right;
    char* name;

    void write_to_binary_stream(std::ostream& os, person& p){
        mpakt::write_c_string(os, strlen(name), name);
        mpakt::write_field(os, left);
        mpakt::write_field(os, right);
    }
    void from_stream(std::istream& is){
        mpakt::read_c_string(is, name);
        mpakt::read_field(is, left);
        mpakt::read_field(is, right);
    }
}

int main(){

    ifstream ifi;
    ifi.open("binary_in.txt", ios::binary);

}
```

## Getting Help
Please post [on the github](https://github.com/edawson/mpakt)
for help or questions.