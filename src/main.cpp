//
//  main.cpp
//  trigrams
//
//  Created by Jeremy Geras on 2024-02-04.
//

#include <iostream>
#include <regex>
#include "TrigramParser/include/TrigramParser.h"

/**
  * Assumption: only a-z and A-Z and space are allowed because the intent of the exercise
  * is probably not to worry about multi-byte characters / UTF-8 / Unicode
 */
bool getValidatedInput(std::string& userin)
{
   getline(std::cin, userin);
   return jgtrigrams::TrigramParser::isInputValid(userin);
}

int main(int argc, const char * argv[]) {
   std::string firstString;
   std::string secondString;
   do {
      std::cout << "Enter first string: " << std::endl;
   }
   while(getValidatedInput(firstString) == false);
   do {
      std::cout << "Enter second string: " << std::endl;
   }
   while(getValidatedInput(secondString) == false);
   std::cout << "You entered: " << firstString << " and " << secondString << std::endl;
   
   std::vector<const char*> trigramPtrs;
   jgtrigrams::TrigramParser tp;
   tp.getTrigrams(firstString, secondString, trigramPtrs);
   
   std::cout << "number of consec equals: " << trigramPtrs.size() << std::endl;
   std::vector<const char*>::iterator it = trigramPtrs.begin();
   for (; it != trigramPtrs.end(); ++it)
   {
      std::cout << "match: " << std::string_view(*it).substr(0,3) << std::endl;
   }
   return 0;
}

