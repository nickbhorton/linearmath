#include <gtest/gtest.h>
#include "matrix.h"

TEST(MATRIX_BASIC, identity_2x2_float) {
    Matrix2f m1 = Identity2f();
    EXPECT_EQ(m1.get(0, 0), 1.0);
    EXPECT_EQ(m1.get(1, 0), 0.0);
    EXPECT_EQ(m1.get(0, 1), 0.0);
    EXPECT_EQ(m1.get(1, 1), 1.0);
}