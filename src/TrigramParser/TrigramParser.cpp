#include "include/TrigramParser.h"
#include <cctype>
#include <algorithm>
#include <string_view>
#include <regex>

using namespace jgtrigrams;

bool ichar_equals(char a, char b)
{
   return std::tolower(static_cast<unsigned char>(a)) ==
          std::tolower(static_cast<unsigned char>(b));
}

// Avoid copies by using string_view
bool iequals(std::string_view lhs, std::string_view rhs, std::string::size_type max_chars=3)
{
   return std::ranges::equal(std::ranges::begin(lhs), std::ranges::begin(lhs)+max_chars, std::ranges::begin(rhs), std::ranges::begin(rhs)+max_chars, ichar_equals);
}

int TrigramParser::getTrigrams(const std::string& firstString, const std::string& secondString, std::vector<const char*>& trigramPtrs)
{
   trigramPtrs.clear();
   
   if (!isInputValid(firstString) || !isInputValid(secondString))
   {
      return -1;
   }
   
   unsigned int consecEqs = 0;
   const char* p1 = firstString.c_str();
   const char* p2 = secondString.c_str();
   unsigned int idx1 = 0;
   unsigned int highestConsecEqs = 0;
   unsigned long idxConseqMatches = 0;
   
   while (idx1 < firstString.size()-2)
   {
      unsigned int idx1test = idx1;
      unsigned int idx2 = 0;
      while (idx2 < secondString.size()-2)
      {
         if (iequals(p1+idx1test, p2+idx2))
         {
            // if the 3 characters and both locations are equal (case insensitive)
            // then:
            // 1) record the location for output later
            // 2) keep track if this is a "new record" number of consecutive matches
            // 3) increment our pointers to try the next locations
            trigramPtrs.push_back(p1+idx1test);
            consecEqs++;
            if (consecEqs > highestConsecEqs)
            {
               highestConsecEqs = consecEqs;
               idxConseqMatches = trigramPtrs.size() - highestConsecEqs;
            }
            idx1test++;
            idx2++;
         }
         else
         {
            // no match; move the ptr for secondString and try again
            consecEqs = 0;
            idx2++;
         }
      }
      idx1++;
   }
   trigramPtrs.erase(trigramPtrs.begin(), trigramPtrs.begin()+idxConseqMatches);
   trigramPtrs.resize(highestConsecEqs);
   return 0;
}

bool TrigramParser::isInputValid(const std::string& inString)
{
   if (inString.length() > 100) {
      return false;
   }
   std::regex pattern("^[a-zA-Z\\s]+$");
   if (!std::regex_match(inString, pattern)) {
      return false;
   }
   return true;
}
