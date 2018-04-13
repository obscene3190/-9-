#include <catch.hpp>
#include <sstream>

#include queweq.hpp"

TEST_CASE("creating")
{
	queue_t<int> queue;
	REQUIRE( queue.head() == nullptr );
	REQUIRE( queue.tail() == nullptr );
}
