#ifndef COMMON_H_
#define COMMON_H_

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <string>
#include <vector>
#include <voidworks/addresses.h>
#include <voidworks/constants.h>

using mLvPtr = std::vector<uintptr_t>;
using Pos    = std::vector<float>;

void PrintOrderedStringVector(const std::vector<std::string>&);
size_t FindInString(std::string, std::string, size_t = 0);

#endif
