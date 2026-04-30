/**
 * Unit Tests for the class
**/

#include <gtest/gtest.h>
#include "Guesser.h"

class GuesserTest : public ::testing::Test
{
	protected:
		GuesserTest(){} //constructor runs before each test
		virtual ~GuesserTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};


//DISTANCE TESTS
TEST(GuesserTest, identical)
{
  Guesser object("Secret");
  ASSERT_EQ(object.distance("Secret"), 0);
}
TEST(GuesserTest, alldifferent)
{
  Guesser object("AAAA");
  ASSERT_EQ(object.distance("BBBB"), 4);
}
TEST(GuesserTest, partialdifferent)
{
  Guesser object("AAAA");
  ASSERT_EQ(object.distance("AAAB"), 1);
}
TEST(GuesserTest, longerguess)
{
  Guesser object("Uber");
  ASSERT_EQ(object.distance("UberHome"), 4);
}
TEST(GuesserTest, shorterguess)
{
  Guesser object("ChickenRice");
  ASSERT_EQ(object.distance("Chicken"), 4);
}
TEST(GuesserTest, waylongerguess)
{
  Guesser object("Secret");
  ASSERT_EQ(object.distance("Secrettttttttttttttttttttttttttttttttttttttttttttttttttttttt"), 6);
}
TEST(GuesserTest, emptyguess)
{
  Guesser object("Secret");
  ASSERT_EQ(object.distance(""), 6);
}

//CONSTRUCTOR TESTS
TEST(GuesserTest, perfectconstructor)
{
  //40 character guess
  Guesser object("hello");
  //32 character should be true
  ASSERT_TRUE(object.match("hello"));
}
TEST(GuesserTest, truncatedconstructor)
{
  //40 character guess
  Guesser object("1234567890123456789012345678901234567890");
  //32 character should be true
  ASSERT_TRUE(object.match("12345678901234567890123456789012"));
}

TEST(GuesserTest, thirtytwoconstructor)
{
  //32 character should not truncuate
  Guesser object("12345678901234567890123456789012");
  ASSERT_TRUE(object.match("12345678901234567890123456789012"));
}

//MATCH TESTS
TEST(GuesserTest, perfectmatch)
{
  Guesser object("Match");
  ASSERT_TRUE(object.match("Match"));
}
TEST(GuesserTest, resetmatch)
{
  Guesser object("Match");
  ASSERT_FALSE(object.match("Matcb"));
  ASSERT_FALSE(object.match("Matcw"));
  ASSERT_TRUE(object.match("Match"));
  //Reset guesses after correct one
  ASSERT_FALSE(object.match("Matck"));
  ASSERT_TRUE(object.match("Match"));
}
TEST(GuesserTest, smallwrongmatches)
{
  Guesser object("Match");
  ASSERT_FALSE(object.match("Matcb"));
  ASSERT_FALSE(object.match("Matcw"));
  ASSERT_FALSE(object.match("Matck"));
  ASSERT_FALSE(object.match("Match"));
}
TEST(GuesserTest, bruteforcematch)
{
  Guesser object("Match");
  ASSERT_FALSE(object.match("HelloTest"));
  ASSERT_FALSE(object.match("Match"));
}


