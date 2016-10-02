
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<std::string> exclude = { "aa", "bb", "cc", "dd", "ee", "ff" };
    for (std::string word; std::cout << "Enter :\n", std::cin >> word; )
    {
        auto is_excluded = std::binary_search(exclude.cbegin(), exclude.cend(), word);
        auto reply = is_excluded ? "excluded" : "not excluded";
        std::cout << reply << std::endl;
        if(!is_excluded){
            exclude.push_back(word);
            sort(exclude.begin(),exclude.end());
        }
    }

    return 0;
}
