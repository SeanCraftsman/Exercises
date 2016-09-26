#ifndef SCREEN_H
#define SCREEN_H
#include <string>

class Screen{
    friend class Window_mgr;
public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos ht, pos wd): height(ht), width(wd) , contents(ht*wd, ' ') {}
    Screen(pos ht, pos wd, char c): height(ht), width(wd),
        contents(ht*wd,c) {}
    char get() const
        { return contents[cursor]; }
    char get(pos ht, pos wd) const;
    Screen &move(pos r, pos c);
    void some_member() const;
    Screen &set(char);
    Screen &set(pos, pos, char);
    Screen &display(std::ostream &os) {
        do_display(os); return *this; }
    const Screen &display(std::ostream &os) const {
        do_display(os); return *this; }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
    mutable size_t access_ctr;
    void do_display(std::ostream &os) const {os << contents;}
};



#endif // SCREEN_H

