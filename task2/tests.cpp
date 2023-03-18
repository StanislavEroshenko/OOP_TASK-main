#include "gtest/gtest.h"

#include "hashtag.h"

TEST(StackTest, StackPush)
{
    EXPECT_EQ("#LovingFluffyCats", hashtag("loving Fluffy cats"));
    EXPECT_EQ("#IWannaSleep", hashtag("                i wanna sleep"));
    EXPECT_EQ("#FefuBestUniversity", hashtag("Fefu best University                   "));
    EXPECT_EQ("#CakeIsALie", hashtag("Cake is                       a Lie"));
    EXPECT_THROW(hashtag(""), std::invalid_argument);
    EXPECT_THROW(hashtag("qwesdfghjytresdfghjkliuytrewazx rtyuioplkjhgfazxcvbnmnb vcxsasdfghjkoiuytrewqqwertyuiolkjhgfdsazxcvbnm"), std::length_error);
}