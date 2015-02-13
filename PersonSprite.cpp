//-----------------------------------------------------------------
// Person Sprite Object
// C++ Source - PersonSprite.cpp
//-----------------------------------------------------------------

//-----------------------------------------------------------------
// Include Files
//-----------------------------------------------------------------
#include "PersonSprite.h"

//-----------------------------------------------------------------
// PersonSprite Constructor(s)/Destructor
//-----------------------------------------------------------------
PersonSprite::PersonSprite(Bitmap* pBitmap, RECT& rcBounds,
  BOUNDSACTION baBoundsAction) : Sprite(pBitmap, rcBounds,
  baBoundsAction)
{
}

PersonSprite::~PersonSprite()
{
}

//-----------------------------------------------------------------
// PersonSprite Virtual Methods
//-----------------------------------------------------------------
inline void PersonSprite::UpdateFrame()
{
}

//-----------------------------------------------------------------
// PersonSprite General Methods
//-----------------------------------------------------------------
void PersonSprite::Walk(int dir, int lvl)
{
  // Toggle between the frames to give the illusion of walking
  if(dir==1)
  {
     if(m_iCurFrame==4)
        m_iCurFrame=5;
     else if(m_iCurFrame==3)
        m_iCurFrame=4;
     else
        m_iCurFrame=3;
     if(lvl==2)
     {
        SetVelocity(-8, 0);
        Update();
        SetVelocity(0, 0);
     }
     if(lvl==3)
     {
        SetVelocity(-8, 0);
        UpdateFrame();
     }
  }
  else if(dir==2)
  {
     if(m_iCurFrame==7)
        m_iCurFrame=8;
     else if(m_iCurFrame==6)
        m_iCurFrame=7;
     else
        m_iCurFrame=6;
     if(lvl==2)
     {
        SetVelocity(8, 0);
        Update();
        SetVelocity(0, 0);
     }
     if(lvl==3)
     {
        SetVelocity(8, 0);
        UpdateFrame();
     }
  }
  else if(dir==3)
  {
     if(m_iCurFrame==1)
        m_iCurFrame=2;
     else if(m_iCurFrame==0)
        m_iCurFrame=1;
     else
        m_iCurFrame=0;
     if(lvl==2)
     {
        SetVelocity(0, -8);
        Update();
        SetVelocity(0, 0);
     }
     if(lvl==3)
     {
        SetVelocity(0, -8);
        UpdateFrame();
     }
  }
  else if(dir==4)
  {
     if(m_iCurFrame==10)
        m_iCurFrame=11;
     else if(m_iCurFrame==9)
        m_iCurFrame=10;
     else
        m_iCurFrame=9;
     if(lvl==2)
     {
        SetVelocity(0, 8);
        Update();
        SetVelocity(0, 0);
     }
     if(lvl==3)
     {
        SetVelocity(0, 8);
        UpdateFrame();
     }
  }
}
