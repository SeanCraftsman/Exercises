
auto find(vector<int>::const_iterator beg, vector<int>::const_iterator end, int num){
    for(; beg != end; ++beg){
        if(*beg == num) return beg;
    }
    return end;
}
