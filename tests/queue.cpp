#include <catch.hpp>
#include <sstream>

#include "graph.hpp"

TEST_CASE("Creating")
{
	graph graph1;
	REQUIRE(graph1.returnsize() == 0);
}

TEST_CASE("Creating")
{
	graph<int> graph1({{1,2},{3},{3},{}});
	std::ostringstream ostream:
	graph1.print(otream);
	REQUIRE(ostream.str() = "0: 1 2 \n"
				"1: 3 \n"
				"2: 3 \n"
				"3: \n";
}
		
TEST_CASE("DFS
{
	graph<int> graph1({{1,2},{3},{3},{}});
	std::ostringstream ostream:
	graph1.print(otream);
	REQUIRE(ostream.str() = 
}	

