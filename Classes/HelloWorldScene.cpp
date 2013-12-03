#include "HelloWorldScene.h"

USING_NS_CC;

CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
	
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
	
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

	CCMenuItemImage* pMenuItem2 = CCMenuItemImage::create("CloseSelected.png","CloseNormal.png",this,menu_selector(HelloWorld::alertDialog));

	//pMenuItem2->setPosition(ccp(100,100));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
	CCMenu* pMenu2 = CCMenu::create(pMenuItem2,NULL);
	pMenu2->setPosition(ccp(150,150));
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);
	this->addChild(pMenu2,1);


	CCTexture2D* pTexture = CCTextureCache::sharedTextureCache()->addImage("girls.png");
	//CCSpriteFrame* frame0=CCSpriteFrame::create(pTexture,CCRectMake(32*0,48*0,32,48));
	CCSpriteFrame* frame0 = CCSpriteFrame::createWithTexture(pTexture,CCRectMake(32*0,48*0,32,48));
	CCSpriteFrame* frame1 = CCSpriteFrame::createWithTexture(pTexture,CCRectMake(32*1,48*0,32,48));
	CCSpriteFrame* frame2 = CCSpriteFrame::createWithTexture(pTexture,CCRectMake(32*2,48*0,32,48));
	CCSpriteFrame* frame3 = CCSpriteFrame::createWithTexture(pTexture,CCRectMake(32*3,48*0,32,48));
	CCArray* pArray = CCArray::createWithCapacity(4); 

	pArray->addObject(frame0); 
	pArray->addObject(frame1); 
	pArray->addObject(frame2); 
	pArray->addObject(frame3); 
 
	CCAnimation* animation = CCAnimation::createWithSpriteFrames(pArray,0.2f);
	CCSprite* girlSprite = CCSprite::createWithSpriteFrame(frame0);
	girlSprite->setPosition(ccp(300,150));
	this->addChild(girlSprite,2);

	CCAnimate* animate = CCAnimate::create(animation);
    girlSprite->runAction(CCRepeatForever::create(animate));
	CCLabelTTF* pLabel2 = CCLabelTTF::create("my test label","Arial",30);
	pLabel2->setPosition(ccp(100,200));
	this->addChild(pLabel2,1);
	CCSprite* pSprite = CCSprite::create("HelloWorld.png");
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(pSprite, 0);
	
    return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}
void HelloWorld::alertDialog(CCObject* pSender)
{
	CCMessageBox("my first alertDialog","alert");
}
