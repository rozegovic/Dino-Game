#pragma once
#include <gui/View.h>
#include <gui/Label.h>
#include <gui/NumericEdit.h>
#include <gui/CheckBox.h>
#include <gui/ColorPicker.h>
#include <gui/Button.h>
#include <gui/GridLayout.h>
#include <gui/GridComposer.h>
#include <gui/Timer.h>
#include <gui/Sound.h>
#include "Dino.h"

const float FPS = 50.0f; //desired frame per second
const float dT = 1 / FPS;

class MainView : public gui::View
{
private:
protected:
    Dino _dino;
    gui::GridLayout _gl;
    gui::Timer _timer;
    std::function<void()>* _pUpdateMenuAndTB;
protected:

   
public:
    MainView(std::function<void()>* pUpdateMenuAndTB, std::function<void(td::INT1, int, int)>* pUpdateScrollBar)
    : _dino(pUpdateMenuAndTB, pUpdateScrollBar)
    , _gl(1, 1)
    , _timer(this, dT, false)
    , _pUpdateMenuAndTB(pUpdateMenuAndTB)
    {   
        gui::GridComposer gc(_gl);
        gc.appendRow(_dino);
        setLayout(&_gl);
    }

    void focusOnCanvas() 
    {
        _dino.setFocus(true);
    }
    bool isRunning() const
    {
        return _dino.isGameInProgress();
    }
    bool setGameDifficulty(Dino::Difficulty d)
    {
        return _dino.setDifficulty(d);
    }

    

    void startStop()
    {
        if (!isRunning()) {

            _timer.start();
            _dino.newGame();
            (*_pUpdateMenuAndTB)();
        }

    }

protected:
    bool onTimer(gui::Timer* pTimer) override
    {
        _dino.timeStep();
        return true;
    }

};
