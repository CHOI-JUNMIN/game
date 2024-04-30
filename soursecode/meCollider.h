#pragma once
#include "meComponent.h"

namespace me
{
	class Collider : public Component
	{
	public:
		Collider();
		~Collider();

		virtual void Initialize();
		virtual void Update();
		virtual void Lateupdate();
		virtual void Render(HDC hdc);

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

		Vector2 GetOffset() { return mOffset; }
		void SetOffset(Vector2 offset) { mOffset = offset; }
		UINT32 GetID() { return mID; }
		Vector2 Getsize() { return mSize; }
		void SetSize(Vector2 size) { mSize = size; }
	private:
		static UINT32 mCollisionID;
		UINT32 mID;
		Vector2 mOffset;
		Vector2 mSize;
	};
}

