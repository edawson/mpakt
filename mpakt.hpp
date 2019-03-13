#ifndef MPAKT_DEF_HPP
#define MPAKT_DEF_HPP
#include <istream>
#include <cstdio>
#include <cstdint>

namespace mpakt{

const static std::uint32_t MPAKT_V0_MAGIC_NUMBER = 4242420;

template<typename X>
inline std::ostream& write_field(std::ostream& os, const X& x){
    os.write((char*)&x, sizeof(X));
    return os;
};

template<typename X>
inline void read_field(std::istream& is, X& x){
    is.read((char*)x, sizeof(X));
};

template<typename X>
inline void read_field(std::istream&is, X*& x){
    is.read((char*)*x, sizeof(X));
};

template<typename X>
inline std::ostream& write_array(std::ostream& os, std::size_t count, const X* data){
    os.write((char*)&count, sizeof(count));
    for (std::size_t i = 0; i < count; ++i){
        os.write((char*)&data[i], sizeof(X));
    }
};

template<typename X>
inline void read_array(std::istream& is, X*& data){
    std::size_t sz;
    data = new X[sz];
    is.read((char*)sz, sizeof(std::size_t));
    for (std::size_t i = 0; i < sz; ++i){
        is.read((char*)data[i], sizeof(X));
    }
};
}
#endif