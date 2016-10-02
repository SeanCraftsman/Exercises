
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;
using Families = map<string, vector<string>>;

Families make_families()
{
    Families families;
    for (string ln; cout << "Last name:\n", cin >> ln && ln != "@q";)
        for (string cn; cout << "|-Children's names:\n", cin >> cn && cn != "@q";)
            families[ln].push_back(cn);
    return families;
}

void print(Families const& families)
{
    for (auto const& family : families)
    {
        cout << family.first << ":\n";
        for (auto const& child : family.second)
            cout << child << " ";
        cout << "\n";
    }
}

int main()
{
    print(make_families());
    return 0;
}
