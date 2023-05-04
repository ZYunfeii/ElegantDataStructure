#ifndef WHEELS_H
#define WHEELS_H

#include <algorithm>
#include <string>
#include <vector>
namespace wheels {
static bool isSpace(char& c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}
static void trim(std::string& str) {
    str.erase(str.begin(), std::find_if_not(str.begin(), str.end(), isSpace));
    str.erase(std::find_if_not(str.rbegin(), str.rend(), isSpace).base(), str.end());
}

static std::vector<std::string> split(const std::string& s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    int start = 0; // start index of current token
    int end = 0; // end index of current token
    while ((end = s.find(delimiter, start)) != std::string::npos) // find next delimiter position
    {
        token = s.substr(start, end - start); // get the substring from start to end
        tokens.push_back(token); // add it to the vector
        start = end + 1; // update the start index for next token
    }
    token = s.substr(start); // get the last token
    tokens.push_back(token); // add it to the vector
    return tokens; // return the vector of tokens
}

};

#endif