#include <iostream>
#include <string>

struct Sales_data{
    std::string bookNo;
    unsigned int units_sold = 0;
    double revenue = 0.0;
};

bool input(Sales_data &item){
    double price;
    if(std::cin >> item.bookNo >> item.units_sold >> price){
        item.revenue = item.units_sold * price;
        return true;
    }
    else{
        return false;
    }
}

void add(Sales_data &item1, Sales_data &item2){
    item1.units_sold += item2.units_sold;
    item1.revenue += item2.revenue;
}

void output(Sales_data &item){
    std::cout << item.bookNo <<" "
            << item.units_sold << " "
            << item.revenue << std::endl;
}

int main(){
    Sales_data item1, item2;
    input(item1);
    while(input(item2)){
        if(item1.bookNo == item2.bookNo)
            add(item1 , item2);
        else{
            std::cout << "Data must refer to same ISBN" << std::endl;
        }
    }
    output(item1);
    return 0;
}

