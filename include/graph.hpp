#include<vector>
#include<iostream>
#include<string>
#include<sstream>

#include <stdexcept>
using namespace std;

template <typename T>
class graph {
private:
  vector<vector<T>> nodes;
  unsigned int size;
  
public:
  graph() {
    size = 0;
  }
  
  graph(graph<T> &other) {
    roots = other.returnnodes();
    size = nodes.size();
  }
  
  graph(vector<vector<T>> inputnodes) {
    nodes = inputnodes;
    for (unsigned i = 0; i < inputnodes.size(); i++) {
	for (const auto& j : inputnodes[i]){
		if (j >= inputnodes.size()) {
			cout<<"Incorrect import";
			throw length_error("No such root");
		}
	}
    }
    size = nodes.size();
  }
  
  
  
  vector<vector<T>> returnnodes() {
    return nodes;
  }
  
  unsigned int returnsize() {
    return size;
  }
  
  void print(std::ostream & stream) {
      for( unsigned int i = 0; i  < size; i++) {
        stream<<i<<": ";
        vector<T> help = nodes[i];
        for(unsigned int j = 0; j<nodes[i].size(); j++) {
          stream<<help[j]<<" ";
        }
        stream<<endl;
      }
    }
  
	vector<bool> checkednodes;
  void dfs(unsigned index, std::ostream & stream ) {
	//неверно
	for (unsigned i = 0; i < size; i++) {
		checkednodes.push_back(false);
	}
	checkednodes[index] = true;
	checkednodes.push_back(index);
	for (const auto& i : nodes[index])
	{
		if (!checkednodes[i])
			dfs(i,stream); // dfs(i,cout)
		}
	}
	void printdepth(std::ostream & stream) {
		for(unsigned int i = 0; i<checkednodes.size(); i++) {
			stream<<checkednodes[i]<<" ";
		}
	}
  ~graph() {
  	nodes.clear();
	size = 0;  
  }
};
