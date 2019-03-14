#ifndef MPAKT_DEF_HPP
#define MPAKT_DEF_HPP
#include <istream>
#include <cstdio>
#include <cstdint>
#include <iostream>

namespace mpakt{

const static std::uint32_t MPAKT_V0_MAGIC_NUMBER = 4242420;

inline std::ostream& write_c_string(std::ofstream& os, std::size_t len, const char* x){
    os.write(reinterpret_cast<char*>(&len), sizeof(std::size_t));
    os.write(x, len);
};

inline std::istream& read_c_string(std::istream& is, char*& x){
    std::size_t sz = 0;
    is.read(reinterpret_cast<char*>(&sz), sizeof(std::size_t));
    x = new char[sz+1];
    is.read(x, sz);
    x[sz] = '\n';
};

template<typename X>
inline std::ostream& write_field(std::ostream& os, const X& x){
    os.write(reinterpret_cast<char*>(&x), sizeof(X));
    return os;
};

template<typename X>
inline std::ostream& write_field(std::ostream& os, const X* x){
    os.write(reinterpret_cast<char*>(&x), sizeof(X));
    return os;
}

template<typename X>
inline void read_field(std::istream& is, X& x){
    is.read(reinterpret_cast<char*>(&x), sizeof(X));
};

template<typename X>
inline void read_field(std::istream&is, X*& x){
    is.read(reinterpret_cast<char*>(&x), sizeof(X));
};

template<typename X>
inline std::ostream& write_array(std::ostream& os, std::size_t count, const X* data){
    os.write((char*)&count, sizeof(count));
    for (std::size_t i = 0; i < count; ++i){
        os.write(reinterpret_cast<char*>(&data[i]), sizeof(X));
    }
    return os;
};

template<typename X>
inline void read_array(std::istream& is, X*& data){
    std::size_t sz;
    data = new X[sz];
    is.read((char*)sz, sizeof(std::size_t));
    for (std::size_t i = 0; i < sz; ++i){
        is.read(reinterpret_cast<char*>(&data[i]), sizeof(X));
    }
};


}
#endif
