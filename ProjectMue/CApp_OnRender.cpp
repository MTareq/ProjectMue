//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnRender() {
	SDL_Rect Rect;
	Rect.x = 0;
	Rect.y = 0;
	Rect.w = WWIDTH;
	Rect.h = WHEIGHT;

	SDL_FillRect(Surf_Display, &Rect, 0);

	CSurface::OnDraw(Surf_Display, Background, -CCamera::CameraControl.GetX(), -CCamera::CameraControl.GetY()+500);
	CSurface::OnDraw(Surf_Display, Background2, -CCamera::CameraControl.GetX()-900, -CCamera::CameraControl.GetY()+500);
	CSurface::OnDraw(Surf_Display, Background2, (-CCamera::CameraControl.GetX()+900), -CCamera::CameraControl.GetY()+500);
    CSurface::OnDraw(Surf_Display, Background2, (-CCamera::CameraControl.GetX()), -CCamera::CameraControl.GetY()+1100);
	CSurface::OnDraw(Surf_Display, Background2, (-CCamera::CameraControl.GetX()+900), -CCamera::CameraControl.GetY()+1000);
	
	CArea::AreaControl.OnRender(Surf_Display, -CCamera::CameraControl.GetX(), -CCamera::CameraControl.GetY());
	/*if(CCamera::CameraControl.GetX() == 800){
		CCamera::CameraControl.TargetMode = TARGET_MODE_NORMAL;
	
	}*/

    //--------------------------------------------------------------------------
    // Entities
    //--------------------------------------------------------------------------
    for(int i = 0;i < CEntity::EntityList.size();i++) {
        if(!CEntity::EntityList[i]) continue;

		CEntity::EntityList[i]->OnRender(Surf_Display);
    }

	SDL_Flip(Surf_Display);
}

//==============================================================================
