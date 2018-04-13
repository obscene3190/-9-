#include <catch.hpp>
#include <sstream>

#include queue.hpp"

TEST_CASE("creating")
{
	queue_t<int> queue;
	REQUIRE( queue.head() == nullptr );
	REQUIRE( queue.tail() == nullptr );
}

TEST_CASE("push pop")
{
	queue_t<int> queue;
	std::string result1{"6  5  4  "};
	queue.push(6);
	queue.push(5);
	queue.push(4);
	std::ostringstream ostream;
	queue.print(ostream);
	REQUIRE( ostream.str() == result );
	std::string result1{"5  4  "};
	std::ostringstream ostream1;
	queue.print(ostream1);
	REQUIRE( ostream1.str() == result1 );
}

TEST_CASE("equals")
{
	queue_t<int> queue1;
	std::string result1{"1  2  3  "};
	queue1.push(6);
	queue1.push(5);
	queue1.push(4);
	queue_t<int> queue2;
	queue2.push(1);
	queue2.push(2);
	queue2.push(3);
	std::ostringstream ostream;
	queue1 = queue2;
	queue1.print(ostream);
	REQUIRE( ostream.str() == result );
}


