#ifndef ex_12_27_H
#define ex_12_27_H

#include <string>
using std::string;
#include <vector>
using std::vector;
#include <memory>
using std::shared_ptr;

#include <iostream>
#include <fstream>
#include <map>
#include <set>

class QueryResult;
class TextQuery{
public:
    using LineNo = vector<string>::size_type;
    TextQuery(std::ifstream&);
    QueryResult query(const string&) const;
private:
    shared_ptr<vector<string>> input;
    std::map<string, shared_ptr<std::set<LineNo>>> result;
};

class QueryResult{
public:
    friend std::ostream& print(std::ostream&, const QueryResult&);
    QueryResult(const string &s, shared_ptr<std::set<TextQuery::LineNo>> sets,
                 shared_ptr<vector<string>> v) : word(s), nos(sets), input(v) { }
private:
    string word;
    shared_ptr<std::set<TextQuery::LineNo>> nos;
    shared_ptr<vector<string>> input;
};

std::ostream& print(std::ostream &, const QueryResult&);

#endif // 12_27_H
