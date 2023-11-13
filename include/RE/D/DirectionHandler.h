#pragma once

#include "RE/M/MenuEventHandler.h"

namespace RE
{
	struct DirectionHandler : public MenuEventHandler
	{
	public:
		inline static constexpr auto RTTI = RTTI_DirectionHandler;

		~DirectionHandler() override;  // 00

		// override
		bool CanProcess(InputEvent* a_event) override;      // 01 
		bool ProcessKinect(KinectEvent* a_event) override;  // 02
		bool ProcessButton(ButtonEvent* a_event) override;  // 05

		char unk10[32];
	};
	static_assert(sizeof(DirectionHandler) == 0x30);
}
