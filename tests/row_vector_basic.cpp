#include <gtest/gtest.h>
#include "matrix.hpp"

//
// ROW_VECTOR_OPS
//

TEST(ROW_VECTOR_OPS, binary_addition){
    rvec2i x = rvec::create(1, 1);
    rvec2i y = rvec::create(1, -1);
    rvec2i z = x + y;
    EXPECT_EQ(z[0], 2);
    EXPECT_EQ(z[1], 0);
}

TEST(ROW_VECTOR_OPS, binary_subtraction){
    rvec2i x = rvec::create(1, 1);
    rvec2i y = rvec::create(1, -1);
    rvec2i z = x - y;
    EXPECT_EQ(z[0], 0);
    EXPECT_EQ(z[1], 2);
}

TEST(ROW_VECTOR_OPS, scalar_mult_lhs){
    rvec2i x = rvec::create(1, 1);
    rvec2i z = 3 * x;
    EXPECT_EQ(z[0], 3);
    EXPECT_EQ(z[1], 3);
}

TEST(ROW_VECTOR_OPS, scalar_mult_rhs){
    rvec2i x = rvec::create(1, 1);
    rvec2i z = x * 3;
    EXPECT_EQ(z[0], 3);
    EXPECT_EQ(z[1], 3);
}

TEST(ROW_VECTOR_OPS, add_assignment){
    rvec2i x = rvec::create(1, 1);
    rvec2i y = rvec::create(1, -1);
    rvec2i z = x;
    z += y;
    EXPECT_EQ(z[0], 2);
    EXPECT_EQ(z[1], 0);
}

TEST(ROW_VECTOR_OPS, sub_assignment){
    rvec2i x = rvec::create(1, 1);
    rvec2i y = rvec::create(1, -1);
    rvec2i z = x;
    z -= y;
    EXPECT_EQ(z[0], 0);
    EXPECT_EQ(z[1], 2);
}

TEST(ROW_VECTOR_OPS, scalar_mult_assignment){
    rvec2i x = rvec::create(1, 2);
    x *= 2;
    EXPECT_EQ(x[0], 2);
    EXPECT_EQ(x[1], 4);
}

TEST(ROW_VECTOR_OPS, unary_negation){
    rvec2i x = rvec::create(1, 2);
    x = -x;
    EXPECT_EQ(x[0], -1);
    EXPECT_EQ(x[1], -2);
}

TEST(ROW_VECTOR_OPS, unary_addition){
    rvec2i x = rvec::create(1, 2);
    x = +x;
    EXPECT_EQ(x[0], 1);
    EXPECT_EQ(x[1], 2);
}

TEST(ROW_VECTOR_OPS, scalar_div){
    rvec2i x = rvec::create(2, 2);
    x = x / 2;
    EXPECT_EQ(x[0], 1);
    EXPECT_EQ(x[1], 1);
}

TEST(ROW_VECTOR_OPS, scalar_div_assignment){
    rvec2i x = rvec::create(2, 2);
    x /= 2;
    EXPECT_EQ(x[0], 1);
    EXPECT_EQ(x[1], 1);
}


// TEST(ROW_VECTOR_OPS, vec_mat_mult){
//     mat2i m {};
//     m.set(0, 0, 1);
//     m.set(0, 1, 2);
//     m.set(1, 0, 3);
//     m.set(1, 1, 4);

//     vec2i v {};
//     v.set(0, 1);
//     v.set(1, 1);

//     vec2i result = m * v;
//     EXPECT_EQ(result.get(0), 3);
//     EXPECT_EQ(result.get(1), 7);
// }

TEST(ROW_VECTOR_OPS, index){
    rvec4i x = rvec::create(1, 2, 3, 4);
    EXPECT_EQ(x[0], 1);
    EXPECT_EQ(x[1], 2);
    EXPECT_EQ(x[2], 3);
    EXPECT_EQ(x[3], 4);
}

TEST(ROW_VECTOR_OPS, index_mutate){
    rvec4i x {};
    x[0] = 1;
    x[1] = 2;
    x[2] = 3;
    x[3] = 4;
    EXPECT_EQ(x[0], 1);
    EXPECT_EQ(x[1], 2);
    EXPECT_EQ(x[2], 3);
    EXPECT_EQ(x[3], 4);
}

TEST(ROW_VECTOR_OPS, dot_product_simple) {
    rvec3i v = rvec::create(1, 1, 1);
    int result = rvec::dot(v, v);
    EXPECT_EQ(result, 3);
}

TEST(ROW_VECTOR_OPS, dot_product_random) {
    const int size = 23;
    RowVector<int, size> v1 {};
    RowVector<int, size> v2 {};
    int know_result = 0;
    for (int j = 0; j < size; j++){
        const int rand_val_for_v1 = (rand() % 501) - 250; // random number between -250 and 250
        const int rand_val_for_v2 = (rand() % 501) - 250; // random number between -250 and 250
        v1.set(j, rand_val_for_v1);
        v2.set(j, rand_val_for_v2);
        know_result += rand_val_for_v1 * rand_val_for_v2;
    }
    int result = rvec::dot(v1, v2);
    EXPECT_EQ(result, know_result);
}

TEST(ROW_VECTOR_OPS, cross_vec3){
    rvec3i x = rvec::create(1, 0, 0);
    rvec3i y = rvec::create(0, 1, 0);
    EXPECT_EQ(rvec::cross(x, y), rvec::create(0, 0, 1));
    EXPECT_EQ(rvec::cross(y, x), rvec::create(0, 0, -1));
}

TEST(ROW_VECTOR_OPS, length){
    rvec2i x = rvec::create(3, 4);
    EXPECT_EQ(rvec::length(x), 5);
    rvec3i y = rvec::create(1, 0, 1);
    EXPECT_EQ(rvec::length(y), std::sqrt(2.0f));
}

TEST(ROW_VECTOR_OPS, normalization){
    rvec3f y = rvec::create(1.0f, 0.0f, 1.0f);
    EXPECT_EQ(rvec::normalize(y), rvec::create(std::sqrt(2.0f)/2.0f, 0.0f, std::sqrt(2.0f)/2.0f));
}

TEST(ROW_VECTOR_OPS, normalization_of_zeros){
    rvec3f y = rvec::create(0.0f, 0.0f, 0.0f);
    EXPECT_EQ(rvec::normalize(y), rvec::create(0.0f, 0.0f, 0.0f));
}

//
// ROW_VECTOR_BASIC
//


TEST(ROW_VECTOR_BASIC, mat2x2_from_vec2) {
    rvec2i x = rvec::create(1, 2);
    rvec2i y = rvec::create(3, 4);
    mat2i m = mat::create(x, y);

    for (int i = 0; i < m.rows(); i++){
        for (int j = 0; j < m.cols(); j++){
            EXPECT_EQ(m.get(j, i), (i * m.rows() + j) + 1);
        }
    }
}

TEST(ROW_VECTOR_BASIC, mat3x3_from_vec3) {
    rvec3i x = rvec::create(1, 2, 3);
    rvec3i y = rvec::create(4, 5, 6);
    rvec3i z = rvec::create(7, 8, 9);
    mat3i m = mat::create(x, y, z);

    for (int i = 0; i < m.rows(); i++){
        for (int j = 0; j < m.cols(); j++){
            EXPECT_EQ(m.get(j, i), (i * m.rows() + j) + 1);
        }
    }
}

TEST(ROW_VECTOR_BASIC, mat4x4_from_vec4) {
    rvec4i x = rvec::create(1, 2, 3, 4);
    rvec4i y = rvec::create(5, 6, 7, 8);
    rvec4i z = rvec::create(9, 10, 11, 12);
    rvec4i w = rvec::create(13, 14, 15, 16);
    mat4i m = mat::create(x, y, z, w);

    for (int i = 0; i < m.rows(); i++){
        for (int j = 0; j < m.cols(); j++){
            EXPECT_EQ(m.get(j, i), (i * m.rows() + j) + 1);
        }
    }
}

TEST(ROW_VECTOR_BASIC, row_promote){
    rvec2i x2 = rvec::create(1, 2);
    rvec4i x4 = x2.promote(3).promote(4);
    EXPECT_EQ(x4[0], 1);
    EXPECT_EQ(x4[1], 2);
    EXPECT_EQ(x4[2], 3);
    EXPECT_EQ(x4[3], 4);
}

TEST(ROW_VECTOR_BASIC, row_demote){
    rvec4i x4 = rvec::create(1, 2, 3, 4);
    rvec2i x2 = x4.demote().demote();
    EXPECT_EQ(x2[0], 1);
    EXPECT_EQ(x2[1], 2);
}