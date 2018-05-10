#include <catch.hpp>
#include <sstream>

#include "graph.hpp"

TEST_CASE("Creating")
{
	graph<int> graph1;
	REQUIRE(graph1.returnsize() == 0);
}

TEST_CASE("Creating with init")
{
	graph<int> graph1({{1,2},{3},{3},{}});
	std::ostringstream ostream;
	graph1.print(ostream);
	REQUIRE(ostream.str() == "0: 1 2 \n"
				"1: 3 \n"
				"2: 3 \n"
				"3: \n");
}
		
TEST_CASE("DFS")
{
	graph<int> graph1({{1,2},{3},{3},{}});
	std::ostringstream ostream;
	graph1.dfs(0);
	graph1.printdepth(ostream);
	REQUIRE(ostream.str() == "0 1 3 2 ");
}

TEST_CASE("Inserting")
{
	graph<int> graph1({{1,2},{3},{3},{}});
	std::ostringstream ostream;
	graph1.insert({{1},{2},{3}});
	graph1.print(ostream);
	REQUIRE(ostream.str() == "0: 1 2 \n"
				"1: 3 \n"
				"2: 3 \n"
				"3: \n"
	       			"4: 1 2 3 \n");
}

