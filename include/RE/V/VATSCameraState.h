#pragma once

#include "RE/T/TESCameraState.h"

namespace RE
{
	class VATSCameraState :
		public TESCameraState  // 00
	{
	public:
		inline static constexpr auto RTTI = RTTI_VATSCameraState;
		inline static constexpr auto VTABLE = VTABLE_VATSCameraState;

		~VATSCameraState() override;  // 00

		// override (TESCameraState)
		void Begin() override;                                               // 01
		void End() override;                                                 // 02
		void Update(BSTSmartPointer<TESCameraState>& a_nextState) override;  // 03
		void GetRotation(NiQuaternion& a_rotation) override;                 // 04
		void GetTranslation(NiPoint3& a_translation) override;               // 05
		void SaveGame(BGSSaveFormBuffer* a_buf) override;                    // 06
		void LoadGame(BGSLoadFormBuffer* a_buf) override;                    // 07
		void Revert(BGSLoadFormBuffer* a_buf) override;                      // 08
	};

}
