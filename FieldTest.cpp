/**
 * Unit Tests for Field class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "Field.h"
 
class FieldTest : public ::testing::Test
{
	protected:
		FieldTest(){}
		virtual ~FieldTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(FieldTest, placeMineInBounds)
{
	Field minefield;
	
	minefield.placeMine(4,5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(4,5) );
}


TEST(FieldTest, placeMineandCheckHidden)
{
        Field minefield;
 
        minefield.placeMine(3,2);
        ASSERT_FALSE(minefield.isSafe(3,2));
}

TEST(FieldTest, placemineandReveal)
{
       Field minefield;
  
       minefield.revealAdjacent(1,2);
       ASSERT_EQ(EMPTY_SHOWN, minefield.get(1,3));
}

TEST(FieldTest, placemineandRevealitself)
{
       Field minefield;
  
       minefield.revealAdjacent(4,2);
       ASSERT_EQ(EMPTY_SHOWN, minefield.get(4,2));
}

