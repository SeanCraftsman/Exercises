#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <list>

int main(){
    std::vector<int> ivec = {1, 2, 3, 4, 5, 6, 5, 4, 6, 5};
    std::cout << std::count(ivec.begin(), ivec.end(), 5) << std::endl;
    std::vector<std::string> svec = {"abc","ab","abc","aa"};
    std::cout << std::count(svec.begin(), svec.end(), "abc") << std::endl;
    return 0;
}
