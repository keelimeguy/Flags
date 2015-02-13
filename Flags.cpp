//-----------------------------------------------------------------
// Flags Application
// C++ Source - Flags.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "Flags.h"

//-----------------------------------------------------------------
// Game Engine Functions
//-----------------------------------------------------------------
BOOL GameInitialize(HINSTANCE hInstance)
{
  // Create the game engine
  g_pGame = new GameEngine(hInstance, TEXT("Flags"),
    TEXT("Flags"), IDI_FLAGS, IDI_FLAGS_SM, 256, 256);
  if (g_pGame == NULL)
    return FALSE;

  // Set the frame rate
  g_pGame->SetFrameRate(30);

  // Initialize the joystick
  g_pGame->InitJoystick();

  // Store the instance handle
  g_hInstance = hInstance;

  return TRUE;
}

void GameStart(HWND hWindow)
{
  // Create the offscreen device context and bitmap
  g_hOffscreenDC = CreateCompatibleDC(GetDC(hWindow));
  g_hOffscreenBitmap = CreateCompatibleBitmap(GetDC(hWindow),
    g_pGame->GetWidth(), g_pGame->GetHeight());
  SelectObject(g_hOffscreenDC, g_hOffscreenBitmap);

  // Create the scrolling background and landscape layer
  HDC hDC = GetDC(hWindow);
  g_pBackground = new ScrollingBackground(256, 256);
  g_pBGLandscapeLayer = new BackgroundLayer(hDC, IDB_BG_WORLD, g_hInstance);
  RECT rcViewport = { 210, 116, 466, 372 };
  g_pBGLandscapeLayer->SetViewport(rcViewport);
  g_pBackground->AddLayer(g_pBGLandscapeLayer);

  //Create the backgrounds
  g_pBGAntarcticaBitmap = new Bitmap(hDC, IDB_BG_ANTARCTICA, g_hInstance);
  g_pBGAntarctica = new Background(g_pBGAntarcticaBitmap);
  g_pBGAfghanistanBitmap = new Bitmap(hDC, IDB_BG_AFGHANISTAN, g_hInstance);
  g_pBGAfghanistan = new Background(g_pBGAfghanistanBitmap);
  g_pBGPanamaBitmap = new Bitmap(hDC, IDB_BG_PANAMA, g_hInstance);
  g_pBGPanama = new Background(g_pBGPanamaBitmap);
  g_pBGUssrBitmap = new Bitmap(hDC, IDB_BG_USSR, g_hInstance);
  g_pBGBritainBitmap = new Bitmap(hDC, IDB_BG_BRITAIN, g_hInstance);
  g_pBGUssr = new Background(g_pBGUssrBitmap);
  g_pBGBritain = new Background(g_pBGBritainBitmap);
  g_pBGChinaBitmap = new Bitmap(hDC, IDB_BG_CHINA, g_hInstance);
  g_pBGChina = new Background(g_pBGChinaBitmap);

  // Create the space layer
  g_pSpace = new StarryBackground(256, 256, 100, 15);
  
  // Create the scrolling foreground and clouds layer
  /*g_pForeground = new ScrollingBackground(256, 256);
  g_pFGCloudsLayer = new BackgroundLayer(hDC, IDB_BG_CLOUDS, g_hInstance);
  rcViewport.left = rcViewport.top = 64;
  rcViewport.right = rcViewport.bottom = 320;
  g_pFGCloudsLayer->SetViewport(rcViewport);
  g_pForeground->AddLayer(g_pFGCloudsLayer);*/

  // Create and load the bitmaps
  g_pPokeSpiritText2Bitmap = new Bitmap(hDC, IDB_T_SPIRIT2, g_hInstance);
  g_pGameWonBitmap = new Bitmap(hDC, IDB_G_WON, g_hInstance);
  g_pPokeBeamText1Bitmap = new Bitmap(hDC, IDB_T_BEAM1, g_hInstance);
  g_pPokeBellText1Bitmap = new Bitmap(hDC, IDB_T_BELL1, g_hInstance);
  g_pPokeSpiritText1Bitmap = new Bitmap(hDC, IDB_T_SPIRIT1, g_hInstance);
  g_pPokeBellBitmap = new Bitmap(hDC, IDB_B_BELL, g_hInstance);
  g_pPokeSpiritBitmap = new Bitmap(hDC, IDB_B_BALL, g_hInstance);
  g_pPokeBeamBitmap = new Bitmap(hDC, IDB_B_BEAM, g_hInstance);
  g_pPokeBattleMenuBitmap = new Bitmap(hDC, IDB_T_BATTLE, g_hInstance);
  g_pPokeTextStartBitmap = new Bitmap(hDC, IDB_T_START, g_hInstance);
  g_pPokeIndicatorBitmap = new Bitmap(hDC, IDB_T_INDICATOR, g_hInstance);
  g_pOpponentHealthBitmap = new Bitmap(hDC, IDB_H_OPPONENT, g_hInstance);
  g_pPlayerHealthBitmap = new Bitmap(hDC, IDB_H_PLAYER, g_hInstance);
  g_pTextBitmap = new Bitmap(hDC, IDB_O_TEXT, g_hInstance);
  g_pBoatRedBitmap = new Bitmap(hDC, IDB_O_BOATR, g_hInstance);
  g_pBoatGrayBitmap = new Bitmap(hDC, IDB_O_BOATG, g_hInstance);
  g_pBoatGreenBitmap = new Bitmap(hDC, IDB_O_BOATV, g_hInstance);
  g_pBoatWhiteBitmap = new Bitmap(hDC, IDB_O_BOATW, g_hInstance);
  g_pBoatBlueBitmap = new Bitmap(hDC, IDB_O_BOATB, g_hInstance);
  g_pBoatOrangeBitmap = new Bitmap(hDC, IDB_O_BOATO, g_hInstance);
  g_pCloudBitmap = new Bitmap(hDC, IDB_BG_CLOUD, g_hInstance);
  g_psudoku1Bitmap = new Bitmap(hDC, IDB_S_ONE, g_hInstance);
  g_psudoku2Bitmap = new Bitmap(hDC, IDB_S_TWO, g_hInstance);
  g_psudoku3Bitmap = new Bitmap(hDC, IDB_S_THREE, g_hInstance);
  g_psudoku4Bitmap = new Bitmap(hDC, IDB_S_FOUR, g_hInstance);
  g_psudoku5Bitmap = new Bitmap(hDC, IDB_S_FIVE, g_hInstance);
  g_psudoku6Bitmap = new Bitmap(hDC, IDB_S_SIX, g_hInstance);
  g_psudoku7Bitmap = new Bitmap(hDC, IDB_S_SEVEN, g_hInstance);
  g_psudoku8Bitmap = new Bitmap(hDC, IDB_S_EIGHT, g_hInstance);
  g_psudoku9Bitmap = new Bitmap(hDC, IDB_S_NINE, g_hInstance);
  g_psudoku1Bitmapy = new Bitmap(hDC, IDB_S_ONEY, g_hInstance);
  g_psudoku2Bitmapy = new Bitmap(hDC, IDB_S_TWOY, g_hInstance);
  g_psudoku3Bitmapy = new Bitmap(hDC, IDB_S_THREEY, g_hInstance);
  g_psudoku4Bitmapy = new Bitmap(hDC, IDB_S_FOURY, g_hInstance);
  g_psudoku5Bitmapy = new Bitmap(hDC, IDB_S_FIVEY, g_hInstance);
  g_psudoku6Bitmapy = new Bitmap(hDC, IDB_S_SIXY, g_hInstance);
  g_psudoku7Bitmapy = new Bitmap(hDC, IDB_S_SEVENY, g_hInstance);
  g_psudoku8Bitmapy = new Bitmap(hDC, IDB_S_EIGHTY, g_hInstance);
  g_psudoku9Bitmapy = new Bitmap(hDC, IDB_S_NINEY, g_hInstance);
  g_pPokePlayerBitmap = new Bitmap(hDC, IDB_CS_PLAYER, g_hInstance);
  g_pPokeOpponentBitmap = new Bitmap(hDC, IDB_CS_OPPONENT, g_hInstance);
  g_pFireworksBitmap = new Bitmap(hDC, IDB_O_FIREWORKS, g_hInstance);
  g_pSilkBitmap = new Bitmap(hDC, IDB_O_SILK, g_hInstance);
  g_pPorcelainBitmap = new Bitmap(hDC, IDB_O_PORCELAIN, g_hInstance);
  g_pSamBitmap = new Bitmap(hDC, IDB_O_SAM, g_hInstance);
  g_pFighterBitmap = new Bitmap(hDC, IDB_CS_FIGHTER, g_hInstance);
  g_pShootBitmap = new Bitmap(hDC, IDB_CS_SHOOT, g_hInstance);
  g_pFlagBitmap = new Bitmap(hDC, IDB_CS_FLAG, g_hInstance);
  g_pDeadBitmap = new Bitmap(hDC, IDB_CS_DEAD, g_hInstance);
  g_pBombBitmap = new Bitmap(hDC, IDB_O_BOMB, g_hInstance);
  g_pPersonBitmap = new Bitmap(hDC, IDB_CS_SAM, g_hInstance);
  g_pAfghanistanBitmap = new Bitmap(hDC, IDB_F_AFGHANISTAN, g_hInstance);
  g_pBritainBitmap = new Bitmap(hDC, IDB_F_BRITAIN, g_hInstance);
  g_pChinaBitmap = new Bitmap(hDC, IDB_F_CHINA, g_hInstance);
  g_pCongoBitmap = new Bitmap(hDC, IDB_F_CONGO, g_hInstance);
  g_pFranceBitmap = new Bitmap(hDC, IDB_F_FRANCE, g_hInstance);
  g_pPanamaBitmap = new Bitmap(hDC, IDB_F_PANAMA, g_hInstance);
  g_pUsaBitmap = new Bitmap(hDC, IDB_F_USA, g_hInstance);
  g_pAntarcticaBitmap = new Bitmap(hDC, IDB_F_ANTARCTICA, g_hInstance);
  g_pWhiteBitmap = new Bitmap(hDC, IDB_F_WHITE, g_hInstance);
  g_pUssrBitmap = new Bitmap(hDC, IDB_F_USSR, g_hInstance);
  g_pIndicatorBitmap = new Bitmap(hDC, IDB_O_INDICATOR, g_hInstance);
  g_pSelectBitmap = new Bitmap(hDC, IDB_S_MASK, g_hInstance);
  g_pPokeTextMenu1Bitmap = new Bitmap(hDC, IDB_T_MENU1, g_hInstance);
  g_pPokeMenuBitmap = new Bitmap(hDC, IDB_T_MENU, g_hInstance);
  g_pPokeMenuIndicatorBitmap = new Bitmap(hDC, IDB_T_MENUINDICATOR, g_hInstance);
  g_pPokeBeamTextBitmap = new Bitmap(hDC, IDB_T_BEAM, g_hInstance);
  g_pPokeSpiritTextBitmap = new Bitmap(hDC, IDB_T_SPIRIT, g_hInstance);
  g_pPokeBellTextBitmap = new Bitmap(hDC, IDB_T_BELL, g_hInstance);
  g_pGameStartBitmap = new Bitmap(hDC, IDB_G_START, g_hInstance);
  g_pPokeOpponentTurnBitmap = new Bitmap(hDC, IDB_O_TURN, g_hInstance);
  
  // Create the person sprite
  RECT rcBounds = { 115, 112, 0, 0 };
  g_pPersonSprite = new PersonSprite(g_pPersonBitmap, rcBounds, BA_STOP);
  
  //Create the sprites
  g_pPokeSpiritText2Sprite = new Sprite(g_pPokeSpiritText2Bitmap);
  g_pGameWonSprite = new Sprite(g_pGameWonBitmap);
  g_pPokeSpiritText1Sprite = new Sprite(g_pPokeSpiritText1Bitmap);
  g_pPokeBeamText1Sprite = new Sprite(g_pPokeBeamText1Bitmap);
  g_pPokeBellText1Sprite = new Sprite(g_pPokeBellText1Bitmap);
  g_pPokeBeamTextSprite = new Sprite(g_pPokeBeamTextBitmap);
  g_pPokeSpiritTextSprite = new Sprite(g_pPokeSpiritTextBitmap);
  g_pPokeBellTextSprite = new Sprite(g_pPokeBellTextBitmap);
  g_pPokeOpponentTurnSprite = new Sprite(g_pPokeOpponentTurnBitmap);
  g_pPokeBeamSprite = new Sprite(g_pPokeBeamBitmap);
  g_pPokeSpiritSprite = new Sprite(g_pPokeSpiritBitmap);
  g_pPokeBellSprite = new Sprite(g_pPokeBellBitmap);
  g_pPokeBattleMenuSprite = new Sprite(g_pPokeBattleMenuBitmap);
  g_pPokeTextStartSprite = new Sprite(g_pPokeTextStartBitmap);
  g_pPokeIndicatorSprite = new Sprite(g_pPokeIndicatorBitmap);
  g_pPlayerHealthSprite = new Sprite(g_pPlayerHealthBitmap);
  g_pOpponentHealthSprite = new Sprite(g_pOpponentHealthBitmap);
  g_pTextSprite = new Sprite(g_pTextBitmap);
  g_pBoatOrangeSprite = new Sprite(g_pBoatOrangeBitmap);
  g_pBoatWhiteSprite = new Sprite(g_pBoatWhiteBitmap);
  g_pBoatGreenSprite = new Sprite(g_pBoatGreenBitmap);
  g_pBoatGraySprite = new Sprite(g_pBoatGrayBitmap);
  g_pBoatRedSprite = new Sprite(g_pBoatRedBitmap);
  g_pBoatBlueSprite = new Sprite(g_pBoatBlueBitmap);
  g_pCloudSprite = new Sprite(g_pCloudBitmap);
  g_pSelectSprite = new Sprite(g_pSelectBitmap);
  g_psudoku1Sprite1 = new Sprite(g_psudoku1Bitmap);
  g_psudoku2Sprite1 = new Sprite(g_psudoku2Bitmap);
  g_psudoku3Sprite1 = new Sprite(g_psudoku3Bitmapy);
  g_psudoku4Sprite1 = new Sprite(g_psudoku4Bitmap);
  g_psudoku5Sprite1 = new Sprite(g_psudoku5Bitmapy);
  g_psudoku6Sprite1 = new Sprite(g_psudoku6Bitmapy);
  g_psudoku7Sprite1 = new Sprite(g_psudoku7Bitmap);
  g_psudoku8Sprite1 = new Sprite(g_psudoku8Bitmapy);
  g_psudoku9Sprite1 = new Sprite(g_psudoku9Bitmapy);
  g_psudoku1Sprite2 = new Sprite(g_psudoku1Bitmapy);
  g_psudoku2Sprite2 = new Sprite(g_psudoku2Bitmap);
  g_psudoku3Sprite2 = new Sprite(g_psudoku3Bitmap);
  g_psudoku4Sprite2 = new Sprite(g_psudoku4Bitmap);
  g_psudoku5Sprite2 = new Sprite(g_psudoku5Bitmapy);
  g_psudoku6Sprite2 = new Sprite(g_psudoku6Bitmap);
  g_psudoku7Sprite2 = new Sprite(g_psudoku7Bitmapy);
  g_psudoku8Sprite2 = new Sprite(g_psudoku8Bitmap);
  g_psudoku9Sprite2 = new Sprite(g_psudoku9Bitmapy);
  g_psudoku1Sprite3 = new Sprite(g_psudoku1Bitmap);
  g_psudoku2Sprite3 = new Sprite(g_psudoku2Bitmap);
  g_psudoku3Sprite3 = new Sprite(g_psudoku3Bitmap);
  g_psudoku4Sprite3 = new Sprite(g_psudoku4Bitmap);
  g_psudoku5Sprite3 = new Sprite(g_psudoku5Bitmap);
  g_psudoku6Sprite3 = new Sprite(g_psudoku6Bitmapy);
  g_psudoku7Sprite3 = new Sprite(g_psudoku7Bitmap);
  g_psudoku8Sprite3 = new Sprite(g_psudoku8Bitmap);
  g_psudoku9Sprite3 = new Sprite(g_psudoku9Bitmap);
  g_psudoku1Sprite4 = new Sprite(g_psudoku1Bitmap);
  g_psudoku2Sprite4 = new Sprite(g_psudoku2Bitmap);
  g_psudoku3Sprite4 = new Sprite(g_psudoku3Bitmap);
  g_psudoku4Sprite4 = new Sprite(g_psudoku4Bitmapy);
  g_psudoku5Sprite4 = new Sprite(g_psudoku5Bitmap);
  g_psudoku6Sprite4 = new Sprite(g_psudoku6Bitmap);
  g_psudoku7Sprite4 = new Sprite(g_psudoku7Bitmapy);
  g_psudoku8Sprite4 = new Sprite(g_psudoku8Bitmapy);
  g_psudoku9Sprite4 = new Sprite(g_psudoku9Bitmap);
  g_psudoku1Sprite5 = new Sprite(g_psudoku1Bitmap);
  g_psudoku2Sprite5 = new Sprite(g_psudoku2Bitmapy);
  g_psudoku3Sprite5 = new Sprite(g_psudoku3Bitmapy);
  g_psudoku4Sprite5 = new Sprite(g_psudoku4Bitmap);
  g_psudoku5Sprite5 = new Sprite(g_psudoku5Bitmap);
  g_psudoku6Sprite5 = new Sprite(g_psudoku6Bitmapy);
  g_psudoku7Sprite5 = new Sprite(g_psudoku7Bitmap);
  g_psudoku8Sprite5 = new Sprite(g_psudoku8Bitmapy);
  g_psudoku9Sprite5 = new Sprite(g_psudoku9Bitmap);
  g_psudoku1Sprite6 = new Sprite(g_psudoku1Bitmapy);
  g_psudoku2Sprite6 = new Sprite(g_psudoku2Bitmap);
  g_psudoku3Sprite6 = new Sprite(g_psudoku3Bitmapy);
  g_psudoku4Sprite6 = new Sprite(g_psudoku4Bitmap);
  g_psudoku5Sprite6 = new Sprite(g_psudoku5Bitmap);
  g_psudoku6Sprite6 = new Sprite(g_psudoku6Bitmapy);
  g_psudoku7Sprite6 = new Sprite(g_psudoku7Bitmap);
  g_psudoku8Sprite6 = new Sprite(g_psudoku8Bitmap);
  g_psudoku9Sprite6 = new Sprite(g_psudoku9Bitmap);
  g_psudoku1Sprite7 = new Sprite(g_psudoku1Bitmap);
  g_psudoku2Sprite7 = new Sprite(g_psudoku2Bitmap);
  g_psudoku3Sprite7 = new Sprite(g_psudoku3Bitmap);
  g_psudoku4Sprite7 = new Sprite(g_psudoku4Bitmap);
  g_psudoku5Sprite7 = new Sprite(g_psudoku5Bitmap);
  g_psudoku6Sprite7 = new Sprite(g_psudoku6Bitmapy);
  g_psudoku7Sprite7 = new Sprite(g_psudoku7Bitmap);
  g_psudoku8Sprite7 = new Sprite(g_psudoku8Bitmap);
  g_psudoku9Sprite7 = new Sprite(g_psudoku9Bitmap);
  g_psudoku1Sprite8 = new Sprite(g_psudoku1Bitmapy);
  g_psudoku2Sprite8 = new Sprite(g_psudoku2Bitmap);
  g_psudoku3Sprite8 = new Sprite(g_psudoku3Bitmap);
  g_psudoku4Sprite8 = new Sprite(g_psudoku4Bitmapy);
  g_psudoku5Sprite8 = new Sprite(g_psudoku5Bitmap);
  g_psudoku6Sprite8 = new Sprite(g_psudoku6Bitmap);
  g_psudoku7Sprite8 = new Sprite(g_psudoku7Bitmap);
  g_psudoku8Sprite8 = new Sprite(g_psudoku8Bitmapy);
  g_psudoku9Sprite8 = new Sprite(g_psudoku9Bitmapy);
  g_psudoku1Sprite9 = new Sprite(g_psudoku1Bitmap);
  g_psudoku2Sprite9 = new Sprite(g_psudoku2Bitmapy);
  g_psudoku3Sprite9 = new Sprite(g_psudoku3Bitmap);
  g_psudoku4Sprite9 = new Sprite(g_psudoku4Bitmap);
  g_psudoku5Sprite9 = new Sprite(g_psudoku5Bitmapy);
  g_psudoku6Sprite9 = new Sprite(g_psudoku6Bitmap);
  g_psudoku7Sprite9 = new Sprite(g_psudoku7Bitmapy);
  g_psudoku8Sprite9 = new Sprite(g_psudoku8Bitmapy);
  g_psudoku9Sprite9 = new Sprite(g_psudoku9Bitmapy);
  g_pAfghanistanWhite = new Sprite(g_pWhiteBitmap);
  g_pBritainWhite = new Sprite(g_pWhiteBitmap);
  g_pChinaWhite = new Sprite(g_pWhiteBitmap);
  g_pCongoWhite = new Sprite(g_pWhiteBitmap);
  g_pFranceWhite = new Sprite(g_pWhiteBitmap);
  g_pPanamaWhite = new Sprite(g_pWhiteBitmap);
  g_pAntarcticaWhite = new Sprite(g_pWhiteBitmap);
  g_pUssrWhite = new Sprite(g_pWhiteBitmap);
  g_pBombSprite = new Sprite(g_pBombBitmap);
  g_pAfghanistanSprite = new Sprite(g_pAfghanistanBitmap);
  g_pBritainSprite = new Sprite(g_pBritainBitmap);
  g_pChinaSprite = new Sprite(g_pChinaBitmap);
  g_pCongoSprite = new Sprite(g_pCongoBitmap);
  g_pFranceSprite = new Sprite(g_pFranceBitmap);
  g_pPanamaSprite = new Sprite(g_pPanamaBitmap);
  g_pUsaSprite = new Sprite(g_pUsaBitmap);
  g_pAntarcticaSprite = new Sprite(g_pAntarcticaBitmap);
  g_pUssrSprite = new Sprite(g_pUssrBitmap);
  g_pPokePlayerSprite = new Sprite(g_pPokePlayerBitmap);
  g_pPokeOpponentSprite = new Sprite(g_pPokeOpponentBitmap);
  g_pFireworksSprite = new Sprite(g_pFireworksBitmap);
  g_pSilkSprite = new Sprite(g_pSilkBitmap);
  g_pPorcelainSprite = new Sprite(g_pPorcelainBitmap);
  g_pSamSprite = new Sprite(g_pSamBitmap);
  g_pIndicatorSprite = new Sprite(g_pIndicatorBitmap);
  g_pFighter01Sprite = new Sprite(g_pFighterBitmap);
  g_pFighter02Sprite = new Sprite(g_pFighterBitmap);
  g_pFighter03Sprite = new Sprite(g_pFighterBitmap);
  g_pFighter04Sprite = new Sprite(g_pFighterBitmap);
  g_pFighter05Sprite = new Sprite(g_pFighterBitmap);
  g_pFighter11Sprite = new Sprite(g_pFighterBitmap);
  g_pFighter12Sprite = new Sprite(g_pFighterBitmap);
  g_pFighter13Sprite = new Sprite(g_pFighterBitmap);
  g_pFighter14Sprite = new Sprite(g_pFighterBitmap);
  g_pFighter15Sprite = new Sprite(g_pFighterBitmap);
  g_pFighter21Sprite = new Sprite(g_pFighterBitmap);
  g_pFighter22Sprite = new Sprite(g_pFighterBitmap);
  g_pFighter23Sprite = new Sprite(g_pFighterBitmap);
  g_pFighter24Sprite = new Sprite(g_pFighterBitmap);
  g_pFighter25Sprite = new Sprite(g_pFighterBitmap);
  g_pShoot01Sprite = new Sprite(g_pShootBitmap);
  g_pShoot02Sprite = new Sprite(g_pShootBitmap);
  g_pShoot03Sprite = new Sprite(g_pShootBitmap);
  g_pShoot04Sprite = new Sprite(g_pShootBitmap);
  g_pShoot05Sprite = new Sprite(g_pShootBitmap);
  g_pShoot06Sprite = new Sprite(g_pShootBitmap);
  g_pShoot07Sprite = new Sprite(g_pShootBitmap);
  g_pShoot08Sprite = new Sprite(g_pShootBitmap);
  g_pShoot09Sprite = new Sprite(g_pShootBitmap);
  g_pShoot10Sprite = new Sprite(g_pShootBitmap);
  g_pShoot11Sprite = new Sprite(g_pShootBitmap);
  g_pShoot12Sprite = new Sprite(g_pShootBitmap);
  g_pShoot13Sprite = new Sprite(g_pShootBitmap);
  g_pShoot14Sprite = new Sprite(g_pShootBitmap);
  g_pShoot15Sprite = new Sprite(g_pShootBitmap);
  g_pShoot16Sprite = new Sprite(g_pShootBitmap);
  g_pShoot17Sprite = new Sprite(g_pShootBitmap);
  g_pShoot18Sprite = new Sprite(g_pShootBitmap);
  g_pShoot19Sprite = new Sprite(g_pShootBitmap);
  g_pShoot20Sprite = new Sprite(g_pShootBitmap);
  g_pShoot21Sprite = new Sprite(g_pShootBitmap);
  g_pShoot22Sprite = new Sprite(g_pShootBitmap);
  g_pShoot23Sprite = new Sprite(g_pShootBitmap);
  g_pShoot24Sprite = new Sprite(g_pShootBitmap);
  g_pShoot25Sprite = new Sprite(g_pShootBitmap);
  g_pShoot26Sprite = new Sprite(g_pShootBitmap);
  g_pShoot27Sprite = new Sprite(g_pShootBitmap);
  g_pShoot28Sprite = new Sprite(g_pShootBitmap);
  g_pShoot29Sprite = new Sprite(g_pShootBitmap);
  g_pShoot30Sprite = new Sprite(g_pShootBitmap);
  g_pFlag01Sprite = new Sprite(g_pFlagBitmap);
  g_pFlag02Sprite = new Sprite(g_pFlagBitmap);
  g_pFlag03Sprite = new Sprite(g_pFlagBitmap);
  g_pFlag04Sprite = new Sprite(g_pFlagBitmap);
  g_pFlag05Sprite = new Sprite(g_pFlagBitmap);
  g_pFlag11Sprite = new Sprite(g_pFlagBitmap);
  g_pFlag12Sprite = new Sprite(g_pFlagBitmap);
  g_pFlag13Sprite = new Sprite(g_pFlagBitmap);
  g_pFlag14Sprite = new Sprite(g_pFlagBitmap);
  g_pFlag15Sprite = new Sprite(g_pFlagBitmap);
  g_pFlag21Sprite = new Sprite(g_pFlagBitmap);
  g_pFlag22Sprite = new Sprite(g_pFlagBitmap);
  g_pFlag23Sprite = new Sprite(g_pFlagBitmap);
  g_pFlag24Sprite = new Sprite(g_pFlagBitmap);
  g_pFlag25Sprite = new Sprite(g_pFlagBitmap);
  g_pDead01Sprite = new Sprite(g_pDeadBitmap);
  g_pDead02Sprite = new Sprite(g_pDeadBitmap);
  g_pDead03Sprite = new Sprite(g_pDeadBitmap);
  g_pDead04Sprite = new Sprite(g_pDeadBitmap);
  g_pDead05Sprite = new Sprite(g_pDeadBitmap);
  g_pDead06Sprite = new Sprite(g_pDeadBitmap);
  g_pDead07Sprite = new Sprite(g_pDeadBitmap);
  g_pDead08Sprite = new Sprite(g_pDeadBitmap);
  g_pDead09Sprite = new Sprite(g_pDeadBitmap);
  g_pDead10Sprite = new Sprite(g_pDeadBitmap);
  g_pDead11Sprite = new Sprite(g_pDeadBitmap);
  g_pDead12Sprite = new Sprite(g_pDeadBitmap);
  g_pDead13Sprite = new Sprite(g_pDeadBitmap);
  g_pDead14Sprite = new Sprite(g_pDeadBitmap);
  g_pDead15Sprite = new Sprite(g_pDeadBitmap);
  g_pDead16Sprite = new Sprite(g_pDeadBitmap);
  g_pDead17Sprite = new Sprite(g_pDeadBitmap);
  g_pDead18Sprite = new Sprite(g_pDeadBitmap);
  g_pDead19Sprite = new Sprite(g_pDeadBitmap);
  g_pDead20Sprite = new Sprite(g_pDeadBitmap);
  g_pDead21Sprite = new Sprite(g_pDeadBitmap);
  g_pDead22Sprite = new Sprite(g_pDeadBitmap);
  g_pDead23Sprite = new Sprite(g_pDeadBitmap);
  g_pDead24Sprite = new Sprite(g_pDeadBitmap);
  g_pDead25Sprite = new Sprite(g_pDeadBitmap);
  g_pDead26Sprite = new Sprite(g_pDeadBitmap);
  g_pDead27Sprite = new Sprite(g_pDeadBitmap);
  g_pDead28Sprite = new Sprite(g_pDeadBitmap);
  g_pDead29Sprite = new Sprite(g_pDeadBitmap);
  g_pDead30Sprite = new Sprite(g_pDeadBitmap);
  g_pGameStartSprite = new Sprite(g_pGameStartBitmap);
  g_pPokeMenuIndicatorSprite = new Sprite(g_pPokeMenuIndicatorBitmap);
  g_pPokeTextMenu1Sprite = new Sprite(g_pPokeTextMenu1Bitmap);
  g_pPokeMenuSprite = new Sprite(g_pPokeMenuBitmap);
  
  g_pGameStartSprite->SetNumFrames(2);
  g_pPokeMenuIndicatorSprite->SetNumFrames(4);
  g_pOpponentHealthSprite->SetNumFrames(7);
  g_pPersonSprite->SetNumFrames(12);
  g_pSamSprite->SetNumFrames(4);
  g_pPokeIndicatorSprite->SetNumFrames(6);
  g_pFighter01Sprite->SetNumFrames(6);
  g_pFighter02Sprite->SetNumFrames(6);
  g_pFighter03Sprite->SetNumFrames(6);
  g_pFighter04Sprite->SetNumFrames(6);
  g_pFighter05Sprite->SetNumFrames(6);
  g_pFighter11Sprite->SetNumFrames(6);
  g_pFighter12Sprite->SetNumFrames(6);
  g_pFighter13Sprite->SetNumFrames(6);
  g_pFighter14Sprite->SetNumFrames(6);
  g_pFighter15Sprite->SetNumFrames(6);
  g_pFighter21Sprite->SetNumFrames(6);
  g_pFighter22Sprite->SetNumFrames(6);
  g_pFighter23Sprite->SetNumFrames(6);
  g_pFighter24Sprite->SetNumFrames(6);
  g_pFighter25Sprite->SetNumFrames(6);
  g_pShoot01Sprite->SetNumFrames(4);
  g_pShoot02Sprite->SetNumFrames(4);
  g_pShoot03Sprite->SetNumFrames(4);
  g_pShoot04Sprite->SetNumFrames(4);
  g_pShoot05Sprite->SetNumFrames(4);
  g_pShoot06Sprite->SetNumFrames(4);
  g_pShoot07Sprite->SetNumFrames(4);
  g_pShoot08Sprite->SetNumFrames(4);
  g_pShoot09Sprite->SetNumFrames(4);
  g_pShoot10Sprite->SetNumFrames(4);
  g_pShoot11Sprite->SetNumFrames(4);
  g_pShoot12Sprite->SetNumFrames(4);
  g_pShoot13Sprite->SetNumFrames(4);
  g_pShoot14Sprite->SetNumFrames(4);
  g_pShoot15Sprite->SetNumFrames(4);
  g_pShoot16Sprite->SetNumFrames(4);
  g_pShoot17Sprite->SetNumFrames(4);
  g_pShoot18Sprite->SetNumFrames(4);
  g_pShoot19Sprite->SetNumFrames(4);
  g_pShoot20Sprite->SetNumFrames(4);
  g_pShoot21Sprite->SetNumFrames(4);
  g_pShoot22Sprite->SetNumFrames(4);
  g_pShoot23Sprite->SetNumFrames(4);
  g_pShoot24Sprite->SetNumFrames(4);
  g_pShoot25Sprite->SetNumFrames(4);
  g_pShoot26Sprite->SetNumFrames(4);
  g_pShoot27Sprite->SetNumFrames(4);
  g_pShoot28Sprite->SetNumFrames(4);
  g_pShoot29Sprite->SetNumFrames(4);
  g_pShoot30Sprite->SetNumFrames(4);
  g_pFlag01Sprite->SetNumFrames(11);
  g_pFlag02Sprite->SetNumFrames(11);
  g_pFlag03Sprite->SetNumFrames(11);
  g_pFlag04Sprite->SetNumFrames(11);
  g_pFlag05Sprite->SetNumFrames(11);
  g_pFlag11Sprite->SetNumFrames(11);
  g_pFlag12Sprite->SetNumFrames(11);
  g_pFlag13Sprite->SetNumFrames(11);
  g_pFlag14Sprite->SetNumFrames(11);
  g_pFlag15Sprite->SetNumFrames(11);
  g_pFlag21Sprite->SetNumFrames(11);
  g_pFlag22Sprite->SetNumFrames(11);
  g_pFlag23Sprite->SetNumFrames(11);
  g_pFlag24Sprite->SetNumFrames(11);
  g_pFlag25Sprite->SetNumFrames(11);
  g_pBoatOrangeSprite->SetNumFrames(8);
  g_pBoatWhiteSprite->SetNumFrames(8);
  g_pBoatGreenSprite->SetNumFrames(8);
  g_pBoatGraySprite->SetNumFrames(8);
  g_pBoatRedSprite->SetNumFrames(8);
  g_pBoatBlueSprite->SetNumFrames(8);
  g_pPokeBeamSprite->SetNumFrames(5);
  g_pPokeSpiritSprite->SetNumFrames(4);
  g_pPokeBellSprite->SetNumFrames(5);
  g_pGame->AddSprite(g_pPokeBattleMenuSprite);
  g_pGame->AddSprite(g_pPokeTextMenu1Sprite);
  g_pGame->AddSprite(g_pPokeMenuSprite);
  g_pGame->AddSprite(g_pPokeTextStartSprite);
  g_pGame->AddSprite(g_pPokeMenuIndicatorSprite);
  g_pGame->AddSprite(g_pTextSprite);
  g_pGame->AddSprite(g_pBoatOrangeSprite);
  g_pGame->AddSprite(g_pBoatWhiteSprite);
  g_pGame->AddSprite(g_pBoatGreenSprite);
  g_pGame->AddSprite(g_pBoatGraySprite);
  g_pGame->AddSprite(g_pBoatRedSprite);
  g_pGame->AddSprite(g_pBoatBlueSprite);
  g_pGame->AddSprite(g_pSelectSprite);
  g_pGame->AddSprite(g_psudoku1Sprite1);
  g_pGame->AddSprite(g_psudoku2Sprite1);
  g_pGame->AddSprite(g_psudoku3Sprite1);
  g_pGame->AddSprite(g_psudoku4Sprite1);
  g_pGame->AddSprite(g_psudoku5Sprite1);
  g_pGame->AddSprite(g_psudoku6Sprite1);
  g_pGame->AddSprite(g_psudoku7Sprite1);
  g_pGame->AddSprite(g_psudoku8Sprite1);
  g_pGame->AddSprite(g_psudoku9Sprite1);
  g_pGame->AddSprite(g_psudoku1Sprite2);
  g_pGame->AddSprite(g_psudoku2Sprite2);
  g_pGame->AddSprite(g_psudoku3Sprite2);
  g_pGame->AddSprite(g_psudoku4Sprite2);
  g_pGame->AddSprite(g_psudoku5Sprite2);
  g_pGame->AddSprite(g_psudoku6Sprite2);
  g_pGame->AddSprite(g_psudoku7Sprite2);
  g_pGame->AddSprite(g_psudoku8Sprite2);
  g_pGame->AddSprite(g_psudoku9Sprite2);
  g_pGame->AddSprite(g_psudoku1Sprite3);
  g_pGame->AddSprite(g_psudoku2Sprite3);
  g_pGame->AddSprite(g_psudoku3Sprite3);
  g_pGame->AddSprite(g_psudoku4Sprite3);
  g_pGame->AddSprite(g_psudoku5Sprite3);
  g_pGame->AddSprite(g_psudoku6Sprite3);
  g_pGame->AddSprite(g_psudoku7Sprite3);
  g_pGame->AddSprite(g_psudoku8Sprite3);
  g_pGame->AddSprite(g_psudoku9Sprite3);
  g_pGame->AddSprite(g_psudoku1Sprite4);
  g_pGame->AddSprite(g_psudoku2Sprite4);
  g_pGame->AddSprite(g_psudoku3Sprite4);
  g_pGame->AddSprite(g_psudoku4Sprite4);
  g_pGame->AddSprite(g_psudoku5Sprite4);
  g_pGame->AddSprite(g_psudoku6Sprite4);
  g_pGame->AddSprite(g_psudoku7Sprite4);
  g_pGame->AddSprite(g_psudoku8Sprite4);
  g_pGame->AddSprite(g_psudoku9Sprite4);
  g_pGame->AddSprite(g_psudoku1Sprite5);
  g_pGame->AddSprite(g_psudoku2Sprite5);
  g_pGame->AddSprite(g_psudoku3Sprite5);
  g_pGame->AddSprite(g_psudoku4Sprite5);
  g_pGame->AddSprite(g_psudoku5Sprite5);
  g_pGame->AddSprite(g_psudoku6Sprite5);
  g_pGame->AddSprite(g_psudoku7Sprite5);
  g_pGame->AddSprite(g_psudoku8Sprite5);
  g_pGame->AddSprite(g_psudoku9Sprite5);
  g_pGame->AddSprite(g_psudoku1Sprite6);
  g_pGame->AddSprite(g_psudoku2Sprite6);
  g_pGame->AddSprite(g_psudoku3Sprite6);
  g_pGame->AddSprite(g_psudoku4Sprite6);
  g_pGame->AddSprite(g_psudoku5Sprite6);
  g_pGame->AddSprite(g_psudoku6Sprite6);
  g_pGame->AddSprite(g_psudoku7Sprite6);
  g_pGame->AddSprite(g_psudoku8Sprite6);
  g_pGame->AddSprite(g_psudoku9Sprite6);
  g_pGame->AddSprite(g_psudoku1Sprite7);
  g_pGame->AddSprite(g_psudoku2Sprite7);
  g_pGame->AddSprite(g_psudoku3Sprite7);
  g_pGame->AddSprite(g_psudoku4Sprite7);
  g_pGame->AddSprite(g_psudoku5Sprite7);
  g_pGame->AddSprite(g_psudoku6Sprite7);
  g_pGame->AddSprite(g_psudoku7Sprite7);
  g_pGame->AddSprite(g_psudoku8Sprite7);
  g_pGame->AddSprite(g_psudoku9Sprite7);
  g_pGame->AddSprite(g_psudoku1Sprite8);
  g_pGame->AddSprite(g_psudoku2Sprite8);
  g_pGame->AddSprite(g_psudoku3Sprite8);
  g_pGame->AddSprite(g_psudoku4Sprite8);
  g_pGame->AddSprite(g_psudoku5Sprite8);
  g_pGame->AddSprite(g_psudoku6Sprite8);
  g_pGame->AddSprite(g_psudoku7Sprite8);
  g_pGame->AddSprite(g_psudoku8Sprite8);
  g_pGame->AddSprite(g_psudoku9Sprite8);
  g_pGame->AddSprite(g_psudoku1Sprite9);
  g_pGame->AddSprite(g_psudoku2Sprite9);
  g_pGame->AddSprite(g_psudoku3Sprite9);
  g_pGame->AddSprite(g_psudoku4Sprite9);
  g_pGame->AddSprite(g_psudoku5Sprite9);
  g_pGame->AddSprite(g_psudoku6Sprite9);
  g_pGame->AddSprite(g_psudoku7Sprite9);
  g_pGame->AddSprite(g_psudoku8Sprite9);
  g_pGame->AddSprite(g_psudoku9Sprite9);
  g_pGame->AddSprite(g_pPokePlayerSprite);
  g_pGame->AddSprite(g_pIndicatorSprite);
  g_pGame->AddSprite(g_pPokeOpponentSprite);
  g_pGame->AddSprite(g_pSilkSprite);
  g_pGame->AddSprite(g_pFireworksSprite);
  g_pGame->AddSprite(g_pPorcelainSprite);
  g_pGame->AddSprite(g_pAfghanistanSprite);
  g_pGame->AddSprite(g_pBritainSprite);
  g_pGame->AddSprite(g_pChinaSprite);
  g_pGame->AddSprite(g_pCongoSprite);
  g_pGame->AddSprite(g_pFranceSprite);
  g_pGame->AddSprite(g_pPanamaSprite);
  g_pGame->AddSprite(g_pUsaSprite);
  g_pGame->AddSprite(g_pAntarcticaSprite);
  g_pGame->AddSprite(g_pUssrSprite);       
  g_pGame->AddSprite(g_pBombSprite);
  g_pGame->AddSprite(g_pPersonSprite);
  g_pGame->AddSprite(g_pAfghanistanWhite);
  g_pGame->AddSprite(g_pBritainWhite);
  g_pGame->AddSprite(g_pChinaWhite);
  g_pGame->AddSprite(g_pCongoWhite);
  g_pGame->AddSprite(g_pFranceWhite);
  g_pGame->AddSprite(g_pPanamaWhite);
  g_pGame->AddSprite(g_pAntarcticaWhite);
  g_pGame->AddSprite(g_pUssrWhite);
  g_pGame->AddSprite(g_pSamSprite);
  g_pGame->AddSprite(g_pDead01Sprite);
  g_pGame->AddSprite(g_pDead02Sprite);
  g_pGame->AddSprite(g_pDead03Sprite);
  g_pGame->AddSprite(g_pDead04Sprite);
  g_pGame->AddSprite(g_pDead05Sprite);
  g_pGame->AddSprite(g_pDead06Sprite);
  g_pGame->AddSprite(g_pDead07Sprite);
  g_pGame->AddSprite(g_pDead08Sprite);
  g_pGame->AddSprite(g_pDead09Sprite);
  g_pGame->AddSprite(g_pDead10Sprite);
  g_pGame->AddSprite(g_pDead11Sprite);
  g_pGame->AddSprite(g_pDead12Sprite);
  g_pGame->AddSprite(g_pDead13Sprite);
  g_pGame->AddSprite(g_pDead14Sprite);
  g_pGame->AddSprite(g_pDead15Sprite);
  g_pGame->AddSprite(g_pDead16Sprite);
  g_pGame->AddSprite(g_pDead17Sprite);
  g_pGame->AddSprite(g_pDead18Sprite);
  g_pGame->AddSprite(g_pDead19Sprite);
  g_pGame->AddSprite(g_pDead20Sprite);
  g_pGame->AddSprite(g_pDead21Sprite);
  g_pGame->AddSprite(g_pDead22Sprite);
  g_pGame->AddSprite(g_pDead23Sprite);
  g_pGame->AddSprite(g_pDead24Sprite);
  g_pGame->AddSprite(g_pDead25Sprite);
  g_pGame->AddSprite(g_pDead26Sprite);
  g_pGame->AddSprite(g_pDead27Sprite);
  g_pGame->AddSprite(g_pDead28Sprite);
  g_pGame->AddSprite(g_pDead29Sprite);
  g_pGame->AddSprite(g_pDead30Sprite);
  g_pGame->AddSprite(g_pFlag01Sprite);
  g_pGame->AddSprite(g_pFlag02Sprite);
  g_pGame->AddSprite(g_pFlag03Sprite);
  g_pGame->AddSprite(g_pFlag04Sprite);
  g_pGame->AddSprite(g_pFlag05Sprite);
  g_pGame->AddSprite(g_pFighter01Sprite);
  g_pGame->AddSprite(g_pFighter02Sprite);
  g_pGame->AddSprite(g_pFighter03Sprite);
  g_pGame->AddSprite(g_pFighter04Sprite);
  g_pGame->AddSprite(g_pFighter05Sprite);
  g_pGame->AddSprite(g_pFlag11Sprite);
  g_pGame->AddSprite(g_pFlag12Sprite);
  g_pGame->AddSprite(g_pFlag13Sprite);
  g_pGame->AddSprite(g_pFlag14Sprite);
  g_pGame->AddSprite(g_pFlag15Sprite);
  g_pGame->AddSprite(g_pFighter11Sprite);
  g_pGame->AddSprite(g_pFighter12Sprite);
  g_pGame->AddSprite(g_pFighter13Sprite);
  g_pGame->AddSprite(g_pFighter14Sprite);
  g_pGame->AddSprite(g_pFighter15Sprite);
  g_pGame->AddSprite(g_pFlag21Sprite);
  g_pGame->AddSprite(g_pFlag22Sprite);
  g_pGame->AddSprite(g_pFlag23Sprite);
  g_pGame->AddSprite(g_pFlag24Sprite);
  g_pGame->AddSprite(g_pFlag25Sprite);
  g_pGame->AddSprite(g_pFighter21Sprite);
  g_pGame->AddSprite(g_pFighter22Sprite);
  g_pGame->AddSprite(g_pFighter23Sprite);
  g_pGame->AddSprite(g_pFighter24Sprite);
  g_pGame->AddSprite(g_pFighter25Sprite);
  g_pGame->AddSprite(g_pShoot01Sprite);
  g_pGame->AddSprite(g_pShoot02Sprite);
  g_pGame->AddSprite(g_pShoot03Sprite);
  g_pGame->AddSprite(g_pShoot04Sprite);
  g_pGame->AddSprite(g_pShoot05Sprite);
  g_pGame->AddSprite(g_pShoot06Sprite);
  g_pGame->AddSprite(g_pShoot07Sprite);
  g_pGame->AddSprite(g_pShoot08Sprite);
  g_pGame->AddSprite(g_pShoot09Sprite);
  g_pGame->AddSprite(g_pShoot10Sprite);
  g_pGame->AddSprite(g_pShoot11Sprite);
  g_pGame->AddSprite(g_pShoot12Sprite);
  g_pGame->AddSprite(g_pShoot13Sprite);
  g_pGame->AddSprite(g_pShoot14Sprite);
  g_pGame->AddSprite(g_pShoot15Sprite);
  g_pGame->AddSprite(g_pShoot16Sprite);
  g_pGame->AddSprite(g_pShoot17Sprite);
  g_pGame->AddSprite(g_pShoot18Sprite);
  g_pGame->AddSprite(g_pShoot19Sprite);
  g_pGame->AddSprite(g_pShoot20Sprite);
  g_pGame->AddSprite(g_pShoot21Sprite);
  g_pGame->AddSprite(g_pShoot22Sprite);
  g_pGame->AddSprite(g_pShoot23Sprite);
  g_pGame->AddSprite(g_pShoot24Sprite);
  g_pGame->AddSprite(g_pShoot25Sprite);
  g_pGame->AddSprite(g_pShoot26Sprite);
  g_pGame->AddSprite(g_pShoot27Sprite);
  g_pGame->AddSprite(g_pShoot28Sprite);
  g_pGame->AddSprite(g_pShoot29Sprite);
  g_pGame->AddSprite(g_pShoot30Sprite);
  g_pGame->AddSprite(g_pCloudSprite);
  g_pGame->AddSprite(g_pOpponentHealthSprite);
  g_pGame->AddSprite(g_pPlayerHealthSprite);
  g_pGame->AddSprite(g_pPokeBeamTextSprite);
  g_pGame->AddSprite(g_pPokeSpiritTextSprite);
  g_pGame->AddSprite(g_pPokeBellTextSprite);
  g_pGame->AddSprite(g_pPokeOpponentTurnSprite);
  g_pGame->AddSprite(g_pPokeIndicatorSprite);
  g_pGame->AddSprite(g_pPokeBeamSprite);
  g_pGame->AddSprite(g_pPokeSpiritSprite);
  g_pGame->AddSprite(g_pPokeBellSprite);
  g_pGame->AddSprite(g_pPokeBeamText1Sprite);
  g_pGame->AddSprite(g_pPokeBellText1Sprite);
  g_pGame->AddSprite(g_pPokeSpiritText1Sprite);
  g_pGame->AddSprite(g_pPokeSpiritText2Sprite);
  g_pGame->AddSprite(g_pGameWonSprite);
  g_pGame->AddSprite(g_pGameStartSprite);
        g_pGameStartSprite->SetHidden(TRUE);
        g_pPokeSpiritText2Sprite->SetHidden(TRUE);
        g_pGameWonSprite->SetHidden(TRUE);
        g_pPokeSpiritText1Sprite->SetHidden(TRUE);
        g_pPokeBellText1Sprite->SetHidden(TRUE);
        g_pPokeBeamText1Sprite->SetHidden(TRUE);
        g_pPokeBeamTextSprite->SetHidden(TRUE);
        g_pPokeSpiritTextSprite->SetHidden(TRUE);
        g_pPokeBellTextSprite->SetHidden(TRUE);
        g_pPokeOpponentTurnSprite->SetHidden(TRUE);
        g_pPokeBeamSprite->SetHidden(TRUE);
        g_pPokeSpiritSprite->SetHidden(TRUE);
        g_pPokeBellSprite->SetHidden(TRUE);
        g_pPokeBattleMenuSprite->SetHidden(TRUE);
        g_pPokeTextMenu1Sprite->SetHidden(TRUE);
        g_pPokeMenuSprite->SetHidden(TRUE);
        g_pPokeTextStartSprite->SetHidden(TRUE);
        g_pPokeIndicatorSprite->SetHidden(TRUE);
        g_pPlayerHealthSprite->SetHidden(TRUE);
        g_pOpponentHealthSprite->SetHidden(TRUE);
        g_pBoatOrangeSprite->SetHidden(TRUE);
        g_pBoatWhiteSprite->SetHidden(TRUE);
        g_pBoatGreenSprite->SetHidden(TRUE);
        g_pBoatGraySprite->SetHidden(TRUE);
        g_pBoatRedSprite->SetHidden(TRUE);
        g_pBoatBlueSprite->SetHidden(TRUE);
        g_pCloudSprite->SetHidden(TRUE);
        g_pSelectSprite->SetHidden(TRUE);
        g_psudoku1Sprite1->SetHidden(TRUE);
        g_psudoku2Sprite1->SetHidden(TRUE);
        g_psudoku3Sprite1->SetHidden(TRUE);
        g_psudoku4Sprite1->SetHidden(TRUE);
        g_psudoku5Sprite1->SetHidden(TRUE);
        g_psudoku6Sprite1->SetHidden(TRUE);
        g_psudoku7Sprite1->SetHidden(TRUE);
        g_psudoku8Sprite1->SetHidden(TRUE);
        g_psudoku9Sprite1->SetHidden(TRUE);
        g_psudoku1Sprite2->SetHidden(TRUE);
        g_psudoku2Sprite2->SetHidden(TRUE);
        g_psudoku3Sprite2->SetHidden(TRUE);
        g_psudoku4Sprite2->SetHidden(TRUE);
        g_psudoku5Sprite2->SetHidden(TRUE);
        g_psudoku6Sprite2->SetHidden(TRUE);
        g_psudoku7Sprite2->SetHidden(TRUE);
        g_psudoku8Sprite2->SetHidden(TRUE);
        g_psudoku9Sprite2->SetHidden(TRUE);
        g_psudoku1Sprite3->SetHidden(TRUE);
        g_psudoku2Sprite3->SetHidden(TRUE);
        g_psudoku3Sprite3->SetHidden(TRUE);
        g_psudoku4Sprite3->SetHidden(TRUE);
        g_psudoku5Sprite3->SetHidden(TRUE);
        g_psudoku6Sprite3->SetHidden(TRUE);
        g_psudoku7Sprite3->SetHidden(TRUE);
        g_psudoku8Sprite3->SetHidden(TRUE);
        g_psudoku9Sprite3->SetHidden(TRUE);
        g_psudoku1Sprite4->SetHidden(TRUE);
        g_psudoku2Sprite4->SetHidden(TRUE);
        g_psudoku3Sprite4->SetHidden(TRUE);
        g_psudoku4Sprite4->SetHidden(TRUE);
        g_psudoku5Sprite4->SetHidden(TRUE);
        g_psudoku6Sprite4->SetHidden(TRUE);
        g_psudoku7Sprite4->SetHidden(TRUE);
        g_psudoku8Sprite4->SetHidden(TRUE);
        g_psudoku9Sprite4->SetHidden(TRUE);
        g_psudoku1Sprite5->SetHidden(TRUE);
        g_psudoku2Sprite5->SetHidden(TRUE);
        g_psudoku3Sprite5->SetHidden(TRUE);
        g_psudoku4Sprite5->SetHidden(TRUE);
        g_psudoku5Sprite5->SetHidden(TRUE);
        g_psudoku6Sprite5->SetHidden(TRUE);
        g_psudoku7Sprite5->SetHidden(TRUE);
        g_psudoku8Sprite5->SetHidden(TRUE);
        g_psudoku9Sprite5->SetHidden(TRUE);
        g_psudoku1Sprite6->SetHidden(TRUE);
        g_psudoku2Sprite6->SetHidden(TRUE);
        g_psudoku3Sprite6->SetHidden(TRUE);
        g_psudoku4Sprite6->SetHidden(TRUE);
        g_psudoku5Sprite6->SetHidden(TRUE);
        g_psudoku6Sprite6->SetHidden(TRUE);
        g_psudoku7Sprite6->SetHidden(TRUE);
        g_psudoku8Sprite6->SetHidden(TRUE);
        g_psudoku9Sprite6->SetHidden(TRUE);
        g_psudoku1Sprite7->SetHidden(TRUE);
        g_psudoku2Sprite7->SetHidden(TRUE);
        g_psudoku3Sprite7->SetHidden(TRUE);
        g_psudoku4Sprite7->SetHidden(TRUE);
        g_psudoku5Sprite7->SetHidden(TRUE);
        g_psudoku6Sprite7->SetHidden(TRUE);
        g_psudoku7Sprite7->SetHidden(TRUE);
        g_psudoku8Sprite7->SetHidden(TRUE);
        g_psudoku9Sprite7->SetHidden(TRUE);
        g_psudoku1Sprite8->SetHidden(TRUE);
        g_psudoku2Sprite8->SetHidden(TRUE);
        g_psudoku3Sprite8->SetHidden(TRUE);
        g_psudoku4Sprite8->SetHidden(TRUE);
        g_psudoku5Sprite8->SetHidden(TRUE);
        g_psudoku6Sprite8->SetHidden(TRUE);
        g_psudoku7Sprite8->SetHidden(TRUE);
        g_psudoku8Sprite8->SetHidden(TRUE);
        g_psudoku9Sprite8->SetHidden(TRUE);
        g_psudoku1Sprite9->SetHidden(TRUE);
        g_psudoku2Sprite9->SetHidden(TRUE);
        g_psudoku3Sprite9->SetHidden(TRUE);
        g_psudoku4Sprite9->SetHidden(TRUE);
        g_psudoku5Sprite9->SetHidden(TRUE);
        g_psudoku6Sprite9->SetHidden(TRUE);
        g_psudoku7Sprite9->SetHidden(TRUE);
        g_psudoku8Sprite9->SetHidden(TRUE);
        g_psudoku9Sprite9->SetHidden(TRUE);
        g_pPokeMenuIndicatorSprite->SetHidden(TRUE);
        g_pSilkSprite->SetHidden(TRUE);
        g_pIndicatorSprite->SetHidden(TRUE);
        g_pPorcelainSprite->SetHidden(TRUE);
        g_pFireworksSprite->SetHidden(TRUE);
        g_pSamSprite->SetHidden(TRUE);
        g_pPokePlayerSprite->SetHidden(TRUE);
        g_pTextSprite->SetHidden(TRUE);
        g_pPokeOpponentSprite->SetHidden(TRUE);
        g_pFighter01Sprite->SetHidden(TRUE);
        g_pFighter02Sprite->SetHidden(TRUE);
        g_pFighter03Sprite->SetHidden(TRUE);
        g_pFighter04Sprite->SetHidden(TRUE);
        g_pFighter05Sprite->SetHidden(TRUE);
        g_pFighter11Sprite->SetHidden(TRUE);
        g_pFighter12Sprite->SetHidden(TRUE);
        g_pFighter13Sprite->SetHidden(TRUE);
        g_pFighter14Sprite->SetHidden(TRUE);
        g_pFighter15Sprite->SetHidden(TRUE);
        g_pFighter21Sprite->SetHidden(TRUE);
        g_pFighter22Sprite->SetHidden(TRUE);
        g_pFighter23Sprite->SetHidden(TRUE);
        g_pFighter24Sprite->SetHidden(TRUE);
        g_pFighter25Sprite->SetHidden(TRUE);
        g_pShoot01Sprite->SetHidden(TRUE);
        g_pShoot02Sprite->SetHidden(TRUE);
        g_pShoot03Sprite->SetHidden(TRUE);
        g_pShoot04Sprite->SetHidden(TRUE);
        g_pShoot05Sprite->SetHidden(TRUE);
        g_pShoot06Sprite->SetHidden(TRUE);
        g_pShoot07Sprite->SetHidden(TRUE);
        g_pShoot08Sprite->SetHidden(TRUE);
        g_pShoot09Sprite->SetHidden(TRUE);
        g_pShoot10Sprite->SetHidden(TRUE);
        g_pShoot11Sprite->SetHidden(TRUE);
        g_pShoot12Sprite->SetHidden(TRUE);
        g_pShoot13Sprite->SetHidden(TRUE);
        g_pShoot14Sprite->SetHidden(TRUE);
        g_pShoot15Sprite->SetHidden(TRUE);
        g_pShoot16Sprite->SetHidden(TRUE);
        g_pShoot17Sprite->SetHidden(TRUE);
        g_pShoot18Sprite->SetHidden(TRUE);
        g_pShoot19Sprite->SetHidden(TRUE);
        g_pShoot20Sprite->SetHidden(TRUE);
        g_pShoot21Sprite->SetHidden(TRUE);
        g_pShoot22Sprite->SetHidden(TRUE);
        g_pShoot23Sprite->SetHidden(TRUE);
        g_pShoot24Sprite->SetHidden(TRUE);
        g_pShoot25Sprite->SetHidden(TRUE);
        g_pShoot26Sprite->SetHidden(TRUE);
        g_pShoot27Sprite->SetHidden(TRUE);
        g_pShoot28Sprite->SetHidden(TRUE);
        g_pShoot29Sprite->SetHidden(TRUE);
        g_pShoot30Sprite->SetHidden(TRUE);
        g_pFlag01Sprite->SetHidden(TRUE);
        g_pFlag02Sprite->SetHidden(TRUE);
        g_pFlag03Sprite->SetHidden(TRUE);
        g_pFlag04Sprite->SetHidden(TRUE);
        g_pFlag05Sprite->SetHidden(TRUE);
        g_pFlag11Sprite->SetHidden(TRUE);
        g_pFlag12Sprite->SetHidden(TRUE);
        g_pFlag13Sprite->SetHidden(TRUE);
        g_pFlag14Sprite->SetHidden(TRUE);
        g_pFlag15Sprite->SetHidden(TRUE);
        g_pFlag21Sprite->SetHidden(TRUE);
        g_pFlag22Sprite->SetHidden(TRUE);
        g_pFlag23Sprite->SetHidden(TRUE);
        g_pFlag24Sprite->SetHidden(TRUE);
        g_pFlag25Sprite->SetHidden(TRUE);
        g_pDead01Sprite->SetHidden(TRUE);
        g_pDead02Sprite->SetHidden(TRUE);
        g_pDead03Sprite->SetHidden(TRUE);
        g_pDead04Sprite->SetHidden(TRUE);
        g_pDead05Sprite->SetHidden(TRUE);
        g_pDead06Sprite->SetHidden(TRUE);
        g_pDead07Sprite->SetHidden(TRUE);
        g_pDead08Sprite->SetHidden(TRUE);
        g_pDead09Sprite->SetHidden(TRUE);
        g_pDead10Sprite->SetHidden(TRUE);
        g_pDead11Sprite->SetHidden(TRUE);
        g_pDead12Sprite->SetHidden(TRUE);
        g_pDead13Sprite->SetHidden(TRUE);
        g_pDead14Sprite->SetHidden(TRUE);
        g_pDead15Sprite->SetHidden(TRUE);
        g_pDead16Sprite->SetHidden(TRUE);
        g_pDead17Sprite->SetHidden(TRUE);
        g_pDead18Sprite->SetHidden(TRUE);
        g_pDead19Sprite->SetHidden(TRUE);
        g_pDead20Sprite->SetHidden(TRUE);
        g_pDead21Sprite->SetHidden(TRUE);
        g_pDead22Sprite->SetHidden(TRUE);
        g_pDead23Sprite->SetHidden(TRUE);
        g_pDead24Sprite->SetHidden(TRUE);
        g_pDead25Sprite->SetHidden(TRUE);
        g_pDead26Sprite->SetHidden(TRUE);
        g_pDead27Sprite->SetHidden(TRUE);
        g_pDead28Sprite->SetHidden(TRUE);
        g_pDead29Sprite->SetHidden(TRUE);
        g_pDead30Sprite->SetHidden(TRUE);
        g_pBombSprite->SetHidden(TRUE);
        g_pAfghanistanWhite->SetHidden(TRUE);
        g_pBritainWhite->SetHidden(TRUE);
        g_pChinaWhite->SetHidden(TRUE);
        g_pCongoWhite->SetHidden(TRUE);
        g_pFranceWhite->SetHidden(TRUE);
        g_pPanamaWhite->SetHidden(TRUE);
        g_pAntarcticaWhite->SetHidden(TRUE);
        g_pUssrWhite->SetHidden(TRUE);
        g_pAfghanistanSprite->SetHidden(TRUE);
        g_pBritainSprite->SetHidden(TRUE);
        g_pChinaSprite->SetHidden(TRUE);
        g_pCongoSprite->SetHidden(TRUE);
        g_pFranceSprite->SetHidden(TRUE);
        g_pPanamaSprite->SetHidden(TRUE);
        g_pAntarcticaSprite->SetHidden(TRUE);
        g_pUssrSprite->SetHidden(TRUE);
        g_pUsaSprite->SetHidden(TRUE);
        g_pPersonSprite->SetHidden(TRUE);
  
  // Set the level
  g_iLevel=LI_START;
  g_Flag0=0;
  g_Flag1=0;
  g_Flag2=0;
  g_ScoreUssr=0;
  g_AfghanistanWon = FALSE;
  g_BritainWon = FALSE;
  g_ChinaWon = FALSE;
  g_CongoWon = FALSE;
  g_FranceWon = FALSE;
  g_PanamaWon = FALSE;
  g_AntarcticaWon = FALSE;
  g_UssrWon = FALSE;

  // Play the background music
  //g_pGame->PlayMIDISong(TEXT("Music.mid"));
}

void GameEnd()
{
  // Close the MIDI player for the background music
  //g_pGame->CloseMIDIPlayer();

  // Cleanup the offscreen device context and bitmap
  DeleteObject(g_hOffscreenBitmap);
  DeleteDC(g_hOffscreenDC);  

  // Cleanup the bitmaps
  delete g_pPokeSpiritText2Bitmap;
  delete g_pGameWonBitmap;
  delete g_pGameStartBitmap;
  delete g_pPokeBeamText1Bitmap;
  delete g_pPokeBellText1Bitmap;
  delete g_pPokeSpiritText1Bitmap;
  delete g_pPokeBeamTextBitmap;
  delete g_pPokeSpiritTextBitmap;
  delete g_pPokeBellTextBitmap;
  delete g_pPokeOpponentTurnBitmap;
  delete g_pPokeBeamBitmap;
  delete g_pPokeSpiritBitmap;
  delete g_pPokeBellBitmap;
  delete g_pPokeBattleMenuBitmap;
  delete g_pPokeMenuIndicatorBitmap;
  delete g_pPokeMenuBitmap;
  delete g_pPokeTextMenu1Bitmap;
  delete g_pPokeTextStartBitmap;
  delete g_pPokeIndicatorBitmap;
  delete g_pPlayerHealthBitmap;
  delete g_pOpponentHealthBitmap;
  delete g_pTextBitmap;
  delete g_pBoatRedBitmap;
  delete g_pBoatGreenBitmap;
  delete g_pBoatWhiteBitmap;
  delete g_pBoatGrayBitmap;
  delete g_pBoatBlueBitmap;
  delete g_pBoatOrangeBitmap;
  delete g_pSelectBitmap;
  delete g_psudoku1Bitmap;
  delete g_psudoku2Bitmap;
  delete g_psudoku3Bitmap;
  delete g_psudoku4Bitmap;
  delete g_psudoku5Bitmap;
  delete g_psudoku6Bitmap;
  delete g_psudoku7Bitmap;
  delete g_psudoku8Bitmap;
  delete g_psudoku9Bitmap;
  delete g_psudoku1Bitmapy;
  delete g_psudoku2Bitmapy;
  delete g_psudoku3Bitmapy;
  delete g_psudoku4Bitmapy;
  delete g_psudoku5Bitmapy;
  delete g_psudoku6Bitmapy;
  delete g_psudoku7Bitmapy;
  delete g_psudoku8Bitmapy;
  delete g_psudoku9Bitmapy;
  delete g_pPokePlayerBitmap;
  delete g_pIndicatorBitmap;
  delete g_pPokeOpponentBitmap;
  delete g_pSilkBitmap;
  delete g_pFireworksBitmap;
  delete g_pPorcelainBitmap;
  delete g_pSamBitmap;
  delete g_pFighterBitmap;
  delete g_pShootBitmap;
  delete g_pFlagBitmap;
  delete g_pDeadBitmap;
  delete g_pBombBitmap;
  delete g_pPersonBitmap;
  delete g_pAfghanistanBitmap;
  delete g_pAntarcticaBitmap;
  delete g_pBritainBitmap;
  delete g_pChinaBitmap;
  delete g_pCongoBitmap;
  delete g_pFranceBitmap;
  delete g_pPanamaBitmap;
  delete g_pUsaBitmap;
  delete g_pWhiteBitmap;
  delete g_pUssrBitmap;
  delete g_pBGUssrBitmap;
  delete g_pBGChinaBitmap;
  delete g_pBGBritainBitmap;
  delete g_pBGPanamaBitmap;
  delete g_pBGAfghanistanBitmap;
  delete g_pBGAntarcticaBitmap;
  delete g_pCloudBitmap;

  // Cleanup the scrolling background and landscape layer
  delete g_pBackground;
  delete g_pBGUssr;
  delete g_pBGChina;
  delete g_pBGBritain;
  delete g_pSpace;
  delete g_pBGPanama;
  delete g_pBGAfghanistan;
  delete g_pBGAntarctica;
  delete g_pBGLandscapeLayer;

  // Cleanup the scrolling foreground and clouds layer
  //delete g_pForeground;
  //delete g_pFGCloudsLayer;

  // Cleanup the sprites
  g_pGame->CleanupSprites();

  // Cleanup the game engine
  delete g_pGame;
}

void GameActivate(HWND hWindow)
{
  // Capture the joystick
  //g_pGame->CaptureJoystick();

  // Resume the background music
  //g_pGame->PlayMIDISong(TEXT(""), FALSE);
}

void GameDeactivate(HWND hWindow)
{
  // Release the joystick
  //g_pGame->ReleaseJoystick();

  // Pause the background music
  //g_pGame->PauseMIDISong();
}

void GamePaint(HDC hDC)
{
   if(g_iLevel==LI_WORLD)
   {
     // Draw the starry background
     g_pSpace->Draw(hDC);  
     
     // Draw the scrolling background
     g_pBackground->Draw(hDC, TRUE);

     // Draw the sprites
     g_pGame->DrawSprites(hDC);

     // Draw the scrolling foreground
     //g_pForeground->Draw(hDC, TRUE); // draw with transparency
   }
   else if(g_iLevel==LI_USSR)
   {
      g_pBGUssr->Draw(hDC);
      g_pGame->DrawSprites(hDC);
   }
   else if(g_iLevel==LI_BRITAIN)
   {
      g_pBGBritain->Draw(hDC);
      g_pGame->DrawSprites(hDC);
   }
   else if(g_iLevel==LI_AFGHANISTAN)
   {
      g_pBGAfghanistan->Draw(hDC);
      g_pGame->DrawSprites(hDC);
   }
   else if(g_iLevel==LI_CHINA)
   {
      g_pBGChina->Draw(hDC);
      
      g_pGame->DrawSprites(hDC);
   }
   else if(g_iLevel==LI_PANAMA)
   {
      g_pBGPanama->Draw(hDC);
      g_pGame->DrawSprites(hDC);
   }
   else if(g_iLevel==LI_CONGO)
   {

   }
   else if(g_iLevel==LI_ANTARCTICA)
   {
      if(g_BritainCounter==0)
         g_pBGAntarctica->Draw(hDC);
      g_pGame->DrawSprites(hDC);
   }
   else if(g_iLevel==LI_START || g_iLevel==LI_WON)
      g_pGame->DrawSprites(hDC);
}

void GameCycle()
{
   HWND  hWindow = g_pGame->GetWindow();
   if(g_iLevel==LI_START)
   {
      if(g_Flag1==0)
      {
        g_pGameStartSprite->SetCurFrame(0);
        g_Timer1=clock();
        g_Flag1++;
      }
      if(clock()-g_Timer1>8000)
         g_pGameStartSprite->SetCurFrame(1);
      g_pGameStartSprite->SetHidden(FALSE);
      g_pGameStartSprite->SetPosition(0, 0);
   }
   if(g_iLevel==LI_WON)
   {
      g_pGameWonSprite->SetHidden(FALSE);
      g_pGameWonSprite->SetPosition(0, 0);
   }
   if(g_iLevel==LI_WORLD)
   {
     if(g_Flag1==0)
     {
        g_pPokeSpiritText2Sprite->SetHidden(TRUE);
        g_pGameWonSprite->SetHidden(TRUE);
        g_pGameStartSprite->SetHidden(TRUE);
        g_pPokeSpiritText1Sprite->SetHidden(TRUE);
        g_pPokeBellText1Sprite->SetHidden(TRUE);
        g_pPokeBeamText1Sprite->SetHidden(TRUE);
        g_pPokeBeamTextSprite->SetHidden(TRUE);
        g_pPokeSpiritTextSprite->SetHidden(TRUE);
        g_pPokeBellTextSprite->SetHidden(TRUE);
        g_pPokeOpponentTurnSprite->SetHidden(TRUE);
        g_pPokeBeamSprite->SetHidden(TRUE);
        g_pPokeSpiritSprite->SetHidden(TRUE);
        g_pPokeBellSprite->SetHidden(TRUE);
        g_pPokeBattleMenuSprite->SetHidden(TRUE);
        g_pPokeMenuIndicatorSprite->SetHidden(TRUE);
        g_pPokeTextMenu1Sprite->SetHidden(TRUE);
        g_pPokeMenuSprite->SetHidden(TRUE);
        g_pPokeTextStartSprite->SetHidden(TRUE);
        g_pPokeIndicatorSprite->SetHidden(TRUE);
        g_pPlayerHealthSprite->SetHidden(TRUE);
        g_pOpponentHealthSprite->SetHidden(TRUE);
        g_pTextSprite->SetHidden(TRUE);
        g_pBoatOrangeSprite->SetHidden(TRUE);
        g_pBoatWhiteSprite->SetHidden(TRUE);
        g_pBoatGreenSprite->SetHidden(TRUE);
        g_pBoatGraySprite->SetHidden(TRUE);
        g_pBoatRedSprite->SetHidden(TRUE);
        g_pBoatBlueSprite->SetHidden(TRUE);
        g_pCloudSprite->SetHidden(TRUE);
        g_pSelectSprite->SetHidden(TRUE);
        g_psudoku1Sprite1->SetHidden(TRUE);
        g_psudoku2Sprite1->SetHidden(TRUE);
        g_psudoku3Sprite1->SetHidden(TRUE);
        g_psudoku4Sprite1->SetHidden(TRUE);
        g_psudoku5Sprite1->SetHidden(TRUE);
        g_psudoku6Sprite1->SetHidden(TRUE);
        g_psudoku7Sprite1->SetHidden(TRUE);
        g_psudoku8Sprite1->SetHidden(TRUE);
        g_psudoku9Sprite1->SetHidden(TRUE);
        g_psudoku1Sprite2->SetHidden(TRUE);
        g_psudoku2Sprite2->SetHidden(TRUE);
        g_psudoku3Sprite2->SetHidden(TRUE);
        g_psudoku4Sprite2->SetHidden(TRUE);
        g_psudoku5Sprite2->SetHidden(TRUE);
        g_psudoku6Sprite2->SetHidden(TRUE);
        g_psudoku7Sprite2->SetHidden(TRUE);
        g_psudoku8Sprite2->SetHidden(TRUE);
        g_psudoku9Sprite2->SetHidden(TRUE);
        g_psudoku1Sprite3->SetHidden(TRUE);
        g_psudoku2Sprite3->SetHidden(TRUE);
        g_psudoku3Sprite3->SetHidden(TRUE);
        g_psudoku4Sprite3->SetHidden(TRUE);
        g_psudoku5Sprite3->SetHidden(TRUE);
        g_psudoku6Sprite3->SetHidden(TRUE);
        g_psudoku7Sprite3->SetHidden(TRUE);
        g_psudoku8Sprite3->SetHidden(TRUE);
        g_psudoku9Sprite3->SetHidden(TRUE);
        g_psudoku1Sprite4->SetHidden(TRUE);
        g_psudoku2Sprite4->SetHidden(TRUE);
        g_psudoku3Sprite4->SetHidden(TRUE);
        g_psudoku4Sprite4->SetHidden(TRUE);
        g_psudoku5Sprite4->SetHidden(TRUE);
        g_psudoku6Sprite4->SetHidden(TRUE);
        g_psudoku7Sprite4->SetHidden(TRUE);
        g_psudoku8Sprite4->SetHidden(TRUE);
        g_psudoku9Sprite4->SetHidden(TRUE);
        g_psudoku1Sprite5->SetHidden(TRUE);
        g_psudoku2Sprite5->SetHidden(TRUE);
        g_psudoku3Sprite5->SetHidden(TRUE);
        g_psudoku4Sprite5->SetHidden(TRUE);
        g_psudoku5Sprite5->SetHidden(TRUE);
        g_psudoku6Sprite5->SetHidden(TRUE);
        g_psudoku7Sprite5->SetHidden(TRUE);
        g_psudoku8Sprite5->SetHidden(TRUE);
        g_psudoku9Sprite5->SetHidden(TRUE);
        g_psudoku1Sprite6->SetHidden(TRUE);
        g_psudoku2Sprite6->SetHidden(TRUE);
        g_psudoku3Sprite6->SetHidden(TRUE);
        g_psudoku4Sprite6->SetHidden(TRUE);
        g_psudoku5Sprite6->SetHidden(TRUE);
        g_psudoku6Sprite6->SetHidden(TRUE);
        g_psudoku7Sprite6->SetHidden(TRUE);
        g_psudoku8Sprite6->SetHidden(TRUE);
        g_psudoku9Sprite6->SetHidden(TRUE);
        g_psudoku1Sprite7->SetHidden(TRUE);
        g_psudoku2Sprite7->SetHidden(TRUE);
        g_psudoku3Sprite7->SetHidden(TRUE);
        g_psudoku4Sprite7->SetHidden(TRUE);
        g_psudoku5Sprite7->SetHidden(TRUE);
        g_psudoku6Sprite7->SetHidden(TRUE);
        g_psudoku7Sprite7->SetHidden(TRUE);
        g_psudoku8Sprite7->SetHidden(TRUE);
        g_psudoku9Sprite7->SetHidden(TRUE);
        g_psudoku1Sprite8->SetHidden(TRUE);
        g_psudoku2Sprite8->SetHidden(TRUE);
        g_psudoku3Sprite8->SetHidden(TRUE);
        g_psudoku4Sprite8->SetHidden(TRUE);
        g_psudoku5Sprite8->SetHidden(TRUE);
        g_psudoku6Sprite8->SetHidden(TRUE);
        g_psudoku7Sprite8->SetHidden(TRUE);
        g_psudoku8Sprite8->SetHidden(TRUE);
        g_psudoku9Sprite8->SetHidden(TRUE);
        g_psudoku1Sprite9->SetHidden(TRUE);
        g_psudoku2Sprite9->SetHidden(TRUE);
        g_psudoku3Sprite9->SetHidden(TRUE);
        g_psudoku4Sprite9->SetHidden(TRUE);
        g_psudoku5Sprite9->SetHidden(TRUE);
        g_psudoku6Sprite9->SetHidden(TRUE);
        g_psudoku7Sprite9->SetHidden(TRUE);
        g_psudoku8Sprite9->SetHidden(TRUE);
        g_psudoku9Sprite9->SetHidden(TRUE);
        g_pSilkSprite->SetHidden(TRUE);
        g_pIndicatorSprite->SetHidden(TRUE);
        g_pPorcelainSprite->SetHidden(TRUE);
        g_pFireworksSprite->SetHidden(TRUE);
        g_pSamSprite->SetHidden(TRUE);
        g_pPokePlayerSprite->SetHidden(TRUE);
        g_pPokeOpponentSprite->SetHidden(TRUE);
        g_pFighter01Sprite->SetHidden(TRUE);
        g_pFighter02Sprite->SetHidden(TRUE);
        g_pFighter03Sprite->SetHidden(TRUE);
        g_pFighter04Sprite->SetHidden(TRUE);
        g_pFighter05Sprite->SetHidden(TRUE);
        g_pFighter11Sprite->SetHidden(TRUE);
        g_pFighter12Sprite->SetHidden(TRUE);
        g_pFighter13Sprite->SetHidden(TRUE);
        g_pFighter14Sprite->SetHidden(TRUE);
        g_pFighter15Sprite->SetHidden(TRUE);
        g_pFighter21Sprite->SetHidden(TRUE);
        g_pFighter22Sprite->SetHidden(TRUE);
        g_pFighter23Sprite->SetHidden(TRUE);
        g_pFighter24Sprite->SetHidden(TRUE);
        g_pFighter25Sprite->SetHidden(TRUE);
        g_pShoot01Sprite->SetHidden(TRUE);
        g_pShoot02Sprite->SetHidden(TRUE);
        g_pShoot03Sprite->SetHidden(TRUE);
        g_pShoot04Sprite->SetHidden(TRUE);
        g_pShoot05Sprite->SetHidden(TRUE);
        g_pShoot06Sprite->SetHidden(TRUE);
        g_pShoot07Sprite->SetHidden(TRUE);
        g_pShoot08Sprite->SetHidden(TRUE);
        g_pShoot09Sprite->SetHidden(TRUE);
        g_pShoot10Sprite->SetHidden(TRUE);
        g_pShoot11Sprite->SetHidden(TRUE);
        g_pShoot12Sprite->SetHidden(TRUE);
        g_pShoot13Sprite->SetHidden(TRUE);
        g_pShoot14Sprite->SetHidden(TRUE);
        g_pShoot15Sprite->SetHidden(TRUE);
        g_pShoot16Sprite->SetHidden(TRUE);
        g_pShoot17Sprite->SetHidden(TRUE);
        g_pShoot18Sprite->SetHidden(TRUE);
        g_pShoot19Sprite->SetHidden(TRUE);
        g_pShoot20Sprite->SetHidden(TRUE);
        g_pShoot21Sprite->SetHidden(TRUE);
        g_pShoot22Sprite->SetHidden(TRUE);
        g_pShoot23Sprite->SetHidden(TRUE);
        g_pShoot24Sprite->SetHidden(TRUE);
        g_pShoot25Sprite->SetHidden(TRUE);
        g_pShoot26Sprite->SetHidden(TRUE);
        g_pShoot27Sprite->SetHidden(TRUE);
        g_pShoot28Sprite->SetHidden(TRUE);
        g_pShoot29Sprite->SetHidden(TRUE);
        g_pShoot30Sprite->SetHidden(TRUE);
        g_pFlag01Sprite->SetHidden(TRUE);
        g_pFlag02Sprite->SetHidden(TRUE);
        g_pFlag03Sprite->SetHidden(TRUE);
        g_pFlag04Sprite->SetHidden(TRUE);
        g_pFlag05Sprite->SetHidden(TRUE);
        g_pFlag11Sprite->SetHidden(TRUE);
        g_pFlag12Sprite->SetHidden(TRUE);
        g_pFlag13Sprite->SetHidden(TRUE);
        g_pFlag14Sprite->SetHidden(TRUE);
        g_pFlag15Sprite->SetHidden(TRUE);
        g_pFlag21Sprite->SetHidden(TRUE);
        g_pFlag22Sprite->SetHidden(TRUE);
        g_pFlag23Sprite->SetHidden(TRUE);
        g_pFlag24Sprite->SetHidden(TRUE);
        g_pFlag25Sprite->SetHidden(TRUE);
        g_pDead01Sprite->SetHidden(TRUE);
        g_pDead02Sprite->SetHidden(TRUE);
        g_pDead03Sprite->SetHidden(TRUE);
        g_pDead04Sprite->SetHidden(TRUE);
        g_pDead05Sprite->SetHidden(TRUE);
        g_pDead06Sprite->SetHidden(TRUE);
        g_pDead07Sprite->SetHidden(TRUE);
        g_pDead08Sprite->SetHidden(TRUE);
        g_pDead09Sprite->SetHidden(TRUE);
        g_pDead10Sprite->SetHidden(TRUE);
        g_pDead11Sprite->SetHidden(TRUE);
        g_pDead12Sprite->SetHidden(TRUE);
        g_pDead13Sprite->SetHidden(TRUE);
        g_pDead14Sprite->SetHidden(TRUE);
        g_pDead15Sprite->SetHidden(TRUE);
        g_pDead16Sprite->SetHidden(TRUE);
        g_pDead17Sprite->SetHidden(TRUE);
        g_pDead18Sprite->SetHidden(TRUE);
        g_pDead19Sprite->SetHidden(TRUE);
        g_pDead20Sprite->SetHidden(TRUE);
        g_pDead21Sprite->SetHidden(TRUE);
        g_pDead22Sprite->SetHidden(TRUE);
        g_pDead23Sprite->SetHidden(TRUE);
        g_pDead24Sprite->SetHidden(TRUE);
        g_pDead25Sprite->SetHidden(TRUE);
        g_pDead26Sprite->SetHidden(TRUE);
        g_pDead27Sprite->SetHidden(TRUE);
        g_pDead28Sprite->SetHidden(TRUE);
        g_pDead29Sprite->SetHidden(TRUE);
        g_pDead30Sprite->SetHidden(TRUE);
        g_pBombSprite->SetHidden(TRUE);
        g_pAfghanistanWhite->SetHidden(TRUE);
        g_pBritainWhite->SetHidden(TRUE);
        g_pChinaWhite->SetHidden(TRUE);
        g_pCongoWhite->SetHidden(TRUE);
        g_pFranceWhite->SetHidden(TRUE);
        g_pPanamaWhite->SetHidden(TRUE);
        g_pAntarcticaWhite->SetHidden(TRUE);
        g_pUssrWhite->SetHidden(TRUE);
        g_pAfghanistanSprite->SetPosition(500, 500);
        g_pBritainSprite->SetPosition(500, 500);
        g_pChinaSprite->SetPosition(500, 500);
        g_pCongoSprite->SetPosition(500, 500);
        g_pFranceSprite->SetPosition(500, 500);
        g_pPanamaSprite->SetPosition(500, 500);
        g_pAntarcticaSprite->SetPosition(500, 500);
        g_pUssrSprite->SetPosition(500, 500);
        g_pPersonSprite->SetHidden(FALSE);
        g_pPersonSprite->SetCurFrame(9);
        g_pPersonSprite->SetPosition(115, 112);
        if(g_Flag2==1)
           g_Flag1=1;
     }
     RECT rcViewport;
     g_pBGLandscapeLayer->GetViewport(rcViewport);
     if(rcViewport.top<233 && rcViewport.left<343 && rcViewport.bottom>200 && rcViewport.right>313)
     {
           g_pUsaSprite->SetPosition(343-rcViewport.left, 200-rcViewport.top);
           g_pUsaSprite->SetHidden(FALSE);
     }
     else
        g_pUsaSprite->SetHidden(TRUE);
     if(rcViewport.top<190 && rcViewport.left<555 && rcViewport.bottom>190 && rcViewport.right>555)
     {
        if(g_BritainWon==FALSE)
        {
           g_pBritainSprite->SetPosition(555-rcViewport.left, 190-rcViewport.top);
           g_pBritainSprite->SetHidden(FALSE);
        }
        else
        {
            g_pBritainWhite->SetPosition(555-rcViewport.left, 160-rcViewport.top);
            g_pBritainWhite->SetHidden(FALSE);
            g_pBritainSprite->SetHidden(TRUE);
        }
     }
     else
     {
        g_pBritainSprite->SetHidden(TRUE);
        g_pBritainWhite->SetHidden(TRUE);
     }
     if(rcViewport.top<183 && rcViewport.left<723 && rcViewport.bottom>183 && rcViewport.right>723)
     {
        if(g_UssrWon==FALSE)
        {
           g_pUssrSprite->SetPosition(723-rcViewport.left, 183-rcViewport.top);
           g_pUssrSprite->SetHidden(FALSE);
        }
        else
        {
            g_pUssrWhite->SetPosition(723-rcViewport.left, 153-rcViewport.top);
            g_pUssrWhite->SetHidden(FALSE);
            g_pUssrSprite->SetHidden(TRUE);
        }
     }
     else
     {
        g_pUssrSprite->SetHidden(TRUE);
        g_pUssrWhite->SetHidden(TRUE);
     }
     if(rcViewport.top<220 && rcViewport.left<572 && rcViewport.bottom>220 && rcViewport.right>572)
     {
        if(g_FranceWon==FALSE)
        {
           g_pFranceSprite->SetPosition(572-rcViewport.left, 220-rcViewport.top);
           g_pFranceSprite->SetHidden(FALSE);
        }
        else
        {
            g_pFranceWhite->SetPosition(572-rcViewport.left, 190-rcViewport.top);
            g_pFranceWhite->SetHidden(FALSE);
            g_pFranceSprite->SetHidden(TRUE);
        }
     }
     else
     {
        g_pFranceSprite->SetHidden(TRUE);
        g_pFranceWhite->SetHidden(TRUE);
     }
     if(rcViewport.top<258 && rcViewport.left<720 && rcViewport.bottom>258 && rcViewport.right>720)
     {
        if(g_AfghanistanWon==FALSE)
        {
           g_pAfghanistanSprite->SetPosition(720-rcViewport.left, 258-rcViewport.top);
           g_pAfghanistanSprite->SetHidden(FALSE);
        }
        else
        {
            g_pAfghanistanWhite->SetPosition(720-rcViewport.left, 228-rcViewport.top);
            g_pAfghanistanWhite->SetHidden(FALSE);
            g_pAfghanistanSprite->SetHidden(TRUE);
        }
     }
     else
     {
        g_pAfghanistanSprite->SetHidden(TRUE);
        g_pAfghanistanWhite->SetHidden(TRUE);
     }
     if(rcViewport.top<267 && rcViewport.left<800 && rcViewport.bottom>267 && rcViewport.right>800)
     {
        if(g_ChinaWon==FALSE)
        {
           g_pChinaSprite->SetPosition(800-rcViewport.left, 267-rcViewport.top);
           g_pChinaSprite->SetHidden(FALSE);
        }
        else
        {
            g_pChinaWhite->SetPosition(800-rcViewport.left, 237-rcViewport.top);
            g_pChinaWhite->SetHidden(FALSE);
            g_pChinaSprite->SetHidden(TRUE);
        }
     }
     else
     {
        g_pChinaSprite->SetHidden(TRUE);
        g_pChinaWhite->SetHidden(TRUE);
     }
     /*if(rcViewport.top<356 && rcViewport.left<592 && rcViewport.bottom>356 && rcViewport.right>592)
     {
        if(g_CongoWon==FALSE)
        {
           g_pCongoSprite->SetPosition(592-rcViewport.left, 356-rcViewport.top);
           g_pCongoSprite->SetHidden(FALSE);
        }
        else
        {
            g_pCongoWhite->SetPosition(592-rcViewport.left, 326-rcViewport.top);
            g_pCongoWhite->SetHidden(FALSE);
            g_pCongoSprite->SetHidden(TRUE);
        }
     }
     else
     {
        g_pCongoSprite->SetHidden(TRUE);
        g_pCongoWhite->SetHidden(TRUE);
     }  */
     if(rcViewport.top<329 && rcViewport.left<366 && rcViewport.bottom>329 && rcViewport.right>366)
     {
        if(g_PanamaWon==FALSE)
        {
           g_pPanamaSprite->SetPosition(366-rcViewport.left, 329-rcViewport.top);
           g_pPanamaSprite->SetHidden(FALSE);
        }
        else
        {
            g_pPanamaWhite->SetPosition(366-rcViewport.left, 299-rcViewport.top);
            g_pPanamaWhite->SetHidden(FALSE);
            g_pPanamaSprite->SetHidden(TRUE);
        }
     }
     else
     {
        g_pPanamaSprite->SetHidden(TRUE);
        g_pPanamaWhite->SetHidden(TRUE);
     }
     if(rcViewport.top<570 && rcViewport.left<590 && rcViewport.bottom>570 && rcViewport.right>590)
     {
        if(g_AntarcticaWon==FALSE)
        {
           g_pAntarcticaSprite->SetPosition(590-rcViewport.left, 570-rcViewport.top);
           g_pAntarcticaSprite->SetHidden(FALSE);
        }
        else
        {
            g_pAntarcticaWhite->SetPosition(590-rcViewport.left, 540-rcViewport.top);
            g_pAntarcticaWhite->SetHidden(FALSE);
            g_pAntarcticaSprite->SetHidden(TRUE);
        }
     }
     else
     {
        g_pAntarcticaSprite->SetHidden(TRUE);
        g_pAntarcticaWhite->SetHidden(TRUE);
     }
     
     // Update the starry background
     g_pSpace->Update();
  
     // Update the background
     g_pBackground->Update();

     // Update the foreground
     //g_pForeground->Update();

     // Update the sprites
     g_pGame->UpdateSprites();
     if(g_AntarcticaWon==TRUE && g_AfghanistanWon==TRUE && g_PanamaWon==TRUE && g_ChinaWon==TRUE && g_UssrWon==TRUE && g_BritainWon==TRUE && g_FranceWon==TRUE)
        g_iLevel=LI_WON;
   }
   else if(g_iLevel==LI_USSR)
   { 
      if(g_Flag1==0)  
      {  
        g_Timer1=clock();
        g_ScoreUssr=0;
        g_pPersonSprite->SetPosition(115, 95);
        g_pPersonSprite->SetCurFrame(9);
        RECT rcPerson = g_pPersonSprite->GetPosition();
        RECT rcBomb;
        int r, y;
        g_pBombSprite->SetHidden(FALSE);
        do
        {
        do
        {
           r = rand()%256;
           y = rand()%152;
           g_pBombSprite->SetPosition(r, y+104);
           rcBomb = g_pBombSprite->GetPosition();
        }while(rcPerson.top<=rcBomb.bottom && rcPerson.bottom>=rcBomb.top && rcPerson.left<=rcBomb.right && rcPerson.right>=rcBomb.left);
        }while(rcBomb.right>256 || rcBomb.bottom>256);
        g_pUsaSprite->SetHidden(TRUE);
        g_pBritainSprite->SetHidden(TRUE);
        g_pUssrSprite->SetHidden(TRUE);
        g_pFranceSprite->SetHidden(TRUE);
        g_pAfghanistanSprite->SetHidden(TRUE);
        g_pChinaSprite->SetHidden(TRUE);
        g_pCongoSprite->SetHidden(TRUE);
        g_pPanamaSprite->SetHidden(TRUE);
        g_pAntarcticaSprite->SetHidden(TRUE);
        g_pAfghanistanWhite->SetHidden(TRUE);
        g_pBritainWhite->SetHidden(TRUE);
        g_pChinaWhite->SetHidden(TRUE);
        g_pCongoWhite->SetHidden(TRUE);
        g_pFranceWhite->SetHidden(TRUE);
        g_pPanamaWhite->SetHidden(TRUE);
        g_pAntarcticaWhite->SetHidden(TRUE);
        g_pUssrWhite->SetHidden(TRUE);
        RECT rcBounds = {0, 104, 256, 256}; 
        g_pPersonSprite->SetBounds(rcBounds);
      }
        if(g_pBombSprite->IsHidden())
        {
           RECT rcPerson = g_pPersonSprite->GetPosition();
           RECT rcBomb;
           int r, y;
           g_pBombSprite->SetHidden(FALSE);
           do
           {
             do
             {
              r = rand()%256;
              y = rand()%152;
              g_pBombSprite->SetPosition(r, y+104);
              rcBomb = g_pBombSprite->GetPosition();
             }while(rcPerson.top<=rcBomb.bottom && rcPerson.bottom>=rcBomb.top && rcPerson.left<=rcBomb.right && rcPerson.right>=rcBomb.left);
           }while(rcBomb.right>256 || rcBomb.bottom>256);
        }
        else
        {
           RECT rcPerson = g_pPersonSprite->GetPosition();
           RECT rcBomb = g_pBombSprite->GetPosition();
           if(rcPerson.top<=rcBomb.bottom && rcPerson.bottom>=rcBomb.top && rcPerson.left<=rcBomb.right && rcPerson.right>=rcBomb.left)
           {
              g_pBombSprite->SetHidden(TRUE);
              g_ScoreUssr++;
           }
        }
        g_pGame->UpdateSprites();
      if(clock()-g_Timer1>27500 && g_ScoreUssr<15)
      {
         MessageBox(hWindow, TEXT("You weren't quick enough and lost."), TEXT("SORRY"), MB_OK|MB_DEFBUTTON1|MB_ICONERROR);
         g_iLevel=LI_WORLD;
         g_Flag1=0;
      }
      if(g_ScoreUssr==15)
      {
         MessageBox(hWindow, TEXT("You won!"), TEXT("CONGRATULATIONS"), MB_OK|MB_DEFBUTTON1|MB_ICONEXCLAMATION);
         g_iLevel=LI_WORLD;
         g_Flag1=0;
         g_UssrWon=TRUE;
      }
   }
   else if(g_iLevel==LI_BRITAIN)
   {
      if(g_Flag1==0)
      {
        g_Flag0=0;
        g_Counter=0;
        g_BritainHealth=500;
        g_pBombSprite->SetHidden(TRUE);
        g_pPersonSprite->SetHidden(TRUE);
        g_pUsaSprite->SetHidden(TRUE);
        g_pBritainSprite->SetHidden(TRUE);
        g_pUssrSprite->SetHidden(TRUE);
        g_pFranceSprite->SetHidden(TRUE);
        g_pAfghanistanSprite->SetHidden(TRUE);
        g_pChinaSprite->SetHidden(TRUE);
        g_pCongoSprite->SetHidden(TRUE);
        g_pPanamaSprite->SetHidden(TRUE);
        g_pAntarcticaSprite->SetHidden(TRUE);
        g_pAfghanistanWhite->SetHidden(TRUE);
        g_pBritainWhite->SetHidden(TRUE);
        g_pChinaWhite->SetHidden(TRUE);
        g_pCongoWhite->SetHidden(TRUE);
        g_pFranceWhite->SetHidden(TRUE);
        g_pPanamaWhite->SetHidden(TRUE);
        g_pAntarcticaWhite->SetHidden(TRUE);
        g_pUssrWhite->SetHidden(TRUE);
        g_pSamSprite->SetHidden(FALSE);
        g_pSamSprite->SetCurFrame(0);
        g_pSamSprite->SetPosition(55, 116);
        g_pFlag01Sprite->SetPosition(257, 113);
        g_pFlag02Sprite->SetPosition(257, 137);
        g_pFlag03Sprite->SetPosition(257, 161);
        g_pFlag04Sprite->SetPosition(257, 185);
        g_pFlag05Sprite->SetPosition(257, 209);
        g_pFlag01Sprite->SetHidden(FALSE);
        g_pFlag02Sprite->SetHidden(FALSE);
        g_pFlag03Sprite->SetHidden(FALSE);
        g_pFlag04Sprite->SetHidden(FALSE);
        g_pFlag05Sprite->SetHidden(FALSE);
        g_pFighter01Sprite->SetPosition(257, 140);
        g_pFighter02Sprite->SetPosition(257, 164);
        g_pFighter03Sprite->SetPosition(257, 188);
        g_pFighter04Sprite->SetPosition(257, 212);
        g_pFighter05Sprite->SetPosition(257, 236);
        g_pFlag11Sprite->SetPosition(257, 113);
        g_pFlag12Sprite->SetPosition(257, 137);
        g_pFlag13Sprite->SetPosition(257, 161);
        g_pFlag14Sprite->SetPosition(257, 185);
        g_pFlag15Sprite->SetPosition(257, 209);
        g_pFighter11Sprite->SetPosition(257, 140);
        g_pFighter12Sprite->SetPosition(257, 164);
        g_pFighter13Sprite->SetPosition(257, 188);
        g_pFighter14Sprite->SetPosition(257, 212);
        g_pFighter15Sprite->SetPosition(257, 236);
        g_pFlag21Sprite->SetPosition(257, 113);
        g_pFlag22Sprite->SetPosition(257, 137);
        g_pFlag23Sprite->SetPosition(257, 161);
        g_pFlag24Sprite->SetPosition(257, 185);
        g_pFlag25Sprite->SetPosition(257, 209);
        g_pFighter21Sprite->SetPosition(257, 140);
        g_pFighter22Sprite->SetPosition(257, 164);
        g_pFighter23Sprite->SetPosition(257, 188);
        g_pFighter24Sprite->SetPosition(257, 212);
        g_pFighter25Sprite->SetPosition(257, 236);
        g_pShoot01Sprite->SetHidden(TRUE);
        g_pShoot02Sprite->SetHidden(TRUE);
        g_pShoot03Sprite->SetHidden(TRUE);
        g_pShoot04Sprite->SetHidden(TRUE);
        g_pShoot05Sprite->SetHidden(TRUE);
        g_pShoot06Sprite->SetHidden(TRUE);
        g_pShoot07Sprite->SetHidden(TRUE);
        g_pShoot08Sprite->SetHidden(TRUE);
        g_pShoot09Sprite->SetHidden(TRUE);
        g_pShoot10Sprite->SetHidden(TRUE);
        g_pShoot11Sprite->SetHidden(TRUE);
        g_pShoot12Sprite->SetHidden(TRUE);
        g_pShoot13Sprite->SetHidden(TRUE);
        g_pShoot14Sprite->SetHidden(TRUE);
        g_pShoot15Sprite->SetHidden(TRUE);
        g_pShoot16Sprite->SetHidden(TRUE);
        g_pShoot17Sprite->SetHidden(TRUE);
        g_pShoot18Sprite->SetHidden(TRUE);
        g_pShoot19Sprite->SetHidden(TRUE);
        g_pShoot20Sprite->SetHidden(TRUE);
        g_pShoot21Sprite->SetHidden(TRUE);
        g_pShoot22Sprite->SetHidden(TRUE);
        g_pShoot23Sprite->SetHidden(TRUE);
        g_pShoot24Sprite->SetHidden(TRUE);
        g_pShoot25Sprite->SetHidden(TRUE);
        g_pShoot26Sprite->SetHidden(TRUE);
        g_pShoot27Sprite->SetHidden(TRUE);
        g_pShoot28Sprite->SetHidden(TRUE);
        g_pShoot29Sprite->SetHidden(TRUE);
        g_pShoot30Sprite->SetHidden(TRUE);
        g_BritainLevel=0;
        g_BritainCounter=0;
      }
      if(g_Flag0==1)
      {
         RECT rcPos = g_pSamSprite->GetPosition();
         RECT rcDead;
         if(g_BritainCounter%4==0)
            g_pSamSprite->Update();
         g_BritainCounter++;
         if(g_BritainCounter>8)
         {
            g_Flag0=0;
            g_BritainCounter=0;
            g_pSamSprite->SetCurFrame(0);
            if(rcPos.top==116)
            {
                  if(!(g_pShoot01Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot01Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot01Sprite->SetHidden(TRUE);
                     g_pDead01Sprite->SetPosition(rcDead);
                     g_pDead01Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pShoot06Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot06Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot06Sprite->SetHidden(TRUE);
                     g_pDead06Sprite->SetPosition(rcDead);
                     g_pDead06Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pShoot11Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot11Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot11Sprite->SetHidden(TRUE);
                     g_pDead11Sprite->SetPosition(rcDead);
                     g_pDead11Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pShoot16Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot16Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot16Sprite->SetHidden(TRUE);
                     g_pDead16Sprite->SetPosition(rcDead);
                     g_pDead16Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pShoot21Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot21Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot21Sprite->SetHidden(TRUE);
                     g_pDead21Sprite->SetPosition(rcDead);
                     g_pDead21Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pShoot26Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot26Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot26Sprite->SetHidden(TRUE);
                     g_pDead26Sprite->SetPosition(rcDead);
                     g_pDead26Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFlag01Sprite->IsHidden()))
                  {
                     rcDead = g_pFlag01Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFlag01Sprite->SetHidden(TRUE);
                     g_pDead01Sprite->SetPosition(rcDead);
                     g_pDead01Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFighter01Sprite->IsHidden()))
                  {
                     rcDead = g_pFighter01Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFighter01Sprite->SetHidden(TRUE);
                     g_pDead06Sprite->SetPosition(rcDead);
                     g_pDead06Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFlag11Sprite->IsHidden()))
                  {
                     rcDead = g_pFlag11Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFlag11Sprite->SetHidden(TRUE);
                     g_pDead11Sprite->SetPosition(rcDead);
                     g_pDead11Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFighter11Sprite->IsHidden()))
                  {
                     rcDead = g_pFighter11Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFighter11Sprite->SetHidden(TRUE);
                     g_pDead16Sprite->SetPosition(rcDead);
                     g_pDead16Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFlag21Sprite->IsHidden()))
                  {
                     rcDead = g_pFlag21Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFlag21Sprite->SetHidden(TRUE);
                     g_pDead21Sprite->SetPosition(rcDead);
                     g_pDead21Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFighter21Sprite->IsHidden()))
                  {
                     rcDead = g_pFighter21Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFighter21Sprite->SetHidden(TRUE);
                     g_pDead26Sprite->SetPosition(rcDead);
                     g_pDead26Sprite->SetHidden(FALSE);
                  }
            }
            if(rcPos.top==140)
            {
                  if(!(g_pShoot02Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot02Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot02Sprite->SetHidden(TRUE);
                     g_pDead02Sprite->SetPosition(rcDead);
                     g_pDead02Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pShoot07Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot07Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot07Sprite->SetHidden(TRUE);
                     g_pDead07Sprite->SetPosition(rcDead);
                     g_pDead07Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pShoot12Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot12Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot12Sprite->SetHidden(TRUE);
                     g_pDead12Sprite->SetPosition(rcDead);
                     g_pDead12Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pShoot17Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot17Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot17Sprite->SetHidden(TRUE);
                     g_pDead17Sprite->SetPosition(rcDead);
                     g_pDead17Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pShoot22Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot22Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot22Sprite->SetHidden(TRUE);
                     g_pDead22Sprite->SetPosition(rcDead);
                     g_pDead22Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pShoot27Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot27Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot27Sprite->SetHidden(TRUE);
                     g_pDead27Sprite->SetPosition(rcDead);
                     g_pDead27Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFlag02Sprite->IsHidden()))
                  {
                     rcDead = g_pFlag02Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFlag02Sprite->SetHidden(TRUE);
                     g_pDead02Sprite->SetPosition(rcDead);
                     g_pDead02Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFighter02Sprite->IsHidden()))
                  {
                     rcDead = g_pFighter02Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFighter02Sprite->SetHidden(TRUE);
                     g_pDead07Sprite->SetPosition(rcDead);
                     g_pDead07Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFlag12Sprite->IsHidden()))
                  {
                     rcDead = g_pFlag12Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFlag12Sprite->SetHidden(TRUE);
                     g_pDead12Sprite->SetPosition(rcDead);
                     g_pDead12Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFighter12Sprite->IsHidden()))
                  {
                     rcDead = g_pFighter12Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFighter12Sprite->SetHidden(TRUE);
                     g_pDead17Sprite->SetPosition(rcDead);
                     g_pDead17Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFlag22Sprite->IsHidden()))
                  {
                     rcDead = g_pFlag22Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFlag22Sprite->SetHidden(TRUE);
                     g_pDead22Sprite->SetPosition(rcDead);
                     g_pDead22Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFighter22Sprite->IsHidden()))
                  {
                     rcDead = g_pFighter22Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFighter22Sprite->SetHidden(TRUE);
                     g_pDead27Sprite->SetPosition(rcDead);
                     g_pDead27Sprite->SetHidden(FALSE);
                  }
            }
            if(rcPos.top==164)
            {
                  if(!(g_pShoot03Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot03Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot03Sprite->SetHidden(TRUE);
                     g_pDead03Sprite->SetPosition(rcDead);
                     g_pDead03Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pShoot08Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot08Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot08Sprite->SetHidden(TRUE);
                     g_pDead08Sprite->SetPosition(rcDead);
                     g_pDead08Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pShoot13Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot13Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot13Sprite->SetHidden(TRUE);
                     g_pDead13Sprite->SetPosition(rcDead);
                     g_pDead13Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pShoot18Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot18Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot18Sprite->SetHidden(TRUE);
                     g_pDead18Sprite->SetPosition(rcDead);
                     g_pDead18Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pShoot23Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot23Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot23Sprite->SetHidden(TRUE);
                     g_pDead23Sprite->SetPosition(rcDead);
                     g_pDead23Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pShoot28Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot28Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot28Sprite->SetHidden(TRUE);
                     g_pDead28Sprite->SetPosition(rcDead);
                     g_pDead28Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFlag03Sprite->IsHidden()))
                  {
                     rcDead = g_pFlag03Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFlag03Sprite->SetHidden(TRUE);
                     g_pDead03Sprite->SetPosition(rcDead);
                     g_pDead03Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFighter03Sprite->IsHidden()))
                  {
                     rcDead = g_pFighter03Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFighter03Sprite->SetHidden(TRUE);
                     g_pDead08Sprite->SetPosition(rcDead);
                     g_pDead08Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFlag13Sprite->IsHidden()))
                  {
                     rcDead = g_pFlag13Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFlag13Sprite->SetHidden(TRUE);
                     g_pDead13Sprite->SetPosition(rcDead);
                     g_pDead13Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFighter13Sprite->IsHidden()))
                  {
                     rcDead = g_pFighter13Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFighter13Sprite->SetHidden(TRUE);
                     g_pDead18Sprite->SetPosition(rcDead);
                     g_pDead18Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFlag23Sprite->IsHidden()))
                  {
                     rcDead = g_pFlag23Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFlag23Sprite->SetHidden(TRUE);
                     g_pDead23Sprite->SetPosition(rcDead);
                     g_pDead23Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFighter23Sprite->IsHidden()))
                  {
                     rcDead = g_pFighter23Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFighter23Sprite->SetHidden(TRUE);
                     g_pDead28Sprite->SetPosition(rcDead);
                     g_pDead28Sprite->SetHidden(FALSE);
                  }
            }
            if(rcPos.top==188)
            {
                  if(!(g_pShoot04Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot04Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot04Sprite->SetHidden(TRUE);
                     g_pDead04Sprite->SetPosition(rcDead);
                     g_pDead04Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pShoot09Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot09Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot09Sprite->SetHidden(TRUE);
                     g_pDead09Sprite->SetPosition(rcDead);
                     g_pDead09Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pShoot14Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot14Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot14Sprite->SetHidden(TRUE);
                     g_pDead14Sprite->SetPosition(rcDead);
                     g_pDead14Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pShoot19Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot19Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot19Sprite->SetHidden(TRUE);
                     g_pDead19Sprite->SetPosition(rcDead);
                     g_pDead19Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pShoot24Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot24Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot24Sprite->SetHidden(TRUE);
                     g_pDead24Sprite->SetPosition(rcDead);
                     g_pDead24Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pShoot29Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot29Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot29Sprite->SetHidden(TRUE);
                     g_pDead29Sprite->SetPosition(rcDead);
                     g_pDead29Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFlag04Sprite->IsHidden()))
                  {
                     rcDead = g_pFlag04Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFlag04Sprite->SetHidden(TRUE);
                     g_pDead04Sprite->SetPosition(rcDead);
                     g_pDead04Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFighter04Sprite->IsHidden()))
                  {
                     rcDead = g_pFighter04Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFighter04Sprite->SetHidden(TRUE);
                     g_pDead09Sprite->SetPosition(rcDead);
                     g_pDead09Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFlag14Sprite->IsHidden()))
                  {
                     rcDead = g_pFlag14Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFlag14Sprite->SetHidden(TRUE);
                     g_pDead14Sprite->SetPosition(rcDead);
                     g_pDead14Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFighter14Sprite->IsHidden()))
                  {
                     rcDead = g_pFighter14Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFighter14Sprite->SetHidden(TRUE);
                     g_pDead19Sprite->SetPosition(rcDead);
                     g_pDead19Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFlag24Sprite->IsHidden()))
                  {
                     rcDead = g_pFlag24Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFlag24Sprite->SetHidden(TRUE);
                     g_pDead24Sprite->SetPosition(rcDead);
                     g_pDead24Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFighter24Sprite->IsHidden()))
                  {
                     rcDead = g_pFighter24Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFighter24Sprite->SetHidden(TRUE);
                     g_pDead29Sprite->SetPosition(rcDead);
                     g_pDead29Sprite->SetHidden(FALSE);
                  }
            }
            if(rcPos.top==212)
            {
                  if(!(g_pShoot05Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot05Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot05Sprite->SetHidden(TRUE);
                     g_pDead05Sprite->SetPosition(rcDead);
                     g_pDead05Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pShoot10Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot10Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot10Sprite->SetHidden(TRUE);
                     g_pDead10Sprite->SetPosition(rcDead);
                     g_pDead10Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pShoot15Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot15Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot15Sprite->SetHidden(TRUE);
                     g_pDead15Sprite->SetPosition(rcDead);
                     g_pDead15Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pShoot20Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot20Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot20Sprite->SetHidden(TRUE);
                     g_pDead20Sprite->SetPosition(rcDead);
                     g_pDead20Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pShoot25Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot25Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot25Sprite->SetHidden(TRUE);
                     g_pDead25Sprite->SetPosition(rcDead);
                     g_pDead25Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pShoot30Sprite->IsHidden()))
                  {
                     rcDead = g_pShoot30Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pShoot30Sprite->SetHidden(TRUE);
                     g_pDead30Sprite->SetPosition(rcDead);
                     g_pDead30Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFlag05Sprite->IsHidden()))
                  {
                     rcDead = g_pFlag05Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFlag05Sprite->SetHidden(TRUE);
                     g_pDead05Sprite->SetPosition(rcDead);
                     g_pDead05Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFighter05Sprite->IsHidden()))
                  {
                     rcDead = g_pFighter05Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFighter05Sprite->SetHidden(TRUE);
                     g_pDead10Sprite->SetPosition(rcDead);
                     g_pDead10Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFlag15Sprite->IsHidden()))
                  {
                     rcDead = g_pFlag15Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFlag15Sprite->SetHidden(TRUE);
                     g_pDead15Sprite->SetPosition(rcDead);
                     g_pDead15Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFighter15Sprite->IsHidden()))
                  {
                     rcDead = g_pFighter15Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFighter15Sprite->SetHidden(TRUE);
                     g_pDead20Sprite->SetPosition(rcDead);
                     g_pDead20Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFlag25Sprite->IsHidden()))
                  {
                     rcDead = g_pFlag25Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFlag25Sprite->SetHidden(TRUE);
                     g_pDead25Sprite->SetPosition(rcDead);
                     g_pDead25Sprite->SetHidden(FALSE);
                  }
                  else if(!(g_pFighter25Sprite->IsHidden()))
                  {
                     rcDead = g_pFighter25Sprite->GetPosition();
                     rcDead.top = rcDead.top+23;
                     rcDead.bottom = rcDead.bottom+23;
                     g_pFighter25Sprite->SetHidden(TRUE);
                     g_pDead30Sprite->SetPosition(rcDead);
                     g_pDead30Sprite->SetHidden(FALSE);
                  }
               }
            
         }
      }
      if((!(g_pFlag01Sprite->IsHidden()) || !(g_pFlag02Sprite->IsHidden()) || !(g_pFlag03Sprite->IsHidden()) || !(g_pFlag04Sprite->IsHidden()) || !(g_pFlag05Sprite->IsHidden()) || !(g_pShoot01Sprite->IsHidden()) || !(g_pShoot02Sprite->IsHidden()) || !(g_pShoot03Sprite->IsHidden()) || !(g_pShoot04Sprite->IsHidden()) || !(g_pShoot05Sprite->IsHidden())) && g_BritainLevel==0)
      {
         RECT rcPos = g_pFlag01Sprite->GetPosition();
         if(!(g_pFlag01Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFlag01Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag01Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag01Sprite->IsHidden()) && rcPos.left<=120)
         {
              g_pFlag01Sprite->SetHidden(TRUE);
              g_pShoot01Sprite->SetPosition(rcPos);
              g_pShoot01Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot01Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot01Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot01Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag02Sprite->GetPosition();
         if(!(g_pFlag02Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFlag02Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag02Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag02Sprite->IsHidden()) && rcPos.left<=120)
         {
              g_pFlag02Sprite->SetHidden(TRUE);
              g_pShoot02Sprite->SetPosition(rcPos);
              g_pShoot02Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot02Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot02Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot02Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag03Sprite->GetPosition();
         if(!(g_pFlag03Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFlag03Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag03Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag03Sprite->IsHidden()) && rcPos.left<=120)
         {
              g_pFlag03Sprite->SetHidden(TRUE);
              g_pShoot03Sprite->SetPosition(rcPos);
              g_pShoot03Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot03Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot03Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot03Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag04Sprite->GetPosition();
         if(!(g_pFlag04Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFlag04Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag04Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag04Sprite->IsHidden()) && rcPos.left<=120)
         {
              g_pFlag04Sprite->SetHidden(TRUE);
              g_pShoot04Sprite->SetPosition(rcPos);
              g_pShoot04Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot04Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot04Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot04Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag05Sprite->GetPosition();
         if(!(g_pFlag05Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFlag05Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag05Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag05Sprite->IsHidden()) && rcPos.left<=120)
         {
              g_pFlag05Sprite->SetHidden(TRUE);
              g_pShoot05Sprite->SetPosition(rcPos);
              g_pShoot05Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot05Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot05Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot05Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         if(g_Counter!=0)
            g_Counter++;
      }
      else if(g_pFlag01Sprite->IsHidden() && g_pFlag02Sprite->IsHidden() && g_pFlag03Sprite->IsHidden() && g_pFlag04Sprite->IsHidden() && g_pFlag05Sprite->IsHidden() && g_pShoot01Sprite->IsHidden() && g_pShoot02Sprite->IsHidden() && g_pShoot03Sprite->IsHidden() && g_pShoot04Sprite->IsHidden() && g_pShoot05Sprite->IsHidden() && g_BritainLevel==0)
      {
        g_BritainLevel++;
        g_pFlag01Sprite->SetPosition(257, 113);
        g_pFlag02Sprite->SetPosition(257, 137);
        g_pFlag03Sprite->SetPosition(257, 161);
        g_pFlag04Sprite->SetPosition(257, 185);
        g_pFlag05Sprite->SetPosition(257, 209);
        g_pFlag01Sprite->SetHidden(FALSE);
        g_pFlag02Sprite->SetHidden(FALSE);
        g_pFlag03Sprite->SetHidden(FALSE);
        g_pFlag04Sprite->SetHidden(FALSE);
        g_pFlag05Sprite->SetHidden(FALSE);
        g_pFighter01Sprite->SetHidden(FALSE);
        g_pFighter02Sprite->SetHidden(FALSE);
        g_pFighter03Sprite->SetHidden(FALSE);
        g_pFighter04Sprite->SetHidden(FALSE);
        g_pFighter05Sprite->SetHidden(FALSE);
        g_pFighter01Sprite->SetPosition(297, 113);
        g_pFighter02Sprite->SetPosition(297, 137);
        g_pFighter03Sprite->SetPosition(297, 161);
        g_pFighter04Sprite->SetPosition(297, 185);
        g_pFighter05Sprite->SetPosition(297, 209);
        g_pDead01Sprite->SetHidden(TRUE);
        g_pDead02Sprite->SetHidden(TRUE);
        g_pDead03Sprite->SetHidden(TRUE);
        g_pDead04Sprite->SetHidden(TRUE);
        g_pDead05Sprite->SetHidden(TRUE);
        g_Counter=0;
      }
      if((!(g_pFlag01Sprite->IsHidden()) || !(g_pFlag02Sprite->IsHidden()) || !(g_pFlag03Sprite->IsHidden()) || !(g_pFlag04Sprite->IsHidden()) || !(g_pFlag05Sprite->IsHidden()) || !(g_pFighter01Sprite->IsHidden()) || !(g_pFighter02Sprite->IsHidden()) || !(g_pFighter03Sprite->IsHidden()) || !(g_pFighter04Sprite->IsHidden()) || !(g_pFighter05Sprite->IsHidden()) || !(g_pShoot01Sprite->IsHidden()) || !(g_pShoot02Sprite->IsHidden()) || !(g_pShoot03Sprite->IsHidden()) || !(g_pShoot04Sprite->IsHidden()) || !(g_pShoot05Sprite->IsHidden()) || !(g_pShoot06Sprite->IsHidden()) || !(g_pShoot07Sprite->IsHidden()) || !(g_pShoot08Sprite->IsHidden()) || !(g_pShoot09Sprite->IsHidden()) || !(g_pShoot10Sprite->IsHidden())) && g_BritainLevel==1)
      {
         RECT rcPos = g_pFlag01Sprite->GetPosition();
         if(!(g_pFlag01Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFlag01Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag01Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag01Sprite->IsHidden()) && rcPos.left<=120)
         {
              g_pFlag01Sprite->SetHidden(TRUE);
              g_pShoot01Sprite->SetPosition(rcPos);
              g_pShoot01Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot01Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot01Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot01Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag02Sprite->GetPosition();
         if(!(g_pFlag02Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFlag02Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag02Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag02Sprite->IsHidden()) && rcPos.left<=120)
         {
              g_pFlag02Sprite->SetHidden(TRUE);
              g_pShoot02Sprite->SetPosition(rcPos);
              g_pShoot02Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot02Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot02Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot02Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag03Sprite->GetPosition();
         if(!(g_pFlag03Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFlag03Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag03Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag03Sprite->IsHidden()) && rcPos.left<=120)
         {
              g_pFlag03Sprite->SetHidden(TRUE);
              g_pShoot03Sprite->SetPosition(rcPos);
              g_pShoot03Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot03Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot03Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot03Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag04Sprite->GetPosition();
         if(!(g_pFlag04Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFlag04Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag04Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag04Sprite->IsHidden()) && rcPos.left<=120)
         {
              g_pFlag04Sprite->SetHidden(TRUE);
              g_pShoot04Sprite->SetPosition(rcPos);
              g_pShoot04Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot04Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot04Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot04Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag05Sprite->GetPosition();
         if(!(g_pFlag05Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFlag05Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag05Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag05Sprite->IsHidden()) && rcPos.left<=120)
         {
              g_pFlag05Sprite->SetHidden(TRUE);
              g_pShoot05Sprite->SetPosition(rcPos);
              g_pShoot05Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot05Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot05Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot05Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter01Sprite->GetPosition();
         if(!(g_pFighter01Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFighter01Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter01Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter01Sprite->IsHidden()) && rcPos.left<=140)
         {
              g_pFighter01Sprite->SetHidden(TRUE);
              g_pShoot06Sprite->SetPosition(rcPos);
              g_pShoot06Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot06Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot06Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot06Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter02Sprite->GetPosition();
         if(!(g_pFighter02Sprite->IsHidden()) && rcPos.left>140)
         {
            g_pFighter02Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter02Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter02Sprite->IsHidden()) && rcPos.left<=140)
         {
              g_pFighter02Sprite->SetHidden(TRUE);
              g_pShoot07Sprite->SetPosition(rcPos);
              g_pShoot07Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot07Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot07Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot07Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter03Sprite->GetPosition();
         if(!(g_pFighter03Sprite->IsHidden()) && rcPos.left>140)
         {
            g_pFighter03Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter03Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter03Sprite->IsHidden()) && rcPos.left<=140)
         {
              g_pFighter03Sprite->SetHidden(TRUE);
              g_pShoot08Sprite->SetPosition(rcPos);
              g_pShoot08Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot08Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot08Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot08Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter04Sprite->GetPosition();
         if(!(g_pFighter04Sprite->IsHidden()) && rcPos.left>140)
         {
            g_pFighter04Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter04Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter04Sprite->IsHidden()) && rcPos.left<=140)
         {
              g_pFighter04Sprite->SetHidden(TRUE);
              g_pShoot09Sprite->SetPosition(rcPos);
              g_pShoot09Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot09Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot09Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot09Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter05Sprite->GetPosition();
         if(!(g_pFighter05Sprite->IsHidden()) && rcPos.left>140)
         {
            g_pFighter05Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter05Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter05Sprite->IsHidden()) && rcPos.left<=140)
         {
              g_pFighter05Sprite->SetHidden(TRUE);
              g_pShoot10Sprite->SetPosition(rcPos);
              g_pShoot10Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot10Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot10Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot10Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         if(g_Counter!=0)
            g_Counter++;
      }
      else if(g_pFlag01Sprite->IsHidden() && g_pFlag02Sprite->IsHidden() && g_pFlag03Sprite->IsHidden() && g_pFlag04Sprite->IsHidden() && g_pFlag05Sprite->IsHidden() && g_pFighter01Sprite->IsHidden() && g_pFighter02Sprite->IsHidden() && g_pFighter03Sprite->IsHidden() && g_pFighter04Sprite->IsHidden() && g_pFighter05Sprite->IsHidden() && g_pShoot01Sprite->IsHidden() && g_pShoot02Sprite->IsHidden() && g_pShoot03Sprite->IsHidden() && g_pShoot04Sprite->IsHidden() && g_pShoot05Sprite->IsHidden() && g_pShoot06Sprite->IsHidden() && g_pShoot07Sprite->IsHidden() && g_pShoot08Sprite->IsHidden() && g_pShoot09Sprite->IsHidden() && g_pShoot10Sprite->IsHidden() && g_BritainLevel==1)
      {
        g_BritainLevel++;
        g_pFlag01Sprite->SetPosition(257, 113);
        g_pFlag02Sprite->SetPosition(257, 137);
        g_pFlag03Sprite->SetPosition(257, 161);
        g_pFlag04Sprite->SetPosition(257, 185);
        g_pFlag05Sprite->SetPosition(257, 209);
        g_pFlag11Sprite->SetPosition(315, 113);
        g_pFlag12Sprite->SetPosition(315, 137);
        g_pFlag13Sprite->SetPosition(315, 161);
        g_pFlag14Sprite->SetPosition(315, 185);
        g_pFlag15Sprite->SetPosition(315, 209);
        g_pFlag01Sprite->SetHidden(FALSE);
        g_pFlag02Sprite->SetHidden(FALSE);
        g_pFlag03Sprite->SetHidden(FALSE);
        g_pFlag04Sprite->SetHidden(FALSE);
        g_pFlag05Sprite->SetHidden(FALSE);
        g_pFlag11Sprite->SetHidden(FALSE);
        g_pFlag12Sprite->SetHidden(FALSE);
        g_pFlag13Sprite->SetHidden(FALSE);
        g_pFlag14Sprite->SetHidden(FALSE);
        g_pFlag15Sprite->SetHidden(FALSE);
        g_pFighter01Sprite->SetHidden(FALSE);
        g_pFighter02Sprite->SetHidden(FALSE);
        g_pFighter03Sprite->SetHidden(FALSE);
        g_pFighter04Sprite->SetHidden(FALSE);
        g_pFighter05Sprite->SetHidden(FALSE);
        g_pFighter01Sprite->SetPosition(297, 113);
        g_pFighter02Sprite->SetPosition(297, 137);
        g_pFighter03Sprite->SetPosition(297, 161);
        g_pFighter04Sprite->SetPosition(297, 185);
        g_pFighter05Sprite->SetPosition(297, 209);
        g_pDead01Sprite->SetHidden(TRUE);
        g_pDead02Sprite->SetHidden(TRUE);
        g_pDead03Sprite->SetHidden(TRUE);
        g_pDead04Sprite->SetHidden(TRUE);
        g_pDead05Sprite->SetHidden(TRUE);
        g_pDead06Sprite->SetHidden(TRUE);
        g_pDead07Sprite->SetHidden(TRUE);
        g_pDead08Sprite->SetHidden(TRUE);
        g_pDead09Sprite->SetHidden(TRUE);
        g_pDead10Sprite->SetHidden(TRUE);
        g_Counter=0;
      }
      if((!(g_pFlag01Sprite->IsHidden()) || !(g_pFlag02Sprite->IsHidden()) || !(g_pFlag03Sprite->IsHidden()) || !(g_pFlag04Sprite->IsHidden()) || !(g_pFlag05Sprite->IsHidden()) || !(g_pFighter01Sprite->IsHidden()) || !(g_pFighter02Sprite->IsHidden()) || !(g_pFighter03Sprite->IsHidden()) || !(g_pFighter04Sprite->IsHidden()) || !(g_pFighter05Sprite->IsHidden()) || !(g_pFlag11Sprite->IsHidden()) || !(g_pFlag12Sprite->IsHidden()) || !(g_pFlag13Sprite->IsHidden()) || !(g_pFlag14Sprite->IsHidden()) || !(g_pFlag15Sprite->IsHidden()) || !(g_pShoot01Sprite->IsHidden()) || !(g_pShoot02Sprite->IsHidden()) || !(g_pShoot03Sprite->IsHidden()) || !(g_pShoot04Sprite->IsHidden()) || !(g_pShoot05Sprite->IsHidden()) || !(g_pShoot06Sprite->IsHidden()) || !(g_pShoot07Sprite->IsHidden()) || !(g_pShoot08Sprite->IsHidden()) || !(g_pShoot09Sprite->IsHidden()) || !(g_pShoot10Sprite->IsHidden()) || !(g_pShoot11Sprite->IsHidden()) || !(g_pShoot12Sprite->IsHidden()) || !(g_pShoot13Sprite->IsHidden()) || !(g_pShoot14Sprite->IsHidden()) || !(g_pShoot15Sprite->IsHidden())) && g_BritainLevel==2)
      {
         RECT rcPos = g_pFlag01Sprite->GetPosition();
         if(!(g_pFlag01Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFlag01Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag01Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag01Sprite->IsHidden()) && rcPos.left<=120)
         {
              g_pFlag01Sprite->SetHidden(TRUE);
              g_pShoot01Sprite->SetPosition(rcPos);
              g_pShoot01Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot01Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot01Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot01Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag02Sprite->GetPosition();
         if(!(g_pFlag02Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFlag02Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag02Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag02Sprite->IsHidden()) && rcPos.left<=120)
         {
              g_pFlag02Sprite->SetHidden(TRUE);
              g_pShoot02Sprite->SetPosition(rcPos);
              g_pShoot02Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot02Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot02Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot02Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag03Sprite->GetPosition();
         if(!(g_pFlag03Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFlag03Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag03Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag03Sprite->IsHidden()) && rcPos.left<=120)
         {
              g_pFlag03Sprite->SetHidden(TRUE);
              g_pShoot03Sprite->SetPosition(rcPos);
              g_pShoot03Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot03Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot03Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot03Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag04Sprite->GetPosition();
         if(!(g_pFlag04Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFlag04Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag04Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag04Sprite->IsHidden()) && rcPos.left<=120)
         {
              g_pFlag04Sprite->SetHidden(TRUE);
              g_pShoot04Sprite->SetPosition(rcPos);
              g_pShoot04Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot04Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot04Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot04Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag05Sprite->GetPosition();
         if(!(g_pFlag05Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFlag05Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag05Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag05Sprite->IsHidden()) && rcPos.left<=120)
         {
              g_pFlag05Sprite->SetHidden(TRUE);
              g_pShoot05Sprite->SetPosition(rcPos);
              g_pShoot05Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot05Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot05Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot05Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter01Sprite->GetPosition();
         if(!(g_pFighter01Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFighter01Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter01Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter01Sprite->IsHidden()) && rcPos.left<=140)
         {
              g_pFighter01Sprite->SetHidden(TRUE);
              g_pShoot06Sprite->SetPosition(rcPos);
              g_pShoot06Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot06Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot06Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot06Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter02Sprite->GetPosition();
         if(!(g_pFighter02Sprite->IsHidden()) && rcPos.left>140)
         {
            g_pFighter02Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter02Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter02Sprite->IsHidden()) && rcPos.left<=140)
         {
              g_pFighter02Sprite->SetHidden(TRUE);
              g_pShoot07Sprite->SetPosition(rcPos);
              g_pShoot07Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot07Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot07Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot07Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter03Sprite->GetPosition();
         if(!(g_pFighter03Sprite->IsHidden()) && rcPos.left>140)
         {
            g_pFighter03Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter03Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter03Sprite->IsHidden()) && rcPos.left<=140)
         {
              g_pFighter03Sprite->SetHidden(TRUE);
              g_pShoot08Sprite->SetPosition(rcPos);
              g_pShoot08Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot08Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot08Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot08Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter04Sprite->GetPosition();
         if(!(g_pFighter04Sprite->IsHidden()) && rcPos.left>140)
         {
            g_pFighter04Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter04Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter04Sprite->IsHidden()) && rcPos.left<=140)
         {
              g_pFighter04Sprite->SetHidden(TRUE);
              g_pShoot09Sprite->SetPosition(rcPos);
              g_pShoot09Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot09Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot09Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot09Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter05Sprite->GetPosition();
         if(!(g_pFighter05Sprite->IsHidden()) && rcPos.left>140)
         {
            g_pFighter05Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter05Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter05Sprite->IsHidden()) && rcPos.left<=140)
         {
              g_pFighter05Sprite->SetHidden(TRUE);
              g_pShoot10Sprite->SetPosition(rcPos);
              g_pShoot10Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot10Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot10Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot10Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag11Sprite->GetPosition();
         if(!(g_pFlag11Sprite->IsHidden()) && rcPos.left>149)
         {
            g_pFlag11Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag11Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag11Sprite->IsHidden()) && rcPos.left<=149)
         {
              g_pFlag11Sprite->SetHidden(TRUE);
              g_pShoot11Sprite->SetPosition(rcPos);
              g_pShoot11Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot11Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot11Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot11Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag12Sprite->GetPosition();
         if(!(g_pFlag12Sprite->IsHidden()) && rcPos.left>149)
         {
            g_pFlag12Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag12Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag12Sprite->IsHidden()) && rcPos.left<=149)
         {
              g_pFlag12Sprite->SetHidden(TRUE);
              g_pShoot12Sprite->SetPosition(rcPos);
              g_pShoot12Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot12Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot12Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot12Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag13Sprite->GetPosition();
         if(!(g_pFlag13Sprite->IsHidden()) && rcPos.left>149)
         {
            g_pFlag13Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag13Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag13Sprite->IsHidden()) && rcPos.left<=149)
         {
              g_pFlag13Sprite->SetHidden(TRUE);
              g_pShoot13Sprite->SetPosition(rcPos);
              g_pShoot13Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot13Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot13Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot13Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag14Sprite->GetPosition();
         if(!(g_pFlag14Sprite->IsHidden()) && rcPos.left>149)
         {
            g_pFlag14Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag14Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag14Sprite->IsHidden()) && rcPos.left<=149)
         {
              g_pFlag14Sprite->SetHidden(TRUE);
              g_pShoot14Sprite->SetPosition(rcPos);
              g_pShoot14Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot14Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot14Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot14Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag15Sprite->GetPosition();
         if(!(g_pFlag15Sprite->IsHidden()) && rcPos.left>149)
         {
            g_pFlag15Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag15Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag15Sprite->IsHidden()) && rcPos.left<=149)
         {
              g_pFlag15Sprite->SetHidden(TRUE);
              g_pShoot15Sprite->SetPosition(rcPos);
              g_pShoot15Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot15Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot15Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot15Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         if(g_Counter!=0)
            g_Counter++;
      }
      else if(g_pFlag01Sprite->IsHidden() && g_pFlag02Sprite->IsHidden() && g_pFlag03Sprite->IsHidden() && g_pFlag04Sprite->IsHidden() && g_pFlag05Sprite->IsHidden() && g_pFighter01Sprite->IsHidden() && g_pFighter02Sprite->IsHidden() && g_pFighter03Sprite->IsHidden() && g_pFighter04Sprite->IsHidden() && g_pFighter05Sprite->IsHidden() && g_pFlag11Sprite->IsHidden() && g_pFlag12Sprite->IsHidden() && g_pFlag13Sprite->IsHidden() && g_pFlag14Sprite->IsHidden() && g_pFlag15Sprite->IsHidden() && g_pShoot01Sprite->IsHidden() && g_pShoot02Sprite->IsHidden() && g_pShoot03Sprite->IsHidden() && g_pShoot04Sprite->IsHidden() && g_pShoot05Sprite->IsHidden() && g_pShoot06Sprite->IsHidden() && g_pShoot07Sprite->IsHidden() && g_pShoot08Sprite->IsHidden() && g_pShoot09Sprite->IsHidden() && g_pShoot10Sprite->IsHidden() && g_pShoot11Sprite->IsHidden() && g_pShoot12Sprite->IsHidden() && g_pShoot13Sprite->IsHidden() && g_pShoot14Sprite->IsHidden() && g_pShoot15Sprite->IsHidden() && g_BritainLevel==2)
      {
        g_Counter=0;
        g_BritainLevel++;
        g_pFlag01Sprite->SetPosition(257, 113);
        g_pFlag02Sprite->SetPosition(257, 137);
        g_pFlag03Sprite->SetPosition(257, 161);
        g_pFlag04Sprite->SetPosition(257, 185);
        g_pFlag05Sprite->SetPosition(257, 209);
        g_pFlag11Sprite->SetPosition(315, 113);
        g_pFlag12Sprite->SetPosition(315, 137);
        g_pFlag13Sprite->SetPosition(315, 161);
        g_pFlag14Sprite->SetPosition(315, 185);
        g_pFlag15Sprite->SetPosition(315, 209);
        g_pFlag01Sprite->SetHidden(FALSE);
        g_pFlag02Sprite->SetHidden(FALSE);
        g_pFlag03Sprite->SetHidden(FALSE);
        g_pFlag04Sprite->SetHidden(FALSE);
        g_pFlag05Sprite->SetHidden(FALSE);
        g_pFlag11Sprite->SetHidden(FALSE);
        g_pFlag12Sprite->SetHidden(FALSE);
        g_pFlag13Sprite->SetHidden(FALSE);
        g_pFlag14Sprite->SetHidden(FALSE);
        g_pFlag15Sprite->SetHidden(FALSE);
        g_pFighter01Sprite->SetHidden(FALSE);
        g_pFighter02Sprite->SetHidden(FALSE);
        g_pFighter03Sprite->SetHidden(FALSE);
        g_pFighter04Sprite->SetHidden(FALSE);
        g_pFighter05Sprite->SetHidden(FALSE);
        g_pFighter11Sprite->SetHidden(FALSE);
        g_pFighter12Sprite->SetHidden(FALSE);
        g_pFighter13Sprite->SetHidden(FALSE);
        g_pFighter14Sprite->SetHidden(FALSE);
        g_pFighter15Sprite->SetHidden(FALSE);
        g_pFighter01Sprite->SetPosition(297, 113);
        g_pFighter02Sprite->SetPosition(297, 137);
        g_pFighter03Sprite->SetPosition(297, 161);
        g_pFighter04Sprite->SetPosition(297, 185);
        g_pFighter05Sprite->SetPosition(297, 209);
        g_pFighter11Sprite->SetPosition(355, 113);
        g_pFighter12Sprite->SetPosition(355, 137);
        g_pFighter13Sprite->SetPosition(355, 161);
        g_pFighter14Sprite->SetPosition(355, 185);
        g_pFighter15Sprite->SetPosition(355, 209);
        g_pDead01Sprite->SetHidden(TRUE);
        g_pDead02Sprite->SetHidden(TRUE);
        g_pDead03Sprite->SetHidden(TRUE);
        g_pDead04Sprite->SetHidden(TRUE);
        g_pDead05Sprite->SetHidden(TRUE);
        g_pDead06Sprite->SetHidden(TRUE);
        g_pDead07Sprite->SetHidden(TRUE);
        g_pDead08Sprite->SetHidden(TRUE);
        g_pDead09Sprite->SetHidden(TRUE);
        g_pDead10Sprite->SetHidden(TRUE);
        g_pDead11Sprite->SetHidden(TRUE);
        g_pDead12Sprite->SetHidden(TRUE);
        g_pDead13Sprite->SetHidden(TRUE);
        g_pDead14Sprite->SetHidden(TRUE);
        g_pDead15Sprite->SetHidden(TRUE);
      }
      if((!(g_pFlag01Sprite->IsHidden()) || !(g_pFlag02Sprite->IsHidden()) || !(g_pFlag03Sprite->IsHidden()) || !(g_pFlag04Sprite->IsHidden()) || !(g_pFlag05Sprite->IsHidden()) || !(g_pFighter01Sprite->IsHidden()) || !(g_pFighter02Sprite->IsHidden()) || !(g_pFighter03Sprite->IsHidden()) || !(g_pFighter04Sprite->IsHidden()) || !(g_pFighter05Sprite->IsHidden()) || !(g_pFlag11Sprite->IsHidden()) || !(g_pFlag12Sprite->IsHidden()) || !(g_pFlag13Sprite->IsHidden()) || !(g_pFlag14Sprite->IsHidden()) || !(g_pFlag15Sprite->IsHidden()) || !(g_pFighter11Sprite->IsHidden()) || !(g_pFighter12Sprite->IsHidden()) || !(g_pFighter13Sprite->IsHidden()) || !(g_pFighter14Sprite->IsHidden()) || !(g_pFighter15Sprite->IsHidden()) || !(g_pShoot01Sprite->IsHidden()) || !(g_pShoot02Sprite->IsHidden()) || !(g_pShoot03Sprite->IsHidden()) || !(g_pShoot04Sprite->IsHidden()) || !(g_pShoot05Sprite->IsHidden()) || !(g_pShoot06Sprite->IsHidden()) || !(g_pShoot07Sprite->IsHidden()) || !(g_pShoot08Sprite->IsHidden()) || !(g_pShoot09Sprite->IsHidden()) || !(g_pShoot10Sprite->IsHidden()) || !(g_pShoot11Sprite->IsHidden()) || !(g_pShoot12Sprite->IsHidden()) || !(g_pShoot13Sprite->IsHidden()) || !(g_pShoot14Sprite->IsHidden()) || !(g_pShoot15Sprite->IsHidden()) || !(g_pShoot16Sprite->IsHidden()) || !(g_pShoot17Sprite->IsHidden()) || !(g_pShoot18Sprite->IsHidden()) || !(g_pShoot19Sprite->IsHidden()) || !(g_pShoot20Sprite->IsHidden())) && g_BritainLevel==3)
      {
         RECT rcPos = g_pFlag01Sprite->GetPosition();
         if(!(g_pFlag01Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFlag01Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag01Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag01Sprite->IsHidden()) && rcPos.left<=120)
         {
              g_pFlag01Sprite->SetHidden(TRUE);
              g_pShoot01Sprite->SetPosition(rcPos);
              g_pShoot01Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot01Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot01Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot01Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag02Sprite->GetPosition();
         if(!(g_pFlag02Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFlag02Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag02Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag02Sprite->IsHidden()) && rcPos.left<=120)
         {
              g_pFlag02Sprite->SetHidden(TRUE);
              g_pShoot02Sprite->SetPosition(rcPos);
              g_pShoot02Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot02Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot02Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot02Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag03Sprite->GetPosition();
         if(!(g_pFlag03Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFlag03Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag03Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag03Sprite->IsHidden()) && rcPos.left<=120)
         {
              g_pFlag03Sprite->SetHidden(TRUE);
              g_pShoot03Sprite->SetPosition(rcPos);
              g_pShoot03Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot03Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot03Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot03Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag04Sprite->GetPosition();
         if(!(g_pFlag04Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFlag04Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag04Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag04Sprite->IsHidden()) && rcPos.left<=120)
         {
              g_pFlag04Sprite->SetHidden(TRUE);
              g_pShoot04Sprite->SetPosition(rcPos);
              g_pShoot04Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot04Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot04Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot04Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag05Sprite->GetPosition();
         if(!(g_pFlag05Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFlag05Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag05Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag05Sprite->IsHidden()) && rcPos.left<=120)
         {
              g_pFlag05Sprite->SetHidden(TRUE);
              g_pShoot05Sprite->SetPosition(rcPos);
              g_pShoot05Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot05Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot05Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot05Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter01Sprite->GetPosition();
         if(!(g_pFighter01Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFighter01Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter01Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter01Sprite->IsHidden()) && rcPos.left<=140)
         {
              g_pFighter01Sprite->SetHidden(TRUE);
              g_pShoot06Sprite->SetPosition(rcPos);
              g_pShoot06Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot06Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot06Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot06Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter02Sprite->GetPosition();
         if(!(g_pFighter02Sprite->IsHidden()) && rcPos.left>140)
         {
            g_pFighter02Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter02Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter02Sprite->IsHidden()) && rcPos.left<=140)
         {
              g_pFighter02Sprite->SetHidden(TRUE);
              g_pShoot07Sprite->SetPosition(rcPos);
              g_pShoot07Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot07Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot07Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot07Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter03Sprite->GetPosition();
         if(!(g_pFighter03Sprite->IsHidden()) && rcPos.left>140)
         {
            g_pFighter03Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter03Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter03Sprite->IsHidden()) && rcPos.left<=140)
         {
              g_pFighter03Sprite->SetHidden(TRUE);
              g_pShoot08Sprite->SetPosition(rcPos);
              g_pShoot08Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot08Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot08Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot08Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter04Sprite->GetPosition();
         if(!(g_pFighter04Sprite->IsHidden()) && rcPos.left>140)
         {
            g_pFighter04Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter04Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter04Sprite->IsHidden()) && rcPos.left<=140)
         {
              g_pFighter04Sprite->SetHidden(TRUE);
              g_pShoot09Sprite->SetPosition(rcPos);
              g_pShoot09Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot09Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot09Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot09Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter05Sprite->GetPosition();
         if(!(g_pFighter05Sprite->IsHidden()) && rcPos.left>140)
         {
            g_pFighter05Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter05Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter05Sprite->IsHidden()) && rcPos.left<=140)
         {
              g_pFighter05Sprite->SetHidden(TRUE);
              g_pShoot10Sprite->SetPosition(rcPos);
              g_pShoot10Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot10Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot10Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot10Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag11Sprite->GetPosition();
         if(!(g_pFlag11Sprite->IsHidden()) && rcPos.left>149)
         {
            g_pFlag11Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag11Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag11Sprite->IsHidden()) && rcPos.left<=149)
         {
              g_pFlag11Sprite->SetHidden(TRUE);
              g_pShoot11Sprite->SetPosition(rcPos);
              g_pShoot11Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot11Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot11Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot11Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag12Sprite->GetPosition();
         if(!(g_pFlag12Sprite->IsHidden()) && rcPos.left>149)
         {
            g_pFlag12Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag12Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag12Sprite->IsHidden()) && rcPos.left<=149)
         {
              g_pFlag12Sprite->SetHidden(TRUE);
              g_pShoot12Sprite->SetPosition(rcPos);
              g_pShoot12Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot12Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot12Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot12Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag13Sprite->GetPosition();
         if(!(g_pFlag13Sprite->IsHidden()) && rcPos.left>149)
         {
            g_pFlag13Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag13Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag13Sprite->IsHidden()) && rcPos.left<=149)
         {
              g_pFlag13Sprite->SetHidden(TRUE);
              g_pShoot13Sprite->SetPosition(rcPos);
              g_pShoot13Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot13Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot13Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot13Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag14Sprite->GetPosition();
         if(!(g_pFlag14Sprite->IsHidden()) && rcPos.left>149)
         {
            g_pFlag14Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag14Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag14Sprite->IsHidden()) && rcPos.left<=149)
         {
              g_pFlag14Sprite->SetHidden(TRUE);
              g_pShoot14Sprite->SetPosition(rcPos);
              g_pShoot14Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot14Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot14Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot14Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag15Sprite->GetPosition();
         if(!(g_pFlag15Sprite->IsHidden()) && rcPos.left>149)
         {
            g_pFlag15Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag15Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag15Sprite->IsHidden()) && rcPos.left<=149)
         {
              g_pFlag15Sprite->SetHidden(TRUE);
              g_pShoot15Sprite->SetPosition(rcPos);
              g_pShoot15Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot15Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot15Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot15Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter11Sprite->GetPosition();
         if(!(g_pFighter11Sprite->IsHidden()) && rcPos.left>169)
         {
            g_pFighter11Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter11Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter11Sprite->IsHidden()) && rcPos.left<=169)
         {
              g_pFighter11Sprite->SetHidden(TRUE);
              g_pShoot16Sprite->SetPosition(rcPos);
              g_pShoot16Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot16Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot16Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot16Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter12Sprite->GetPosition();
         if(!(g_pFighter12Sprite->IsHidden()) && rcPos.left>169)
         {
            g_pFighter12Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter12Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter12Sprite->IsHidden()) && rcPos.left<=169)
         {
              g_pFighter12Sprite->SetHidden(TRUE);
              g_pShoot17Sprite->SetPosition(rcPos);
              g_pShoot17Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot17Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot17Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot17Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter13Sprite->GetPosition();
         if(!(g_pFighter13Sprite->IsHidden()) && rcPos.left>169)
         {
            g_pFighter13Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter13Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter13Sprite->IsHidden()) && rcPos.left<=169)
         {
              g_pFighter13Sprite->SetHidden(TRUE);
              g_pShoot18Sprite->SetPosition(rcPos);
              g_pShoot18Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot18Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot18Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot18Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter14Sprite->GetPosition();
         if(!(g_pFighter14Sprite->IsHidden()) && rcPos.left>169)
         {
            g_pFighter14Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter14Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter14Sprite->IsHidden()) && rcPos.left<=169)
         {
              g_pFighter14Sprite->SetHidden(TRUE);
              g_pShoot19Sprite->SetPosition(rcPos);
              g_pShoot19Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot19Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot19Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot19Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter15Sprite->GetPosition();
         if(!(g_pFighter15Sprite->IsHidden()) && rcPos.left>169)
         {
            g_pFighter15Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter15Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter15Sprite->IsHidden()) && rcPos.left<=169)
         {
              g_pFighter15Sprite->SetHidden(TRUE);
              g_pShoot20Sprite->SetPosition(rcPos);
              g_pShoot20Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot20Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot20Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot20Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         if(g_Counter!=0)
            g_Counter++;
      }
      else if(g_pFlag01Sprite->IsHidden() && g_pFlag02Sprite->IsHidden() && g_pFlag03Sprite->IsHidden() && g_pFlag04Sprite->IsHidden() && g_pFlag05Sprite->IsHidden() && g_pFighter01Sprite->IsHidden() && g_pFighter02Sprite->IsHidden() && g_pFighter03Sprite->IsHidden() && g_pFighter04Sprite->IsHidden() && g_pFighter05Sprite->IsHidden() && g_pFighter11Sprite->IsHidden() && g_pFighter12Sprite->IsHidden() && g_pFighter13Sprite->IsHidden() && g_pFighter14Sprite->IsHidden() && g_pFighter15Sprite->IsHidden() && g_pFlag11Sprite->IsHidden() && g_pFlag12Sprite->IsHidden() && g_pFlag13Sprite->IsHidden() && g_pFlag14Sprite->IsHidden() && g_pFlag15Sprite->IsHidden() && g_pShoot01Sprite->IsHidden() && g_pShoot02Sprite->IsHidden() && g_pShoot03Sprite->IsHidden() && g_pShoot04Sprite->IsHidden() && g_pShoot05Sprite->IsHidden() && g_pShoot06Sprite->IsHidden() && g_pShoot07Sprite->IsHidden() && g_pShoot08Sprite->IsHidden() && g_pShoot09Sprite->IsHidden() && g_pShoot10Sprite->IsHidden() && g_pShoot11Sprite->IsHidden() && g_pShoot12Sprite->IsHidden() && g_pShoot13Sprite->IsHidden() && g_pShoot14Sprite->IsHidden() && g_pShoot15Sprite->IsHidden() && g_pShoot16Sprite->IsHidden() && g_pShoot17Sprite->IsHidden() && g_pShoot18Sprite->IsHidden() && g_pShoot19Sprite->IsHidden() && g_pShoot20Sprite->IsHidden() && g_BritainLevel==3)
      {
        g_BritainLevel++;
        g_pFlag01Sprite->SetPosition(257, 113);
        g_pFlag02Sprite->SetPosition(257, 137);
        g_pFlag03Sprite->SetPosition(257, 161);
        g_pFlag04Sprite->SetPosition(257, 185);
        g_pFlag05Sprite->SetPosition(257, 209);
        g_pFlag11Sprite->SetPosition(315, 113);
        g_pFlag12Sprite->SetPosition(315, 137);
        g_pFlag13Sprite->SetPosition(315, 161);
        g_pFlag14Sprite->SetPosition(315, 185);
        g_pFlag15Sprite->SetPosition(315, 209);
        g_pFlag21Sprite->SetPosition(373, 113);
        g_pFlag22Sprite->SetPosition(373, 137);
        g_pFlag23Sprite->SetPosition(373, 161);
        g_pFlag24Sprite->SetPosition(373, 185);
        g_pFlag25Sprite->SetPosition(373, 209);
        g_pFlag01Sprite->SetHidden(FALSE);
        g_pFlag02Sprite->SetHidden(FALSE);
        g_pFlag03Sprite->SetHidden(FALSE);
        g_pFlag04Sprite->SetHidden(FALSE);
        g_pFlag05Sprite->SetHidden(FALSE);
        g_pFlag11Sprite->SetHidden(FALSE);
        g_pFlag12Sprite->SetHidden(FALSE);
        g_pFlag13Sprite->SetHidden(FALSE);
        g_pFlag14Sprite->SetHidden(FALSE);
        g_pFlag15Sprite->SetHidden(FALSE);
        g_pFlag21Sprite->SetHidden(FALSE);
        g_pFlag22Sprite->SetHidden(FALSE);
        g_pFlag23Sprite->SetHidden(FALSE);
        g_pFlag24Sprite->SetHidden(FALSE);
        g_pFlag25Sprite->SetHidden(FALSE);
        g_pFighter01Sprite->SetHidden(FALSE);
        g_pFighter02Sprite->SetHidden(FALSE);
        g_pFighter03Sprite->SetHidden(FALSE);
        g_pFighter04Sprite->SetHidden(FALSE);
        g_pFighter05Sprite->SetHidden(FALSE);
        g_pFighter11Sprite->SetHidden(FALSE);
        g_pFighter12Sprite->SetHidden(FALSE);
        g_pFighter13Sprite->SetHidden(FALSE);
        g_pFighter14Sprite->SetHidden(FALSE);
        g_pFighter15Sprite->SetHidden(FALSE);
        g_pFighter21Sprite->SetHidden(FALSE);
        g_pFighter22Sprite->SetHidden(FALSE);
        g_pFighter23Sprite->SetHidden(FALSE);
        g_pFighter24Sprite->SetHidden(FALSE);
        g_pFighter25Sprite->SetHidden(FALSE);
        g_pFighter01Sprite->SetPosition(297, 113);
        g_pFighter02Sprite->SetPosition(297, 137);
        g_pFighter03Sprite->SetPosition(297, 161);
        g_pFighter04Sprite->SetPosition(297, 185);
        g_pFighter05Sprite->SetPosition(297, 209);
        g_pFighter11Sprite->SetPosition(355, 113);
        g_pFighter12Sprite->SetPosition(355, 137);
        g_pFighter13Sprite->SetPosition(355, 161);
        g_pFighter14Sprite->SetPosition(355, 185);
        g_pFighter15Sprite->SetPosition(413, 209);
        g_pFighter11Sprite->SetPosition(413, 113);
        g_pFighter12Sprite->SetPosition(413, 137);
        g_pFighter13Sprite->SetPosition(413, 161);
        g_pFighter14Sprite->SetPosition(413, 185);
        g_pFighter15Sprite->SetPosition(413, 209);
        g_pDead01Sprite->SetHidden(TRUE);
        g_pDead02Sprite->SetHidden(TRUE);
        g_pDead03Sprite->SetHidden(TRUE);
        g_pDead04Sprite->SetHidden(TRUE);
        g_pDead05Sprite->SetHidden(TRUE);
        g_pDead06Sprite->SetHidden(TRUE);
        g_pDead07Sprite->SetHidden(TRUE);
        g_pDead08Sprite->SetHidden(TRUE);
        g_pDead09Sprite->SetHidden(TRUE);
        g_pDead10Sprite->SetHidden(TRUE);
        g_pDead11Sprite->SetHidden(TRUE);
        g_pDead12Sprite->SetHidden(TRUE);
        g_pDead13Sprite->SetHidden(TRUE);
        g_pDead14Sprite->SetHidden(TRUE);
        g_pDead15Sprite->SetHidden(TRUE);
        g_pDead16Sprite->SetHidden(TRUE);
        g_pDead17Sprite->SetHidden(TRUE);
        g_pDead18Sprite->SetHidden(TRUE);
        g_pDead19Sprite->SetHidden(TRUE);
        g_pDead20Sprite->SetHidden(TRUE);
      }
      if((!(g_pFlag01Sprite->IsHidden()) || !(g_pFlag02Sprite->IsHidden()) || !(g_pFlag03Sprite->IsHidden()) || !(g_pFlag04Sprite->IsHidden()) || !(g_pFlag05Sprite->IsHidden()) || !(g_pFighter01Sprite->IsHidden()) || !(g_pFighter02Sprite->IsHidden()) || !(g_pFighter03Sprite->IsHidden()) || !(g_pFighter04Sprite->IsHidden()) || !(g_pFighter05Sprite->IsHidden()) || !(g_pFlag11Sprite->IsHidden()) || !(g_pFlag12Sprite->IsHidden()) || !(g_pFlag13Sprite->IsHidden()) || !(g_pFlag14Sprite->IsHidden()) || !(g_pFlag15Sprite->IsHidden()) || !(g_pFighter11Sprite->IsHidden()) || !(g_pFighter12Sprite->IsHidden()) || !(g_pFighter13Sprite->IsHidden()) || !(g_pFighter14Sprite->IsHidden()) || !(g_pFighter15Sprite->IsHidden()) || !(g_pFlag21Sprite->IsHidden()) || !(g_pFlag22Sprite->IsHidden()) || !(g_pFlag23Sprite->IsHidden()) || !(g_pFlag24Sprite->IsHidden()) || !(g_pFlag25Sprite->IsHidden()) || !(g_pFighter21Sprite->IsHidden()) || !(g_pFighter22Sprite->IsHidden()) || !(g_pFighter23Sprite->IsHidden()) || !(g_pFighter24Sprite->IsHidden()) || !(g_pFighter25Sprite->IsHidden()) || !(g_pShoot01Sprite->IsHidden()) || !(g_pShoot02Sprite->IsHidden()) || !(g_pShoot03Sprite->IsHidden()) || !(g_pShoot04Sprite->IsHidden()) || !(g_pShoot05Sprite->IsHidden()) || !(g_pShoot06Sprite->IsHidden()) || !(g_pShoot07Sprite->IsHidden()) || !(g_pShoot08Sprite->IsHidden()) || !(g_pShoot09Sprite->IsHidden()) || !(g_pShoot10Sprite->IsHidden()) || !(g_pShoot11Sprite->IsHidden()) || !(g_pShoot12Sprite->IsHidden()) || !(g_pShoot13Sprite->IsHidden()) || !(g_pShoot14Sprite->IsHidden()) || !(g_pShoot15Sprite->IsHidden()) || !(g_pShoot16Sprite->IsHidden()) || !(g_pShoot17Sprite->IsHidden()) || !(g_pShoot18Sprite->IsHidden()) || !(g_pShoot19Sprite->IsHidden()) || !(g_pShoot20Sprite->IsHidden()) || !(g_pShoot21Sprite->IsHidden()) || !(g_pShoot22Sprite->IsHidden()) || !(g_pShoot23Sprite->IsHidden()) || !(g_pShoot24Sprite->IsHidden()) || !(g_pShoot25Sprite->IsHidden()) || !(g_pShoot26Sprite->IsHidden()) || !(g_pShoot27Sprite->IsHidden()) || !(g_pShoot28Sprite->IsHidden()) || !(g_pShoot29Sprite->IsHidden()) || !(g_pShoot30Sprite->IsHidden())) &&  g_BritainLevel==4)
      {
         RECT rcPos = g_pFlag01Sprite->GetPosition();
         if(!(g_pFlag01Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFlag01Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag01Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag01Sprite->IsHidden()) && rcPos.left<=120)
         {
              g_pFlag01Sprite->SetHidden(TRUE);
              g_pShoot01Sprite->SetPosition(rcPos);
              g_pShoot01Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot01Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot01Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot01Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag02Sprite->GetPosition();
         if(!(g_pFlag02Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFlag02Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag02Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag02Sprite->IsHidden()) && rcPos.left<=120)
         {
              g_pFlag02Sprite->SetHidden(TRUE);
              g_pShoot02Sprite->SetPosition(rcPos);
              g_pShoot02Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot02Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot02Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot02Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag03Sprite->GetPosition();
         if(!(g_pFlag03Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFlag03Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag03Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag03Sprite->IsHidden()) && rcPos.left<=120)
         {
              g_pFlag03Sprite->SetHidden(TRUE);
              g_pShoot03Sprite->SetPosition(rcPos);
              g_pShoot03Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot03Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot03Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot03Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag04Sprite->GetPosition();
         if(!(g_pFlag04Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFlag04Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag04Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag04Sprite->IsHidden()) && rcPos.left<=120)
         {
              g_pFlag04Sprite->SetHidden(TRUE);
              g_pShoot04Sprite->SetPosition(rcPos);
              g_pShoot04Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot04Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot04Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot04Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag05Sprite->GetPosition();
         if(!(g_pFlag05Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFlag05Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag05Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag05Sprite->IsHidden()) && rcPos.left<=120)
         {
              g_pFlag05Sprite->SetHidden(TRUE);
              g_pShoot05Sprite->SetPosition(rcPos);
              g_pShoot05Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot05Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot05Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot05Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter01Sprite->GetPosition();
         if(!(g_pFighter01Sprite->IsHidden()) && rcPos.left>120)
         {
            g_pFighter01Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter01Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter01Sprite->IsHidden()) && rcPos.left<=140)
         {
              g_pFighter01Sprite->SetHidden(TRUE);
              g_pShoot06Sprite->SetPosition(rcPos);
              g_pShoot06Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot06Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot06Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot06Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter02Sprite->GetPosition();
         if(!(g_pFighter02Sprite->IsHidden()) && rcPos.left>140)
         {
            g_pFighter02Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter02Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter02Sprite->IsHidden()) && rcPos.left<=140)
         {
              g_pFighter02Sprite->SetHidden(TRUE);
              g_pShoot07Sprite->SetPosition(rcPos);
              g_pShoot07Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot07Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot07Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot07Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter03Sprite->GetPosition();
         if(!(g_pFighter03Sprite->IsHidden()) && rcPos.left>140)
         {
            g_pFighter03Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter03Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter03Sprite->IsHidden()) && rcPos.left<=140)
         {
              g_pFighter03Sprite->SetHidden(TRUE);
              g_pShoot08Sprite->SetPosition(rcPos);
              g_pShoot08Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot08Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot08Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot08Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter04Sprite->GetPosition();
         if(!(g_pFighter04Sprite->IsHidden()) && rcPos.left>140)
         {
            g_pFighter04Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter04Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter04Sprite->IsHidden()) && rcPos.left<=140)
         {
              g_pFighter04Sprite->SetHidden(TRUE);
              g_pShoot09Sprite->SetPosition(rcPos);
              g_pShoot09Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot09Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot09Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot09Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter05Sprite->GetPosition();
         if(!(g_pFighter05Sprite->IsHidden()) && rcPos.left>140)
         {
            g_pFighter05Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter05Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter05Sprite->IsHidden()) && rcPos.left<=140)
         {
              g_pFighter05Sprite->SetHidden(TRUE);
              g_pShoot10Sprite->SetPosition(rcPos);
              g_pShoot10Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot10Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot10Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot10Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag11Sprite->GetPosition();
         if(!(g_pFlag11Sprite->IsHidden()) && rcPos.left>149)
         {
            g_pFlag11Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag11Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag11Sprite->IsHidden()) && rcPos.left<=149)
         {
              g_pFlag11Sprite->SetHidden(TRUE);
              g_pShoot11Sprite->SetPosition(rcPos);
              g_pShoot11Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot11Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot11Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot11Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag12Sprite->GetPosition();
         if(!(g_pFlag12Sprite->IsHidden()) && rcPos.left>149)
         {
            g_pFlag12Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag12Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag12Sprite->IsHidden()) && rcPos.left<=149)
         {
              g_pFlag12Sprite->SetHidden(TRUE);
              g_pShoot12Sprite->SetPosition(rcPos);
              g_pShoot12Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot12Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot12Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot12Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag13Sprite->GetPosition();
         if(!(g_pFlag13Sprite->IsHidden()) && rcPos.left>149)
         {
            g_pFlag13Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag13Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag13Sprite->IsHidden()) && rcPos.left<=149)
         {
              g_pFlag13Sprite->SetHidden(TRUE);
              g_pShoot13Sprite->SetPosition(rcPos);
              g_pShoot13Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot13Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot13Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot13Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag14Sprite->GetPosition();
         if(!(g_pFlag14Sprite->IsHidden()) && rcPos.left>149)
         {
            g_pFlag14Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag14Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag14Sprite->IsHidden()) && rcPos.left<=149)
         {
              g_pFlag14Sprite->SetHidden(TRUE);
              g_pShoot14Sprite->SetPosition(rcPos);
              g_pShoot14Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot14Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot14Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot14Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag15Sprite->GetPosition();
         if(!(g_pFlag15Sprite->IsHidden()) && rcPos.left>149)
         {
            g_pFlag15Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag15Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag15Sprite->IsHidden()) && rcPos.left<=149)
         {
              g_pFlag15Sprite->SetHidden(TRUE);
              g_pShoot15Sprite->SetPosition(rcPos);
              g_pShoot15Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot15Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot15Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot15Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter11Sprite->GetPosition();
         if(!(g_pFighter11Sprite->IsHidden()) && rcPos.left>169)
         {
            g_pFighter11Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter11Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter11Sprite->IsHidden()) && rcPos.left<=169)
         {
              g_pFighter11Sprite->SetHidden(TRUE);
              g_pShoot16Sprite->SetPosition(rcPos);
              g_pShoot16Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot16Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot16Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot16Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter12Sprite->GetPosition();
         if(!(g_pFighter12Sprite->IsHidden()) && rcPos.left>169)
         {
            g_pFighter12Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter12Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter12Sprite->IsHidden()) && rcPos.left<=169)
         {
              g_pFighter12Sprite->SetHidden(TRUE);
              g_pShoot17Sprite->SetPosition(rcPos);
              g_pShoot17Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot17Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot17Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot17Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter13Sprite->GetPosition();
         if(!(g_pFighter13Sprite->IsHidden()) && rcPos.left>169)
         {
            g_pFighter13Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter13Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter13Sprite->IsHidden()) && rcPos.left<=169)
         {
              g_pFighter13Sprite->SetHidden(TRUE);
              g_pShoot18Sprite->SetPosition(rcPos);
              g_pShoot18Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot18Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot18Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot18Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter14Sprite->GetPosition();
         if(!(g_pFighter14Sprite->IsHidden()) && rcPos.left>169)
         {
            g_pFighter14Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter14Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter14Sprite->IsHidden()) && rcPos.left<=169)
         {
              g_pFighter14Sprite->SetHidden(TRUE);
              g_pShoot19Sprite->SetPosition(rcPos);
              g_pShoot19Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot19Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot19Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot19Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter15Sprite->GetPosition();
         if(!(g_pFighter15Sprite->IsHidden()) && rcPos.left>169)
         {
            g_pFighter15Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter15Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter15Sprite->IsHidden()) && rcPos.left<=169)
         {
              g_pFighter15Sprite->SetHidden(TRUE);
              g_pShoot20Sprite->SetPosition(rcPos);
              g_pShoot20Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot20Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot20Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot20Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag21Sprite->GetPosition();
         if(!(g_pFlag21Sprite->IsHidden()) && rcPos.left>178)
         {
            g_pFlag21Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag21Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag21Sprite->IsHidden()) && rcPos.left<=178)
         {
              g_pFlag21Sprite->SetHidden(TRUE);
              g_pShoot21Sprite->SetPosition(rcPos);
              g_pShoot21Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot21Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot21Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot21Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag22Sprite->GetPosition();
         if(!(g_pFlag22Sprite->IsHidden()) && rcPos.left>178)
         {
            g_pFlag22Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag22Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag22Sprite->IsHidden()) && rcPos.left<=178)
         {
              g_pFlag22Sprite->SetHidden(TRUE);
              g_pShoot22Sprite->SetPosition(rcPos);
              g_pShoot22Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot22Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot22Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot22Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag23Sprite->GetPosition();
         if(!(g_pFlag23Sprite->IsHidden()) && rcPos.left>178)
         {
            g_pFlag23Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag23Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag23Sprite->IsHidden()) && rcPos.left<=178)
         {
              g_pFlag23Sprite->SetHidden(TRUE);
              g_pShoot23Sprite->SetPosition(rcPos);
              g_pShoot23Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot23Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot23Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot23Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag24Sprite->GetPosition();
         if(!(g_pFlag24Sprite->IsHidden()) && rcPos.left>178)
         {
            g_pFlag24Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag24Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag24Sprite->IsHidden()) && rcPos.left<=178)
         {
              g_pFlag24Sprite->SetHidden(TRUE);
              g_pShoot24Sprite->SetPosition(rcPos);
              g_pShoot24Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot24Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot24Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot24Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFlag25Sprite->GetPosition();
         if(!(g_pFlag25Sprite->IsHidden()) && rcPos.left>178)
         {
            g_pFlag25Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFlag25Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFlag25Sprite->IsHidden()) && rcPos.left<=178)
         {
              g_pFlag25Sprite->SetHidden(TRUE);
              g_pShoot25Sprite->SetPosition(rcPos);
              g_pShoot25Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot25Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot25Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot25Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter21Sprite->GetPosition();
         if(!(g_pFighter21Sprite->IsHidden()) && rcPos.left>218)
         {
            g_pFighter21Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter21Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter21Sprite->IsHidden()) && rcPos.left<=218)
         {
              g_pFighter21Sprite->SetHidden(TRUE);
              g_pShoot26Sprite->SetPosition(rcPos);
              g_pShoot26Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot26Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot26Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot26Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter22Sprite->GetPosition();
         if(!(g_pFighter22Sprite->IsHidden()) && rcPos.left>218)
         {
            g_pFighter22Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter22Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter22Sprite->IsHidden()) && rcPos.left<=218)
         {
              g_pFighter22Sprite->SetHidden(TRUE);
              g_pShoot27Sprite->SetPosition(rcPos);
              g_pShoot27Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot27Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot27Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot27Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter23Sprite->GetPosition();
         if(!(g_pFighter23Sprite->IsHidden()) && rcPos.left>218)
         {
            g_pFighter23Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter23Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter23Sprite->IsHidden()) && rcPos.left<=218)
         {
              g_pFighter23Sprite->SetHidden(TRUE);
              g_pShoot28Sprite->SetPosition(rcPos);
              g_pShoot28Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot28Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot28Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot28Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter24Sprite->GetPosition();
         if(!(g_pFighter24Sprite->IsHidden()) && rcPos.left>218)
         {
            g_pFighter24Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter24Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter24Sprite->IsHidden()) && rcPos.left<=218)
         {
              g_pFighter24Sprite->SetHidden(TRUE);
              g_pShoot29Sprite->SetPosition(rcPos);
              g_pShoot29Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot29Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot29Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot29Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         rcPos = g_pFighter25Sprite->GetPosition();
         if(!(g_pFighter25Sprite->IsHidden()) && rcPos.left>218)
         {
            g_pFighter25Sprite->Update();
            rcPos.left-=1;
            rcPos.right-=1;
            g_pFighter25Sprite->SetPosition(rcPos);
         }
         else if(!(g_pFighter25Sprite->IsHidden()) && rcPos.left<=218)
         {
              g_pFighter25Sprite->SetHidden(TRUE);
              g_pShoot30Sprite->SetPosition(rcPos);
              g_pShoot30Sprite->SetHidden(FALSE);
         }
         if(!(g_pShoot30Sprite->IsHidden()))
         {
               if(g_Counter%4==0)
                  g_pShoot30Sprite->Update();
               if(g_Counter==0)
                  g_Counter++;
               if(g_pShoot30Sprite->GetCurFrame()==3)
                  g_BritainHealth--;
         }
         if(g_Counter!=0)
            g_Counter++;
      }
      else if(g_pFlag01Sprite->IsHidden() && g_pFlag02Sprite->IsHidden() && g_pFlag03Sprite->IsHidden() && g_pFlag04Sprite->IsHidden() && g_pFlag05Sprite->IsHidden() && g_pFighter01Sprite->IsHidden() && g_pFighter02Sprite->IsHidden() && g_pFighter03Sprite->IsHidden() && g_pFighter04Sprite->IsHidden() && g_pFighter05Sprite->IsHidden() && g_pFighter11Sprite->IsHidden() && g_pFighter12Sprite->IsHidden() && g_pFighter13Sprite->IsHidden() && g_pFighter14Sprite->IsHidden() && g_pFighter15Sprite->IsHidden() && g_pFlag11Sprite->IsHidden() && g_pFlag12Sprite->IsHidden() && g_pFlag13Sprite->IsHidden() && g_pFlag14Sprite->IsHidden() && g_pFlag15Sprite->IsHidden() && g_pFighter21Sprite->IsHidden() && g_pFighter22Sprite->IsHidden() && g_pFighter23Sprite->IsHidden() && g_pFighter24Sprite->IsHidden() && g_pFighter25Sprite->IsHidden() && g_pFlag21Sprite->IsHidden() && g_pFlag22Sprite->IsHidden() && g_pFlag23Sprite->IsHidden() && g_pFlag24Sprite->IsHidden() && g_pFlag25Sprite->IsHidden() && g_pShoot01Sprite->IsHidden() && g_pShoot02Sprite->IsHidden() && g_pShoot03Sprite->IsHidden() && g_pShoot04Sprite->IsHidden() && g_pShoot05Sprite->IsHidden() && g_pShoot06Sprite->IsHidden() && g_pShoot07Sprite->IsHidden() && g_pShoot08Sprite->IsHidden() && g_pShoot09Sprite->IsHidden() && g_pShoot10Sprite->IsHidden() && g_pShoot11Sprite->IsHidden() && g_pShoot12Sprite->IsHidden() && g_pShoot13Sprite->IsHidden() && g_pShoot14Sprite->IsHidden() && g_pShoot15Sprite->IsHidden() && g_pShoot16Sprite->IsHidden() && g_pShoot17Sprite->IsHidden() && g_pShoot18Sprite->IsHidden() && g_pShoot19Sprite->IsHidden() && g_pShoot20Sprite->IsHidden() && g_pShoot21Sprite->IsHidden() && g_pShoot22Sprite->IsHidden() && g_pShoot23Sprite->IsHidden() && g_pShoot24Sprite->IsHidden() && g_pShoot25Sprite->IsHidden() && g_pShoot26Sprite->IsHidden() && g_pShoot27Sprite->IsHidden() && g_pShoot28Sprite->IsHidden() && g_pShoot29Sprite->IsHidden() && g_pShoot30Sprite->IsHidden() &&  g_BritainLevel==4)
      {
        MessageBox(hWindow, TEXT("You won!"), TEXT("CONGRATULATIONS"), MB_OK|MB_DEFBUTTON1|MB_ICONEXCLAMATION);
         g_iLevel=LI_WORLD;
         g_Flag1=0;
         g_BritainWon=TRUE;
      }
      if(g_BritainHealth<=0)
      {
        MessageBox(hWindow, TEXT("You took too much damage."), TEXT("SORRY"), MB_OK|MB_DEFBUTTON1|MB_ICONERROR);
         g_iLevel=LI_WORLD;
         g_Flag1=0;
      }
   }
   else if(g_iLevel==LI_AFGHANISTAN)
   {
      if(g_Flag1==0)
      {
        for(int k=0; k<9; k++)
          for(int j=0; j<9; j++)
            g_sudoku[k][j]=0;
        g_pBombSprite->SetHidden(TRUE);
        g_pPersonSprite->SetHidden(TRUE);
        g_pUsaSprite->SetHidden(TRUE);
        g_pBritainSprite->SetHidden(TRUE);
        g_pUssrSprite->SetHidden(TRUE);
        g_pFranceSprite->SetHidden(TRUE);
        g_pAfghanistanSprite->SetHidden(TRUE);
        g_pChinaSprite->SetHidden(TRUE);
        g_pCongoSprite->SetHidden(TRUE);
        g_pPanamaSprite->SetHidden(TRUE);
        g_pAntarcticaSprite->SetHidden(TRUE);
        g_pAfghanistanWhite->SetHidden(TRUE);
        g_pBritainWhite->SetHidden(TRUE);
        g_pChinaWhite->SetHidden(TRUE);
        g_pCongoWhite->SetHidden(TRUE);
        g_pFranceWhite->SetHidden(TRUE);
        g_pPanamaWhite->SetHidden(TRUE);
        g_pAntarcticaWhite->SetHidden(TRUE);
        g_pUssrWhite->SetHidden(TRUE);
        g_psudoku9Sprite9->SetHidden(FALSE);
        g_psudoku8Sprite9->SetHidden(FALSE);
        g_psudoku7Sprite9->SetHidden(FALSE);
        g_psudoku5Sprite9->SetHidden(FALSE);
        g_psudoku2Sprite9->SetHidden(FALSE);
        g_psudoku1Sprite8->SetHidden(FALSE);
        g_psudoku4Sprite8->SetHidden(FALSE);
        g_psudoku8Sprite8->SetHidden(FALSE);
        g_psudoku9Sprite8->SetHidden(FALSE);
        g_psudoku6Sprite7->SetHidden(FALSE);
        g_psudoku1Sprite6->SetHidden(FALSE);
        g_psudoku3Sprite6->SetHidden(FALSE);
        g_psudoku6Sprite6->SetHidden(FALSE);
        g_psudoku8Sprite5->SetHidden(FALSE);
        g_psudoku6Sprite5->SetHidden(FALSE);
        g_psudoku2Sprite5->SetHidden(FALSE);
        g_psudoku3Sprite5->SetHidden(FALSE);
        g_psudoku8Sprite4->SetHidden(FALSE);
        g_psudoku4Sprite4->SetHidden(FALSE);
        g_psudoku7Sprite4->SetHidden(FALSE);
        g_psudoku6Sprite3->SetHidden(FALSE);
        g_psudoku7Sprite2->SetHidden(FALSE);
        g_psudoku5Sprite2->SetHidden(FALSE);
        g_psudoku9Sprite2->SetHidden(FALSE);
        g_psudoku1Sprite2->SetHidden(FALSE);
        g_psudoku8Sprite1->SetHidden(FALSE);
        g_psudoku9Sprite1->SetHidden(FALSE);
        g_psudoku3Sprite1->SetHidden(FALSE);
        g_psudoku5Sprite1->SetHidden(FALSE);
        g_psudoku6Sprite1->SetHidden(FALSE);
        g_psudoku9Sprite9->SetPosition(225, 226);
        g_psudoku8Sprite9->SetPosition(198, 172);
        g_psudoku7Sprite9->SetPosition(198, 226);
        g_psudoku5Sprite9->SetPosition(225, 226);
        g_psudoku2Sprite9->SetPosition(171, 172);
        g_psudoku1Sprite8->SetPosition(115, 199);
        g_psudoku4Sprite8->SetPosition(88, 199);
        g_psudoku8Sprite8->SetPosition(115, 226);
        g_psudoku9Sprite8->SetPosition(142, 199);
        g_psudoku6Sprite7->SetPosition(33, 172);
        g_psudoku1Sprite6->SetPosition(225, 117);
        g_psudoku3Sprite6->SetPosition(225, 90);
        g_psudoku6Sprite6->SetPosition(225, 144);
        g_psudoku8Sprite5->SetPosition(88, 117);
        g_psudoku6Sprite5->SetPosition(115, 90);
        g_psudoku2Sprite5->SetPosition(115, 144);
        g_psudoku3Sprite5->SetPosition(142, 117);
        g_psudoku8Sprite4->SetPosition(6, 90);
        g_psudoku4Sprite4->SetPosition(6, 117);
        g_psudoku7Sprite4->SetPosition(6, 144);
        g_psudoku6Sprite3->SetPosition(198, 61);
        g_psudoku7Sprite2->SetPosition(115, 7);
        g_psudoku5Sprite2->SetPosition(142, 34);
        g_psudoku9Sprite2->SetPosition(115, 34);
        g_psudoku1Sprite2->SetPosition(88, 34);
        g_psudoku8Sprite1->SetPosition(60, 61);
        g_psudoku9Sprite1->SetPosition(33, 61);
        g_psudoku3Sprite1->SetPosition(33, 7);
        g_psudoku5Sprite1->SetPosition(6, 7);
        g_psudoku6Sprite1->SetPosition(6, 34);
        g_sudoku[8][8]=9;
        g_sudoku[8][7]=5;
        g_sudoku[8][5]=6;
        g_sudoku[8][4]=1;
        g_sudoku[8][3]=3;
        g_sudoku[7][8]=7;
        g_sudoku[7][6]=8;
        g_sudoku[7][2]=6;
        g_sudoku[6][6]=2;
        g_sudoku[5][7]=9;
        g_sudoku[5][4]=3;
        g_sudoku[5][1]=5;
        g_sudoku[4][8]=8;
        g_sudoku[4][7]=1;
        g_sudoku[4][5]=2;
        g_sudoku[4][3]=6;
        g_sudoku[4][1]=9;
        g_sudoku[4][0]=7;
        g_sudoku[3][1]=1;
        g_sudoku[3][4]=8;
        g_sudoku[3][7]=4;
        g_sudoku[2][2]=8;
        g_sudoku[1][0]=3;
        g_sudoku[1][2]=9;
        g_sudoku[1][6]=6;
        g_sudoku[0][5]=7;
        g_sudoku[0][4]=4;
        g_sudoku[0][3]=8;
        g_sudoku[0][1]=6;
        g_sudoku[0][0]=5;
        g_BritainCounter=0;
        g_Timer1=clock();
      }
      g_Counter=1;
      for(int k=0; k<9; k++)
      {
         if(g_sudoku[k][0]==g_sudoku[k][1] || g_sudoku[k][0]==g_sudoku[k][2] || g_sudoku[k][0]==g_sudoku[k][3] || g_sudoku[k][0]==g_sudoku[k][4] || g_sudoku[k][0]==g_sudoku[k][5] || g_sudoku[k][0]==g_sudoku[k][6] || g_sudoku[k][0]==g_sudoku[k][7] || g_sudoku[k][0]==g_sudoku[k][8])
            g_Counter=0;
         else if(g_sudoku[k][1]==g_sudoku[k][2] || g_sudoku[k][1]==g_sudoku[k][3] || g_sudoku[k][1]==g_sudoku[k][4] || g_sudoku[k][1]==g_sudoku[k][5] || g_sudoku[k][1]==g_sudoku[k][6] || g_sudoku[k][1]==g_sudoku[k][7] || g_sudoku[k][1]==g_sudoku[k][8])
            g_Counter=0;
         else if(g_sudoku[k][2]==g_sudoku[k][3] || g_sudoku[k][2]==g_sudoku[k][4] || g_sudoku[k][2]==g_sudoku[k][5] || g_sudoku[k][2]==g_sudoku[k][6] || g_sudoku[k][2]==g_sudoku[k][7] || g_sudoku[k][2]==g_sudoku[k][8])
            g_Counter=0;
         else if(g_sudoku[k][3]==g_sudoku[k][4] || g_sudoku[k][3]==g_sudoku[k][5] || g_sudoku[k][3]==g_sudoku[k][6] || g_sudoku[k][3]==g_sudoku[k][7] || g_sudoku[k][3]==g_sudoku[k][8])
            g_Counter=0;
         else if(g_sudoku[k][4]==g_sudoku[k][5] || g_sudoku[k][4]==g_sudoku[k][6] || g_sudoku[k][4]==g_sudoku[k][7] || g_sudoku[k][4]==g_sudoku[k][8])
            g_Counter=0;
         else if(g_sudoku[k][5]==g_sudoku[k][6] || g_sudoku[k][5]==g_sudoku[k][7] || g_sudoku[k][5]==g_sudoku[k][8])
            g_Counter=0;
         else if(g_sudoku[k][6]==g_sudoku[k][7] || g_sudoku[k][6]==g_sudoku[k][8])
            g_Counter=0;
         else if(g_sudoku[k][7]==g_sudoku[k][8])
            g_Counter=0;
      }
      for(int k=0; k<9; k++)
      {
         if(g_sudoku[0][k]==g_sudoku[1][k] || g_sudoku[0][k]==g_sudoku[2][k] || g_sudoku[0][k]==g_sudoku[3][k] || g_sudoku[0][k]==g_sudoku[4][k] || g_sudoku[0][k]==g_sudoku[5][k] || g_sudoku[0][k]==g_sudoku[6][k] || g_sudoku[0][k]==g_sudoku[7][k] || g_sudoku[0][k]==g_sudoku[8][k])
            g_Counter=0;
         else if(g_sudoku[1][k]==g_sudoku[2][k] || g_sudoku[1][k]==g_sudoku[3][k] || g_sudoku[1][k]==g_sudoku[4][k] || g_sudoku[1][k]==g_sudoku[5][k] || g_sudoku[1][k]==g_sudoku[6][k] || g_sudoku[1][k]==g_sudoku[7][k] || g_sudoku[1][k]==g_sudoku[8][k])
            g_Counter=0;
         else if(g_sudoku[2][k]==g_sudoku[3][k] || g_sudoku[2][k]==g_sudoku[4][k] || g_sudoku[2][k]==g_sudoku[5][k] || g_sudoku[2][k]==g_sudoku[6][k] || g_sudoku[2][k]==g_sudoku[7][k] || g_sudoku[2][k]==g_sudoku[8][k])
            g_Counter=0;
         else if(g_sudoku[3][k]==g_sudoku[4][k] || g_sudoku[3][k]==g_sudoku[5][k] || g_sudoku[3][k]==g_sudoku[6][k] || g_sudoku[3][k]==g_sudoku[7][k] || g_sudoku[3][k]==g_sudoku[8][k])
            g_Counter=0;
         else if(g_sudoku[4][k]==g_sudoku[5][k] || g_sudoku[4][k]==g_sudoku[6][k] || g_sudoku[4][k]==g_sudoku[7][k] || g_sudoku[4][k]==g_sudoku[8][k])
            g_Counter=0;
         else if(g_sudoku[5][k]==g_sudoku[6][k] || g_sudoku[5][k]==g_sudoku[7][k] || g_sudoku[5][k]==g_sudoku[8][k])
            g_Counter=0;
         else if(g_sudoku[6][k]==g_sudoku[7][k] || g_sudoku[6][k]==g_sudoku[8][k])
            g_Counter=0;
         else if(g_sudoku[7][k]==g_sudoku[8][k])
            g_Counter=0;
      }
      for(int k=0; k<9; k+=3)
      {
        if(g_sudoku[0][0+k]==g_sudoku[1][1+k] || g_sudoku[0][0+k]==g_sudoku[1][2+k] || g_sudoku[0][0+k]==g_sudoku[2][1+k] || g_sudoku[0][0+k]==g_sudoku[2][2+k] || g_sudoku[0][1+k]==g_sudoku[1][2+k] || g_sudoku[0][1+k]==g_sudoku[2][2+k] || g_sudoku[1][0+k]==g_sudoku[0][1+k] || g_sudoku[1][0+k]==g_sudoku[0][2+k] || g_sudoku[1][0+k]==g_sudoku[2][1+k] || g_sudoku[1][0+k]==g_sudoku[2][2+k] || g_sudoku[1][1+k]==g_sudoku[0+k][2+k] || g_sudoku[1][1+k]==g_sudoku[2][2+k] ||  g_sudoku[2][0+k]==g_sudoku[0][1+k] ||  g_sudoku[2][0+k]==g_sudoku[0][2+k] ||  g_sudoku[2][0+k]==g_sudoku[1][1+k] ||  g_sudoku[2][0+k]==g_sudoku[1][2+k] ||  g_sudoku[2][1+k]==g_sudoku[0][2+k] ||  g_sudoku[2][1+k]==g_sudoku[1][2+k])
           g_Counter=0;
        if(g_sudoku[0+k][0]==g_sudoku[1+k][1] || g_sudoku[0+k][0]==g_sudoku[1+k][2] || g_sudoku[0+k][0]==g_sudoku[2+k][1] || g_sudoku[0+k][0]==g_sudoku[2+k][2] || g_sudoku[0+k][1]==g_sudoku[1+k][2] || g_sudoku[0+k][1]==g_sudoku[2+k][2] || g_sudoku[1+k][0]==g_sudoku[0+k][1] || g_sudoku[1+k][0]==g_sudoku[0+k][2] || g_sudoku[1+k][0]==g_sudoku[2+k][1] || g_sudoku[1+k][0]==g_sudoku[2+k][2] || g_sudoku[1+k][1]==g_sudoku[0+k][2] || g_sudoku[1+k][1]==g_sudoku[2+k][2] ||  g_sudoku[2+k][0]==g_sudoku[0+k][1] ||  g_sudoku[2+k][0]==g_sudoku[0+k][2] ||  g_sudoku[2+k][0]==g_sudoku[1+k][1] ||  g_sudoku[2+k][0]==g_sudoku[1+k][2] ||  g_sudoku[2+k][1]==g_sudoku[0+k][2] ||  g_sudoku[2+k][1]==g_sudoku[1+k][2])
           g_Counter=0;
        if(g_sudoku[0+k][0+k]==g_sudoku[1+k][1+k] || g_sudoku[0+k][0+k]==g_sudoku[1+k][2+k] || g_sudoku[0+k][0+k]==g_sudoku[2+k][1+k] || g_sudoku[0+k][0+k]==g_sudoku[2+k][2+k] || g_sudoku[0+k][1+k]==g_sudoku[1+k][2+k] || g_sudoku[0+k][1+k]==g_sudoku[2+k][2+k] || g_sudoku[1+k][0+k]==g_sudoku[0+k][1+k] || g_sudoku[1+k][0+k]==g_sudoku[0+k][2+k] || g_sudoku[1+k][0+k]==g_sudoku[2+k][1+k] || g_sudoku[1+k][0+k]==g_sudoku[2+k][2+k] || g_sudoku[1+k][1+k]==g_sudoku[0+k][2+k] || g_sudoku[1+k][1+k]==g_sudoku[2+k][2+k] ||  g_sudoku[2+k][0+k]==g_sudoku[0+k][1+k] ||  g_sudoku[2+k][0+k]==g_sudoku[0+k][2+k] ||  g_sudoku[2+k][0+k]==g_sudoku[1+k][1+k] ||  g_sudoku[2+k][0+k]==g_sudoku[1+k][2+k] ||  g_sudoku[2+k][1+k]==g_sudoku[0+k][2+k] ||  g_sudoku[2+k][1+k]==g_sudoku[1+k][2+k])
           g_Counter=0;
      }
      if(g_sudoku[0+6][0+3]==g_sudoku[1+6][1+3] || g_sudoku[0+6][0+3]==g_sudoku[1+6][2+3] || g_sudoku[0+6][0+3]==g_sudoku[2+6][1+3] || g_sudoku[0+6][0+3]==g_sudoku[2+6][2+3] || g_sudoku[0+6][1+3]==g_sudoku[1+6][2+3] || g_sudoku[0+6][1+3]==g_sudoku[2+6][2+3] || g_sudoku[1+6][0+3]==g_sudoku[0+6][1+3] || g_sudoku[1+6][0+3]==g_sudoku[0+6][2+3] || g_sudoku[1+6][0+3]==g_sudoku[2+6][1+3] || g_sudoku[1+6][0+3]==g_sudoku[2+6][2+3] || g_sudoku[1+6][1+3]==g_sudoku[0+6][2+3] || g_sudoku[1+6][1+3]==g_sudoku[2+6][2+3] ||  g_sudoku[2+6][0+3]==g_sudoku[0+6][1+3] ||  g_sudoku[2+6][0+3]==g_sudoku[0+6][2+3] ||  g_sudoku[2+6][0+3]==g_sudoku[1+6][1+3] ||  g_sudoku[2+6][0+3]==g_sudoku[1+6][2+3] ||  g_sudoku[2+6][1+3]==g_sudoku[0+6][2+3] ||  g_sudoku[2+6][1+3]==g_sudoku[1+6][2+3])
           g_Counter=0;
      if(g_sudoku[0+3][0+6]==g_sudoku[1+3][1+6] || g_sudoku[0+3][0+6]==g_sudoku[1+3][2+6] || g_sudoku[0+3][0+6]==g_sudoku[2+3][1+6] || g_sudoku[0+3][0+6]==g_sudoku[2+3][2+6] || g_sudoku[0+3][1+6]==g_sudoku[1+3][2+6] || g_sudoku[0+3][1+6]==g_sudoku[2+3][2+6] || g_sudoku[1+3][0+6]==g_sudoku[0+3][1+6] || g_sudoku[1+3][0+6]==g_sudoku[0+3][2+6] || g_sudoku[1+3][0+6]==g_sudoku[2+3][1+6] || g_sudoku[1+3][0+6]==g_sudoku[2+3][2+6] || g_sudoku[1+3][1+6]==g_sudoku[0+3][2+6] || g_sudoku[1+3][1+6]==g_sudoku[2+3][2+6] ||  g_sudoku[2+3][0+6]==g_sudoku[0+3][1+6] ||  g_sudoku[2+3][0+6]==g_sudoku[0+3][2+6] ||  g_sudoku[2+3][0+6]==g_sudoku[1+3][1+6] ||  g_sudoku[2+3][0+6]==g_sudoku[1+3][2+6] ||  g_sudoku[2+3][1+6]==g_sudoku[0+3][2+6] ||  g_sudoku[2+3][1+6]==g_sudoku[1+3][2+6])
           g_Counter=0;
      if(g_Counter==1)
      {
         MessageBox(hWindow, TEXT("You won!"), TEXT("CONGRATULATIONS"), MB_OK|MB_DEFBUTTON1|MB_ICONEXCLAMATION);
         g_iLevel=LI_WORLD;
         g_Flag1=0;
         g_AfghanistanWon=TRUE;
      }
      if(clock()-g_Timer1>60000 && g_BritainCounter==0)
      {
         MessageBox(hWindow, TEXT("Give up or can't play sudoku?\n Press 'W' to automatically win."), TEXT("HINT"), MB_OK|MB_DEFBUTTON1|MB_ICONINFORMATION);
         g_BritainCounter=1;
      }
   }
   else if(g_iLevel==LI_CHINA)
   {
      if(g_Flag1==0)
      {
        g_pBombSprite->SetHidden(TRUE);
        g_pPersonSprite->SetHidden(TRUE);
        g_pUsaSprite->SetHidden(TRUE);
        g_pBritainSprite->SetHidden(TRUE);
        g_pUssrSprite->SetHidden(TRUE);
        g_pFranceSprite->SetHidden(TRUE);
        g_pAfghanistanSprite->SetHidden(TRUE);
        g_pChinaSprite->SetHidden(TRUE);
        g_pCongoSprite->SetHidden(TRUE);
        g_pPanamaSprite->SetHidden(TRUE);
        g_pAntarcticaSprite->SetHidden(TRUE);
        g_pAfghanistanWhite->SetHidden(TRUE);
        g_pBritainWhite->SetHidden(TRUE);
        g_pChinaWhite->SetHidden(TRUE);
        g_pCongoWhite->SetHidden(TRUE);
        g_pFranceWhite->SetHidden(TRUE);
        g_pPanamaWhite->SetHidden(TRUE);
        g_pAntarcticaWhite->SetHidden(TRUE);
        g_pUssrWhite->SetHidden(TRUE);
        g_pSilkSprite->SetHidden(FALSE);
        g_pPorcelainSprite->SetHidden(FALSE);
        g_pFireworksSprite->SetHidden(FALSE);
        g_pIndicatorSprite->SetHidden(FALSE);
        g_pIndicatorSprite->SetPosition( 207, 239);
        g_pFireworksSprite->SetPosition(193, 25);
        g_pSilkSprite->SetPosition(193, 96);
        g_pPorcelainSprite->SetPosition(193, 167);
        g_Counter=0;
      }
      RECT rcPorcelain = g_pPorcelainSprite->GetPosition();
      RECT rcSilk = g_pSilkSprite->GetPosition();
      RECT rcFireworks = g_pFireworksSprite->GetPosition();
      RECT rcIndicator = g_pIndicatorSprite->GetPosition();
      if(g_Counter==1)
      {
         MessageBox(hWindow, TEXT("You failed."), TEXT("SORRY"), MB_OK|MB_DEFBUTTON1|MB_ICONERROR);
         g_iLevel=LI_WORLD;
         g_Flag1=0;
      }
      if(g_Counter==2)
      {
         MessageBox(hWindow, TEXT("You won!"), TEXT("CONGRATULATIONS"), MB_OK|MB_DEFBUTTON1|MB_ICONEXCLAMATION);
         g_iLevel=LI_WORLD;
         g_Flag1=0;
         g_ChinaWon=TRUE;   
      }
      if(rcPorcelain.left==6 && rcSilk.left==6 && rcFireworks.left==193 && rcIndicator.left==207)
         g_Counter=1;
      else if(rcPorcelain.left==6 && rcSilk.left==193 && rcFireworks.left==6 && rcIndicator.left==207)
         g_Counter=1;
      else if(rcPorcelain.left==193 && rcSilk.left==6 && rcFireworks.left==193 && rcIndicator.left==20)
         g_Counter=1;
      else if(rcPorcelain.left==193 && rcSilk.left==193 && rcFireworks.left==6 && rcIndicator.left==20)
         g_Counter=1;
      else if(rcPorcelain.left==6 && rcSilk.left==6 && rcFireworks.left==6)
         g_Counter=2;
   }
   else if(g_iLevel==LI_PANAMA)
   {
      if(g_Flag1==0)
      {
        g_pPersonSprite->SetHidden(TRUE);
        g_pUsaSprite->SetHidden(TRUE);
        g_pBritainSprite->SetHidden(TRUE);
        g_pUssrSprite->SetHidden(TRUE);
        g_pFranceSprite->SetHidden(TRUE);
        g_pAfghanistanSprite->SetHidden(TRUE);
        g_pChinaSprite->SetHidden(TRUE);
        g_pCongoSprite->SetHidden(TRUE);
        g_pPanamaSprite->SetHidden(TRUE);
        g_pAntarcticaSprite->SetHidden(TRUE);
        g_pAfghanistanWhite->SetHidden(TRUE);
        g_pBritainWhite->SetHidden(TRUE);
        g_pChinaWhite->SetHidden(TRUE);
        g_pCongoWhite->SetHidden(TRUE);
        g_pFranceWhite->SetHidden(TRUE);
        g_pPanamaWhite->SetHidden(TRUE);
        g_pAntarcticaWhite->SetHidden(TRUE);
        g_pUssrWhite->SetHidden(TRUE);
        g_pBoatOrangeSprite->SetHidden(FALSE);
        g_pBoatOrangeSprite->SetPosition(-63, 100);
        g_pBoatWhiteSprite->SetHidden(FALSE);
        g_pBoatWhiteSprite->SetPosition(-63, 100);
        g_pBoatGreenSprite->SetHidden(FALSE);
        g_pBoatGreenSprite->SetPosition(-63, 100);
        g_pBoatGraySprite->SetHidden(FALSE);
        g_pBoatGraySprite->SetPosition(-63, 100);
        g_pBoatRedSprite->SetHidden(FALSE);
        g_pBoatRedSprite->SetPosition(-63, 100);
        g_pBoatBlueSprite->SetHidden(FALSE);
        g_pBoatBlueSprite->SetPosition(-63, 100);
        g_pCloudSprite->SetHidden(FALSE);
        g_pCloudSprite->SetPosition(0, 0);
        g_Counter=0;
        g_BritainCounter=0;
      }
      RECT rcClouds = g_pCloudSprite->GetPosition();
      RECT rcRed = g_pBoatRedSprite->GetPosition();
      RECT rcBlue = g_pBoatBlueSprite->GetPosition();
      RECT rcGray = g_pBoatGraySprite->GetPosition();
      RECT rcGreen = g_pBoatGreenSprite->GetPosition();
      RECT rcWhite = g_pBoatWhiteSprite->GetPosition();
      RECT rcOrange = g_pBoatOrangeSprite->GetPosition();
      if(g_BritainCounter==-1)
      {
         MessageBox(hWindow, TEXT("You lost."), TEXT("SORRY"), MB_OK|MB_DEFBUTTON1|MB_ICONERROR);
         g_iLevel=LI_WORLD;
         g_Flag1=0;
      }
      if(g_Counter==0)
      {
         rcRed.left+=3;
         rcRed.right+=3;
         g_pBoatRedSprite->SetPosition(rcRed);
         if(rcRed.left>=100)
            g_Counter++;
      }
      else if(g_Counter==1)
      {
         rcWhite.left+=3;
         rcWhite.right+=3;
         g_pBoatWhiteSprite->SetPosition(rcWhite);
         if(rcWhite.left>=100)
            g_Counter++;
      }
      else if(g_Counter==2)
      {
         rcBlue.left+=3;
         rcBlue.right+=3;
         g_pBoatBlueSprite->SetPosition(rcBlue);
         if(rcBlue.left>=100)
            g_Counter++;
      }
      else if(g_Counter==3)
      {
         g_pBoatWhiteSprite->SetPosition(170, 130);
         g_pBoatRedSprite->SetPosition(170, 70);
         rcClouds.left+=5;
         rcClouds.right+=5;
         g_pCloudSprite->SetPosition(rcClouds);
         g_pTextSprite->SetPosition(100, 20);
         g_pTextSprite->SetHidden(FALSE);
         if(rcClouds.left>=180)
            g_Counter++;
      }
      else if(g_Counter==4)
      {
           if(g_BritainCounter>0)
           {
              rcRed.left+=3;
              rcRed.right+=3;
              g_pBoatRedSprite->SetPosition(rcRed);
              if(g_BritainCounter>1)
              {
                 rcWhite.left+=3;
                 rcWhite.right+=3;
                 g_pBoatWhiteSprite->SetPosition(rcWhite);
              }
              if(g_BritainCounter==3)
              {
                 rcBlue.left+=3;
                 rcBlue.right+=3;
                 g_pBoatBlueSprite->SetPosition(rcBlue);
                 if(rcBlue.left>256)
                 {
                    g_Counter++;
                    g_BritainCounter=0;
                    g_pTextSprite->SetHidden(TRUE);
                    g_pBoatOrangeSprite->SetPosition(-63, 100);
                    g_pBoatWhiteSprite->SetPosition(-63, 100);
                    g_pBoatGreenSprite->SetPosition(-63, 100);
                    g_pBoatGraySprite->SetPosition(-63, 100);
                    g_pBoatRedSprite->SetPosition(-63, 100);
                    g_pBoatBlueSprite->SetPosition(-63, 100);
                    g_pCloudSprite->SetPosition(0, 0);
                 }
              }
           }
      }
      else if(g_Counter==5)
      {
         rcWhite.left+=3;
         rcWhite.right+=3;
         g_pBoatWhiteSprite->SetPosition(rcWhite);
         if(rcWhite.left>=100)
            g_Counter++;
      }
      else if(g_Counter==6)
      {
         rcOrange.left+=3;
         rcOrange.right+=3;
         g_pBoatOrangeSprite->SetPosition(rcOrange);
         if(rcOrange.left>=100)
            g_Counter++;
      }
      else if(g_Counter==7)
      {
         rcGray.left+=3;
         rcGray.right+=3;
         g_pBoatGraySprite->SetPosition(rcGray);
         if(rcGray.left>=100)
            g_Counter++;
      }
      else if(g_Counter==8)
      {
         rcRed.left+=3;
         rcRed.right+=3;
         g_pBoatRedSprite->SetPosition(rcRed);
         if(rcRed.left>=100)
            g_Counter++;
      }
      else if(g_Counter==9)
      {
         g_pBoatGraySprite->SetPosition(170, 130);
         g_pBoatOrangeSprite->SetPosition(170, 70);
         g_pBoatRedSprite->SetPosition(102, 130);
         g_pBoatWhiteSprite->SetPosition(102, 70);
         rcClouds.left+=5;
         rcClouds.right+=5;
         g_pCloudSprite->SetPosition(rcClouds);
         g_pTextSprite->SetPosition(100, 20);
         g_pTextSprite->SetHidden(FALSE);
         if(rcClouds.left>=180)
            g_Counter++;
      }
      else if(g_Counter==10)
      {
           if(g_BritainCounter>0)
           {
              rcWhite.left+=3;
              rcWhite.right+=3;
              g_pBoatWhiteSprite->SetPosition(rcWhite);
              if(g_BritainCounter>1)
              {
                 rcOrange.left+=3;
                 rcOrange.right+=3;
                 g_pBoatOrangeSprite->SetPosition(rcOrange);
              }
              if(g_BritainCounter>2)
              {
                 rcGray.left+=3;
                 rcGray.right+=3;
                 g_pBoatGraySprite->SetPosition(rcGray);
              }
              if(g_BritainCounter==4)
              {
                 rcRed.left+=3;
                 rcRed.right+=3;
                 g_pBoatRedSprite->SetPosition(rcRed);
                 if(rcRed.left>256)
                 {
                    g_Counter++;
                    g_BritainCounter=0;
                    g_pTextSprite->SetHidden(TRUE);
                    g_pBoatOrangeSprite->SetPosition(-63, 100);
                    g_pBoatWhiteSprite->SetPosition(-63, 100);
                    g_pBoatGreenSprite->SetPosition(-63, 100);
                    g_pBoatGraySprite->SetPosition(-63, 100);
                    g_pBoatRedSprite->SetPosition(-63, 100);
                    g_pBoatBlueSprite->SetPosition(-63, 100);
                    g_pCloudSprite->SetPosition(0, 0);
                 }
              }
           }
      }
      else if(g_Counter==11)
      {
         rcGreen.left+=3;
         rcGreen.right+=3;
         g_pBoatGreenSprite->SetPosition(rcGreen);
         if(rcGreen.left>=100)
            g_Counter++;
      }
      else if(g_Counter==12)
      {
         rcBlue.left+=3;
         rcBlue.right+=3;
         g_pBoatBlueSprite->SetPosition(rcBlue);
         if(rcBlue.left>=100)
            g_Counter++;
      }
      else if(g_Counter==13)
      {
         rcGray.left+=3;
         rcGray.right+=3;
         g_pBoatGraySprite->SetPosition(rcGray);
         if(rcGray.left>=100)
            g_Counter++;
      }
      else if(g_Counter==14)
      {
         rcRed.left+=3;
         rcRed.right+=3;
         g_pBoatRedSprite->SetPosition(rcRed);
         if(rcRed.left>=100)
            g_Counter++;
      }
      else if(g_Counter==15)
      {
         rcWhite.left+=3;
         rcWhite.right+=3;
         g_pBoatWhiteSprite->SetPosition(rcWhite);
         if(rcWhite.left>=100)
            g_Counter++;
      }
      else if(g_Counter==16)
      {
         rcOrange.left+=3;
         rcOrange.right+=3;
         g_pBoatOrangeSprite->SetPosition(rcOrange);
         if(rcOrange.left>=100)
            g_Counter++;
      }
      else if(g_Counter==17)
      {
         g_pBoatRedSprite->SetPosition(190, 130);
         g_pBoatGraySprite->SetPosition(190, 70);
         g_pBoatGreenSprite->SetPosition(122, 130);
         g_pBoatBlueSprite->SetPosition(122, 70);
         g_pBoatOrangeSprite->SetPosition(54, 130);
         g_pBoatWhiteSprite->SetPosition(54, 70);
         rcClouds.left+=5;
         rcClouds.right+=5;
         g_pCloudSprite->SetPosition(rcClouds);
         g_pTextSprite->SetPosition(100, 20);
         g_pTextSprite->SetHidden(FALSE);
         if(rcClouds.left>=180)
            g_Counter++;
      }
      else if(g_Counter==18)
      {
           if(g_BritainCounter>0)
           {
              rcGreen.left+=3;
              rcGreen.right+=3;
              g_pBoatGreenSprite->SetPosition(rcGreen);
              if(g_BritainCounter>1)
              {
                 rcBlue.left+=3;
                 rcBlue.right+=3;
                 g_pBoatBlueSprite->SetPosition(rcBlue);
              }
              if(g_BritainCounter>2)
              {
                 rcGray.left+=3;
                 rcGray.right+=3;
                 g_pBoatGraySprite->SetPosition(rcGray);
              }
              if(g_BritainCounter>3)
              {
                 rcRed.left+=3;
                 rcRed.right+=3;
                 g_pBoatRedSprite->SetPosition(rcRed);
              }
              if(g_BritainCounter>4)
              {
                 rcWhite.left+=3;
                 rcWhite.right+=3;
                 g_pBoatWhiteSprite->SetPosition(rcWhite);
              }
              if(g_BritainCounter==6)
              {
                 rcOrange.left+=3;
                 rcOrange.right+=3;
                 g_pBoatOrangeSprite->SetPosition(rcOrange);
              }
                 if(rcOrange.left>256)
                 {
                    g_Counter++;
                 }
              
           }
      }
      else if(g_Counter==19)
      {
         MessageBox(hWindow, TEXT("You won!"), TEXT("CONGRATULATIONS"), MB_OK|MB_DEFBUTTON1|MB_ICONEXCLAMATION);
         g_iLevel=LI_WORLD;
         g_PanamaWon=TRUE;
         g_Flag1=0;
      }
   }
   else if(g_iLevel==LI_CONGO)
   {
   
   }
   else if(g_iLevel==LI_ANTARCTICA)
   {
      if(g_Flag1==0)
      {
        g_pPersonSprite->SetHidden(TRUE);
        g_pUsaSprite->SetHidden(TRUE);
        g_pBritainSprite->SetHidden(TRUE);
        g_pUssrSprite->SetHidden(TRUE);
        g_pFranceSprite->SetHidden(TRUE);
        g_pAfghanistanSprite->SetHidden(TRUE);
        g_pChinaSprite->SetHidden(TRUE);
        g_pCongoSprite->SetHidden(TRUE);
        g_pPanamaSprite->SetHidden(TRUE);
        g_pAntarcticaSprite->SetHidden(TRUE);
        g_pAfghanistanWhite->SetHidden(TRUE);
        g_pBritainWhite->SetHidden(TRUE);
        g_pChinaWhite->SetHidden(TRUE);
        g_pCongoWhite->SetHidden(TRUE);
        g_pFranceWhite->SetHidden(TRUE);
        g_pPanamaWhite->SetHidden(TRUE);
        g_pAntarcticaWhite->SetHidden(TRUE);
        g_pUssrWhite->SetHidden(TRUE);
        g_pPokePlayerSprite->SetPosition(-158, 75);
        g_pPokePlayerSprite->SetHidden(FALSE);
        g_pPokeOpponentSprite->SetPosition(378, 30);
        g_pPokeOpponentSprite->SetHidden(FALSE);
        g_pPokeBellSprite->SetCurFrame(0);
        g_pPokeBeamSprite->SetCurFrame(0);
        g_pPokeSpiritSprite->SetCurFrame(0);
        g_pOpponentHealthSprite->SetCurFrame(0);
        g_PokeFlag1=0;
        g_PokeFlag2=0;
        g_PokeFlag3=0;
      }
      if(g_PokeFlag1==-1)
      {
         MessageBox(hWindow, TEXT("You lost."), TEXT("SORRY"), MB_OK|MB_DEFBUTTON1|MB_ICONERROR);
         g_iLevel=LI_WORLD;
         g_Flag1=0;
      }
      if(g_PokeFlag1==0)
      {
         RECT rcPlayer = g_pPokePlayerSprite->GetPosition();
         RECT rcOpponent = g_pPokeOpponentSprite->GetPosition();
         rcPlayer.left+=8;
         rcPlayer.right+=8;
         rcOpponent.left-=12;
         rcOpponent.right-=12;
         g_pPokePlayerSprite->SetPosition(rcPlayer);
         g_pPokeOpponentSprite->SetPosition(rcOpponent);
         if(rcPlayer.left>=0)
            g_PokeFlag1++;
      }
      if(g_PokeFlag1==1)
      {
         g_pPokeTextStartSprite->SetHidden(FALSE);
         g_pPokeTextStartSprite->SetPosition(14, 183);
         g_pPokeIndicatorSprite->SetHidden(FALSE);
         g_pPokeIndicatorSprite->SetPosition(168, 188);
         g_pPokeIndicatorSprite->SetCurFrame(0);
         g_PokeFlag1++;
      }
      if(g_PokeFlag1==2)
      {
        if(g_pPokeIndicatorSprite->GetCurFrame()==0)
           g_pPokeIndicatorSprite->SetCurFrame(1);
        else if(g_pPokeIndicatorSprite->GetCurFrame()==1)
           g_pPokeIndicatorSprite->SetCurFrame(2);
        else if(g_pPokeIndicatorSprite->GetCurFrame()==2)
           g_pPokeIndicatorSprite->SetCurFrame(3);
        else if(g_pPokeIndicatorSprite->GetCurFrame()==3)
           g_pPokeIndicatorSprite->SetCurFrame(4);
        else if(g_pPokeIndicatorSprite->GetCurFrame()==4)
           g_pPokeIndicatorSprite->SetCurFrame(5);
        else if(g_pPokeIndicatorSprite->GetCurFrame()==5)
           g_pPokeIndicatorSprite->SetCurFrame(0);
      }
      if(g_PokeFlag1==3)
      {
         g_pPokeIndicatorSprite->SetHidden(TRUE);
         g_pPokeTextStartSprite->SetHidden(TRUE);
         g_pPokeMenuIndicatorSprite->SetHidden(FALSE);
         g_pPokeMenuIndicatorSprite->SetPosition(130, 192);
         g_pPokeMenuIndicatorSprite->SetCurFrame(0);
         g_pPlayerHealthSprite->SetHidden(FALSE);
         g_pOpponentHealthSprite->SetHidden(FALSE);
         g_pPokeMenuSprite->SetHidden(FALSE);
         g_pPokeTextMenu1Sprite->SetHidden(FALSE);
         g_pOpponentHealthSprite->SetPosition(19, 7);
         g_pPlayerHealthSprite->SetPosition(128, 121);
         g_pPokeTextMenu1Sprite->SetPosition(14, 183);
         g_pPokeMenuSprite->SetPosition(120, 173);
         g_PokeFlag1++;
      }
      if(g_PokeFlag1==4)
      {
        if(g_pPokeMenuIndicatorSprite->GetCurFrame()==0)
           g_pPokeMenuIndicatorSprite->SetCurFrame(1);
        else if(g_pPokeMenuIndicatorSprite->GetCurFrame()==1)
           g_pPokeMenuIndicatorSprite->SetCurFrame(2);
        else if(g_pPokeMenuIndicatorSprite->GetCurFrame()==2)
           g_pPokeMenuIndicatorSprite->SetCurFrame(3);
        else if(g_pPokeMenuIndicatorSprite->GetCurFrame()==3)
           g_pPokeMenuIndicatorSprite->SetCurFrame(0);
      }
      if(g_PokeFlag1==5)
      {
         g_pPokeTextMenu1Sprite->SetHidden(TRUE);;
         g_pPokeMenuSprite->SetHidden(TRUE);
         g_pPokeBattleMenuSprite->SetHidden(FALSE);
         g_pPokeBattleMenuSprite->SetPosition(0, 173);
         g_pPokeMenuIndicatorSprite->SetPosition(9, 194);
         g_PokeFlag1++;
      }
      if(g_PokeFlag1==6)
      {
         if(g_pPokeMenuIndicatorSprite->GetCurFrame()==0)
           g_pPokeMenuIndicatorSprite->SetCurFrame(1);
        else if(g_pPokeMenuIndicatorSprite->GetCurFrame()==1)
           g_pPokeMenuIndicatorSprite->SetCurFrame(2);
        else if(g_pPokeMenuIndicatorSprite->GetCurFrame()==2)
           g_pPokeMenuIndicatorSprite->SetCurFrame(3);
        else if(g_pPokeMenuIndicatorSprite->GetCurFrame()==3)
           g_pPokeMenuIndicatorSprite->SetCurFrame(0);
      }
      if(g_PokeFlag1==7)
      {
         g_pPokeMenuIndicatorSprite->SetHidden(TRUE);
         g_pPokeBattleMenuSprite->SetHidden(TRUE);
         g_pPokeBellSprite->SetHidden(FALSE);
         g_pPokeBellSprite->SetPosition(122, 62);
         g_pPokeBellText1Sprite->SetHidden(FALSE);
         g_pPokeBellText1Sprite->SetPosition(14, 183);
         g_PokeFlag1++;
      }
      if(g_PokeFlag1==8)
      {
         if(g_pPokeBellSprite->GetCurFrame()==0 && g_PokeFlag2==0)
           g_pPokeBellSprite->SetCurFrame(1);
        else if(g_pPokeBellSprite->GetCurFrame()==1 && g_PokeFlag2==0)
           g_pPokeBellSprite->SetCurFrame(2);
        else if(g_pPokeBellSprite->GetCurFrame()==2 && g_PokeFlag2==0)
           g_pPokeBellSprite->SetCurFrame(3);
        else if(g_pPokeBellSprite->GetCurFrame()==3 && g_PokeFlag2==0)
           g_pPokeBellSprite->SetCurFrame(4);
        else if(g_pPokeBellSprite->GetCurFrame()==4 && g_PokeFlag2==0)
        {
           g_PokeFlag2=1;
           g_pPokeBellSprite->SetCurFrame(3);
        }
        else if(g_pPokeBellSprite->GetCurFrame()==3 && g_PokeFlag2==1)
           g_pPokeBellSprite->SetCurFrame(2);
        else if(g_pPokeBellSprite->GetCurFrame()==2 && g_PokeFlag2==1)
           g_pPokeBellSprite->SetCurFrame(1);
        else if(g_pPokeBellSprite->GetCurFrame()==1 && g_PokeFlag2==1)
           g_pPokeBellSprite->SetCurFrame(0);
        else if(g_pPokeBellSprite->GetCurFrame()==0 && g_PokeFlag2==1)
        {
           g_pPokeBellSprite->SetCurFrame(1);
           g_PokeFlag2++;
        }
        if(g_pPokeBellSprite->GetCurFrame()==1 && g_PokeFlag2==2)
           g_pPokeBellSprite->SetCurFrame(2);
        else if(g_pPokeBellSprite->GetCurFrame()==2 && g_PokeFlag2==2)
           g_pPokeBellSprite->SetCurFrame(3);
        else if(g_pPokeBellSprite->GetCurFrame()==3 && g_PokeFlag2==2)
           g_pPokeBellSprite->SetCurFrame(4);
        else if(g_pPokeBellSprite->GetCurFrame()==4 && g_PokeFlag2==2)
        {
           g_pPokeBellSprite->SetCurFrame(3);
           g_PokeFlag2++;
        }
        else if(g_pPokeBellSprite->GetCurFrame()==3 && g_PokeFlag2==3)
           g_pPokeBellSprite->SetCurFrame(2);
        else if(g_pPokeBellSprite->GetCurFrame()==2 && g_PokeFlag2==3)
           g_pPokeBellSprite->SetCurFrame(1);
        else if(g_pPokeBellSprite->GetCurFrame()==1 && g_PokeFlag2==3)
           g_pPokeBellSprite->SetCurFrame(0);
        else if(g_pPokeBellSprite->GetCurFrame()==0 && g_PokeFlag2==3)
        {
           g_pPokeBellSprite->SetHidden(TRUE);
           g_PokeFlag2=0;
           g_PokeFlag1++;
        }
      }
      if(g_PokeFlag1==9)
      {
         g_pPokeBellText1Sprite->SetHidden(TRUE);
         g_pPokeBellTextSprite->SetPosition(14, 183);
         g_pPokeBellTextSprite->SetHidden(FALSE);
         g_pPokeIndicatorSprite->SetHidden(FALSE);
         g_pPokeIndicatorSprite->SetPosition(168, 188);
         g_pPokeIndicatorSprite->SetCurFrame(0);
         g_PokeFlag1++;
      }
      if(g_PokeFlag1==10)
      {
         if(g_pPokeIndicatorSprite->GetCurFrame()==0)
           g_pPokeIndicatorSprite->SetCurFrame(1);
        else if(g_pPokeIndicatorSprite->GetCurFrame()==1)
           g_pPokeIndicatorSprite->SetCurFrame(2);
        else if(g_pPokeIndicatorSprite->GetCurFrame()==2)
           g_pPokeIndicatorSprite->SetCurFrame(3);
        else if(g_pPokeIndicatorSprite->GetCurFrame()==3)
           g_pPokeIndicatorSprite->SetCurFrame(4);
        else if(g_pPokeIndicatorSprite->GetCurFrame()==4)
           g_pPokeIndicatorSprite->SetCurFrame(5);
        else if(g_pPokeIndicatorSprite->GetCurFrame()==5)
           g_pPokeIndicatorSprite->SetCurFrame(0);
      }
      if(g_PokeFlag1==11)
      {
         g_pPokeOpponentTurnSprite->SetHidden(FALSE);
         g_pPokeOpponentTurnSprite->SetPosition(14, 183);
         g_pPokeIndicatorSprite->SetHidden(FALSE);
         g_pPokeIndicatorSprite->SetPosition(166, 211);
         g_pPokeIndicatorSprite->SetCurFrame(0);
         g_PokeFlag1=12;
      }
      if(g_PokeFlag1==12)
      {
         if(g_pPokeIndicatorSprite->GetCurFrame()==0)
           g_pPokeIndicatorSprite->SetCurFrame(1);
        else if(g_pPokeIndicatorSprite->GetCurFrame()==1)
           g_pPokeIndicatorSprite->SetCurFrame(2);
        else if(g_pPokeIndicatorSprite->GetCurFrame()==2)
           g_pPokeIndicatorSprite->SetCurFrame(3);
        else if(g_pPokeIndicatorSprite->GetCurFrame()==3)
           g_pPokeIndicatorSprite->SetCurFrame(4);
        else if(g_pPokeIndicatorSprite->GetCurFrame()==4)
           g_pPokeIndicatorSprite->SetCurFrame(5);
        else if(g_pPokeIndicatorSprite->GetCurFrame()==5)
           g_pPokeIndicatorSprite->SetCurFrame(0);
      }
      if(g_PokeFlag1==13)
      {
         g_pPokeMenuIndicatorSprite->SetHidden(TRUE);
         g_pPokeBattleMenuSprite->SetHidden(TRUE);
         g_pPokeBeamSprite->SetHidden(FALSE);
         g_pPokeBeamSprite->SetPosition(120, 30);
         g_pPokeBeamSprite->SetCurFrame(0);
         g_pPokeBeamText1Sprite->SetHidden(FALSE);
         g_pPokeBeamText1Sprite->SetPosition(14, 183);
         g_Timer1=clock();
         g_PokeFlag1++;
      }
      if(g_PokeFlag1==14)
      {
         if(g_pPokeBeamSprite->GetCurFrame()==0 && clock()-g_Timer1>200)
           g_pPokeBeamSprite->SetCurFrame(1);
        else if(g_pPokeBeamSprite->GetCurFrame()==1 && clock()-g_Timer1>400)
           g_pPokeBeamSprite->SetCurFrame(2);
        else if(g_pPokeBeamSprite->GetCurFrame()==2 && clock()-g_Timer1>600)
           g_pPokeBeamSprite->SetCurFrame(3);
        else if(g_pPokeBeamSprite->GetCurFrame()==3 && clock()-g_Timer1>800)
           g_pPokeBeamSprite->SetCurFrame(4);
        else if(g_pPokeBeamSprite->GetCurFrame()==4 && clock()-g_Timer1>1200)
        {
           g_pPokeBeamSprite->SetHidden(TRUE);
           g_PokeFlag1++;
        }
      }
      if(g_PokeFlag1==15)
      {
         g_pPokeBeamText1Sprite->SetHidden(TRUE);
         g_pPokeBeamTextSprite->SetPosition(14, 183);
         g_pPokeBeamTextSprite->SetHidden(FALSE);
         g_pPokeIndicatorSprite->SetHidden(FALSE);
         g_pPokeIndicatorSprite->SetPosition(206, 193);
         g_pPokeIndicatorSprite->SetCurFrame(0);
         g_PokeFlag1++;
      }
      if(g_PokeFlag1==16)
      {
         if(g_pPokeIndicatorSprite->GetCurFrame()==0)
           g_pPokeIndicatorSprite->SetCurFrame(1);
         else if(g_pPokeIndicatorSprite->GetCurFrame()==1)
           g_pPokeIndicatorSprite->SetCurFrame(2);
         else if(g_pPokeIndicatorSprite->GetCurFrame()==2)
           g_pPokeIndicatorSprite->SetCurFrame(3);
         else if(g_pPokeIndicatorSprite->GetCurFrame()==3)
           g_pPokeIndicatorSprite->SetCurFrame(4);
         else if(g_pPokeIndicatorSprite->GetCurFrame()==4)
           g_pPokeIndicatorSprite->SetCurFrame(5);
         else if(g_pPokeIndicatorSprite->GetCurFrame()==5)
           g_pPokeIndicatorSprite->SetCurFrame(0);
      }
      if(g_PokeFlag1==17)
      {
         g_pPokeMenuIndicatorSprite->SetHidden(TRUE);
         g_pPokeBattleMenuSprite->SetHidden(TRUE);
         g_pPokeSpiritTextSprite->SetHidden(FALSE);
         g_pPokeSpiritTextSprite->SetPosition(14, 183);
         g_Timer1=clock();
         g_PokeFlag1++;
      }
      if(g_PokeFlag1==18)
      {
         if(clock()-g_Timer1>1000)
         {
            g_pPokeSpiritTextSprite->SetHidden(TRUE);  
            g_PokeFlag3++;
            g_PokeFlag1++;
         }
      }
      if(g_PokeFlag1==19)
      {
         g_pPokeOpponentTurnSprite->SetHidden(FALSE);
         g_pPokeOpponentTurnSprite->SetPosition(14, 183);
         g_pPokeIndicatorSprite->SetHidden(FALSE);
         g_pPokeIndicatorSprite->SetPosition(166, 211);
         g_pPokeIndicatorSprite->SetCurFrame(0);
         g_PokeFlag1++;
      }
      if(g_PokeFlag1==20)
      {
         if(g_pPokeIndicatorSprite->GetCurFrame()==0)
           g_pPokeIndicatorSprite->SetCurFrame(1);
        else if(g_pPokeIndicatorSprite->GetCurFrame()==1)
           g_pPokeIndicatorSprite->SetCurFrame(2);
        else if(g_pPokeIndicatorSprite->GetCurFrame()==2)
           g_pPokeIndicatorSprite->SetCurFrame(3);
        else if(g_pPokeIndicatorSprite->GetCurFrame()==3)
           g_pPokeIndicatorSprite->SetCurFrame(4);
        else if(g_pPokeIndicatorSprite->GetCurFrame()==4)
           g_pPokeIndicatorSprite->SetCurFrame(5);
        else if(g_pPokeIndicatorSprite->GetCurFrame()==5)
           g_pPokeIndicatorSprite->SetCurFrame(0);
      }
      if(g_PokeFlag1==21)
      {
         g_pPokeSpiritText1Sprite->SetHidden(FALSE);
         g_pPokeSpiritText1Sprite->SetPosition(14, 183);
         g_pPokeSpiritSprite->SetHidden(FALSE);
         g_pPokeSpiritSprite->SetPosition(100, 72);
         g_pPokeSpiritSprite->SetCurFrame(0);
         g_PokeFlag1++;
         g_Timer1=clock();
      }
      if(g_PokeFlag1==22)
      {
         RECT rcSpirit = g_pPokeSpiritSprite->GetPosition();
         if(clock()-g_Timer1>300)
         {
            rcSpirit.left+=6;
            rcSpirit.top-=4;
            g_pPokeSpiritSprite->SetPosition(rcSpirit);
         }
         if(rcSpirit.left==184 && rcSpirit.top==16)
            g_PokeFlag1++;
      }
      if(g_PokeFlag1==23)
      {
         if(g_pPokeSpiritSprite->GetCurFrame()==0)
            g_pPokeSpiritSprite->SetCurFrame(1);
         else if(g_pPokeSpiritSprite->GetCurFrame()==1)
            g_pPokeSpiritSprite->SetCurFrame(2);
         else if(g_pPokeSpiritSprite->GetCurFrame()==2)
            g_pPokeSpiritSprite->SetCurFrame(3);
         else if(g_pPokeSpiritSprite->GetCurFrame()==3)
            g_PokeFlag1++;
      }
      else if(g_PokeFlag1==24)
      {
         g_pPokeSpiritSprite->SetHidden(TRUE);
         g_pPokeSpiritText1Sprite->SetHidden(TRUE);
         g_pPokeSpiritText2Sprite->SetHidden(FALSE);
         g_pPokeSpiritText2Sprite->SetPosition(14, 183);
         g_Timer1=clock();
         g_PokeFlag1++;
      }
      if(g_PokeFlag1==25)
      {
        if(g_pOpponentHealthSprite->GetCurFrame()==0)
            g_pOpponentHealthSprite->SetCurFrame(1);
         else if(g_pOpponentHealthSprite->GetCurFrame()==1 && clock()-g_Timer1>100)
            g_pOpponentHealthSprite->SetCurFrame(2);
         else if(g_pOpponentHealthSprite->GetCurFrame()==2 && clock()-g_Timer1>200)
            g_pOpponentHealthSprite->SetCurFrame(3);
         else if(g_pOpponentHealthSprite->GetCurFrame()==3 && clock()-g_Timer1>300)
            g_pOpponentHealthSprite->SetCurFrame(4);
         else if(g_pOpponentHealthSprite->GetCurFrame()==4 && clock()-g_Timer1>400)
            g_pOpponentHealthSprite->SetCurFrame(5);
         else if(g_pOpponentHealthSprite->GetCurFrame()==5 && clock()-g_Timer1>500)
            g_pOpponentHealthSprite->SetCurFrame(6);
         else if(g_pOpponentHealthSprite->GetCurFrame()==6 && clock()-g_Timer1>600)
            g_PokeFlag1++;
      }
      else if (g_PokeFlag1==26)
      {
           MessageBox(hWindow, TEXT("You won!"), TEXT("CONGRATULATIONS"), MB_OK|MB_DEFBUTTON1|MB_ICONEXCLAMATION);
           g_Flag1=0;
           g_iLevel=LI_WORLD;
           g_AntarcticaWon=TRUE;
      }
   }

  // Obtain a device context for repainting the game
  HDC   hDC = GetDC(hWindow);

  // Paint the game to the offscreen device context
  GamePaint(g_hOffscreenDC);

  // Blit the offscreen bitmap to the game screen
  BitBlt(hDC, 0, 0, g_pGame->GetWidth(), g_pGame->GetHeight(),
    g_hOffscreenDC, 0, 0, SRCCOPY);
    
  
   //Give instructions
   if(g_iLevel==LI_WORLD && g_Flag1==0 && g_Flag2==0)
   {
      MessageBox(hWindow, TEXT("Prove that your flag is the best!\nArrows to move. Space to select.\nPress 'Q' to quit any level."), TEXT("HINT"), MB_OK|MB_DEFBUTTON1|MB_ICONINFORMATION);
      g_Flag1=1;
      g_Flag2=1;
   }
   else if(g_iLevel==LI_USSR && g_Flag1==0)
   {
      MessageBox(hWindow, TEXT("It's an arms race!\nArrows to move."), TEXT("HINT"), MB_OK|MB_DEFBUTTON1|MB_ICONINFORMATION);
   }
   else if(g_iLevel==LI_BRITAIN && g_Flag1==0)
   {
      MessageBox(hWindow, TEXT("Fight for the revolution!\nUse arrows and space."), TEXT("HINT"), MB_OK|MB_DEFBUTTON1|MB_ICONINFORMATION);
   }
   else if(g_iLevel==LI_AFGHANISTAN && g_Flag1==0)
   {
      MessageBox(hWindow, TEXT("Spread your culture!\nPoint and click. Use numpad."), TEXT("HINT"), MB_OK|MB_DEFBUTTON1|MB_ICONINFORMATION);
   }
   else if(g_iLevel==LI_CHINA && g_Flag1==0)
   {
      MessageBox(hWindow, TEXT("Get by trade limitations!\nPoint and click."), TEXT("HINT"), MB_OK|MB_DEFBUTTON1|MB_ICONINFORMATION);
   }
   else if(g_iLevel==LI_PANAMA && g_Flag1==0)
   {
      MessageBox(hWindow, TEXT("Control the canal!\nPoint and click."), TEXT("HINT"), MB_OK|MB_DEFBUTTON1|MB_ICONINFORMATION);
   }
   else if(g_iLevel==LI_CONGO && g_Flag1==0)
   {
      MessageBox(hWindow, TEXT("Defeat the slave trade!"), TEXT("HINT"), MB_OK|MB_DEFBUTTON1|MB_ICONINFORMATION);
      g_Timer1=clock();
      while((clock()-g_Timer1)<500)
      {
      }
      MessageBox(hWindow, TEXT("You did it!\n"), TEXT("CONGRATULATIONS"), MB_OK|MB_DEFBUTTON1|MB_ICONEXCLAMATION);
      g_iLevel=LI_WORLD;
      g_Flag1=0;
      g_CongoWon=TRUE;
   }
   else if(g_iLevel==LI_FRANCE && g_Flag1==0)
   {
      MessageBox(hWindow, TEXT("Defeat France!\n"), TEXT("HINT"), MB_OK|MB_DEFBUTTON1|MB_ICONINFORMATION);
      g_Timer1=clock();
      while((clock()-g_Timer1)<500)
      {
      }
      MessageBox(hWindow, TEXT("France surrenders!\n"), TEXT("CONGRATULATIONS"), MB_OK|MB_DEFBUTTON1|MB_ICONEXCLAMATION);
      g_iLevel=LI_WORLD;
      g_Flag1=0;
      g_FranceWon=TRUE;
   }
   else if(g_iLevel==LI_ANTARCTICA && g_Flag1==0)
   {
      Bitmap* Blank = new Bitmap(hDC, 256, 256, RGB(0, 0, 0));
      Bitmap* Flash = new Bitmap(hDC, 256, 256, RGB(255, 255, 255));
      g_Counter=clock();
      while((clock()-g_Counter)<800)
      {
         g_Timer1=clock();
         while((clock()-g_Timer1)<100)
         {
         }
         Blank->Draw(hDC, 0, 0, FALSE, (COLORREF)0);
         g_Timer1=clock();
         while((clock()-g_Timer1)<100)
         {
         }
         Flash->Draw(hDC, 0, 0, FALSE, (COLORREF)0);
      }
      delete Blank;
      delete Flash;
      g_BritainCounter=0;
   }

  // Cleanup
  if(g_iLevel!=LI_WORLD)
     g_Flag1=1;
  ReleaseDC(hWindow, hDC);
}

void HandleKeys()
{
   if (GetAsyncKeyState(0x51) < 0 && g_iLevel!=LI_START && g_iLevel!=LI_WON)
   {
      g_iLevel=LI_WORLD;
      g_Flag1=0;
   }
   else if (GetAsyncKeyState(0x57) < 0 && g_iLevel!=LI_START && g_iLevel!=LI_WON)
   {
      if(g_iLevel==LI_BRITAIN)
         g_BritainWon=TRUE;
      else if(g_iLevel==LI_CONGO)
         g_CongoWon=TRUE;
      else if(g_iLevel==LI_AFGHANISTAN)
         g_AfghanistanWon=TRUE;
      else if(g_iLevel==LI_ANTARCTICA)
         g_AntarcticaWon=TRUE;
      else if(g_iLevel==LI_USSR)
         g_UssrWon=TRUE;
      else if(g_iLevel==LI_PANAMA)
         g_PanamaWon=TRUE;
      else if(g_iLevel==LI_CHINA)
         g_ChinaWon=TRUE;
      else if(g_iLevel==LI_FRANCE)
         g_FranceWon=TRUE;
      g_iLevel=LI_WORLD;
      g_Flag1=0;
   }   
   else if(g_iLevel==LI_START)
   {
      if(GetAsyncKeyState(VK_SPACE) < 0 && g_pGameStartSprite->GetCurFrame()==1)
      {
         g_Flag1=0;
         g_iLevel=LI_WORLD;
      }
   }
   else if(g_iLevel==LI_WORLD)
   {
     // Move the landscape/cloud layers based upon arrow key presses
     if (g_iInputDelay++ > 1)
     {
        if (GetAsyncKeyState(VK_LEFT) < 0)
        {
           // Make the person walk
           g_pPersonSprite->Walk(1, 0);

           // Move the landscape layer to the right
           g_pBGLandscapeLayer->SetSpeed(16);
           g_pBGLandscapeLayer->SetDirection(SD_RIGHT);
           g_pBGLandscapeLayer->Update();
           g_pBGLandscapeLayer->SetSpeed(0);

           // Move the cloud layer to the right
           //g_pFGCloudsLayer->SetSpeed(4);
           //g_pFGCloudsLayer->SetDirection(SD_RIGHT);
           //g_pFGCloudsLayer->Update();
           //g_pFGCloudsLayer->SetSpeed(0);
        }
        else if (GetAsyncKeyState(VK_RIGHT) < 0)
        {
           // Make the person walk
           g_pPersonSprite->Walk(2, 0);

           // Move the landscape layer to the left
           g_pBGLandscapeLayer->SetSpeed(16);
           g_pBGLandscapeLayer->SetDirection(SD_LEFT);
           g_pBGLandscapeLayer->Update();
           g_pBGLandscapeLayer->SetSpeed(0);
      
           // Move the cloud layer to the left
           //g_pFGCloudsLayer->SetSpeed(4);
           //g_pFGCloudsLayer->SetDirection(SD_LEFT);
           //g_pFGCloudsLayer->Update();
           //g_pFGCloudsLayer->SetSpeed(0);
        }
        else if (GetAsyncKeyState(VK_UP) < 0)
        {
           // Make the person walk
           g_pPersonSprite->Walk(3, 0);

           // Move the landscape layer down
           g_pBGLandscapeLayer->SetSpeed(16);
           g_pBGLandscapeLayer->SetDirection(SD_DOWN);
           g_pBGLandscapeLayer->Update();
           g_pBGLandscapeLayer->SetSpeed(0);

           // Move the cloud layer down
           //g_pFGCloudsLayer->SetSpeed(4);
           //g_pFGCloudsLayer->SetDirection(SD_DOWN);
           //g_pFGCloudsLayer->Update();
           //g_pFGCloudsLayer->SetSpeed(0);
        }
        else if (GetAsyncKeyState(VK_DOWN) < 0)
        {
           // Make the person walk
           g_pPersonSprite->Walk(4, 0);

           // Move the landscape layer up
           g_pBGLandscapeLayer->SetSpeed(16);
           g_pBGLandscapeLayer->SetDirection(SD_UP);
           g_pBGLandscapeLayer->Update();
           g_pBGLandscapeLayer->SetSpeed(0);

           // Move the cloud layer up
           //g_pFGCloudsLayer->SetSpeed(4);
           //g_pFGCloudsLayer->SetDirection(SD_UP);
           //g_pFGCloudsLayer->Update();
           //g_pFGCloudsLayer->SetSpeed(0);
        }
        else if(GetAsyncKeyState(VK_SPACE) <0)
        {
          RECT& rcPosition = g_pPersonSprite->GetPosition();
          RECT& rcTest = g_pUssrSprite->GetPosition();
          if(g_UssrWon==FALSE)
          if(rcPosition.left<=rcTest.right && rcTest.left<=rcPosition.right && rcPosition.top<=rcTest.bottom && rcTest.top<=rcPosition.bottom)
          {   
                g_iLevel=LI_USSR;
                g_Flag1=0;
          }
          rcTest = g_pChinaSprite->GetPosition();
          if(g_ChinaWon==FALSE)
          if(rcPosition.left<=rcTest.right && rcTest.left<=rcPosition.right && rcPosition.top<=rcTest.bottom && rcTest.top<=rcPosition.bottom)
          {   
                g_iLevel=LI_CHINA;
                g_Flag1=0;
          }
          rcTest = g_pBritainSprite->GetPosition();
          if(g_BritainWon==FALSE)
          if(rcPosition.left<=rcTest.right && rcTest.left<=rcPosition.right && rcPosition.top<=rcTest.bottom && rcTest.top<=rcPosition.bottom)
          {   
                g_iLevel=LI_BRITAIN;
                g_Flag1=0;
          }
          rcTest = g_pAfghanistanSprite->GetPosition();
          if(g_AfghanistanWon==FALSE)
          if(rcPosition.left<=rcTest.right && rcTest.left<=rcPosition.right && rcPosition.top<=rcTest.bottom && rcTest.top<=rcPosition.bottom)
          {   
                g_iLevel=LI_AFGHANISTAN;
                g_Flag1=0;
          }
          rcTest = g_pFranceSprite->GetPosition();
          if(g_FranceWon==FALSE)
          if(rcPosition.left<=rcTest.right && rcTest.left<=rcPosition.right && rcPosition.top<=rcTest.bottom && rcTest.top<=rcPosition.bottom)
          {   
                g_iLevel=LI_FRANCE;
                g_Flag1=0;
          }
          rcTest = g_pCongoSprite->GetPosition();
          if(g_CongoWon==FALSE)
          if(rcPosition.left<=rcTest.right && rcTest.left<=rcPosition.right && rcPosition.top<=rcTest.bottom && rcTest.top<=rcPosition.bottom)
          {   
                //g_iLevel=LI_CONGO;
                //g_Flag1=0;
          }
          rcTest = g_pPanamaSprite->GetPosition();
          if(g_PanamaWon==FALSE)
          if(rcPosition.left<=rcTest.right && rcTest.left<=rcPosition.right && rcPosition.top<=rcTest.bottom && rcTest.top<=rcPosition.bottom)
          {   
                g_iLevel=LI_PANAMA;
                g_Flag1=0;
          }
          rcTest = g_pAntarcticaSprite->GetPosition();
          if(g_AntarcticaWon==FALSE)
          if(rcPosition.left<=rcTest.right && rcTest.left<=rcPosition.right && rcPosition.top<=rcTest.bottom && rcTest.top<=rcPosition.bottom)
          {   
                g_iLevel=LI_ANTARCTICA;
                g_Flag1=0;
                g_BritainCounter=1;
          }
        }
        // Reset the input delay
        g_iInputDelay = 0;
     }
   }
   else if(g_iLevel==LI_USSR)
   {
     if (g_iInputDelay++ > 1)
     {
        if (GetAsyncKeyState(VK_LEFT) < 0)
        {
           // Make the person walk
           g_pPersonSprite->Walk(1, 2);
        }
        else if (GetAsyncKeyState(VK_RIGHT) < 0)
        {
           // Make the person walk
           g_pPersonSprite->Walk(2, 2);
        }
        else if (GetAsyncKeyState(VK_UP) < 0)
        {
           // Make the person walk
           g_pPersonSprite->Walk(3, 2);
        }
        else if (GetAsyncKeyState(VK_DOWN) < 0)
        {
           // Make the person walk
           g_pPersonSprite->Walk(4, 2);
        }
        // Reset the input delay
        g_iInputDelay = 0;
     }
   }
   else if(g_iLevel==LI_BRITAIN)
   {
      if (g_iInputDelay++ > 1)
     {
        RECT& rcPosition = g_pSamSprite->GetPosition();
        if (GetAsyncKeyState(VK_UP) < 0 && g_Flag0==0)
        {
           if(rcPosition.top>135)
           {
              rcPosition.top-=24;
              rcPosition.bottom-=24;
              g_pSamSprite->SetPosition(rcPosition);
           }
        }
        else if (GetAsyncKeyState(VK_DOWN) < 0)
        {
           if(rcPosition.bottom<235 && g_Flag0==0)
           {
              rcPosition.top+=24;
              rcPosition.bottom+=24;
              g_pSamSprite->SetPosition(rcPosition);
           }
        }
        else if(GetAsyncKeyState(VK_SPACE) <0 && g_Flag0==0)
        {
                g_Flag0=1;
                g_Timer1=clock();
        }
        // Reset the input delay
        g_iInputDelay = 0;
     }
   }
   else if(g_iLevel==LI_AFGHANISTAN)
   {
      if(!(g_pSelectSprite->IsHidden()))
      {
         RECT rcSelect = g_pSelectSprite->GetPosition();
         int k, y;
         if(rcSelect.left==6)
           k=0;
         if(rcSelect.left==33)
           k=1;
         if(rcSelect.left==60)
           k=2;
         if(rcSelect.left==88)
           k=3;
         if(rcSelect.left==115)
           k=4;
         if(rcSelect.left==142)
           k=5;
         if(rcSelect.left==171)
           k=6;
         if(rcSelect.left==198)
           k=7;
         if(rcSelect.left==225)
           k=8;
         if(rcSelect.top==7)
           y=0;
         if(rcSelect.top==34)
           y=1;
         if(rcSelect.top==61)
           y=2;
         if(rcSelect.top==90)
           y=3;
         if(rcSelect.top==117)
           y=4;
         if(rcSelect.top==144)
           y=5;
         if(rcSelect.top==172)
           y=6;
         if(rcSelect.top==199)
           y=7;
         if(rcSelect.top==226)
           y=8;
         if (GetAsyncKeyState(VK_NUMPAD1) < 0 || GetAsyncKeyState(0x31) < 0)
         {
           if(rcSelect.left>5 && rcSelect.left<61 && rcSelect.top>6 && rcSelect.top<62)
           {
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite1->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite1->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite1->SetHidden(TRUE);
             g_psudoku1Sprite1->SetHidden(FALSE);
             g_psudoku1Sprite1->SetPosition(rcSelect);
           }
           if(rcSelect.left>170 && rcSelect.left<226 && rcSelect.top>6 && rcSelect.top<62)
           {
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==8)
               g_psudoku8Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==9)
               g_psudoku9Sprite3->SetHidden(TRUE);
             g_psudoku1Sprite3->SetHidden(FALSE);
             g_psudoku1Sprite3->SetPosition(rcSelect);
           }
           if(rcSelect.left>5 && rcSelect.left<61 && rcSelect.top>89 && rcSelect.top<145)
           {
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite4->SetHidden(TRUE);
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite4->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite4->SetHidden(TRUE);
             if(g_sudoku[k][y]==6)
               g_psudoku6Sprite4->SetHidden(TRUE);
             if(g_sudoku[k][y]==9)
               g_psudoku9Sprite4->SetHidden(TRUE);
             g_psudoku1Sprite4->SetHidden(FALSE);
             g_psudoku1Sprite4->SetPosition(rcSelect);
           }
           if(rcSelect.left>87 && rcSelect.left<143 && rcSelect.top>89 && rcSelect.top<145)
           {
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite5->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite5->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite5->SetHidden(TRUE);
             if(g_sudoku[k][y]==9)
               g_psudoku9Sprite5->SetHidden(TRUE);
             g_psudoku1Sprite5->SetHidden(FALSE);
             g_psudoku1Sprite5->SetPosition(rcSelect);
           }
           if(rcSelect.left>5 && rcSelect.left<61 && rcSelect.top>171 && rcSelect.top<227)
           {
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==8)
               g_psudoku8Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==9)
               g_psudoku9Sprite7->SetHidden(TRUE);
             g_psudoku1Sprite7->SetHidden(FALSE);
             g_psudoku1Sprite7->SetPosition(rcSelect);
           }
           if(rcSelect.left>170 && rcSelect.left<226 && rcSelect.top>171 && rcSelect.top<227)
           {
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite9->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite9->SetHidden(TRUE);
             if(g_sudoku[k][y]==6)
               g_psudoku6Sprite9->SetHidden(TRUE);
             g_psudoku1Sprite9->SetHidden(FALSE);
             g_psudoku1Sprite9->SetPosition(rcSelect);
           }
           g_sudoku[k][y]=1;
         }
         else if (GetAsyncKeyState(VK_NUMPAD2) < 0 || GetAsyncKeyState(0x32) < 0)
         {
           if(rcSelect.left>5 && rcSelect.left<61 && rcSelect.top>6 && rcSelect.top<62)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite1->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite1->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite1->SetHidden(TRUE);
             g_psudoku2Sprite1->SetHidden(FALSE);
             g_psudoku2Sprite1->SetPosition(rcSelect);
           }
           if(rcSelect.left>87 && rcSelect.left<143 && rcSelect.top>6 && rcSelect.top<62)
           {
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite2->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite2->SetHidden(TRUE);
             if(g_sudoku[k][y]==6)
               g_psudoku6Sprite2->SetHidden(TRUE);
             if(g_sudoku[k][y]==8)
               g_psudoku8Sprite2->SetHidden(TRUE);
             g_psudoku2Sprite2->SetHidden(FALSE);
             g_psudoku2Sprite2->SetPosition(rcSelect);
           }
           if(rcSelect.left>170 && rcSelect.left<226 && rcSelect.top>6 && rcSelect.top<62)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==8)
               g_psudoku8Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==9)
               g_psudoku9Sprite3->SetHidden(TRUE);
             g_psudoku2Sprite3->SetHidden(FALSE);
             g_psudoku2Sprite3->SetPosition(rcSelect);
           }
           if(rcSelect.left>5 && rcSelect.left<61 && rcSelect.top>89 && rcSelect.top<145)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite4->SetHidden(TRUE);
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite4->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite4->SetHidden(TRUE);
             if(g_sudoku[k][y]==6)
               g_psudoku6Sprite4->SetHidden(TRUE);
             if(g_sudoku[k][y]==9)
               g_psudoku9Sprite4->SetHidden(TRUE);
             g_psudoku2Sprite4->SetHidden(FALSE);
             g_psudoku2Sprite4->SetPosition(rcSelect);
           }
           if(rcSelect.left>170 && rcSelect.left<226 && rcSelect.top>89 && rcSelect.top<145)
           {
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite6->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite6->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite6->SetHidden(TRUE);
             if(g_sudoku[k][y]==8)
               g_psudoku8Sprite6->SetHidden(TRUE);
             if(g_sudoku[k][y]==9)
               g_psudoku9Sprite6->SetHidden(TRUE);
             g_psudoku2Sprite6->SetHidden(FALSE);
             g_psudoku2Sprite6->SetPosition(rcSelect);
           }
           if(rcSelect.left>5 && rcSelect.left<61 && rcSelect.top>171 && rcSelect.top<227)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==8)
               g_psudoku8Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==9)
               g_psudoku9Sprite7->SetHidden(TRUE);
             g_psudoku2Sprite7->SetHidden(FALSE);
             g_psudoku2Sprite7->SetPosition(rcSelect);
           }
           if(rcSelect.left>87 && rcSelect.left<143 && rcSelect.top>171 && rcSelect.top<227)
           {
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite8->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite8->SetHidden(TRUE);
             if(g_sudoku[k][y]==6)
               g_psudoku6Sprite8->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite8->SetHidden(TRUE);
             g_psudoku2Sprite8->SetHidden(FALSE);
             g_psudoku2Sprite8->SetPosition(rcSelect);
           }
           g_sudoku[k][y]=2;
         }
         else if (GetAsyncKeyState(VK_NUMPAD3) < 0 || GetAsyncKeyState(0x33) < 0)
         {
           if(rcSelect.left>87 && rcSelect.left<143 && rcSelect.top>6 && rcSelect.top<62)
           {
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite2->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite2->SetHidden(TRUE);
             if(g_sudoku[k][y]==6)
               g_psudoku6Sprite2->SetHidden(TRUE);
             if(g_sudoku[k][y]==8)
               g_psudoku8Sprite2->SetHidden(TRUE);
             g_psudoku3Sprite2->SetHidden(FALSE);
             g_psudoku3Sprite2->SetPosition(rcSelect);
           }
           if(rcSelect.left>170 && rcSelect.left<226 && rcSelect.top>6 && rcSelect.top<62)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==8)
               g_psudoku8Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==9)
               g_psudoku9Sprite3->SetHidden(TRUE);
             g_psudoku3Sprite3->SetHidden(FALSE);
             g_psudoku3Sprite3->SetPosition(rcSelect);
           }
           if(rcSelect.left>5 && rcSelect.left<61 && rcSelect.top>89 && rcSelect.top<145)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite4->SetHidden(TRUE);
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite4->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite4->SetHidden(TRUE);
             if(g_sudoku[k][y]==6)
               g_psudoku6Sprite4->SetHidden(TRUE);
             if(g_sudoku[k][y]==9)
               g_psudoku9Sprite4->SetHidden(TRUE);
             g_psudoku3Sprite4->SetHidden(FALSE);
             g_psudoku3Sprite4->SetPosition(rcSelect);
           }
           if(rcSelect.left>5 && rcSelect.left<61 && rcSelect.top>171 && rcSelect.top<227)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==8)
               g_psudoku8Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==9)
               g_psudoku9Sprite7->SetHidden(TRUE);
             g_psudoku3Sprite7->SetHidden(FALSE);
             g_psudoku3Sprite7->SetPosition(rcSelect);
           }
           if(rcSelect.left>87 && rcSelect.left<143 && rcSelect.top>171 && rcSelect.top<227)
           {
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite8->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite8->SetHidden(TRUE);
             if(g_sudoku[k][y]==6)
               g_psudoku6Sprite8->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite8->SetHidden(TRUE);
             g_psudoku3Sprite8->SetHidden(FALSE);
             g_psudoku3Sprite8->SetPosition(rcSelect);
           }
           if(rcSelect.left>170 && rcSelect.left<226 && rcSelect.top>171 && rcSelect.top<227)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite9->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite9->SetHidden(TRUE);
             if(g_sudoku[k][y]==6)
               g_psudoku6Sprite9->SetHidden(TRUE);
             g_psudoku3Sprite9->SetHidden(FALSE);
             g_psudoku3Sprite9->SetPosition(rcSelect);
           }
           g_sudoku[k][y]=3;
         }
         else if (GetAsyncKeyState(VK_NUMPAD4) < 0 || GetAsyncKeyState(0x34) < 0)
         {
           if(rcSelect.left>5 && rcSelect.left<61 && rcSelect.top>6 && rcSelect.top<62)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite1->SetHidden(TRUE);
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite1->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite1->SetHidden(TRUE);
             g_psudoku4Sprite1->SetHidden(FALSE);
             g_psudoku4Sprite1->SetPosition(rcSelect);
           }
           if(rcSelect.left>87 && rcSelect.left<143 && rcSelect.top>6 && rcSelect.top<62)
           {
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite2->SetHidden(TRUE);
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite2->SetHidden(TRUE);
             if(g_sudoku[k][y]==6)
               g_psudoku6Sprite2->SetHidden(TRUE);
             if(g_sudoku[k][y]==8)
               g_psudoku8Sprite2->SetHidden(TRUE);
             g_psudoku4Sprite2->SetHidden(FALSE);
             g_psudoku4Sprite2->SetPosition(rcSelect);
           }
           if(rcSelect.left>170 && rcSelect.left<226 && rcSelect.top>6 && rcSelect.top<62)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==8)
               g_psudoku8Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==9)
               g_psudoku9Sprite3->SetHidden(TRUE);
             g_psudoku4Sprite3->SetHidden(FALSE);
             g_psudoku4Sprite3->SetPosition(rcSelect);
           }
           if(rcSelect.left>87 && rcSelect.left<143 && rcSelect.top>89 && rcSelect.top<145)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite5->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite5->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite5->SetHidden(TRUE);
             if(g_sudoku[k][y]==9)
               g_psudoku9Sprite5->SetHidden(TRUE);
             g_psudoku4Sprite5->SetHidden(FALSE);
             g_psudoku4Sprite5->SetPosition(rcSelect);
           }
           if(rcSelect.left>170 && rcSelect.left<226 && rcSelect.top>89 && rcSelect.top<145)
           {
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite6->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite6->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite6->SetHidden(TRUE);
             if(g_sudoku[k][y]==8)
               g_psudoku8Sprite6->SetHidden(TRUE);
             if(g_sudoku[k][y]==9)
               g_psudoku9Sprite6->SetHidden(TRUE);
             g_psudoku4Sprite6->SetHidden(FALSE);
             g_psudoku4Sprite6->SetPosition(rcSelect);
           }
           if(rcSelect.left>5 && rcSelect.left<61 && rcSelect.top>171 && rcSelect.top<227)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==8)
               g_psudoku8Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==9)
               g_psudoku9Sprite7->SetHidden(TRUE);
             g_psudoku4Sprite7->SetHidden(FALSE);
             g_psudoku4Sprite7->SetPosition(rcSelect);
           }
           if(rcSelect.left>170 && rcSelect.left<226 && rcSelect.top>171 && rcSelect.top<227)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite9->SetHidden(TRUE);
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite9->SetHidden(TRUE);
             if(g_sudoku[k][y]==6)
               g_psudoku6Sprite9->SetHidden(TRUE);
             g_psudoku4Sprite9->SetHidden(FALSE);
             g_psudoku4Sprite9->SetPosition(rcSelect);
           }
           g_sudoku[k][y]=4;
         }
         else if (GetAsyncKeyState(VK_NUMPAD5) < 0 || GetAsyncKeyState(0x35) < 0)
         {
           if(rcSelect.left>170 && rcSelect.left<226 && rcSelect.top>6 && rcSelect.top<62)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==8)
               g_psudoku8Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==9)
               g_psudoku9Sprite3->SetHidden(TRUE);
             g_psudoku5Sprite3->SetHidden(FALSE);
             g_psudoku5Sprite3->SetPosition(rcSelect);
           }
           if(rcSelect.left>5 && rcSelect.left<61 && rcSelect.top>89 && rcSelect.top<145)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite4->SetHidden(TRUE);
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite4->SetHidden(TRUE);
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite4->SetHidden(TRUE);
             if(g_sudoku[k][y]==6)
               g_psudoku6Sprite4->SetHidden(TRUE);
             if(g_sudoku[k][y]==9)
               g_psudoku9Sprite4->SetHidden(TRUE);
             g_psudoku5Sprite4->SetHidden(FALSE);
             g_psudoku5Sprite4->SetPosition(rcSelect);
           }
           if(rcSelect.left>87 && rcSelect.left<143 && rcSelect.top>89 && rcSelect.top<145)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite5->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite5->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite5->SetHidden(TRUE);
             if(g_sudoku[k][y]==9)
               g_psudoku9Sprite5->SetHidden(TRUE);
             g_psudoku5Sprite5->SetHidden(FALSE);
             g_psudoku5Sprite5->SetPosition(rcSelect);
           }
           if(rcSelect.left>170 && rcSelect.left<226 && rcSelect.top>89 && rcSelect.top<145)
           {
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite6->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite6->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite6->SetHidden(TRUE);
             if(g_sudoku[k][y]==8)
               g_psudoku8Sprite6->SetHidden(TRUE);
             if(g_sudoku[k][y]==9)
               g_psudoku9Sprite6->SetHidden(TRUE);
             g_psudoku5Sprite6->SetHidden(FALSE);
             g_psudoku5Sprite6->SetPosition(rcSelect);
           }
           if(rcSelect.left>5 && rcSelect.left<61 && rcSelect.top>171 && rcSelect.top<227)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==8)
               g_psudoku8Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==9)
               g_psudoku9Sprite7->SetHidden(TRUE);
             g_psudoku5Sprite7->SetHidden(FALSE);
             g_psudoku5Sprite7->SetPosition(rcSelect);
           }
           if(rcSelect.left>87 && rcSelect.left<143 && rcSelect.top>171 && rcSelect.top<227)
           {
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite8->SetHidden(TRUE);
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite8->SetHidden(TRUE);
             if(g_sudoku[k][y]==6)
               g_psudoku6Sprite8->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite8->SetHidden(TRUE);
             g_psudoku5Sprite8->SetHidden(FALSE);
             g_psudoku5Sprite8->SetPosition(rcSelect);
           }
           g_sudoku[k][y]=5;
         }
         else if (GetAsyncKeyState(VK_NUMPAD6) < 0 || GetAsyncKeyState(0x36) < 0)
         {
           if(rcSelect.left>87 && rcSelect.left<143 && rcSelect.top>6 && rcSelect.top<62)
           {
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite2->SetHidden(TRUE);
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite2->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite2->SetHidden(TRUE);
             if(g_sudoku[k][y]==8)
               g_psudoku8Sprite2->SetHidden(TRUE);
             g_psudoku6Sprite2->SetHidden(FALSE);
             g_psudoku6Sprite2->SetPosition(rcSelect);
           }
           if(rcSelect.left>5 && rcSelect.left<61 && rcSelect.top>89 && rcSelect.top<145)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite4->SetHidden(TRUE);
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite4->SetHidden(TRUE);
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite4->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite4->SetHidden(TRUE);
             if(g_sudoku[k][y]==9)
               g_psudoku9Sprite4->SetHidden(TRUE);
             g_psudoku6Sprite4->SetHidden(FALSE);
             g_psudoku6Sprite4->SetPosition(rcSelect);
           }
           if(rcSelect.left>87 && rcSelect.left<143 && rcSelect.top>171 && rcSelect.top<227)
           {
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite8->SetHidden(TRUE);
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite8->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite8->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite8->SetHidden(TRUE);
             g_psudoku6Sprite8->SetHidden(FALSE);
             g_psudoku6Sprite8->SetPosition(rcSelect);
           }
           if(rcSelect.left>170 && rcSelect.left<226 && rcSelect.top>171 && rcSelect.top<227)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite9->SetHidden(TRUE);
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite9->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite9->SetHidden(TRUE);
             g_psudoku6Sprite9->SetHidden(FALSE);
             g_psudoku6Sprite9->SetPosition(rcSelect);
           }
           g_sudoku[k][y]=6;
         }
         else if (GetAsyncKeyState(VK_NUMPAD7) < 0 || GetAsyncKeyState(0x37) < 0)
         {
           if(rcSelect.left>5 && rcSelect.left<61 && rcSelect.top>6 && rcSelect.top<62)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite1->SetHidden(TRUE);
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite1->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite1->SetHidden(TRUE);
             g_psudoku7Sprite1->SetHidden(FALSE);
             g_psudoku7Sprite1->SetPosition(rcSelect);
           }
           if(rcSelect.left>170 && rcSelect.left<226 && rcSelect.top>6 && rcSelect.top<62)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==8)
               g_psudoku8Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==9)
               g_psudoku9Sprite3->SetHidden(TRUE);
             g_psudoku7Sprite3->SetHidden(FALSE);
             g_psudoku7Sprite3->SetPosition(rcSelect);
           }
           if(rcSelect.left>87 && rcSelect.left<143 && rcSelect.top>89 && rcSelect.top<145)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite5->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite5->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite5->SetHidden(TRUE);
             if(g_sudoku[k][y]==9)
               g_psudoku9Sprite5->SetHidden(TRUE);
             g_psudoku7Sprite5->SetHidden(FALSE);
             g_psudoku7Sprite5->SetPosition(rcSelect);
           }
           if(rcSelect.left>170 && rcSelect.left<226 && rcSelect.top>89 && rcSelect.top<145)
           {
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite6->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite6->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite6->SetHidden(TRUE);
             if(g_sudoku[k][y]==8)
               g_psudoku8Sprite6->SetHidden(TRUE);
             if(g_sudoku[k][y]==9)
               g_psudoku9Sprite6->SetHidden(TRUE);
             g_psudoku7Sprite6->SetHidden(FALSE);
             g_psudoku7Sprite6->SetPosition(rcSelect);
           }
           if(rcSelect.left>5 && rcSelect.left<61 && rcSelect.top>171 && rcSelect.top<227)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==8)
               g_psudoku8Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==9)
               g_psudoku9Sprite7->SetHidden(TRUE);
             g_psudoku7Sprite7->SetHidden(FALSE);
             g_psudoku7Sprite7->SetPosition(rcSelect);
           }
           if(rcSelect.left>87 && rcSelect.left<143 && rcSelect.top>171 && rcSelect.top<227)
           {
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite8->SetHidden(TRUE);
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite8->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite8->SetHidden(TRUE);
             if(g_sudoku[k][y]==6)
               g_psudoku6Sprite8->SetHidden(TRUE);
             g_psudoku7Sprite8->SetHidden(FALSE);
             g_psudoku7Sprite8->SetPosition(rcSelect);
           }
           g_sudoku[k][y]=7;
         }
         else if (GetAsyncKeyState(VK_NUMPAD8) < 0 || GetAsyncKeyState(0x38) < 0)
         {
           if(rcSelect.left>87 && rcSelect.left<143 && rcSelect.top>6 && rcSelect.top<62)
           {
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite2->SetHidden(TRUE);
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite2->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite2->SetHidden(TRUE);
             if(g_sudoku[k][y]==6)
               g_psudoku6Sprite2->SetHidden(TRUE);
             g_psudoku8Sprite2->SetHidden(FALSE);
             g_psudoku8Sprite2->SetPosition(rcSelect);
           }
           if(rcSelect.left>170 && rcSelect.left<226 && rcSelect.top>6 && rcSelect.top<62)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==9)
               g_psudoku9Sprite3->SetHidden(TRUE);
             g_psudoku8Sprite3->SetHidden(FALSE);
             g_psudoku8Sprite3->SetPosition(rcSelect);
           }
           if(rcSelect.left>170 && rcSelect.left<226 && rcSelect.top>89 && rcSelect.top<145)
           {
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite6->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite6->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite6->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite6->SetHidden(TRUE);
             if(g_sudoku[k][y]==9)
               g_psudoku9Sprite6->SetHidden(TRUE);
             g_psudoku8Sprite6->SetHidden(FALSE);
             g_psudoku8Sprite6->SetPosition(rcSelect);
           }
           if(rcSelect.left>5 && rcSelect.left<61 && rcSelect.top>171 && rcSelect.top<227)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==9)
               g_psudoku9Sprite7->SetHidden(TRUE);
             g_psudoku8Sprite7->SetHidden(FALSE);
             g_psudoku8Sprite7->SetPosition(rcSelect);
           }
           g_sudoku[k][y]=8;
         }
         else if (GetAsyncKeyState(VK_NUMPAD9) < 0 || GetAsyncKeyState(0x39) < 0)
         {
           if(rcSelect.left>170 && rcSelect.left<226 && rcSelect.top>6 && rcSelect.top<62)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite3->SetHidden(TRUE);
             if(g_sudoku[k][y]==8)
               g_psudoku8Sprite3->SetHidden(TRUE);
             g_psudoku9Sprite3->SetHidden(FALSE);
             g_psudoku9Sprite3->SetPosition(rcSelect);
           }
           if(rcSelect.left>5 && rcSelect.left<61 && rcSelect.top>89 && rcSelect.top<145)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite4->SetHidden(TRUE);
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite4->SetHidden(TRUE);
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite4->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite4->SetHidden(TRUE);
             if(g_sudoku[k][y]==6)
               g_psudoku6Sprite4->SetHidden(TRUE);
             g_psudoku9Sprite4->SetHidden(FALSE);
             g_psudoku9Sprite4->SetPosition(rcSelect);
           }
           if(rcSelect.left>87 && rcSelect.left<143 && rcSelect.top>89 && rcSelect.top<145)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite5->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite5->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite5->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite5->SetHidden(TRUE);
             g_psudoku9Sprite5->SetHidden(FALSE);
             g_psudoku9Sprite5->SetPosition(rcSelect);
           }
           if(rcSelect.left>170 && rcSelect.left<226 && rcSelect.top>89 && rcSelect.top<145)
           {
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite6->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite6->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite6->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite6->SetHidden(TRUE);
             if(g_sudoku[k][y]==8)
               g_psudoku8Sprite6->SetHidden(TRUE);
             g_psudoku9Sprite6->SetHidden(FALSE);
             g_psudoku9Sprite6->SetPosition(rcSelect);
           }
           if(rcSelect.left>5 && rcSelect.left<61 && rcSelect.top>171 && rcSelect.top<227)
           {
             if(g_sudoku[k][y]==1)
               g_psudoku1Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==2)
               g_psudoku2Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==3)
               g_psudoku3Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==4)
               g_psudoku4Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==5)
               g_psudoku5Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==7)
               g_psudoku7Sprite7->SetHidden(TRUE);
             if(g_sudoku[k][y]==8)
               g_psudoku8Sprite7->SetHidden(TRUE);
             g_psudoku9Sprite7->SetHidden(FALSE);
             g_psudoku9Sprite7->SetPosition(rcSelect);
           }
           g_sudoku[k][y]=9;
         }
      }
   }
   else if(g_iLevel==LI_CONGO)
   {
      if (GetAsyncKeyState(VK_UP) < 0)
      {
         g_pPersonSprite->Walk(3, 3);
      }
      else if (GetAsyncKeyState(VK_DOWN) < 0)
      {
         g_pPersonSprite->Walk(4, 3);
      }
      else if (GetAsyncKeyState(VK_LEFT) < 0)
      {
         g_pPersonSprite->Walk(1, 3);
      }
      else if (GetAsyncKeyState(VK_RIGHT) < 0)
      {
         g_pPersonSprite->Walk(2, 3);
      }
   }
   else if(g_iLevel==LI_ANTARCTICA)
   {
    if (g_iInputDelay++ > 1)
    {
      RECT rcMenuIndicator = g_pPokeMenuIndicatorSprite->GetPosition();
      if (GetAsyncKeyState(VK_SPACE) < 0 && g_PokeFlag1==2)
         g_PokeFlag1++;
      //else if (GetAsyncKeyState(VK_SPACE) < 0 && g_PokeFlag1==3)
        // g_PokeFlag1++;
      else if (GetAsyncKeyState(VK_LEFT) < 0 && g_PokeFlag1==4)
      {
         if( rcMenuIndicator.left==191 && rcMenuIndicator.top==192)
             g_pPokeMenuIndicatorSprite->SetPosition(130, 192);
         if( rcMenuIndicator.left==191 && rcMenuIndicator.top==223)
             g_pPokeMenuIndicatorSprite->SetPosition(130, 223);
      }
      else if (GetAsyncKeyState(VK_RIGHT) < 0 && g_PokeFlag1==4)
      {
         if( rcMenuIndicator.left==130 && rcMenuIndicator.top==192)
             g_pPokeMenuIndicatorSprite->SetPosition(191, 192);
         if( rcMenuIndicator.left==130 && rcMenuIndicator.top==223)
             g_pPokeMenuIndicatorSprite->SetPosition(191, 223);
      }
      else if (GetAsyncKeyState(VK_UP) < 0 && g_PokeFlag1==4)
      {
         if( rcMenuIndicator.left==191 && rcMenuIndicator.top==223)
             g_pPokeMenuIndicatorSprite->SetPosition(191, 192);
         if( rcMenuIndicator.left==130 && rcMenuIndicator.top==223)
             g_pPokeMenuIndicatorSprite->SetPosition(130, 192);
      }
      else if (GetAsyncKeyState(VK_DOWN) < 0 && g_PokeFlag1==4)
      {
         if( rcMenuIndicator.left==191 && rcMenuIndicator.top==192)
             g_pPokeMenuIndicatorSprite->SetPosition(191, 223);
         if( rcMenuIndicator.left==130 && rcMenuIndicator.top==192)
             g_pPokeMenuIndicatorSprite->SetPosition(130, 223);
      }
      else if (GetAsyncKeyState(VK_SPACE) < 0 && g_PokeFlag1==4)
      {
         if(rcMenuIndicator.left==130 && rcMenuIndicator.top==192)
           g_PokeFlag1++;
         if(rcMenuIndicator.left==191 && rcMenuIndicator.top==223)
           g_PokeFlag1=-1;
      }
      else if (GetAsyncKeyState(VK_LEFT) < 0 && g_PokeFlag1==6)
      {
         if( rcMenuIndicator.left==86 && rcMenuIndicator.top==194)
             g_pPokeMenuIndicatorSprite->SetPosition(9, 194);
      }
      else if (GetAsyncKeyState(VK_RIGHT) < 0 && g_PokeFlag1==6)
      {
         if( rcMenuIndicator.left==9 && rcMenuIndicator.top==194)
             g_pPokeMenuIndicatorSprite->SetPosition(86, 194);
      }
      else if (GetAsyncKeyState(VK_UP) < 0 && g_PokeFlag1==6)
      {
         if( rcMenuIndicator.left==9 && rcMenuIndicator.top==223)
             g_pPokeMenuIndicatorSprite->SetPosition(9, 194);
      }
      else if (GetAsyncKeyState(VK_DOWN) < 0 && g_PokeFlag1==6)
      {
         if( rcMenuIndicator.left==9 && rcMenuIndicator.top==194)
             g_pPokeMenuIndicatorSprite->SetPosition(9, 223);
      }
      else if (GetAsyncKeyState(VK_SPACE) < 0 && g_PokeFlag1==6)
      {
         if(rcMenuIndicator.left==9 && rcMenuIndicator.top==194)
           g_PokeFlag1=17;
         if(rcMenuIndicator.left==86 && rcMenuIndicator.top==194)
           g_PokeFlag1=13;
         if(rcMenuIndicator.left==9 && rcMenuIndicator.top==223)
           g_PokeFlag1++;
      }
      else if (GetAsyncKeyState(VK_SPACE) < 0 && g_PokeFlag1==10)
      {
           g_pPokeBellTextSprite->SetHidden(TRUE);
           g_PokeFlag1++;
      }
      else if (GetAsyncKeyState(VK_SPACE) < 0 && g_PokeFlag1==12)
      {
           g_pPokeOpponentTurnSprite->SetHidden(TRUE);
           g_PokeFlag1=3;
      }
      else if (GetAsyncKeyState(VK_SPACE) < 0 && g_PokeFlag1==16)
      {
           g_pPokeBeamTextSprite->SetHidden(TRUE);
           g_PokeFlag1=11;
      }
      else if (GetAsyncKeyState(VK_SPACE) < 0 && g_PokeFlag1==20)
      {
           g_pPokeOpponentTurnSprite->SetHidden(TRUE);
           g_pPokeIndicatorSprite->SetHidden(TRUE);
           if(g_PokeFlag3<2)
             g_PokeFlag1=17;
           else
             g_PokeFlag1=21;
      }
      g_iInputDelay=0;
    }
   }
}

void MouseButtonDown(int x, int y, BOOL bLeft)
{
     if(g_iLevel==LI_CHINA && bLeft==TRUE)
     {
        RECT rcObject = g_pFireworksSprite->GetPosition();
        RECT rcIndicator = g_pIndicatorSprite->GetPosition();
        if(y<rcObject.bottom && y>rcObject.top && x<rcObject.right && x>rcObject.left)
        {
           if(rcObject.left==6)
           {
              if(rcIndicator.left!=20)
                 g_pIndicatorSprite->SetPosition(20, 239);
              else
              {
                 g_pFireworksSprite->SetPosition(193, 25);
                 g_pIndicatorSprite->SetPosition(207, 239);
              }
           }
           else
           {
              if(rcIndicator.left!=207)
                 g_pIndicatorSprite->SetPosition(207, 239);
              else
              {
                 g_pFireworksSprite->SetPosition(6, 25);
                 g_pIndicatorSprite->SetPosition(20, 239);
              }
           }
        }
        rcObject = g_pSilkSprite->GetPosition();
        if(y<rcObject.bottom && y>rcObject.top && x<rcObject.right && x>rcObject.left)
        {
           if(rcObject.left==6)
           {
              if(rcIndicator.left!=20)
                 g_pIndicatorSprite->SetPosition(20, 239);
              else
              {
                 g_pSilkSprite->SetPosition(193, 96);
                 g_pIndicatorSprite->SetPosition(207, 239);
              }
              
           }
           else
           {
              if(rcIndicator.left!=207)
                 g_pIndicatorSprite->SetPosition(207, 239);
              else
              {
                 g_pSilkSprite->SetPosition(6, 96);
                 g_pIndicatorSprite->SetPosition(20, 239);
              }
           }
        }
        rcObject = g_pPorcelainSprite->GetPosition();
        if(y<rcObject.bottom && y>rcObject.top && x<rcObject.right && x>rcObject.left)
        {
           if(rcObject.left==6)
           {
              if(rcIndicator.left!=20)
                 g_pIndicatorSprite->SetPosition(20, 239);
              else
              {
                 g_pPorcelainSprite->SetPosition(193, 167);
                 g_pIndicatorSprite->SetPosition(207, 239);
              }
           }
           else
           {
              if(rcIndicator.left!=207)
                 g_pIndicatorSprite->SetPosition(207, 239);
              else
              {
                 g_pPorcelainSprite->SetPosition(6, 167);
                 g_pIndicatorSprite->SetPosition(20, 239);
              }
           }
          
        }
     }
     else if(g_iLevel==LI_PANAMA && bLeft==TRUE)
     {
          RECT rcBlue = g_pBoatBlueSprite->GetPosition();
          RECT rcRed = g_pBoatRedSprite->GetPosition();
          RECT rcGray = g_pBoatGraySprite->GetPosition();
          RECT rcWhite = g_pBoatWhiteSprite->GetPosition();
          RECT rcOrange = g_pBoatOrangeSprite->GetPosition();
          RECT rcGreen = g_pBoatGreenSprite->GetPosition();
          if(g_Counter==4)
          {
             if(g_BritainCounter==2 && x>rcBlue.left && x<rcBlue.right && y<rcBlue.bottom && y>rcBlue.top)
                g_BritainCounter++;
             else if(g_BritainCounter==2)
                g_BritainCounter=-1;
             if(g_BritainCounter==1 && x>rcWhite.left && x<rcWhite.right && y<rcWhite.bottom && y>rcWhite.top)
                g_BritainCounter++;
             else if(g_BritainCounter==1)
                g_BritainCounter=-1;
             if(g_BritainCounter==0 && x>rcRed.left && x<rcRed.right && y<rcRed.bottom && y>rcRed.top)
                g_BritainCounter++;
             else if(g_BritainCounter==0)
                g_BritainCounter=-1;
          }
          if(g_Counter==10)
          {
             if(g_BritainCounter==3 && x>rcRed.left && x<rcRed.right && y<rcRed.bottom && y>rcRed.top)
                g_BritainCounter++;
             else if(g_BritainCounter==3)
                g_BritainCounter=-1;
             if(g_BritainCounter==2 && x>rcGray.left && x<rcGray.right && y<rcGray.bottom && y>rcGray.top)
                g_BritainCounter++;
             else if(g_BritainCounter==2)
                g_BritainCounter=-1;
             if(g_BritainCounter==1 && x>rcOrange.left && x<rcOrange.right && y<rcOrange.bottom && y>rcOrange.top)
                g_BritainCounter++;
             else if(g_BritainCounter==1)
                g_BritainCounter=-1;
             if(g_BritainCounter==0 && x>rcWhite.left && x<rcWhite.right && y<rcWhite.bottom && y>rcWhite.top)
                g_BritainCounter++;
             else if(g_BritainCounter==0)
                g_BritainCounter=-1;
          }
          if(g_Counter==18)
          {
             if(g_BritainCounter==5 && x>rcOrange.left && x<rcOrange.right && y<rcOrange.bottom && y>rcOrange.top)
                g_BritainCounter++;
             else if(g_BritainCounter==5)
                g_BritainCounter=-1;
             if(g_BritainCounter==4 && x>rcWhite.left && x<rcWhite.right && y<rcWhite.bottom && y>rcWhite.top)
                g_BritainCounter++;
             else if(g_BritainCounter==4)
                g_BritainCounter=-1;
             if(g_BritainCounter==3 && x>rcRed.left && x<rcRed.right && y<rcRed.bottom && y>rcRed.top)
                g_BritainCounter++;
             else if(g_BritainCounter==3)
                g_BritainCounter=-1;
             if(g_BritainCounter==2 && x>rcGray.left && x<rcGray.right && y<rcGray.bottom && y>rcGray.top)
                g_BritainCounter++;
             else if(g_BritainCounter==2)
                g_BritainCounter=-1;
             if(g_BritainCounter==1 && x>rcBlue.left && x<rcBlue.right && y<rcBlue.bottom && y>rcBlue.top)
                g_BritainCounter++;
             else if(g_BritainCounter==1)
                g_BritainCounter=-1;
             if(g_BritainCounter==0 && x>rcGreen.left && x<rcGreen.right && y<rcGreen.bottom && y>rcGreen.top)
                g_BritainCounter++;
             else if(g_BritainCounter==0)
                g_BritainCounter=-1;
          }
     }
     else if(g_iLevel==LI_AFGHANISTAN && bLeft==TRUE)
     {
         if(x>60 && x<88 && y>7 && y<34)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(60, 7);
         }
         if(x>88 && x<115 && y>7 && y<34)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(88, 7);
         }
         if(x>142 && x<171 && y>7 && y<34)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(142, 7);
         }
         if(x>171 && x<198 && y>7 && y<34)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(171, 7);
         }
         if(x>198 && x<225 && y>7 && y<34)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(198, 7);
         }
         if(x>225 && x<250 && y>7 && y<34)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(225, 7);
         }
         if(x>33 && x<60 && y>34 && y<61)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(33, 34);
         }
         if(x>60 && x<88 && y>34 && y<61)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(60, 34);
         }
         if(x>171 && x<198 && y>34 && y<61)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(171, 34);
         }
         if(x>198 && x<225 && y>34 && y<61)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(198, 34);
         }
         if(x>225 && x<250 && y>34 && y<61)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(225, 34);
         }
         if(x>6 && x<33 && y>61 && y<90)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(6, 61);
         }
         if(x>88 && x<115 && y>61 && y<90)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(88, 61);
         }
         if(x>115 && x<142 && y>61 && y<90)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(115, 61);
         }
         if(x>142 && x<171 && y>61 && y<90)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(142, 61);
         }
         if(x>171 && x<198 && y>61 && y<90)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(171, 61);
         }
         if(x>225 && x<250 && y>61 && y<90)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(225, 61);
         }
         if(x>33 && x<60 && y>90 && y<117)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(33, 90);
         }
         if(x>60 && x<88 && y>90 && y<117)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(60, 90);
         }
         if(x>88 && x<115 && y>90 && y<117)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(88, 90);
         }
         if(x>142 && x<171 && y>90 && y<117)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(142, 90);
         }
         if(x>171 && x<198 && y>90 && y<117)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(171, 90);
         }
         if(x>198 && x<225 && y>90 && y<117)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(198, 90);
         }
         if(x>33 && x<60 && y>117 && y<144)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(33, 117);
         }
         if(x>60 && x<88 && y>117 && y<144)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(60, 117);
         }
         if(x>115 && x<142 && y>117 && y<144)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(115, 117);
         }
         if(x>171 && x<198 && y>117 && y<144)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(171, 117);
         }
         if(x>198 && x<225 && y>117 && y<144)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(198, 117);
         }
         if(x>33 && x<60 && y>144 && y<172)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(33, 144);
         }
         if(x>60 && x<88 && y>144 && y<172)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(60, 144);
         }
         if(x>88 && x<115 && y>144 && y<172)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(88, 144);
         }
         if(x>142 && x<171 && y>144 && y<172)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(142, 144);
         }
         if(x>171 && x<198 && y>144 && y<172)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(171, 144);
         }
         if(x>198 && x<225 && y>144 && y<172)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(198, 144);
         }
         if(x>6 && x<33 && y>172 && y<199)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(6, 172);
         }
         if(x>60 && x<88 && y>172 && y<199)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(60, 172);
         }
         if(x>88 && x<115 && y>172 && y<199)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(88, 172);
         }
         if(x>115 && x<142 && y>172 && y<199)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(115, 172);
         }
         if(x>142 && x<171 && y>172 && y<199)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(142, 172);
         }
         if(x>225 && x<250 && y>172 && y<199)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(225, 172);
         }
         if(x>6 && x<33 && y>199 && y<226)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(6, 199);
         }
         if(x>33 && x<60 && y>199 && y<226)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(33, 199);
         }
         if(x>60 && x<88 && y>199 && y<226)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(60, 199);
         }
         if(x>171 && x<198 && y>199 && y<226)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(171, 199);
         }
         if(x>198 && x<225 && y>199 && y<226)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(198, 199);
         }
         if(x>6 && x<33 && y>226 && y<251)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(6, 226);
         }
         if(x>33 && x<60 && y>226 && y<251)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(33, 226);
         }
         if(x>60 && x<88 && y>226 && y<251)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(60, 226);
         }
         if(x>88 && x<115 && y>226 && y<251)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(88, 226);
         }
         if(x>142 && x<171 && y>226 && y<251)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(142, 226);
         }
         if(x>171 && x<198 && y>226 && y<251)
         {
            g_pSelectSprite->SetHidden(FALSE);
            g_pSelectSprite->SetPosition(171, 226);
         }
     }
}

void MouseButtonUp(int x, int y, BOOL bLeft)
{
}

void MouseMove(int x, int y)
{
}

void HandleJoystick(JOYSTATE jsJoystickState)
{
  /*if (++g_iInputDelay > 2)
  {
    // Check horizontal movement
    if (jsJoystickState & JOY_LEFT)
    {
      // Make the person walk
      g_pPersonSprite->Walk();

      // Move the landscape layer to the right
      g_pBGLandscapeLayer->SetSpeed(16);
      g_pBGLandscapeLayer->SetDirection(SD_RIGHT);
      g_pBGLandscapeLayer->Update();
      g_pBGLandscapeLayer->SetSpeed(0);

      // Move the cloud layer to the right
      g_pFGCloudsLayer->SetSpeed(4);
      g_pFGCloudsLayer->SetDirection(SD_RIGHT);
      g_pFGCloudsLayer->Update();
      g_pFGCloudsLayer->SetSpeed(0);
    }
    else if (jsJoystickState & JOY_RIGHT)
    {
      // Make the person walk
      g_pPersonSprite->Walk();

      // Move the landscape layer to the left
      g_pBGLandscapeLayer->SetSpeed(16);
      g_pBGLandscapeLayer->SetDirection(SD_LEFT);
      g_pBGLandscapeLayer->Update();
      g_pBGLandscapeLayer->SetSpeed(0);

      // Move the cloud layer to the left
      g_pFGCloudsLayer->SetSpeed(4);
      g_pFGCloudsLayer->SetDirection(SD_LEFT);
      g_pFGCloudsLayer->Update();
      g_pFGCloudsLayer->SetSpeed(0);
    }
    else if (jsJoystickState & JOY_UP)
    {
      // Make the person walk
      g_pPersonSprite->Walk();

      // Move the landscape layer down
      g_pBGLandscapeLayer->SetSpeed(16);
      g_pBGLandscapeLayer->SetDirection(SD_DOWN);
      g_pBGLandscapeLayer->Update();
      g_pBGLandscapeLayer->SetSpeed(0);

      // Move the cloud layer down
      g_pFGCloudsLayer->SetSpeed(4);
      g_pFGCloudsLayer->SetDirection(SD_DOWN);
      g_pFGCloudsLayer->Update();
      g_pFGCloudsLayer->SetSpeed(0);
    }
    else if (jsJoystickState & JOY_DOWN)
    {
      // Make the person walk
      g_pPersonSprite->Walk();

      // Move the landscape layer up
      g_pBGLandscapeLayer->SetSpeed(16);
      g_pBGLandscapeLayer->SetDirection(SD_UP);
      g_pBGLandscapeLayer->Update();
      g_pBGLandscapeLayer->SetSpeed(0);

      // Move the cloud layer up
      g_pFGCloudsLayer->SetSpeed(4);
      g_pFGCloudsLayer->SetDirection(SD_UP);
      g_pFGCloudsLayer->Update();
      g_pFGCloudsLayer->SetSpeed(0);
    }

    // Reset the input delay
    g_iInputDelay = 0;
  }*/
}

BOOL SpriteCollision(Sprite* pSpriteHitter, Sprite* pSpriteHittee)
{
  
  return FALSE;
}

void SpriteDying(Sprite* pSpriteDying)
{
}
