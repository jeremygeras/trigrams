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
    int getTrigrams(const std::string& firstString, const std::string& secondString, std::vector<const char*>& trigramPtrs);
    static bool isInputValid(const std::string& inString);
};
}
