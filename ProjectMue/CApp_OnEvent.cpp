//==============================================================================
#include "CApp.h"

//==============================================================================
void CApp::OnEvent(SDL_Event* Event) {
    CEvent::OnEvent(Event);
}

//==============================================================================
void CApp::OnKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
	switch(sym) {
		case SDLK_LEFT: {
			Player.MoveLeft = true;
			Player.Stat =	ENTITY_STAT_MOVING;
			break;
		}

		case SDLK_RIGHT: {
			Player.MoveRight = true;
			Player.Stat =	ENTITY_STAT_MOVING;
			break;
		}

		case SDLK_SPACE: {
		    Player.Stat =	ENTITY_STAT_ATTACKING;
		    break;
		}

		default: {
		}
	}
}

//------------------------------------------------------------------------------
void CApp::OnKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
	switch(sym) {
		case SDLK_LEFT: {
			Player.MoveLeft = false;
			
			break;
		}

		case SDLK_RIGHT: {
			Player.MoveRight = false;
			
			
			break;
		}

		default: {
		}
	}
	Player.Stat =	ENTITY_STAT_IDLE;
	
}

//------------------------------------------------------------------------------
void CApp::OnExit() {
	Running = false;
}

//==============================================================================
