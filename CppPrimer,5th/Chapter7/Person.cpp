#include <iostream>
#include <string>
using namespace std;

class Person{
    friend istream &read(istream&, Person&);
    friend ostream &print(ostream&, const Person&);
public:
    Person() = default;
    Person(const std::string &s): name(s){ }
    Person(const std::string &n, const std::string &a):
        name(n), address(a) { }

    std::string getName() const { return name; }
    std::string getAddr() const { return address; }
private:
    std::string name;
    std::string address;
};

istream &read(istream& is, Person& item){
    is >> item.name >> item.address ;
    return is;
}

ostream &print(ostream &os, const Person &item){
    os << item.getName() << " " << item.getAddr() ;
    return os;
}
