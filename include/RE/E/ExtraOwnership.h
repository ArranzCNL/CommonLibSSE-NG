#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class TESForm;

	class ExtraOwnership : public BSExtraData
	{
	public:
		inline static constexpr auto RTTI = RTTI_ExtraOwnership;
		inline static constexpr auto VTABLE = VTABLE_ExtraOwnership;
		inline static constexpr auto EXTRADATATYPE = ExtraDataType::kOwnership;

		ExtraOwnership();
		explicit ExtraOwnership(TESForm* a_owner);
		~ExtraOwnership() override = default;  // 00

		// override (BSExtraData)
		ExtraDataType GetType() const override;                             // 01 - { return kOwnership; }
		bool          IsNotEqual(const BSExtraData* a_rhs) const override;  // 02 - { return owner != a_rhs->owner; }

		// members
		TESForm* owner;  // 10
	};
	static_assert(sizeof(ExtraOwnership) == 0x18);
}
