#include<vector>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

template <typename T>
class graph {
private:
  vector<vector<T>> roots;
  unsigned int size;
  
public:
  graph() {
    size = 0;
  }
  
  graph(graph<T> &other) {
    roots = other.returnroots();
    size = roots.size();
  }
  
  graph(vector<vector<T>> inputroots) {
    roots = inputroots;
    size = roots.size();
  }
  
  
  
  vector<vector<T>> returnroots() {
    return roots;
  }
  
  void set_vertices(unsigned int vertices) {
    size = vertices;
  }
  
  void print(std::ostream & stream) {
    //if(roots) {
      for( unsigned int i = 0; i  < size; i++) {
        stream<<i+1<<": ";
        vector<T> help = roots[i];
        for(unsigned int j = 0; j<roots[i].size(); j++) {
          stream<<help[j]<<" ";
        }
        stream<<endl;
      }
    }
  //}
  
  ~graph() {};
  
/*	void read();
	Graph operator = (Graph & other);
	void dfs(unsigned index);
	void input(vector < vector<unsigned> > & in); */
};

int main() {
    graph<int> graph1({{ 1 },{ 2,6 },{4,5},{},{}});
    //graph1.print(cout);
    graph<int> graph12(graph1);
    graph12.print(cout);
}
