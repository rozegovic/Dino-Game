#pragma once
#include <gui/Canvas.h>
#include <gui/Shape.h>
#include <math/math.h>
#include <gui/Image.h>
#include <gui/Symbol.h>
#include <gui/Transformation.h>
#include <math/Constants.h>
#include <math/math.h>
#include <gui/DrawableString.h>
#include <gui/Sound.h>
#include <random>
#include <cnt/FullQueue.h>
#include <vector>
#include <chrono>
#include <thread>
#include <gui/Timer.h>
#include "MainView.h"



class Dino : public gui::Canvas
{

public:
    enum class Difficulty { EASY = 0, MEDIUM, HARD };

protected:
    const gui::CoordType _difficultySpeed[3] = { 2.5, 5., 10. };
    enum class Direction { NONE, LEFT, RIGHT, UP, DOWN };

protected:


    std::function<void()>* _pUpdateMenuAndTB;  
    std::function<void(td::INT1, int, int)>* _pUpdateScrollBar;

    

    gui::Image cactusBiggest[6]{ (":21"), (":22"), (":23"), (":24"), (":25"), (":26") };

    gui::CoordType c21width = 496 + 1000, c21height = 341, c21size = 45,
                   c22width = 480 + 1000, c22height = 315, c22size = 110,
                   c23width = 529 + 1000, c23height = 336, c23size = 45,
                   c24width = 543 + 1000, c24height = 328, c24size = 45,
                   c25width = 527 + 1000, c25height = 315, c25size = 110,
                   c26width = 576 + 1000, c26height = 338, c26size = 45;

    gui::Rect rect21 = {
            c21width, c21height, c21size
    };

    gui::Rect rect22 = {
        c22width, c22height, c22size
    };

    gui::Rect rect23 = {
        c23width, c23height, c23size
    };

    gui::Rect rect24 = {
            c24width, c24height, c24size
    };

    gui::Rect rect25 = {
        c25width, c25height, c25size
    };

    gui::Rect rect26 = {
        c26width, c26height, c26size
    };


    gui::Image cactus[3]{ (":11"), (":12"), (":13") };

    gui::CoordType c11width = 1000 + 196, c11height = 341, c11size =  45,
                   c12width = 1000 + 180, c12height = 315, c12size = 110, 
                   c13width = 1000 + 229, c13height = 338, c13size = 45;

    gui::Rect rect11 = {
            c11width, c11height, c11size
    };

    gui::Rect rect12 = {
        c12width, c12height, c12size
    };

    gui::Rect rect13 = {
        c13width, c13height, c13size
    };


    gui::Image dinoJump[4]{ (":d1"), (":d2"), (":d3"), (":d4") };

    gui::CoordType d1width = 475 - 466, d1height = 339.5, d1size = 58,
                   d2width = 492 - 466, d2height = 339, d2size = 80,
                   d3width = 499.5 - 466, d3height = 300, d3size = 120,
                   d4width = 554.5 - 466, d4height = 301.5, d4size = 64.5;

    gui::Rect drect1 = {
        d1width, d1height, d1size
    };

    gui::Rect drect2 = {
        d2width, d2height, d2size
    };

    gui::Rect drect3 = {
        d3width, d3height, d3size
    };

    gui::Rect drect4 = {
        d4width, d4height, d4size
    };

   
    // dinorectove dodati i nacrtati sliku 

    gui::Image _dinoRun1;
    gui::Image _dinoRun2;
    gui::Image _dinoJump;
    gui::Image _dinoSlide1;
    gui::Image _dinoSlide2;
    gui::Image _dinoDead;
    gui::Image _track;
    gui::Image _cactus[2]{ (":cactus1"), (":cactus2") };
    gui::Image _cactusBig[2]{ (":big_cactus1"), (":big_cactus2") };


    gui::Image _title;
    gui::Image _board;

    gui::Image _birdFly1;
    gui::Image _birdFly2;
;
    gui::Point _dinoPos;

    gui::CoordType _dinoHeight, _dinoWidth, _dinoSize, _dinoMaxJump;
    gui::CoordType _trackLength, _trackHeight, _trackSize, _trackUpdateLength;

    gui::CoordType _cactusBigHeight, _cactusBigWidth, _cactusBigSize, _cactusBigMovingWidth;

    gui::CoordType _birdHeight, _birdWidth, _birdSize, _birdMovingWidth;
    gui::CoordType _cloudHeight, _cloudWidth, _cloudSize, _cloudMovingWidth;
    gui::CoordType _cloudWidth2, _cloudHeight2, _cloudSize2, _cloudMovingWidth2;




    gui::Rect _dinoRect, _dinoSlideRect, _dinoCollisionRect;
    gui::Rect _trackRect;
    gui::Rect _cactusRect, _cactusBigRect, _cactusBiggestRect;
    gui::Rect _birdRect;

    td::INT1  _currentCactusBig;
    td::INT1 _currentDistance;

    gui::Image _gameOverImage;
    gui::Rect _gameOverRect;

    bool _jump = false;
    bool _slide = false;
    bool _jumpRequested = false;
    bool _dead = false;
    bool _land = false;

    gui::Rect _titleRect;

    gui::Image _cloud = (":cloud");
    gui::Image _cloud2 = (":cloud");

    gui::Rect _cloudRect, _cloudRect2;

    gui::Size _size;

    bool _gameInProgress = false;
    Direction _direction = Direction::NONE;
    Difficulty _difficulty = Difficulty::HARD;
    gui::CoordType _stepSize = _difficultySpeed[static_cast<int>(_difficulty)];

    gui::Shape _bounds;
    gui::CoordType _boundsSize = 4.; //debljina kaveza oko arene
    gui::Rect _boundsRect;
    
    gui::CoordType _minimumDistanceFromPreviousCactus = 190;


    int _currentDino = 0;

    bool _gameOver = false;
    bool _restartGame = false;
    gui::Image _gameOverImg;
    int _score = 0;
    
    td::String _scoreString;

    std::random_device _randomDevice;
    std::mt19937 _rng;
    
    gui::Sound _soundBackground;
    gui::Sound _soundEating;
    gui::Sound _soundGameOver;
    gui::Sound _runDinorun;
    td::INT4 _highScore = 0;
    td::WORD _stepState = 0;
    td::BYTE _openMouth = 0;

    bool _moveDone = false;


    bool _moveWhenPressed = false;
    bool _keyPressed = false;

    bool _gamePaused = false;

    td::INT4 _scoreMult = 6.;

public:
    Dino(std::function<void()>* pUpdateMenuAndTB, std::function<void(td::INT1, int, int)>* pUpdateScrollBar)
    : gui::Canvas({ gui::InputDevice::Event::Keyboard })
    , _pUpdateMenuAndTB(pUpdateMenuAndTB)
    , _pUpdateScrollBar(pUpdateScrollBar)
    , _dinoRun1(":dino1")
    , _dinoRun2(":dino2")
    , _dinoJump(":dinojump")
    , _dinoSlide1(":dinoslide1")
    , _dinoSlide2(":dinoslide2")
    , _dinoDead(":dinodead")
    , _track(":track")
    , _cloud(":cloud")
    , _birdFly1(":birdfly1")
    , _birdFly2(":birdfly2")
    , _gameOverImage(":gameover")
    , _title(":title")
    , _gameOverImg(":gameover")
    , _rng(_randomDevice())
    , _soundBackground(":background")
    , _runDinorun(":rundinorun")
    , _soundEating(":jump")
    , _soundGameOver(":die")
    {

        _highScore = getApplication()->getProperties()->getValue("snakeHS", 0);
        _difficulty = static_cast<Difficulty>(getApplication()->getProperties()->getValue("snakeD", 2));
        _stepSize = _difficultySpeed[static_cast<int>(_difficulty)];
        _scoreMult = static_cast<td::INT4>(_difficulty) + 1;
        enableResizeEvent(true);

        _titleRect = {
            500,
            300,
            100
        };

        _gameOverRect = {
            250,
            -100,
            450
        };

        _dinoWidth = 20;           
        _dinoHeight = 300;
        _dinoSize = 120;
        _dinoMaxJump = 175;

        _cactusBigWidth = 650;
        _cactusBigHeight = 320;
        _cactusBigSize = 100;
        _cactusBigMovingWidth = 1500;

        _birdWidth = 400;
        _birdHeight = 100;
        _birdSize = 100;
        _birdMovingWidth = 900;

        _cloudWidth = 500;
        _cloudHeight = 200;
        _cloudSize = 150;
        _cloudMovingWidth = 500;

        _cloudWidth2 = 200;
        _cloudHeight2 = 100;
        _cloudSize2 = 150;
        _cloudMovingWidth2 = 200;


        _dinoRect = {
            _dinoWidth,
            _dinoHeight,
            _dinoSize,
        };

        _dinoSlideRect = {
            _dinoWidth + 5,
            _dinoHeight + 15,
            _dinoSize + 20
        };

        _dinoCollisionRect = {
            _dinoWidth + 25,
            _dinoHeight,
            _dinoSize - 50 
        };

        _trackHeight = 0;
        _trackLength = -100;
        _trackSize = 1000;

        _trackUpdateLength = 1000;

        _trackRect = {
            _trackHeight,
            _trackLength,
            _trackSize
        };

        _cactusBigRect = {
            _cactusBigWidth,
            _cactusBigHeight,
            _cactusBigSize
        };

        _birdRect = {
            _birdWidth,
            _birdHeight,
            _birdSize
        };

        _cloudRect = {
            _cloudWidth,
            _cloudHeight,
            _cloudSize
        };

        _cloudRect2 = {
            _cloudWidth2,
            _cloudHeight2,
            _cloudSize2
        };
       
    }

    bool isGameInProgress() const
    {
        return _gameInProgress;
    }

    bool setDifficulty(Difficulty d)
    {
        if (_gameInProgress)
            return false;
        _difficulty = d;
        _stepSize = _difficultySpeed[static_cast<int>(d)];
        _scoreMult = static_cast<td::INT4>(_difficulty) + 1;
        getApplication()->getProperties()->setValue("snakeD", static_cast<int>(_difficulty));

        return true;
    }

    void newGame()
    {
        _gameInProgress = true;
        _gameOver = false;
        _direction = Direction::NONE;
         
        rect11 = {
            c11width = 1000 + 196,
            c11height = 341,
            c11size = 45
        };
        rect12 = {
            c12width = 1000 + 180,
            c12height = 315,
            c12size = 110
        };
        rect13 = {
            c13width = 1000 + 229,
            c13height = 338,
            c13size = 45
        };
        reDraw();
    }

    td::INT4 getScore() {
        return _score;
    }

    void timeStep()
    {
        ++_stepState;
        if (_stepState > 5)
        {
            if (_openMouth == 1)
                _openMouth = 0;
            else
                _openMouth = 1;

            _stepState = 0;
        }

        if (!_gameOver) {

            handleDinoMovement();
            handleBirdMovement();
            handleCloudMovement();
            /*handleCactusBigMovement();*/
            handleCactusMovement();
            handleCloudMovement2();
        }

        reDraw();
    }

    void onCollision() {
        cactus[0].draw(rect11);
        cactus[1].draw(rect12);
        cactus[2].draw(rect13);

        /*cactusBiggest[0].draw(rect21);
        cactusBiggest[1].draw(rect22);
        cactusBiggest[2].draw(rect23);
        cactusBiggest[3].draw(rect24);
        cactusBiggest[4].draw(rect25);
        cactusBiggest[5].draw(rect26);*/

        _dinoDead.draw(_dinoRect);
    }
    
    void setGameOver()
    {
        //_soundGameOver.play();

        //_gameInProgress = false;
        _direction = Direction::NONE;
        _gameOver = true;
        _gameOverImage.draw(_gameOverRect);
        _track.draw(_trackRect);
        onCollision();
        _gameInProgress = false;
        reDraw();
    }

protected:

    void onResize(const gui::Size& newSize) override
    {
        _size = newSize;
        auto offset = _boundsSize / 2.;
        gui::Point tl{ offset, offset }, br{ _size.width - offset, _size.height - offset };
        _boundsRect = { tl, br };
        _bounds.createRect(_boundsRect, _boundsSize);
    }


    void drawGameOver(const gui::Rect& rect)
    {
        _gameOverImg.draw(rect);
        gui::DrawableString scoreShow(_scoreString);
        gui::Size sz;
        scoreShow.measure(gui::Font::ID::SystemLargestBold, sz);
        gui::Point sp = { 0.5 * (_size.width - sz.width)  , 0.6 * _size.height };

        scoreShow.draw(sp, gui::Font::ID::SystemLargestBold, td::ColorID::Red);
    }

    void onDraw(const gui::Rect& rect) override
    {

        _bounds.drawFillAndWire(td::ColorID::White, td::ColorID::DarkGray);

        if (!_gameInProgress) {
            _dinoJump.draw(_dinoRect);
            _track.draw(_trackRect);
        }

        if (_gameOver)
        {
            setGameOver();
            return;
        }

        if (_gameInProgress)
        {
            cactus[0].draw(rect11);
            cactus[1].draw(rect12);
            cactus[2].draw(rect13);

            cactusBiggest[0].draw(rect21);
            cactusBiggest[1].draw(rect22);
            cactusBiggest[2].draw(rect23);
            cactusBiggest[3].draw(rect24);
            cactusBiggest[4].draw(rect25);
            cactusBiggest[5].draw(rect26);

            _cloud.draw(_cloudRect);
            _cloud2.draw(_cloudRect2);
            _track.draw(_trackRect);
            
            if (_openMouth) {
                _birdFly1.draw(_birdRect);
            }
            else {
                _birdFly2.draw(_birdRect);
            }
            
            if (_jump) {
                if (_currentDino == 1) {
                    //_dinoJump.draw(_dinoRect);

                    dinoJump[0].draw(drect1);
                    dinoJump[1].draw(drect2);
                    dinoJump[2].draw(drect3);
                    dinoJump[3].draw(drect4);

                }
            }
            else if (_land) {
                if (_currentDino == 1) {
                    //_dinoJump.draw(_dinoRect);

                    dinoJump[0].draw(drect1);
                    dinoJump[1].draw(drect2);
                    dinoJump[2].draw(drect3);
                    dinoJump[3].draw(drect4);
                }
            }
            else if (_slide) {
                if (_currentDino == 2) {
                    if (_openMouth) {
                        _dinoSlide1.draw(_dinoSlideRect);
                    }
                    else {
                        _dinoSlide2.draw(_dinoSlideRect);
                    }
                }
            }
            else if (_dead) {
                _dinoDead.draw(_dinoRect);

            }
            else {
                if (_openMouth) {
                    _dinoRun1.draw(_dinoRect);
                }
                else {
                    _dinoRun2.draw(_dinoRect);
                }
            } 
            _moveDone = false;
        }

    }


    

    void checkCollisionWithCactus() 
    {  
        if (_jump || _land) {
            if (drect3.intersects(rect13)) {
                _gameOver = true;
            }
            /*if (drect1.intersects(rect11)) {
                _gameOver = true;
            }*/
        }

        if (!_jump) {
            if (_dinoRect.intersects(rect11)) {
                _gameOver = true;
            }
            /*if (_dinoRect.intersects(rect11)) {
                _gameOver = true;
            }*/
        }
    }

    void handleCactusMovement() {

        c11width -= 20;
        c12width -= 20;
        c13width -= 20;
        rect11 = {
            c11width,
            c11height,
            c11size
        };
        rect12 = {
            c12width,
            c12height,
            c12size
        };
        rect13 = {
            c13width,
            c13height,
            c13size
        };

        if (/*c11width < 0 && c12width < 0 && */c13width < 0) {
            td::INT4 randomDistance = generateRandomNumber(2000, 2500);
            c11width = randomDistance + 196;
            c12width = randomDistance + 180;
            c13width = randomDistance + 229;
        }
        
    }

    td::INT4 generateRandomNumber(td::INT4 lowerBound, td::INT4 upperBound) {
        std::random_device rd;
        std::mt19937 generator(rd());
        std::uniform_int_distribution<td::INT4> distribution(lowerBound, upperBound);
        return distribution(generator);
    }

    void handleCactusBigMovement()
    {
        c21width -= 20;
        c22width -= 20;
        c23width -= 20;
        c24width -= 20;
        c25width -= 20;
        c26width -= 20;

        rect21 = {
            c21width,
            c21height,
            c21size
        };

        rect22 = {
            c22width,
            c22height,
            c22size
        };

        rect23 = {
            c23width,
            c23height,
            c23size
        };

        rect24 = {
            c24width,
            c24height,
            c24size
        };

        rect25 = {
            c25width,
            c25height,
            c25size
        };

        rect26 = {
            c26width,
            c26height,
            c26size
        };

        if (c21width < 0 && c22width < 0 && c23width < 0 && c24width < 0 && c25width < 0 && c26width < 0) {
            td::INT4 randomDistance = generateRandomNumber(1000, 1500);
            c21width = randomDistance + 496;
            c22width = randomDistance + 480;
            c23width = randomDistance + 529;
            c24width = randomDistance + 543;
            c25width = randomDistance + 527;
            c26width = randomDistance + 576;
        }
    }

    void handleTrackMovement()
    {

        _trackUpdateLength -= _stepSize;
        _trackRect = {
            _trackUpdateLength,
            _trackHeight,
            _trackSize
        };
    }

    void handleBirdMovement() {
        _birdMovingWidth -= 5;
        _birdRect = {
            _birdMovingWidth,
            _birdHeight,
            _birdSize
        };

        if (_birdMovingWidth + _birdWidth < 0) {
            _birdMovingWidth = 900;
        }
    }

    void handleCloudMovement() {
        _cloudMovingWidth -= 1;
        _cloudRect = {
            _cloudMovingWidth,
            _cloudHeight,
            _cloudSize
        };

        if (_cloudMovingWidth + _cloudWidth < 0) {
            _cloudMovingWidth = 900;
        }
    }


    void handleCloudMovement2() {
        _cloudMovingWidth2 -= 1;
        _cloudRect2 = {
            _cloudMovingWidth2,
            _cloudHeight2,
            _cloudSize
        };

        if (_cloudMovingWidth2 - _stepSize < 0) {
            _cloudMovingWidth2 = 1300;
        }
    }

    void handleDinoMovement()
    {
        if (_gameOver)
            return;

        if (_gamePaused)
            return;


        if (_moveWhenPressed && !_keyPressed)
            return;

        int _jumpStep = 20; // 15
        int _landStep = 18; // 10

        if (_jumpRequested)
        {
            _jump = true;
            _jumpRequested = false;
            _land = false;
        }

        if (_jump)
        {
            _dinoRect.top -= _jumpStep;
            _dinoRect.bottom -= _jumpStep;


            // glavni dio za skok
            drect1.top -= _jumpStep;
            drect2.top -= _jumpStep;
            drect3.top -= _jumpStep;
            drect4.top -= _jumpStep;
            drect1.bottom -= _jumpStep;
            drect2.bottom -= _jumpStep;
            drect3.bottom -= _jumpStep;
            drect4.bottom -= _jumpStep;
            

            /*if (_dinoRect.top <= _dinoHeight - 250)
            {
                
                _jump = false;
                _currentDino = 1;
                _land = true;
            }*/

            if (drect1.top <= _dinoHeight - 220 && drect2.top <= _dinoHeight - 220 && drect3.top <= _dinoHeight - 220 && drect4.top <= _dinoHeight - 220)
            {

                _jump = false;
                _currentDino = 1;
                _land = true;
            }

        }
        else
        {
            if (drect3.top < _dinoHeight) // _dinoRect.top
            {
                _dinoRect.top += _landStep;
                _dinoRect.bottom += _landStep;

                drect1.top += _landStep;
                drect2.top += _landStep;
                drect3.top += _landStep;
                drect4.top += _landStep;
                drect1.bottom += _landStep;
                drect2.bottom += _landStep;
                drect3.bottom += _landStep;
                drect4.bottom += _landStep;

                _currentDino = 1;
            }
            else
            {
                _dinoRect.top = _dinoHeight;                
                _dinoRect.bottom = _dinoHeight + _dinoSize;
                _land = false;
            }
        }

        if (!_gameOver) {
            checkCollisionWithCactus();
        }
    }

    bool onKeyReleased(const gui::Key& key) override
    {
        if (key.getVirtual() == gui::Key::Virtual::Down)
        {
            _slide = false;
        }

        _keyPressed = false;
        return true;
    }

    bool onKeyPressed(const gui::Key& key) override
    {
        _keyPressed = true;

        if (td::toUpper(key.getChar()) == 'P')
        {
            _gamePaused = !_gamePaused;
            return true;
        }

        if (_gamePaused)
            return true;

        if (_moveDone)
            return true;

        if (!_jump && key.getVirtual() == gui::Key::Virtual::Up)
        {
            _direction = Direction::UP;
            _jumpRequested = true;
            _currentDino = 1;
            _moveDone = true;
            return true;
        }

        if (key.getVirtual() == gui::Key::Virtual::Down && !_land && !_jump)
        {
            _direction = Direction::DOWN;
            _slide = true;
            _currentDino = 2;
            _moveDone = true;
            return true;
        }

        if (_direction == Direction::NONE)
        {
            
             if (!_jump && key.getVirtual() == gui::Key::Virtual::Up)
            {
                /*if (_gameInProgress)
                    _soundBackground.play(true);*/

                _direction = Direction::UP;
            }
            else if (key.getVirtual() == gui::Key::Virtual::Down)
            {
                /*if (_gameInProgress)
                    _soundBackground.play(true);*/

                _direction = Direction::DOWN;
            }
            return true;
        }

        return false;
    }

    

};
