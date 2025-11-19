/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("Z"));
}
TEST(PasswordTest, double_leading_letters)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("zz"));
}
TEST(PasswordTest, empty_password)
{
	Password my_password;
	ASSERT_EQ(0, my_password.count_leading_characters(""));
}
TEST(PasswordTest, lowercase_uppercase_characters)
{
	Password my_password;
	ASSERT_EQ(1, my_password.count_leading_characters("Zz"));
}
TEST(PasswordTest, space_character)
{
	Password my_password;
	ASSERT_EQ(2, my_password.count_leading_characters("  "));
}
TEST(PasswordTest, upper_and_lower_case)
{
	Password my_password;
	ASSERT_EQ(true, my_password.has_mixed_case("Zz"));
}
TEST(PasswordTest, upper_and_lower_case_with_spaces)
{
	Password my_password;
	ASSERT_EQ(true, my_password.has_mixed_case("Zz  "));
}
TEST(PasswordTest, lower_case_upper_case)
{
	Password my_password;
	ASSERT_EQ(true, my_password.has_mixed_case("zZ"));
}
TEST(PasswordTest, upper_and_lower_test_case)
{
	Password my_password;
	ASSERT_EQ(true, my_password.has_mixed_case("Zz"));
}
TEST(PasswordTest, mixed_case_with_special_characters)
{
	Password my_password;
	ASSERT_EQ(true, my_password.has_mixed_case("!@#Pp"));
}
TEST(PasswordTest, two_conditions_mix)
{
	Password my_password;
	ASSERT_EQ(true, my_password.has_mixed_case("AbaB"));
}
TEST(PasswordTest, false_condition_all_lowercase)
{
	Password my_password;
	ASSERT_EQ(false, my_password.has_mixed_case("abab"));
}
TEST(PasswordTest, empty_mix_case)
{
	Password my_password;
	ASSERT_EQ(false, my_password.has_mixed_case(" "));
}
TEST(PasswordTest, failing_case_check)
{
	Password my_password;
	ASSERT_EQ(true, my_password.has_mixed_case("A a"));
}
TEST(PasswordTest, lower_case_numbers)
{
	Password my_password;
	ASSERT_EQ(false, my_password.has_mixed_case("a1b2c3"));
}
TEST(PasswordTest, upper_case_numbers)
{
	Password my_password;
	ASSERT_EQ(false, my_password.has_mixed_case("A1B2C3"));
}
TEST(PasswordTest, mixed_case_numbers1)
{
	Password my_password;
	ASSERT_EQ(true, my_password.has_mixed_case("Aa"));
}
TEST(PasswordTest, mixed_case_numbers2)
{
	Password my_password;
	ASSERT_EQ(true, my_password.has_mixed_case("aAbB 11@@bbAA"));
}
TEST(PasswordTest, unique_special_characters)
{
	Password my_password;
	ASSERT_EQ(5, my_password.has_mixed_case("Aa1 !"));
}
TEST(PasswordTest, unique_all_same_characters)
{
    Password my_password;
    EXPECT_EQ(1, my_password.unique_characters("zzzz"));
}