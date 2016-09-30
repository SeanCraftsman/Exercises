#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::vector<std::string> v;
    for (std::string buffer; std::cin >> buffer; v.push_back(buffer))
        std::cout << "Size: "<<v.size()
                  << " Capacity: "<<v.capacity() << std::endl;

    return 0;
}
