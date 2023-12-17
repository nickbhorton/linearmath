#include <gtest/gtest.h>
#include "matrix.hpp"

//
// MATRIX_BASIC
//

TEST(MATRIX_BASIC, identity_constructor) {
    mat2f m2x2 {};
    m2x2 = mat::identity<float, 2, 2>();
    for (int i = 0; i < m2x2.rows(); i++){
        for (int j = 0; j < m2x2.cols(); j++){
            if (i == j){
                EXPECT_EQ(m2x2.get(i, j), 1);
            }
        }
    }

    mat3f m3x3 {};
    m3x3 = mat::identity<float, 3, 3>();
    for (int i = 0; i < m3x3.rows(); i++){
        for (int j = 0; j < m3x3.cols(); j++){
            if (i == j){
                EXPECT_EQ(m3x3.get(i, j), 1);
            }
        }
    }

    Matrix<int, 301, 147> m301x147 {};
    m301x147 = mat::identity<int, 301, 147>();
    for (int i = 0; i < m301x147.rows(); i++){
        for (int j = 0; j < m301x147.cols(); j++){
            if (i == j){
                EXPECT_EQ(m301x147.get(i, j), 1);
            }
        }
    }

    Matrix<int, 147, 301> m147x301 {};
    m147x301 = mat::identity<int, 147, 301>(1);
    for (int i = 0; i < m147x301.rows(); i++){
        for (int j = 0; j < m147x301.cols(); j++){
            if (i == j){
                EXPECT_EQ(m147x301.get(i, j), 1);
            }
        }
    }

}

TEST(MATRIX_BASIC, mat_ns_identity) {
    mat4i m = mat::identity<int, 4, 4>(1);
    for (int i = 0; i < m.rows(); i++){
        for (int j = 0; j < m.cols(); j++){
            if (i == j){
                EXPECT_EQ(m.get(i, j), 1);
            }
            else {
                EXPECT_EQ(m.get(i, j), 0);
            }
        }
    }

    m = mat::identity<int, 4, 4>(10);
    for (int i = 0; i < m.rows(); i++){
        for (int j = 0; j < m.cols(); j++){
            if (i == j){
                EXPECT_EQ(m.get(i, j), 10);
            }
            else {
                EXPECT_EQ(m.get(i, j), 0);
            }
        }
    }
}

//
// MATRIX_MULT
// 

TEST(MATRIX_MULT, square_mult){
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

TEST(MATRIX_MULT, non_square_mult){
    Matrix<int, 2, 3> m1 {};
    m1.set(0, 0, 3);
    m1.set(0, 1, -9);
    m1.set(0, 2, -8);
    m1.set(1, 0, 2);
    m1.set(1, 1, 4);
    m1.set(1, 2, 3);

    Matrix<int, 3, 2> m2 {};
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
}

//
// MATRIX_OPS
//

TEST(MATRIX_OPS, mat_add_simple){
    mat2i m {};
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

TEST(MATRIX_OPS, mat_add_random){
    const int rows = 23;
    const int cols = 17;
    Matrix<int, rows, cols> m1 {};
    Matrix<int, rows, cols> m2 {};
    std::vector<int> know_results {};
    for (int i = 0; i < rows; i ++){
        for (int j = 0; j < cols; j++){
            const int rand_val_for_m1 = (rand() % 10'001) - 5'000; // random number between -5,000 and 5,000
            const int rand_val_for_m2 = (rand() % 10'001) - 5'000; // random number between -5,000 and 5,000
            m1.set(i, j, rand_val_for_m1);
            m2.set(i, j, rand_val_for_m2);
            know_results.push_back(rand_val_for_m1 + rand_val_for_m2);
        }
    }
    Matrix<int, rows, cols> result = m1 + m2;
    for (int i = 0; i < rows; i ++){
        for (int j = 0; j < cols; j++){
            EXPECT_EQ(result.get(i, j), know_results[i * cols + j]);
        }
    }
}

TEST(MATRIX_OPS, mat_sub_simple){
    mat2i m {};
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

TEST(MATRIX_OPS, mat_sub_random){
    const int rows = 41;
    const int cols = 6;
    Matrix<int, rows, cols> m1 {};
    Matrix<int, rows, cols> m2 {};
    std::vector<int> know_results {};
    for (int i = 0; i < rows; i ++){
        for (int j = 0; j < cols; j++){
            const int rand_val_for_m1 = (rand() % 10'001) - 5'000; // random number between -5,000 and 5,000
            const int rand_val_for_m2 = (rand() % 10'001) - 5'000; // random number between -5,000 and 5,000
            m1.set(i, j, rand_val_for_m1);
            m2.set(i, j, rand_val_for_m2);
            know_results.push_back(rand_val_for_m1 - rand_val_for_m2);
        }
    }
    Matrix<int, rows, cols> result = m1 - m2;
    for (int i = 0; i < rows; i ++){
        for (int j = 0; j < cols; j++){
            EXPECT_EQ(result.get(i, j), know_results[i * cols + j]);
        }
    }
}

TEST(MATRIX_OPS, mat_scalar_mult){
    mat2i m {};
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

TEST(MATRIX_OPS, mat_scalar_div_simple){
    mat2i m {};
    m.set(0, 0, 2);
    m.set(0, 1, 4);
    m.set(1, 0, 6);
    m.set(1, 1, 8);

    mat2i result = m / 2;
    EXPECT_EQ(result.get(0,0), 1);
    EXPECT_EQ(result.get(0,1), 2);
    EXPECT_EQ(result.get(1,0), 3);
    EXPECT_EQ(result.get(1,1), 4);
}

TEST(MATRIX_OPS, mat_scalar_div_by_zero){
    mat2i m {};
    m.set(0, 0, 2);
    m.set(0, 1, 4);
    m.set(1, 0, 6);
    m.set(1, 1, 8);
    mat2i result = m / 0;
    EXPECT_EQ(result.get(0,0), 0);
    EXPECT_EQ(result.get(0,1), 0);
    EXPECT_EQ(result.get(1,0), 0);
    EXPECT_EQ(result.get(1,1), 0);
}

TEST(MATRIX_OPS, row_and_col){
    mat2i m = mat::identity<int, 2, 2>();
    vec2i x = m.col(0);
    vec2i y = m.col(1);
    EXPECT_EQ(x[0], 1);
    EXPECT_EQ(x[1], 0);
    EXPECT_EQ(y[0], 0);
    EXPECT_EQ(y[1], 1);
    m = mat::create(vec::create(1, 2), vec::create(3, 4));
    rvec2i z = m.row(0);
    rvec2i w = m.row(1);
    EXPECT_EQ(z[0], 1);
    EXPECT_EQ(z[1], 3);
    EXPECT_EQ(w[0], 2);
    EXPECT_EQ(w[1], 4);
}

//    0 1 2
// 0 |1 2 3|
// 1 |4 5 6|
// 2 |7 8 9|
TEST(MATRIX_OPS, minor_3x3) {
    vec3i x = vec::create(1, 2, 3);
    vec3i y = vec::create(4, 5, 6);
    vec3i z = vec::create(7, 8, 9);
    mat3i m = mat::create(x, y, z).transpose();
    mat2i m_0_0 = m.minor(0, 0);
    mat2i m_0_1 = m.minor(0, 1);
    mat2i m_0_2 = m.minor(0, 2);
    mat2i m_1_0 = m.minor(1, 0);
    mat2i m_1_1 = m.minor(1, 1);
    mat2i m_1_2 = m.minor(1, 2);
    mat2i m_2_0 = m.minor(2, 0);
    mat2i m_2_1 = m.minor(2, 1);
    mat2i m_2_2 = m.minor(2, 2);

    EXPECT_EQ(m_0_0.get(0,0), 5);
    EXPECT_EQ(m_0_0.get(0,1), 6);
    EXPECT_EQ(m_0_0.get(1,0), 8);
    EXPECT_EQ(m_0_0.get(1,1), 9);

    EXPECT_EQ(m_0_1.get(0,0), 4);
    EXPECT_EQ(m_0_1.get(0,1), 6);
    EXPECT_EQ(m_0_1.get(1,0), 7);
    EXPECT_EQ(m_0_1.get(1,1), 9);

    EXPECT_EQ(m_0_2.get(0,0), 4);
    EXPECT_EQ(m_0_2.get(0,1), 5);
    EXPECT_EQ(m_0_2.get(1,0), 7);
    EXPECT_EQ(m_0_2.get(1,1), 8);

    EXPECT_EQ(m_1_0.get(0,0), 2);
    EXPECT_EQ(m_1_0.get(0,1), 3);
    EXPECT_EQ(m_1_0.get(1,0), 8);
    EXPECT_EQ(m_1_0.get(1,1), 9);

    EXPECT_EQ(m_1_1.get(0,0), 1);
    EXPECT_EQ(m_1_1.get(0,1), 3);
    EXPECT_EQ(m_1_1.get(1,0), 7);
    EXPECT_EQ(m_1_1.get(1,1), 9);
    
    EXPECT_EQ(m_1_2.get(0,0), 1);
    EXPECT_EQ(m_1_2.get(0,1), 2);
    EXPECT_EQ(m_1_2.get(1,0), 7);
    EXPECT_EQ(m_1_2.get(1,1), 8);

    EXPECT_EQ(m_2_0.get(0,0), 2);
    EXPECT_EQ(m_2_0.get(0,1), 3);
    EXPECT_EQ(m_2_0.get(1,0), 5);
    EXPECT_EQ(m_2_0.get(1,1), 6);

    EXPECT_EQ(m_2_1.get(0,0), 1);
    EXPECT_EQ(m_2_1.get(0,1), 3);
    EXPECT_EQ(m_2_1.get(1,0), 4);
    EXPECT_EQ(m_2_1.get(1,1), 6);

    EXPECT_EQ(m_2_2.get(0,0), 1);
    EXPECT_EQ(m_2_2.get(0,1), 2);
    EXPECT_EQ(m_2_2.get(1,0), 4);
    EXPECT_EQ(m_2_2.get(1,1), 5);
}

TEST(MATRIX_OPS, det_2x2){
    vec2i x = vec::create(1, 2);
    vec2i y = vec::create(3, 4);
    mat2i m = mat::create(x, y).transpose();
    EXPECT_EQ(m.det(), -2);
}

TEST(MATRIX_OPS, det_3x3){
    vec3i x = vec::create(1, 2, 3);
    vec3i y = vec::create(4, 5, 6);
    vec3i z = vec::create(7, 8, 9);
    mat3i m = mat::create(x, y, z).transpose();
    EXPECT_EQ(m.det(), 0);
}

TEST(MATRIX_OPS, det_4x4){
    vec4i x = vec::create(1, 2, 3, 4);
    vec4i y = vec::create(5, 6, 7, 8);
    vec4i z = vec::create(9, 10, 11, 12);
    vec4i w = vec::create(13, 14, 15, 16);
    mat4i m = mat::create(x, y, z, w).transpose();
    EXPECT_EQ(m.det(), 0);
}