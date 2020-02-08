#ifndef TRADESUMMARIZER_UTIL_H
#define TRADESUMMARIZER_UTIL_H

namespace tradesummarizer {

// Doesn't seem that this exact function is in type_traits, and the instructions did ask for usage of TMP.
// Somewhat pedantic, but not inappropriate.

template<class T>
struct as_constref
{
    using type = T const&;
};

} //namespace tradesummarizer

#endif //TRADESUMMARIZER_UTIL_H
