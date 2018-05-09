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
    for (unsigned i = 0; i < in.size(); i++) {
	for (const auto& j : in[i]){
		if (j >= in.size()) {
			cout<<"Incorrect import";
			return 0;
		}
	}
    }
    size = roots.size();
  }
  
  
  
  vector<vector<T>> returnroots() {
    return roots;
  }
  
  unsigned int returnsize() {
    return size;
  }
  
  void print(std::ostream & stream) {
      for( unsigned int i = 0; i  < size; i++) {
        stream<<i<<": ";
        vector<T> help = roots[i];
        for(unsigned int j = 0; j<roots[i].size(); j++) {
          stream<<help[j]<<" ";
        }
        stream<<endl;
      }
    }
  
  vector<bool> alreadycheckedroots;
  void dfs(unsigned index) {
	for (unsigned i = 0; i < size; i++) {
		alreadycheckedroots.push_back(false);
	}
	alreadycheckedroots[index] = true;
	cout << index << " ";
	for (const auto& i : roots[index])
	{
		if (!alreadycheckedroots[i])
			dfs(i);
		}
	}
  ~graph() {}
};
