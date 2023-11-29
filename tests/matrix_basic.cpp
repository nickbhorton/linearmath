#include <gtest/gtest.h>
#include "matrix.hpp"

TEST(MATRIX_BASIC, identity_constructor) {
    Matrix2f m2x2 {};
    m2x2 = m2x2.Identity();
    for (int i = 0; i < m2x2.rows(); i++){
        for (int j = 0; j < m2x2.cols(); j++){
            if (i == j){
                EXPECT_EQ(m2x2.get(i, j), 1);
            }
        }
    }

    Matrix<int, 3, 3> m3x3 {};
    m3x3 = m3x3.Identity();
    for (int i = 0; i < m3x3.rows(); i++){
        for (int j = 0; j < m3x3.cols(); j++){
            if (i == j){
                EXPECT_EQ(m3x3.get(i, j), 1);
            }
        }
    }

    Matrix<int, 301, 147> m301x147 {};
    m301x147 = m301x147.Identity();
    for (int i = 0; i < m301x147.rows(); i++){
        for (int j = 0; j < m301x147.cols(); j++){
            if (i == j){
                EXPECT_EQ(m301x147.get(i, j), 1);
            }
        }
    }

    Matrix<int, 301, 147> m301x147_col_row_ord {false};
    m301x147_col_row_ord = m301x147_col_row_ord.Identity();
    for (int i = 0; i < m301x147_col_row_ord.rows(); i++){
        for (int j = 0; j < m301x147_col_row_ord.cols(); j++){
            if (i == j){
                EXPECT_EQ(m301x147_col_row_ord.get(i, j), 1);
            }
        }
    }

    Matrix<int, 147, 301> m147x301 {};
    m147x301 = m147x301.Identity();
    for (int i = 0; i < m147x301.rows(); i++){
        for (int j = 0; j < m147x301.cols(); j++){
            if (i == j){
                EXPECT_EQ(m147x301.get(i, j), 1);
            }
        }
    }

    Matrix<int, 147, 301> m147x301_col_row_ord {false};
    m147x301_col_row_ord = m147x301_col_row_ord.Identity();
    for (int i = 0; i < m147x301_col_row_ord.rows(); i++){
        for (int j = 0; j < m147x301_col_row_ord.cols(); j++){
            if (i == j){
                EXPECT_EQ(m147x301_col_row_ord.get(i, j), 1);
            }
        }
    }
}