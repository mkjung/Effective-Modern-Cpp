/*
 * Key idea:
 *
 *   The ability to declare references to arrays enables creation of a template
 *   to deduce the number of elements that an array contains.
 */

#include <array>
#include <cstddef>

// return size of an array as a compile-time constant. (The
// array parameter has no name, because we care only about
// the number of elements it contains.)
template<typename T, std::size_t N>                 // see info
constexpr std::size_t arraySize(T (&)[N]) noexcept  // below on
{                                                   // constexpr 
    return N;                                       // and
}                                                   // noexcept

#include <iostream>
#include <algorithm>

int main()
{
    int keyVals[] = { 1, 3, 7, 9, 11, 22, 35 };  // keyVals has
                                                 // 7 elements

    std::cout << "arraySize of keyVals[] is " << arraySize(keyVals) << '\n';

    int mappedVals1[arraySize(keyVals)];         // so does
                                                 // mappedVals
    std::copy(keyVals, keyVals + arraySize(keyVals), mappedVals1);

    std::array<int, arraySize(keyVals)> mappedVals2;  // mappedVals'
                                                      // size is 7
    std::copy(keyVals, keyVals + arraySize(keyVals), mappedVals2.begin());

    std::cout << "mappedVals1 =>" << '\n';
    for (int value : mappedVals1) {
        std::cout << value << '\n';
    }

    std::cout << "mappedVals2 =>" << '\n';
    for (int value : mappedVals2) {
        std::cout << value << '\n';
    }
}