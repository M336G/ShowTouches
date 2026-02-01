#include "TouchTrail.hpp"

#include <Geode/modify/CCTouchDispatcher.hpp>
class $modify(cocos2d::CCTouchDispatcher) {
	void touches(cocos2d::CCSet *touches, cocos2d::CCEvent *event, unsigned int type) {
		if (!cocos2d::CCScene::get())
			return CCTouchDispatcher::touches(touches, event, type);

		if (cocos2d::CCScene::get()->getChildByType<LoadingLayer>(0))
			return CCTouchDispatcher::touches(touches, event, type);

		CCTouchDispatcher::touches(touches, event, type);

		if (auto *touch = static_cast<cocos2d::CCTouch *>(touches->anyObject())) {
			if (type == cocos2d::CCTOUCHBEGAN && !geode::Mod::get()->getSettingValue<bool>("disable-show-touches"))
				cocos2d::CCScene::get()->addChild(CCTouchTrail::create(touch), cocos2d::CCScene::get()->getHighestChildZ() + 1);

			if (type >= cocos2d::CCTOUCHENDED)
				CCTouchTrail::remove(touch);
		}
	};
};