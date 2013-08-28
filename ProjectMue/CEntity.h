//==============================================================================
#ifndef _CENTITY_H_
    #define _CENTITY_H_

#include <vector>
#include <SDL.h>

#include "CArea.h"
#include "CAnimation.h"
#include "CCamera.h"
#include "CFPS.h"
#include "CSurface.h"
#include <cstdlib>
#include <ctime>

//==============================================================================
enum {
	ENTITY_TYPE_GENERIC = 0,

	ENTITY_TYPE_PLAYER,

	ENTITY_TYPE_AI,

	ENTITY_TYPE_PROJECTILE

};

enum {
	ENTITY_STAT_IDLE = 0,
	ENTITY_STAT_MOVING,
	ENTITY_STAT_HIT,
	ENTITY_STAT_ATTACKING,
	ENTITY_STAT_BLOCKING

};

//==============================================================================
enum {
	ENTITY_FLAG_NONE 	= 0,

	ENTITY_FLAG_GRAVITY	= 0x00000001,
	ENTITY_FLAG_GHOST	= 0x00000002,
	ENTITY_FLAG_MAPONLY	= 0x00000004
};

//==============================================================================
class CEntity {
	public:
		static std::vector<CEntity*>    EntityList;

	protected:
		CAnimation      Anim_Control;

		SDL_Surface*    Surf_Entity;

	public:
		float	X;
		float	Y;

		int		Width;
		int		Height;

		bool	MoveLeft;
		bool	MoveRight;

	public:
		int		Type;
		int		Stat; //Defines the animation state..!!

		bool	Dead;
		int		Flags;

	protected:
		float	SpeedX;
		float	SpeedY;

		float	AccelX;
		float	AccelY;

		bool	CanJump;

	public:
		float	MaxSpeedX;
		float	MaxSpeedY;

	protected:
		int		CurrentFrameCol;
		int		CurrentFrameRow;

	protected:
		int		Col_X;
		int		Col_Y;
		int		Col_Width;
		int		Col_Height;

	public:
		CEntity();

		virtual ~CEntity();

	public:
		virtual bool OnLoad(char* File, int Width, int Height, int MaxFrames);

		virtual void OnLoop();

		/*virtual void Spawn();*/

		virtual void OnRender(SDL_Surface* Surf_Display);

		virtual void OnCleanup();

		virtual void OnAnimate();

		virtual bool OnCollision(CEntity* Entity);

	public:
		void    OnMove(float MoveX, float MoveY);

		bool 	Jump();

		void 	StopMove();

	public:
		bool    Collides(int oX, int oY, int oW, int oH);

	private:
		bool 	PosValid(int NewX, int NewY);

		bool 	PosValidTile(CTile* Tile);

		bool 	PosValidEntity(CEntity* Entity, int NewX, int NewY);
};

//==============================================================================
class CEntityCol {
    public:
        static std::vector<CEntityCol>	EntityColList;

	public:
		CEntity* EntityA;
		CEntity* EntityB;

	public:
		CEntityCol();
};

//==============================================================================

#endif
