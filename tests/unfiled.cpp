#include <gtest/gtest.h>
#include "matrix.hpp"

TEST(UNFILED, rotation_mat4f_vec3f){
    vec4f x = vec::create(1.0f, 0.0f, 0.0f, 1.0f);
    vec4f y = vec::create(0.0f, 1.0f, 0.0f, 0.0f);
    vec4f z = vec::create(0.0f, 0.0f, 1.0f, 0.0f);
    vec4f w = vec::create(0.0f, 0.0f, 0.0f, 1.0f);
    mat4f m = mat::create(x, y, z, w).transpose();
    std::cout << m << "\n";

    vec3f target = vec::create(1.0f, 1.0f, 1.0f);
    vec3f intermediate = (m * target.promote(1.0f)).demote();
    std::cout << "befor: \n" << target << "\n";
    std::cout << "after: \n" << intermediate << "\n";
    // EXPECT_EQ(intermediate[0], 2);
    // EXPECT_EQ(intermediate[1], 3);
    // EXPECT_EQ(intermediate[2], 4);
}



TEST(UNFILED, view_matrix_texting){
    vec3f u = vec::create(1.0f, 0.0f, 0.0f);
    vec3f v = vec::create(0.0f, 1.0f, 0.0f);
    vec3f n = vec::create(0.0f, 0.0f, 1.0f);
    vec3f pos = vec::create(1.0f, 1.0f, 1.0f);
    mat4f view = mat::view(u, v, n, pos);
    EXPECT_EQ(view.col(0)[0], 1);
    EXPECT_EQ(view.col(0)[1], 0);
    EXPECT_EQ(view.col(0)[2], 0);
    EXPECT_EQ(view.col(0)[3], 0);
    EXPECT_EQ(view.col(1)[0], 0);
    EXPECT_EQ(view.col(1)[1], 1);
    EXPECT_EQ(view.col(1)[2], 0);
    EXPECT_EQ(view.col(1)[3], 0);
    EXPECT_EQ(view.col(2)[0], 0);
    EXPECT_EQ(view.col(2)[1], 0);
    EXPECT_EQ(view.col(2)[2], 1);
    EXPECT_EQ(view.col(2)[3], 0);
    EXPECT_EQ(view.col(3)[0], -1);
    EXPECT_EQ(view.col(3)[1], -1);
    EXPECT_EQ(view.col(3)[2], -1);
    EXPECT_EQ(view.col(3)[3], 1);
}

TEST(UNFILED, mat4i_vec3i_mult){
    vec4i x = vec::create(0, 0, 4, 0);
    vec4i y = vec::create(2, 0, 0, 0);
    vec4i z = vec::create(0, 3, 0, 5);
    vec4i w = vec::create(0, 0, 0, 0);
    mat4i m = mat::create(x, y, z, w);
    std::cout << m << "\n";

    vec3i target = vec::create(1, 1, 1);
    vec3i intermediate = (m * target.promote(0.0f)).demote();

    EXPECT_EQ(intermediate[0], 2);
    EXPECT_EQ(intermediate[1], 3);
    EXPECT_EQ(intermediate[2], 4);
}


TEST(UNFILED, ortho_matrix_texting){
    mat4f view = mat::ortho(-1, 1, -1, 1, -1, 1);
    EXPECT_EQ(view.col(0)[0], 1.0f);
    EXPECT_EQ(view.col(0)[1], 0);
    EXPECT_EQ(view.col(0)[2], 0);
    EXPECT_EQ(view.col(0)[3], 0);
    EXPECT_EQ(view.col(1)[0], 0);
    EXPECT_EQ(view.col(1)[1], 1.0f);
    EXPECT_EQ(view.col(1)[2], 0);
    EXPECT_EQ(view.col(1)[3], 0);
    EXPECT_EQ(view.col(2)[0], 0);
    EXPECT_EQ(view.col(2)[1], 0);
    EXPECT_EQ(view.col(2)[2], -1.0f);
    EXPECT_EQ(view.col(2)[3], 0);
    EXPECT_EQ(view.col(3)[0], 0);
    EXPECT_EQ(view.col(3)[1], 0);
    EXPECT_EQ(view.col(3)[2], 0);
    EXPECT_EQ(view.col(3)[3], 1.0f);
}