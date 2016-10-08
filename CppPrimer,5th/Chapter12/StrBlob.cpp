
#include "StrBlob.h"

using std::vector; using std::string;
using std::initializer_list;
using std::make_shared;

StrBlob::StrBlob(): data(make_shared<vector<string>>()) { }
StrBlob::StrBlob( initializer_list<string> il ):
    data(make_shared<vector<string>>(il)) { }

void StrBlob::check(size_type i, const string &msg) const
{
    if (i >= data->size())
        throw std::out_of_range(msg);
}

string& StrBlob::front(){
    check(0, "front on empty StrBlob");
    return data->front();
}

string& StrBlob::back(){
    check(0, "back on empty StrBlob");
    return data->back();
}

const string& StrBlob::front() const {
    check(0, "front on empty StrBlob");
    return data->front();
}

const string& StrBlob::back() const {
    check(0, "back on empty StrBlob");
    return data->back();
}

void StrBlob::pop_back(){
    check(0, "pop_back on empty StrBlob");
    data->pop_back();
}

std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string &msg) const
{
    auto ret = wptr.lock();
    if (!ret){
        throw std::runtime_error("unbound StrBlobPtr");
    }
    if ( i >= ret->size()){
        throw std::out_of_range(msg);
    }
    return ret;
}

string& StrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr(){
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

StrBlobPtr StrBlob::begin(){
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end(){
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

std::shared_ptr<std::vector<std::string>>
ConstStrBlobPtr::check(std::size_t i, const std::string &msg) const
{
    auto ret = wptr.lock();
    if (!ret){
        throw std::runtime_error("unbound StrBlobPtr");
    }
    if ( i >= ret->size()){
        throw std::out_of_range(msg);
    }
    return ret;
}

const string& ConstStrBlobPtr::deref() const
{
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}


ConstStrBlobPtr& ConstStrBlobPtr::incr(){
    check(curr, "increment past end of StrBlobPtr");
    ++curr;
    return *this;
}

ConstStrBlobPtr StrBlob::begin() const {
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const{
    return ConstStrBlobPtr(*this, data->size());
}
