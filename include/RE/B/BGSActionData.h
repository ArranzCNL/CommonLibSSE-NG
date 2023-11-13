#pragma once

#include "RE/A/ActionInput.h"
#include "RE/A/ActionOutput.h"

namespace RE
{
	class BGSActionData :
		public ActionInput,  // 00
		public ActionOutput  // 28
	{
	public:
		inline static constexpr auto RTTI = RTTI_BGSActionData;
		inline static constexpr auto VTABLE = VTABLE_BGSActionData;

		virtual ~BGSActionData() override;  // 00

		// add
		virtual BGSActionData* Clone() const;  // 04
		virtual bool           Process();      // 05 - { return false; }

		// members 
		BSFixedString AnimationEvent;  // 28
		BSFixedString unk30;           // 30
		std::uint64_t unk38;           // 38
		std::uint64_t unk40;           // 40
		std::uint64_t unk48;           // 48
		TESIdleForm*  IdleForm;        // 50
		std::uint64_t unk58;           // 58
	};
	static_assert(sizeof(BGSActionData) == 0x90);
}
