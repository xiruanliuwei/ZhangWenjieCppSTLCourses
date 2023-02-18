
#include <iostream>

#include <cstring>

using namespace std;

template <typename T> class SigmaTraits {};

template <> class SigmaTraits<char> {
public:
    typedef int ReturnType;
};

template <> class SigmaTraits<short> {
public:
    typedef int ReturnType;
};

template <> class SigmaTraits<int> {
public:
    typedef long ReturnType;
};

template <> class SigmaTraits<unsigned int> {
public:
    typedef unsigned long ReturnType;
};

template <> class SigmaTraits<float> {
public:
    typedef double ReturnType;
};

template <typename T>
inline typename SigmaTraits<T>::ReturnType Sigma(const T* start, const T* end) {  // what does "typename" mean ?
    
    typedef typename SigmaTraits<T>::ReturnType ReturnType;

    ReturnType s = ReturnType();

    while( start != end) {
        s += *start;
        start++;
    }

    return s;
}

int main(int argc, char** argv) {

    char szNames[] = "abc";

    std::size_t nLength = std::strlen(szNames);

    char* p = szNames;
    char* q = szNames + nLength;

    printf("Sigma(szNames) = %d\n", Sigma(p, q));

    int i = int();
    printf("i = %d\n", i);

    float f = float();
    printf("f is: %f\n", f);

    return 0;
}

