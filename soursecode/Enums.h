#pragma once


namespace me :: enums
{
	enum class eComponentType
	{
		Transform,
		SpriteRenderer,
		Animator,
		Script,
		Camera,
		End,
	};


	enum class eLayerType
	{
		None,
		BackGround,
		Player,
		Particle,
		Animal,
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
}