#ifndef Window_mgr_H
#define Window_mgr_H
#include <vector>
#include "Screen.h"

class Window_mgr{
public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
    ScreenIndex addScreen(const Screen&);
private:
    std::vector<Screen> screens{Screen(24, 80, ' ')};
};


#endif // Window_mgr_H
