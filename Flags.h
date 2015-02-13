//-----------------------------------------------------------------
// Flags Application
// C++ Header - Flags.h
//-----------------------------------------------------------------

#ifndef FLAGS_H
#define FLAGS_H

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include <windows.h>
#include <time.h>
#include "Resource.h"
#include "GameEngine.h"
#include "Bitmap.h"
#include "Sprite.h"
#include "ScrollingBackground.h"
#include "PersonSprite.h"

//-----------------------------------------------------------------
// Global Variables
//-----------------------------------------------------------------
typedef int LEVELINDICATOR;
const LEVELINDICATOR    LI_WORLD=0,
                        LI_BRITAIN=1,
                        LI_USSR=2,
                        LI_AFGHANISTAN=3,
                        LI_CHINA=4,
                        LI_PANAMA=5,
                        LI_CONGO=6,
                        LI_FRANCE=7,
                        LI_ANTARCTICA=8,
                        LI_START=9,
                        LI_WON=10;

LEVELINDICATOR        g_iLevel;
HINSTANCE             g_hInstance;
GameEngine*           g_pGame;
HDC                   g_hOffscreenDC;
HBITMAP               g_hOffscreenBitmap;
Background*           g_pBGUssr;
Background*           g_pBGBritain;
Background*           g_pBGAntarctica;
Background*           g_pBGAfghanistan;
Background*           g_pBGPanama;
Background*           g_pBGChina;
BackgroundLayer*      g_pBGLandscapeLayer;
BackgroundLayer*      g_pFGCloudsLayer;
ScrollingBackground*  g_pBackground;
ScrollingBackground*  g_pForeground;
StarryBackground*     g_pSpace;
Bitmap*               g_pPersonBitmap;
PersonSprite*         g_pPersonSprite;
Sprite*               g_pCloudSprite;
Sprite*               g_pPokePlayerSprite;
Sprite*               g_pPokeOpponentSprite;
Sprite*               g_pFireworksSprite;
Sprite*               g_pSilkSprite;
Sprite*               g_pPorcelainSprite;
Sprite*               g_pFighter01Sprite;
Sprite*               g_pFighter02Sprite;
Sprite*               g_pFighter03Sprite;
Sprite*               g_pFighter04Sprite;
Sprite*               g_pFighter05Sprite;
Sprite*               g_pFighter11Sprite;
Sprite*               g_pFighter12Sprite;
Sprite*               g_pFighter13Sprite;
Sprite*               g_pFighter14Sprite;
Sprite*               g_pFighter15Sprite;
Sprite*               g_pFighter21Sprite;
Sprite*               g_pFighter22Sprite;
Sprite*               g_pFighter23Sprite;
Sprite*               g_pFighter24Sprite;
Sprite*               g_pFighter25Sprite;
Sprite*               g_pSamSprite;
Sprite*               g_pShoot01Sprite;
Sprite*               g_pShoot02Sprite;
Sprite*               g_pShoot03Sprite;
Sprite*               g_pShoot04Sprite;
Sprite*               g_pShoot05Sprite;
Sprite*               g_pShoot06Sprite;
Sprite*               g_pShoot07Sprite;
Sprite*               g_pShoot08Sprite;
Sprite*               g_pShoot09Sprite;
Sprite*               g_pShoot10Sprite;
Sprite*               g_pShoot11Sprite;
Sprite*               g_pShoot12Sprite;
Sprite*               g_pShoot13Sprite;
Sprite*               g_pShoot14Sprite;
Sprite*               g_pShoot15Sprite;
Sprite*               g_pShoot16Sprite;
Sprite*               g_pShoot17Sprite;
Sprite*               g_pShoot18Sprite;
Sprite*               g_pShoot19Sprite;
Sprite*               g_pShoot20Sprite;
Sprite*               g_pShoot21Sprite;
Sprite*               g_pShoot22Sprite;
Sprite*               g_pShoot23Sprite;
Sprite*               g_pShoot24Sprite;
Sprite*               g_pShoot25Sprite;
Sprite*               g_pShoot26Sprite;
Sprite*               g_pShoot27Sprite;
Sprite*               g_pShoot28Sprite;
Sprite*               g_pShoot29Sprite;
Sprite*               g_pShoot30Sprite;
Sprite*               g_pFlag01Sprite;
Sprite*               g_pFlag02Sprite;
Sprite*               g_pFlag03Sprite;
Sprite*               g_pFlag04Sprite;
Sprite*               g_pFlag05Sprite;
Sprite*               g_pFlag11Sprite;
Sprite*               g_pFlag12Sprite;
Sprite*               g_pFlag13Sprite;
Sprite*               g_pFlag14Sprite;
Sprite*               g_pFlag15Sprite;
Sprite*               g_pFlag21Sprite;
Sprite*               g_pFlag22Sprite;
Sprite*               g_pFlag23Sprite;
Sprite*               g_pFlag24Sprite;
Sprite*               g_pFlag25Sprite;
Sprite*               g_pDead01Sprite;
Sprite*               g_pDead02Sprite;
Sprite*               g_pDead03Sprite;
Sprite*               g_pDead04Sprite;
Sprite*               g_pDead05Sprite;
Sprite*               g_pDead06Sprite;
Sprite*               g_pDead07Sprite;
Sprite*               g_pDead08Sprite;
Sprite*               g_pDead09Sprite;
Sprite*               g_pDead10Sprite;
Sprite*               g_pDead11Sprite;
Sprite*               g_pDead12Sprite;
Sprite*               g_pDead13Sprite;
Sprite*               g_pDead14Sprite;
Sprite*               g_pDead15Sprite;
Sprite*               g_pDead16Sprite;
Sprite*               g_pDead17Sprite;
Sprite*               g_pDead18Sprite;
Sprite*               g_pDead19Sprite;
Sprite*               g_pDead20Sprite;
Sprite*               g_pDead21Sprite;
Sprite*               g_pDead22Sprite;
Sprite*               g_pDead23Sprite;
Sprite*               g_pDead24Sprite;
Sprite*               g_pDead25Sprite;
Sprite*               g_pDead26Sprite;
Sprite*               g_pDead27Sprite;
Sprite*               g_pDead28Sprite;
Sprite*               g_pDead29Sprite;
Sprite*               g_pDead30Sprite;
Sprite*               g_pAfghanistanSprite;
Sprite*               g_pAntarcticaSprite;
Sprite*               g_pBritainSprite;
Sprite*               g_pChinaSprite;
Sprite*               g_pCongoSprite;
Sprite*               g_pFranceSprite;
Sprite*               g_pPanamaSprite;
Sprite*               g_pUsaSprite;
Sprite*               g_pWhiteSprite;
Sprite*               g_pUssrSprite;
Sprite*               g_pBombSprite;
Sprite*               g_pAfghanistanWhite;
Sprite*               g_pAntarcticaWhite;
Sprite*               g_pBritainWhite;
Sprite*               g_pChinaWhite;
Sprite*               g_pCongoWhite;
Sprite*               g_pFranceWhite;
Sprite*               g_pPanamaWhite;
Sprite*               g_pUssrWhite;
Sprite*               g_pSelectSprite;
Sprite*               g_pIndicatorSprite;
Sprite*               g_psudoku1Sprite1;
Sprite*               g_psudoku2Sprite1;
Sprite*               g_psudoku3Sprite1;
Sprite*               g_psudoku4Sprite1;
Sprite*               g_psudoku5Sprite1;
Sprite*               g_psudoku6Sprite1;
Sprite*               g_psudoku7Sprite1;
Sprite*               g_psudoku8Sprite1;
Sprite*               g_psudoku9Sprite1;
Sprite*               g_psudoku1Sprite2;
Sprite*               g_psudoku2Sprite2;
Sprite*               g_psudoku3Sprite2;
Sprite*               g_psudoku4Sprite2;
Sprite*               g_psudoku5Sprite2;
Sprite*               g_psudoku6Sprite2;
Sprite*               g_psudoku7Sprite2;
Sprite*               g_psudoku8Sprite2;
Sprite*               g_psudoku9Sprite2;
Sprite*               g_psudoku1Sprite3;
Sprite*               g_psudoku2Sprite3;
Sprite*               g_psudoku3Sprite3;
Sprite*               g_psudoku4Sprite3;
Sprite*               g_psudoku5Sprite3;
Sprite*               g_psudoku6Sprite3;
Sprite*               g_psudoku7Sprite3;
Sprite*               g_psudoku8Sprite3;
Sprite*               g_psudoku9Sprite3;
Sprite*               g_psudoku1Sprite4;
Sprite*               g_psudoku2Sprite4;
Sprite*               g_psudoku3Sprite4;
Sprite*               g_psudoku4Sprite4;
Sprite*               g_psudoku5Sprite4;
Sprite*               g_psudoku6Sprite4;
Sprite*               g_psudoku7Sprite4;
Sprite*               g_psudoku8Sprite4;
Sprite*               g_psudoku9Sprite4;
Sprite*               g_psudoku1Sprite5;
Sprite*               g_psudoku2Sprite5;
Sprite*               g_psudoku3Sprite5;
Sprite*               g_psudoku4Sprite5;
Sprite*               g_psudoku5Sprite5;
Sprite*               g_psudoku6Sprite5;
Sprite*               g_psudoku7Sprite5;
Sprite*               g_psudoku8Sprite5;
Sprite*               g_psudoku9Sprite5;
Sprite*               g_psudoku1Sprite6;
Sprite*               g_psudoku2Sprite6;
Sprite*               g_psudoku3Sprite6;
Sprite*               g_psudoku4Sprite6;
Sprite*               g_psudoku5Sprite6;
Sprite*               g_psudoku6Sprite6;
Sprite*               g_psudoku7Sprite6;
Sprite*               g_psudoku8Sprite6;
Sprite*               g_psudoku9Sprite6;
Sprite*               g_psudoku1Sprite7;
Sprite*               g_psudoku2Sprite7;
Sprite*               g_psudoku3Sprite7;
Sprite*               g_psudoku4Sprite7;
Sprite*               g_psudoku5Sprite7;
Sprite*               g_psudoku6Sprite7;
Sprite*               g_psudoku7Sprite7;
Sprite*               g_psudoku8Sprite7;
Sprite*               g_psudoku9Sprite7;
Sprite*               g_psudoku1Sprite8;
Sprite*               g_psudoku2Sprite8;
Sprite*               g_psudoku3Sprite8;
Sprite*               g_psudoku4Sprite8;
Sprite*               g_psudoku5Sprite8;
Sprite*               g_psudoku6Sprite8;
Sprite*               g_psudoku7Sprite8;
Sprite*               g_psudoku8Sprite8;
Sprite*               g_psudoku9Sprite8;
Sprite*               g_psudoku1Sprite9;
Sprite*               g_psudoku2Sprite9;
Sprite*               g_psudoku3Sprite9;
Sprite*               g_psudoku4Sprite9;
Sprite*               g_psudoku5Sprite9;
Sprite*               g_psudoku6Sprite9;
Sprite*               g_psudoku7Sprite9;
Sprite*               g_psudoku8Sprite9;
Sprite*               g_psudoku9Sprite9;
Sprite*               g_pBoatGreenSprite;
Sprite*               g_pBoatGraySprite;
Sprite*               g_pBoatWhiteSprite;
Sprite*               g_pBoatOrangeSprite;
Sprite*               g_pBoatRedSprite;
Sprite*               g_pBoatBlueSprite;
Sprite*               g_pTextSprite;
Sprite*               g_pOpponentHealthSprite;
Sprite*               g_pPlayerHealthSprite;
Sprite*               g_pPokeTextStartSprite;
Sprite*               g_pPokeIndicatorSprite;
Sprite*               g_pPokeMenuSprite;
Sprite*               g_pPokeTextMenu1Sprite;
Sprite*               g_pPokeMenuIndicatorSprite;
Sprite*               g_pPokeBattleMenuSprite;
Sprite*               g_pPokeBellSprite;
Sprite*               g_pPokeBeamSprite;
Sprite*               g_pPokeSpiritSprite;
Sprite*               g_pPokeBeamTextSprite;
Sprite*               g_pPokeSpiritTextSprite;
Sprite*               g_pPokeBellTextSprite;
Sprite*               g_pPokeOpponentTurnSprite;
Sprite*               g_pPokeBellText1Sprite;
Sprite*               g_pPokeBeamText1Sprite;
Sprite*               g_pPokeSpiritText1Sprite;
Sprite*               g_pPokeSpiritText2Sprite;
Sprite*               g_pGameWonSprite;
Sprite*               g_pGameStartSprite;
Bitmap*               g_pGameStartBitmap;
Bitmap*               g_pPokeSpiritText2Bitmap;
Bitmap*               g_pGameWonBitmap;
Bitmap*               g_pPokeBellText1Bitmap;
Bitmap*               g_pPokeBeamText1Bitmap;
Bitmap*               g_pPokeSpiritText1Bitmap;
Bitmap*               g_pPokeBeamTextBitmap;
Bitmap*               g_pPokeSpiritTextBitmap;
Bitmap*               g_pPokeBellTextBitmap;
Bitmap*               g_pPokeOpponentTurnBitmap;
Bitmap*               g_pPokeBattleMenuBitmap;
Bitmap*               g_pPokeBellBitmap;
Bitmap*               g_pPokeBeamBitmap;
Bitmap*               g_pPokeSpiritBitmap;
Bitmap*               g_pPokeMenuIndicatorBitmap;
Bitmap*               g_pPokeTextMenu1Bitmap;
Bitmap*               g_pPokeTextStartBitmap;
Bitmap*               g_pPokeMenuBitmap;
Bitmap*               g_pPokeIndicatorBitmap;
Bitmap*               g_pPlayerHealthBitmap;
Bitmap*               g_pOpponentHealthBitmap;
Bitmap*               g_pBoatGreenBitmap;
Bitmap*               g_pBoatGrayBitmap;
Bitmap*               g_pBoatWhiteBitmap;
Bitmap*               g_pBoatOrangeBitmap;
Bitmap*               g_pBoatRedBitmap;
Bitmap*               g_pBoatBlueBitmap;
Bitmap*               g_pCloudBitmap;
Bitmap*               g_pTextBitmap;
Bitmap*               g_pSelectBitmap;
Bitmap*               g_pPokePlayerBitmap;
Bitmap*               g_pPokeOpponentBitmap;
Bitmap*               g_pFireworksBitmap;
Bitmap*               g_pSilkBitmap;
Bitmap*               g_pPorcelainBitmap;
Bitmap*               g_pBGBritainBitmap;
Bitmap*               g_pBGUssrBitmap;
Bitmap*               g_pBGAntarcticaBitmap;
Bitmap*               g_pBGAfghanistanBitmap;
Bitmap*               g_pBGPanamaBitmap;
Bitmap*               g_pBGChinaBitmap;
Bitmap*               g_pAfghanistanBitmap;
Bitmap*               g_pAntarcticaBitmap;
Bitmap*               g_pBritainBitmap;
Bitmap*               g_pChinaBitmap;
Bitmap*               g_pCongoBitmap;
Bitmap*               g_pFranceBitmap;
Bitmap*               g_pPanamaBitmap;
Bitmap*               g_pUsaBitmap;
Bitmap*               g_pWhiteBitmap;
Bitmap*               g_pUssrBitmap;
Bitmap*               g_pBombBitmap;
Bitmap*               g_pSamBitmap;
Bitmap*               g_pFighterBitmap;
Bitmap*               g_pShootBitmap;
Bitmap*               g_pFlagBitmap;
Bitmap*               g_pDeadBitmap;
Bitmap*               g_pIndicatorBitmap;
Bitmap*               g_psudoku1Bitmap;
Bitmap*               g_psudoku2Bitmap;
Bitmap*               g_psudoku3Bitmap;
Bitmap*               g_psudoku4Bitmap;
Bitmap*               g_psudoku5Bitmap;
Bitmap*               g_psudoku6Bitmap;
Bitmap*               g_psudoku7Bitmap;
Bitmap*               g_psudoku8Bitmap;
Bitmap*               g_psudoku9Bitmap;
Bitmap*               g_psudoku1Bitmapy;
Bitmap*               g_psudoku2Bitmapy;
Bitmap*               g_psudoku3Bitmapy;
Bitmap*               g_psudoku4Bitmapy;
Bitmap*               g_psudoku5Bitmapy;
Bitmap*               g_psudoku6Bitmapy;
Bitmap*               g_psudoku7Bitmapy;
Bitmap*               g_psudoku8Bitmapy;
Bitmap*               g_psudoku9Bitmapy;
int                   g_iInputDelay;
int                   g_Flag0;
int                   g_Flag1;
int                   g_Flag2;
int                   g_PokeFlag1;
int                   g_PokeFlag2;
int                   g_PokeFlag3;
int                   g_ScoreUssr;
clock_t               g_Timer1;
int                   g_sudoku[9][9];
int                   g_BritainLevel;
int                   g_BritainCounter;
int                   g_Counter;
int                   g_BritainHealth;
BOOL                  g_AfghanistanWon;
BOOL                  g_AntarcticaWon;
BOOL                  g_BritainWon;
BOOL                  g_ChinaWon;
BOOL                  g_CongoWon;
BOOL                  g_FranceWon;
BOOL                  g_PanamaWon;
BOOL                  g_UssrWon;

#endif
