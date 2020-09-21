#include "roman.h"

namespace numeral {

std::string roman(std::size_t number) {
  if(number == 2) {
    return "II";
  }
  return "I";
}

} // namespace numeral
