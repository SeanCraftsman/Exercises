#include <fstream>
#include <iostream>
#include "StrBlob.h"

int main(){
    std::ifstream ifs("../message/letter.txt");
    StrBlob blob;
    for (std::string str; std::getline(ifs, str); )
        blob.push_back(str);
    for (StrBlobPtr ptr(blob.begin()), Bend(blob.end()); ptr != Bend; ptr.incr())
        std::cout << ptr.deref() << std::endl;
}
