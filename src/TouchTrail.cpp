// https://github.com/TheSillyDoggo/GeodeMenu/blob/1d67f0216adca9c37debc1e7267effb269e6df96/src/Hacks/Universal/ShowTouches/TouchTrail.cpp

#include "TouchTrail.hpp"

cocos2d::ccColor3B baseColor = cocos2d::ccc3(255, 255, 255);

bool CCTouchTrail::init(cocos2d::CCTouch *touch) {
    if (!CCNode::init())
        return false;

    touches.emplace(touch, this);

    this->touch = touch;
    this->scheduleUpdate();

    streak = cocos2d::CCMotionStreak::create(0.3f, 2, 10, baseColor, "streak_05_001.png");
    streak->setUserObject("ignore-longer-trail"_spr, cocos2d::CCBool::create(true));

    circle = cocos2d::CCSprite::createWithSpriteFrameName("d_circle_02_001.png");
    circle->setScale(0.2f);
    circle->setOpacity(128);

    auto clip = cocos2d::CCClippingNode::create(circle);
    clip->setAlphaThreshold(0.03f);
    clip->setInverted(true);

    clip->addChild(streak);

    this->addChild(clip);
    this->addChild(circle);
    return true;
};

void CCTouchTrail::update(float dt) {
    auto pos = touch->getLocation();

    streak->setPosition(pos);
    circle->setPosition(pos);

    circle->setColor(baseColor);
    streak->setColor(baseColor);
};

CCTouchTrail *CCTouchTrail::create(cocos2d::CCTouch *touch) {
    auto pRet = new CCTouchTrail();

    pRet->init(touch);

    return pRet;
};

void CCTouchTrail::remove(cocos2d::CCTouch *touch) {
    if (!touches.contains(touch))
        return;

    auto t = touches[touch];
    t->removeFromParent();

    touches.erase(touch);

    delete t;
};