/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: <Please write your names here>
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "snowman.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input)
{
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
    input.erase(remove(input.begin(), input.end(), '\t'), input.end());
    input.erase(remove(input.begin(), input.end(), '\n'), input.end());
    input.erase(remove(input.begin(), input.end(), '\r'), input.end());
    return input;
}

TEST_CASE("Good snowman code") {
CHECK(nospaces(snowman(11114411)) == nospaces("_===_\n(.,.)\n( : )\n( : )\n"));
CHECK(nospaces(snowman(33232124)) == nospaces("   _   \n  /_\\\n\\(o_O) \n (] [)>\n (   )\n"));
CHECK(nospaces(snowman(11111111)) == nospaces("     \n_===_\n (.,.) \n<( : )>\n ( : ) \n"));
CHECK(nospaces(snowman(21111111)) == nospaces(" ___ \n.....\n (.,.) \n<( : )>\n ( : ) \n"));
CHECK(nospaces(snowman(12111111)) == nospaces("     \n_===_\n (...) \n<( : )>\n ( : ) \n"));
CHECK(nospaces(snowman(11211111)) == nospaces("     \n_===_\n (o,.) \n<( : )>\n ( : ) \n"));
CHECK(nospaces(snowman(11121111)) == nospaces("     \n_===_\n (.,o) \n<( : )>\n ( : ) \n"));
CHECK(nospaces(snowman(11112111)) == nospaces("     \n_===_\n\\(.,.) \n ( : )>\n ( : ) \n"));
CHECK(nospaces(snowman(11111211)) == nospaces("     \n_===_\n (.,.)/\n<( : ) \n ( : ) \n"));
CHECK(nospaces(snowman(11111121)) == nospaces("     \n_===_\n (.,.) \n<(] [)>\n ( : ) \n"));
CHECK(nospaces(snowman(11111112)) == nospaces("     \n_===_\n (.,.) \n<( : )>\n (" ") \n"));
    
} 


TEST_CASE("Bad snowman code") {
    CHECK_THROWS(snowman(1));//short number
    CHECK_THROWS(snowman(19111111));//9 is big number
    CHECK_THROWS(snowman(-2));//negative number
    CHECK_THROWS(snowman(111111111));//longer then 8
    CHECK_THROWS(snowman(10111111));//with 0 number
    CHECK_THROWS(snowman(5));//5 is big number
    CHECK_THROWS(snowman(11191111));//longer then 8 and also 9 is big number
    CHECK_THROWS(snowman(-777));//negative number and short number and also 7 is big number
    CHECK_THROWS(snowman(22299999));
    CHECK_THROWS(snowman(-4));
    CHECK_THROWS(snowman(2828111));
    CHECK_THROWS(snowman(33338333));
}