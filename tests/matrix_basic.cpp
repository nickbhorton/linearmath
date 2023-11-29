#include <gtest/gtest.h>
#include "matrix.hpp"

TEST(MATRIX_BASIC, identity_constructor) {
    mat2f m2x2 {};
    m2x2 = m2x2.Identity();
    for (int i = 0; i < m2x2.rows(); i++){
        for (int j = 0; j < m2x2.cols(); j++){
            if (i == j){
                EXPECT_EQ(m2x2.get(i, j), 1);
            }
        }
    }

    mat3f m3x3 {};
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

TEST(MATRIX_BASIC, memory_ordering) {
    mat2i m2x2_row_col_ord {true};
    m2x2_row_col_ord.set(0, 0, 0);
    m2x2_row_col_ord.set(0, 1, 1);
    m2x2_row_col_ord.set(1, 0, 2);
    m2x2_row_col_ord.set(1, 1, 3);
    EXPECT_EQ(m2x2_row_col_ord.get(0, 0), 0);
    EXPECT_EQ(m2x2_row_col_ord.get(0, 1), 1);
    EXPECT_EQ(m2x2_row_col_ord.get(1, 0), 2);
    EXPECT_EQ(m2x2_row_col_ord.get(1, 1), 3);

    mat2i m2x2_col_row_ord {false};
    m2x2_col_row_ord.set(0, 0, 0);
    m2x2_col_row_ord.set(0, 1, 1);
    m2x2_col_row_ord.set(1, 0, 2);
    m2x2_col_row_ord.set(1, 1, 3);
    EXPECT_EQ(m2x2_col_row_ord.get(0, 0), 0);
    EXPECT_EQ(m2x2_col_row_ord.get(0, 1), 1);
    EXPECT_EQ(m2x2_col_row_ord.get(1, 0), 2);
    EXPECT_EQ(m2x2_col_row_ord.get(1, 1), 3);
}

TEST(MATRIX_BASIC, square_mult){
    mat2i m1 {};
    m1.set(0, 0, 1);
    m1.set(0, 1, 2);
    m1.set(1, 0, 3);
    m1.set(1, 1, 4);

    mat2i m2 {};
    m2.set(0, 0, 1);
    m2.set(0, 1, 2);
    m2.set(1, 0, 3);
    m2.set(1, 1, 4);

    mat2i result = m1 * m2;
    EXPECT_EQ(result.get(0,0), 7);
    EXPECT_EQ(result.get(0,1), 10);
    EXPECT_EQ(result.get(1,0), 15);
    EXPECT_EQ(result.get(1,1), 22);
}

TEST(MATRIX_BASIC, non_square_mult){
    Matrix<int, 2, 3> m1 {true};
    m1.set(0, 0, 3);
    m1.set(0, 1, -9);
    m1.set(0, 2, -8);
    m1.set(1, 0, 2);
    m1.set(1, 1, 4);
    m1.set(1, 2, 3);

    Matrix<int, 3, 2> m2 {true};
    m2.set(0, 0, 7);
    m2.set(0, 1, -3);
    m2.set(1, 0, -2);
    m2.set(1, 1, 3);
    m2.set(2, 0, 6);
    m2.set(2, 1, 2);

    mat2i result = m1 * m2;
    EXPECT_EQ(result.get(0,0), -9);
    EXPECT_EQ(result.get(0,1), -52);
    EXPECT_EQ(result.get(1,0), 24);
    EXPECT_EQ(result.get(1,1), 12);

    // Col Row memory order

    Matrix<int, 2, 3> m1_flip {false};
    m1_flip.set(0, 0, 3);
    m1_flip.set(0, 1, -9);
    m1_flip.set(0, 2, -8);
    m1_flip.set(1, 0, 2);
    m1_flip.set(1, 1, 4);
    m1_flip.set(1, 2, 3);

    Matrix<int, 3, 2> m2_flip {false};
    m2_flip.set(0, 0, 7);
    m2_flip.set(0, 1, -3);
    m2_flip.set(1, 0, -2);
    m2_flip.set(1, 1, 3);
    m2_flip.set(2, 0, 6);
    m2_flip.set(2, 1, 2);

    result = m1_flip * m2_flip;
    EXPECT_EQ(result.get(0,0), -9);
    EXPECT_EQ(result.get(0,1), -52);
    EXPECT_EQ(result.get(1,0), 24);
    EXPECT_EQ(result.get(1,1), 12);
}

TEST(MATRIX_BASIC, vec_mat_mult){
    mat2i m {true};
    m.set(0, 0, 1);
    m.set(0, 1, 2);
    m.set(1, 0, 3);
    m.set(1, 1, 4);

    vec2i v {true};
    v.set(0, 0, 1);
    v.set(1, 0, 1);

    vec2i result = m * v;
    EXPECT_EQ(result.get(0,0), 3);
    EXPECT_EQ(result.get(1,0), 7);
}

TEST(MATRIX_BASIC, mat_add){
    mat2i m {true};
    m.set(0, 0, 1);
    m.set(0, 1, 2);
    m.set(1, 0, 3);
    m.set(1, 1, 4);

    mat2i result = m + m;
    EXPECT_EQ(result.get(0,0), 2);
    EXPECT_EQ(result.get(0,1), 4);
    EXPECT_EQ(result.get(1,0), 6);
    EXPECT_EQ(result.get(1,1), 8);
}

TEST(MATRIX_BASIC, mat_sub){
    mat2i m {true};
    m.set(0, 0, 1);
    m.set(0, 1, 2);
    m.set(1, 0, 3);
    m.set(1, 1, 4);

    mat2i result = m - m;
    EXPECT_EQ(result.get(0,0), 0);
    EXPECT_EQ(result.get(0,1), 0);
    EXPECT_EQ(result.get(1,0), 0);
    EXPECT_EQ(result.get(1,1), 0);
}

TEST(MATRIX_BASIC, mat_scalar_mult){
    mat2i m {true};
    m.set(0, 0, 1);
    m.set(0, 1, 2);
    m.set(1, 0, 3);
    m.set(1, 1, 4);

    mat2i result = 2 * m;
    EXPECT_EQ(result.get(0,0), 2);
    EXPECT_EQ(result.get(0,1), 4);
    EXPECT_EQ(result.get(1,0), 6);
    EXPECT_EQ(result.get(1,1), 8);

    result = m * 2;
    EXPECT_EQ(result.get(0,0), 2);
    EXPECT_EQ(result.get(0,1), 4);
    EXPECT_EQ(result.get(1,0), 6);
    EXPECT_EQ(result.get(1,1), 8);
}

TEST(MATRIX_BASIC, mat2x2_from_cvec2) {
    vec2i x = vec::create(1, 2);
    vec2i y = vec::create(3, 4);
    mat2i m = mat::create(x, y);

    for (int i = 0; i < m.rows(); i++){
        for (int j = 0; j < m.cols(); j++){
            EXPECT_EQ(m.get(j, i), (i * m.rows() + j) + 1);
        }
    }
}

TEST(MATRIX_BASIC, mat2x2_from_rvec2) {
    rvec2i x = vec::create(1, 2).transpose();
    rvec2i y = vec::create(3, 4).transpose();
    mat2i m = mat::create(x, y);

    for (int i = 0; i < m.rows(); i++){
        for (int j = 0; j < m.cols(); j++){
            EXPECT_EQ(m.get(i, j), (i * m.rows() + j) + 1);
        }
    }
}

TEST(MATRIX_BASIC, mat3x3_from_cvec3) {
    vec3i x = vec::create(1, 2, 3);
    vec3i y = vec::create(4, 5, 6);
    vec3i z = vec::create(7, 8, 9);
    mat3i m = mat::create(x, y, z);

    for (int i = 0; i < m.rows(); i++){
        for (int j = 0; j < m.cols(); j++){
            EXPECT_EQ(m.get(j, i), (i * m.rows() + j) + 1);
        }
    }
}

TEST(MATRIX_BASIC, mat3x3_from_rvec3) {
    rvec3i x = vec::create(1, 2, 3).transpose();
    rvec3i y = vec::create(4, 5, 6).transpose();
    rvec3i z = vec::create(7, 8, 9).transpose();
    mat3i m = mat::create(x, y, z);

    for (int i = 0; i < m.rows(); i++){
        for (int j = 0; j < m.cols(); j++){
            EXPECT_EQ(m.get(i, j), (i * m.rows() + j) + 1);
        }
    }
}

TEST(MATRIX_BASIC, mat4x4_from_cvec3) {
    vec3i x = vec::create(1, 2, 3);
    vec3i y = vec::create(4, 5, 6);
    vec3i z = vec::create(7, 8, 9);
    mat4i m = mat::create(x, y, z, 1);

    for (int i = 0; i < m.rows() - 1; i++){
        for (int j = 0; j < m.cols() - 1; j++){
            EXPECT_EQ(m.get(j, i), (i * (m.rows() - 1) + j) + 1);
        }
    }
    EXPECT_EQ(m.get(3, 3), 1);
}

TEST(MATRIX_BASIC, mat4x4_from_rvec3) {
    rvec3i x = vec::create(1, 2, 3).transpose();
    rvec3i y = vec::create(4, 5, 6).transpose();
    rvec3i z = vec::create(7, 8, 9).transpose();
    mat4i m = mat::create(x, y, z, 1);

    for (int i = 0; i < m.rows() - 1; i++){
        for (int j = 0; j < m.cols() - 1; j++){
            EXPECT_EQ(m.get(i, j), (i * (m.rows() - 1) + j) + 1);
        }
    }
    EXPECT_EQ(m.get(3, 3), 1);
}