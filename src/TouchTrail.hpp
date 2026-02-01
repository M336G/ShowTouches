// https://github.com/TheSillyDoggo/GeodeMenu/blob/1d67f0216adca9c37debc1e7267effb269e6df96/src/Hacks/Universal/ShowTouches/TouchTrail.hpp

#pragma once

class CCTouchTrail : public cocos2d::CCNode {
public:
    static inline std::unordered_map<cocos2d::CCTouch *, CCTouchTrail *> touches = {};
    cocos2d::CCTouch *touch;
    cocos2d::CCMotionStreak *streak;
    cocos2d::CCSprite *circle;

    bool init(cocos2d::CCTouch *touch);

    virtual void update(float dt);

    static CCTouchTrail *create(cocos2d::CCTouch *touch);
    static void remove(cocos2d::CCTouch *touch);
};