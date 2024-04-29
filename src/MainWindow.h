#pragma once
#include <gui/Window.h>
#include "MenuBar.h"
#include "ToolBar.h"
#include "MainView.h"
//#include "StatusBar.h"
#include <functional>

class MainWindow : public gui::Window
{
protected:
    gui::Image _imgStart;
    gui::Image _imgStop;
    MenuBar _mainMenuBar;
    ToolBar _toolBar;
        
    std::function<void()> _fnUpdateMenuAndTB;
    
    std::function<void(td::INT1, int, int)> _fnUpdateStatusBar;
    
    MainView _mainView;
protected:
    
    void onInitialAppearance() override
    {
        _mainView.focusOnCanvas();
    }

    void updateMenuAndTB()
    {
        bool isRunning = _mainView.isRunning();
        
        gui::ToolBarItem* pTBItem = _toolBar.getItem(20, 0, 0, 10);
        if (pTBItem)
        {
            if (isRunning)
            {
                pTBItem->setImage(&_imgStop);
                //pTBItem->setLabel(tr("stop"));
                //pTBItem->setTooltip(tr("stopTT"));
            }
            else
            {
                pTBItem->setImage(&_imgStart);
                //pTBItem->setLabel(tr("start"));
                //pTBItem->setTooltip(tr("startTT"));
            }
        }
    }

    bool onActionItem(gui::ActionItemDescriptor& aiDesc) override
    {

        auto [menuID, firstSubMenuID, lastSubMenuID, actionID] = aiDesc.getIDs();

        if (menuID == 20 && firstSubMenuID== 0 && lastSubMenuID == 0)
        {
            switch (actionID)
            {
                case 10:
                {
                    _mainView.startStop();
                    return true;
                }
            }
        }
        return false;
    }
    
    void updateStatusBar(td::INT1 fruit, int fruitPts, int totalScore)
    {
        //_statusBar.updatePoints(fruit, fruitPts, totalScore);
    }
    
public:
    MainWindow()
    : gui::Window(gui::Size(1000, 600))
    , _imgStart(":start")
    , _imgStop(":stop")
    , _toolBar()
    , _fnUpdateMenuAndTB(std::bind(&MainWindow::updateMenuAndTB, this))
    , _fnUpdateStatusBar(std::bind(&MainWindow::updateStatusBar, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3))
    , _mainView(&_fnUpdateMenuAndTB, &_fnUpdateStatusBar)
    {
        
        setResizable(false);

        setTitle(tr("appTitle"));
        _mainMenuBar.setAsMain(this);
        setToolBar(_toolBar);
        setCentralView(&_mainView);

    }
    
    ~MainWindow()
    {
    }
    
};
