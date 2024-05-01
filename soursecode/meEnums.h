#pragma once

namespace me :: enums
{
	enum class eComponentType
	{
		Transform,
		Collider,
		Script,
		SpriteRenderer,
		Animator,
		Camera,
		End,
	};


	enum class eLayerType
	{
		None,
		BackGround,
		Tile,
		Animal,
		Player,
		Particle,
		Max=16,
	};

	enum class eResourceType
	{
		Texture,
		AudioClip,
		Animation,
		Prefab,
		End,
	};
	enum class eColliderType
	{
		Circle2D,
		Rect2D,
		End,
	};
}