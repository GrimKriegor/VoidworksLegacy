#include <voidworks/common.h>

void PrintOrderedStringVector(const std::vector<std::string>& vector)
{
  for (size_t index = 0; index < vector.size(); index++)
  {
    printf(ANSI_GRN "%d) %s\n" ANSI_RESET,
        index, vector.at(index).c_str()
      );
  }
}

size_t FindInString(std::string string, std::string search_term, size_t pos)
{
    std::transform(string.begin(), string.end(), string.begin(), ::tolower);
    std::transform(search_term.begin(), search_term.end(), search_term.begin(), ::tolower);
    return string.find(search_term, pos);
}

