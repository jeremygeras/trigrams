#pragma once

#include <vector>
#include <string>

namespace jgtrigrams
{
class TrigramParser
{
public:
    TrigramParser() {}
    virtual ~TrigramParser() {}
    /**
     * @brief Get the consecutive matching trigrams from two input strings.
     * Input strings are validated - must be < 100 characters in length
     * and contain only a-z or A-Z or the space character.
     * 
     * @param firstString Valid string.
     * @param secondString Valid string.
     * @param trigramPtrs Output param containing the resulting trigrams; should be empty on input.
     * @return int Returns 0 if input parameters were valid, -1 otherwise.
     */
    int getTrigrams(const std::string& firstString, const std::string& secondString, std::vector<const char*>& trigramPtrs);
    
    static bool isInputValid(const std::string& inString);
};
}
