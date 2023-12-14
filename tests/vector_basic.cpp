#include <gtest/gtest.h>
#include "matrix.hpp"

//
// ROW_VECTOR_OPS
//

TEST(ROW_VECTOR_OPS, assignment_ops){
    vec2i x = vec::create(1, 1);
    vec2i y = vec::create(1, -1);
    vec2i z = x - y;
    EXPECT_EQ(z[0], 0);
    EXPECT_EQ(z[1], 2);
    z *= 2;
    EXPECT_EQ(z[0], 0);
    EXPECT_EQ(z[1], 4);
    z += x;
    EXPECT_EQ(z[0], 1);
    EXPECT_EQ(z[1], 5);
    z -= 2*x;
    EXPECT_EQ(z[0], -1);
    EXPECT_EQ(z[1], 3);
    z += -(2*x);
    EXPECT_EQ(z[0], -3);
    EXPECT_EQ(z[1], 1);
    EXPECT_EQ((-(-x))[0], 1);
    EXPECT_EQ((-(-x))[1], 1);
}

TEST(ROW_VECTOR_OPS, vec_mat_mult){
    mat2i m {};
    m.set(0, 0, 1);
    m.set(0, 1, 2);
    m.set(1, 0, 3);
    m.set(1, 1, 4);

    vec2i v {};
    v.set(0, 1);
    v.set(1, 1);

    vec2i result = m * v;
    EXPECT_EQ(result.get(0), 3);
    EXPECT_EQ(result.get(1), 7);
    
    rvec2i result2 = (v.transpose() * m.transpose());
    EXPECT_EQ(result2.get(0), 3);
    EXPECT_EQ(result2.get(1), 7);
}

TEST(ROW_VECTOR_OPS, index){
    vec4i x = vec::create(1, 2, 3, 4);
    EXPECT_EQ(x[0], 1);
    EXPECT_EQ(x[1], 2);
    EXPECT_EQ(x[2], 3);
    EXPECT_EQ(x[3], 4);
}

TEST(ROW_VECTOR_OPS, index_setting){
    vec4i x {};
    x[0] = 1;
    x[1] = 2;
    x[2] = 3;
    x[3] = 4;
    EXPECT_EQ(x[0], 1);
    EXPECT_EQ(x[1], 2);
    EXPECT_EQ(x[2], 3);
    EXPECT_EQ(x[3], 4);
}

//
// ROW_VECTOR_BASIC
//

TEST(ROW_VECTOR_BASIC, dot_product_simple) {
    vec3i v = vec::create(1, 1, 1);
    int result = vec::dot(v, v);
    EXPECT_EQ(result, 3);
}

TEST(ROW_VECTOR_BASIC, dot_product_random) {
    const int size = 23;
    ColVector<int, size> v1 {};
    ColVector<int, size> v2 {};
    int know_result = 0;
    for (int j = 0; j < size; j++){
        const int rand_val_for_v1 = (rand() % 501) - 250; // random number between -250 and 250
        const int rand_val_for_v2 = (rand() % 501) - 250; // random number between -250 and 250
        v1.set(j, rand_val_for_v1);
        v2.set(j, rand_val_for_v2);
        know_result += rand_val_for_v1 * rand_val_for_v2;
    }
    int result = vec::dot(v1, v2);
    EXPECT_EQ(result, know_result);
}

TEST(ROW_VECTOR_BASIC, cross_vec3){
    vec3i x = vec::create(1, 0, 0);
    vec3i y = vec::create(0, 1, 0);
    EXPECT_EQ(vec::cross(x, y), vec::create(0, 0, 1));
    EXPECT_EQ(vec::cross(y, x), vec::create(0, 0, -1));
}

TEST(ROW_VECTOR_BASIC, length){
    vec2i x = vec::create(3, 4);
    EXPECT_EQ(vec::length(x), 5);
    vec3i y = vec::create(1, 0, 1);
    EXPECT_EQ(vec::length(y), std::sqrt(2.0f));
}

TEST(ROW_VECTOR_BASIC, normalization){
    vec3f y = vec::create(1.0f, 0.0f, 1.0f);
    EXPECT_EQ(vec::normalize(y), vec::create(std::sqrt(2.0f)/2.0f, 0.0f, std::sqrt(2.0f)/2.0f));
}

TEST(ROW_VECTOR_BASIC, normalization_of_zeros){
    vec3f y = vec::create(0.0f, 0.0f, 0.0f);
    EXPECT_EQ(vec::normalize(y), vec::create(0.0f, 0.0f, 0.0f));
}

TEST(ROW_VECTOR_BASIC, mat2x2_from_vec2) {
    vec2i x = vec::create(1, 2);
    vec2i y = vec::create(3, 4);
    mat2i m = mat::create(x, y);

    for (int i = 0; i < m.rows(); i++){
        for (int j = 0; j < m.cols(); j++){
            EXPECT_EQ(m.get(j, i), (i * m.rows() + j) + 1);
        }
    }
}

TEST(ROW_VECTOR_BASIC, mat3x3_from_vec3) {
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

TEST(ROW_VECTOR_BASIC, mat4x4_from_vec4) {
    vec4i x = vec::create(1, 2, 3, 4);
    vec4i y = vec::create(5, 6, 7, 8);
    vec4i z = vec::create(9, 10, 11, 12);
    vec4i w = vec::create(13, 14, 15, 16);
    mat4i m = mat::create(x, y, z, w);

    for (int i = 0; i < m.rows(); i++){
        for (int j = 0; j < m.cols(); j++){
            EXPECT_EQ(m.get(j, i), (i * m.rows() + j) + 1);
        }
    }
}

TEST(VECTOR_BASIC, row_promote){
    vec2i x2 = vec::create(1, 2);
    vec4i x4 = x2.promote(3).promote(4);
    EXPECT_EQ(x4[0], 1);
    EXPECT_EQ(x4[1], 2);
    EXPECT_EQ(x4[2], 3);
    EXPECT_EQ(x4[3], 4);
}

TEST(VECTOR_BASIC, row_demote){
    vec4i x4 = vec::create(1, 2, 3, 4);
    vec2i x2 = x4.demote().demote();
    EXPECT_EQ(x2[0], 1);
    EXPECT_EQ(x2[1], 2);
}