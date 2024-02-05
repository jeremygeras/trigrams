//
//  main.cpp
//  trigrams
//
//  Created by Jeremy Geras on 2024-02-04.
//

#include <iostream>
#include <regex>
#include <cctype>
#include <algorithm>
#include <string_view>

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

/**
  * Assumption: only a-z and A-Z and space are allowed because the intent of the exercise
  * is probably not to worry about multi-byte characters / UTF-8 / Unicode
 */
int getValidatedInput(std::string& userin)
{
   getline(std::cin, userin);
   if (userin.length() > 100) {
      return -1;
   }
   std::regex pattern("^[a-zA-Z\\s]+$");
   if (!std::regex_match(userin, pattern)) {
      return -1;
   }
   return 0;
}

int main(int argc, const char * argv[]) {
   std::string firstString;
   std::string secondString;
   do {
      std::cout << "Enter first string: " << std::endl;
   }
   while(getValidatedInput(firstString) < 0);
   do {
      std::cout << "Enter second string: " << std::endl;
   }
   while(getValidatedInput(secondString) < 0);
   std::cout << "You entered: " << firstString << " and " << secondString << std::endl;
   
   unsigned int consecEqs = 0;
   const char* p1 = firstString.c_str();
   const char* p2 = secondString.c_str();
   unsigned int idx1 = 0;
   unsigned int highestConsecEqs = 0;
   std::vector<const char*> trigramPtrs;
   unsigned long idxConseqMatches = 0;
   
   while (idx1 < firstString.size()-2)
   {
      unsigned int idx2 = 0;
      while (idx2 < secondString.size()-2)
      {
         if (iequals(p1+idx1, p2+idx2))
         {
            // if the 3 characters and both locations are equal (case insensitive)
            // then:
            // 1) record the location for output later
            // 2) keep track if this is a "new record" number of consecutive matches
            // 3) increment our pointers to try the next locations
            trigramPtrs.push_back(p1+idx1);
            consecEqs++;
            if (consecEqs > highestConsecEqs)
            {
               highestConsecEqs = consecEqs;
               idxConseqMatches = trigramPtrs.size() - highestConsecEqs;
            }
            idx1++;
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
   
   std::cout << "number of consec equals: " << highestConsecEqs << std::endl;
   std::vector<const char*>::iterator it = trigramPtrs.begin() + idxConseqMatches;
   for (; it != trigramPtrs.end() && highestConsecEqs-- > 0; ++it)
   {
      std::cout << "match: " << std::string_view(*it).substr(0,3) << std::endl;
   }
   return 0;
}

