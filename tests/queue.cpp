#include <catch.hpp>
#include <sstream>

#include "queue.hpp"

TEST_CASE("Creating")
{
	queue<int> queue;
	REQUIRE( queue.gethead() == nullptr );
	REQUIRE( queue.gettrail() == nullptr );
}

TEST_CASE("Creating with copy")
{
	std::string result{"1  2  3  "};
	queue<int> queue2;
	queue2.push(1);
	queue2.push(2);
	queue2.push(3);
	queue<int> queue1(queue2);
	std::ostringstream ostream;
	queue1.print(ostream);
	REQUIRE( ostream.str() == result );
	
}

TEST_CASE("push pop")
{
	queue<int> queue;
	std::string result{"6  5  4  "};
	queue.push(6);
	queue.push(5);
	queue.push(4);
	std::ostringstream ostream;
	queue.print(ostream);
	REQUIRE( ostream.str() == result );
	std::string result1{"5  4  "};
	queue.pop();
	std::ostringstream ostream1;
	queue.print(ostream1);
	REQUIRE( ostream1.str() == result1 );
}

TEST_CASE("equals")
{
	queue<int> queue1;
	std::string result{"1  2  3  "};
	queue1.push(6);
	queue1.push(5);
	queue1.push(4);
	queue<int> queue2;
	queue2.push(1);
	queue2.push(2);
	queue2.push(3);
	std::ostringstream ostream;
	queue1 = queue2;
	queue1.print(ostream);
	REQUIRE( ostream.str() == result );
}

TEST_CASE("Out of range")
{
	queue<int> queue;
	REQUIRE_THROWS_AS( queue.pop() , std::out_of_range);
	
}


