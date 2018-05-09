#include<vector>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

template <typename T>
class graph {
private:
  vector<vector<T>> roots;
  unsigned int sizeg;
  
public:
  graph() {
    sizeg = 0;
  }
  
  graph(graph<T> &other) {
    roots = other.returnroots();
    sizeg = roots.size();
  }
  
  graph(vector<vector<T>> inputroots) {
    roots = inputroots;
    sizeg = roots.size();
  }
  
  
  
  vector<vector<T>> returnroots() {
    return roots;
  }
  
  unsigned int returnsize() {
    return sizeg;
  }
  
  void set_vertices(unsigned int vertices) {
    sizeg = vertices;
  }
  
  void print(std::ostream & stream) {
    //if(roots) {
      for( unsigned int i = 0; i  < sizeg; i++) {
        stream<<i<<": ";
        vector<T> help = roots[i];
        for(unsigned int j = 0; j<roots[i].size(); j++) {
          stream<<help[j]<<" ";
        }
        stream<<endl;
      }
    }
  //}
  
  vector<bool> used;
  vector<unsigned> result;
  void dfs(unsigned index) {
	for (unsigned i = 0; i < sizeg; i++) {
		used.push_back(false);
	}
	used[index] = true;
	result.push_back(index);
	for (const auto& i : roots[index])
	{
		if (!used[i])
			dfs(i);
	}
}
  void printresult() {
    for (unsigned i = 0; i < result.size(); i++) {
		cout<<result[i]<<" ";
	}         
  }
  ~graph() {};
  
/*	void read();
	Graph operator = (Graph & other);
	void dfs(unsigned index);
	void input(vector < vector<unsigned> > & in); */
};

int main() {
    graph<int> graph1({{ 1 },{ 2,6 },{4,5},{},{}});
    //graph1.print(cout);
    if(graph1.returnsize()) {
    cout<<graph1.returnsize()<<" ";}
    else cout<<"nothing";
    graph1.dfs(0);
    graph1.printresult();
}
