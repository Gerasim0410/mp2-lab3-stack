#include "../mp2-lab3-stack/TStack.h"

#include "gtest.h"

TEST(TStack, can_create_bitfield_with_positive_length)
{
  ASSERT_NO_THROW(TStack<int> bf(3));
}

