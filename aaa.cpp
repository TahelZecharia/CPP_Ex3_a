#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main(){
    vector<double> mat2(10000, 0.0); 
	int j = 0;
	for (auto i: mat2) {
		j++;
    	std::cout << i << '\n'; // will print: "a b c"
	}
	std::cout << mat2.size()   << '\n';
	
	vector<double> mat22(100); 

	std::cout << mat22.size()   << '\n';
    return 0;
}