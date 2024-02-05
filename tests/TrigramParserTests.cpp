#include <gtest/gtest.h>
#include "../src/TrigramParser/include/TrigramParser.h"

using namespace jgtrigrams;

TEST(TrigramParserTests, TestEquStrings)
{
    TrigramParser tp;
    std::vector<const char*> ptrs;
    tp.getTrigrams("abcd", "abcd", ptrs);
    ASSERT_EQ(2, ptrs.size());
}

TEST(TrigramParserTests, TestDiffStrings)
{
    TrigramParser tp;
    std::vector<const char*> ptrs;
    tp.getTrigrams("abcd", "wxyz", ptrs);
    ASSERT_EQ(0, ptrs.size());
}

TEST(TrigramParserTests, TestShiftStrings1)
{
    TrigramParser tp;
    std::vector<const char*> ptrs;
    tp.getTrigrams("computed", "Composted", ptrs);
    ASSERT_EQ(2, ptrs.size());
}

TEST(TrigramParserTests, TestShiftStrings2)
{
    TrigramParser tp;
    std::vector<const char*> ptrs;
    tp.getTrigrams("computed", "smelly compost", ptrs);
    ASSERT_EQ(2, ptrs.size());
}

TEST(TrigramParserTests, TestShortStrings)
{
    TrigramParser tp;
    std::vector<const char*> ptrs;
    tp.getTrigrams("as", "df", ptrs);
    ASSERT_EQ(0, ptrs.size());
}

TEST(TrigramParserTests, TestInvalChars)
{
    TrigramParser tp;
    std::vector<const char*> ptrs;
    tp.getTrigrams("a123", "4s56", ptrs);
    ASSERT_EQ(0, ptrs.size());
}

TEST(TrigramParserTests, TestWithSpaces)
{
    TrigramParser tp;
    std::vector<const char*> ptrs;
    tp.getTrigrams("this is a", "thus is a", ptrs);
    ASSERT_EQ(4, ptrs.size());
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
