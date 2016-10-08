#ifndef StrBlob_H
#define StrBlob_H

#include <string>
#include <vector>
#include <initializer_list>
#include <memory>
#include <exception>

class StrBlobPtr;

class StrBlob{
public:
    typedef std::vector<std::string>::size_type size_type;
    friend class StrBlobPtr;

    StrBlobPtr begin();
    StrBlobPtr end();

    StrBlob();
    StrBlob(std::initializer_list<std::string> il);

    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }

    void push_back( const std::string &t) { data->push_back(t); }
    void pop_back();

    std::string& front();
    const std::string& front() const;
    std::string& back();
    const std::string& back() const;
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

class StrBlobPtr{
public:
    StrBlobPtr():curr(0) { }
    StrBlobPtr(StrBlob &a, size_t sz = 0):
        wptr(a.data), curr(sz) { }
    bool operator!=(const StrBlobPtr& p) { return p.curr!=curr; }
    std::string& deref() const;
    StrBlobPtr& incr();
private:
    std::shared_ptr<std::vector<std::string>>
        check(std::size_t, const std::string&) const;
    std::weak_ptr<std::vector<std::string>> wptr;
    std::size_t curr;
};


#endif // StrBlob_H
