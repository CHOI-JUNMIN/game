#pragma once
#include "Component.h"
#include "Animation.h"
namespace me
{
	class Animator : public Component 
	{
	public:
		struct Event
		{
			void operator=(std::function<void()> func)
			{
				mEvent = std::move(func);
			}
			void operator()()
			{
				if (mEvent)
					mEvent;
			}
			std::function<void()> mEvent;
		};
		struct Events
		{
			Event mStartEvent;
			Event mCompleteEvent;
			Event mEndEvent;
		};

		Animator();
		~Animator();

		void Initialize() override;
		void update() override;
		void Lateupdate() override;
		void Render(HDC hdc) override;
			
		void CreateAnimation(const std::wstring& name
			, graphcis::Texture* spriteSheet
			, Vector2 leftTop
			, Vector2 size
			, Vector2 offset
			, UINT spriteLegth
			, float duration);

		Animation* FindAnimation(const std::wstring& name);
		void PlayAnimation(const std::wstring& name, bool loop =true);
		bool IsComplete() { return mActiveAnimation->IsComplete(); }
	private:
		std::map<std::wstring, Animation*> mAnimations;
		Animation* mActiveAnimation;
		bool mbLoop;

		std::map<std::wstring, Events*> mEvents;
	};
}