//
//  GameSceneBG.hpp
//  LoStudioEngine
//
//  Created by Yuhang Huang on 2019/07/17.
//  Copyright © 2019 Masaki Iwasaki. All rights reserved.
//

#ifndef GameSceneBG_hpp
#define GameSceneBG_hpp

enum SceneBGType
{
    BG_BLACK    = 0,
    BG_GRAY     = 1,
    BG_LIGHTGRAY= 2,
    BG_WHITE    = 3,
    BG_DIY      = 10,
};

class GameSceneBG
{
    
private:
    int color_type = BG_BLACK;
    
public:
    void setType(int type);
    void drawBackGround();
    
protected:
    void virtual draw();
    
};

#endif /* GameSceneBG_hpp */
