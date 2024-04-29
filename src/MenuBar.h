#pragma once
#include <gui/MenuBar.h>

class MenuBar : public gui::MenuBar
{
private:
    gui::SubMenu subFirst;
protected:
    void populateFirstMenu()
    {
        auto& items = subFirst.getItems();
        items[1].initAsQuitAppActionItem(tr("Quit"), "q");
    }

public:
    MenuBar()
    : gui::MenuBar(1)
    , subFirst(10, tr("theApp"), 3)
    {
        populateFirstMenu();
        _menus[0] = &subFirst;      
    }
   
    ~MenuBar()
    {
    }
};
