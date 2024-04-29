#pragma once
#include <gui/ToolBar.h>
#include <gui/Image.h>
#include <gui/Symbol.h>

class ToolBar : public gui::ToolBar
{
    gui::Image _imgRun;
public:
    ToolBar()
    : gui::ToolBar("mainTB", 1)
    , _imgRun(":start")
    {
        initItem(0, tr("start"), &_imgRun, tr("startTT"), 20, 0, 0, 10);
    }


};

