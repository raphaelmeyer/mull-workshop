#include <gmock/gmock.h>

#include "roman.h"

using namespace testing;

TEST(roman_numerals, convert_arabic_to_roman) {
  ASSERT_THAT(numeral::roman(1), StrEq("I"));
  ASSERT_THAT(numeral::roman(2), StrEq("II"));
}
