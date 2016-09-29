
bool contains(vector<int>::const_iterator begin, vector<int>::const_iterator end, int num){
    for(; begin != end; ++begin){
        if(*begin == num) return true;
    }
    return false;
}
