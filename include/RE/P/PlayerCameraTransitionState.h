#pragma once

#include "RE/T/TESCameraState.h"

namespace RE
{
	class PlayerCameraTransitionState :
		public TESCameraState
	{
	public:
		inline static constexpr auto RTTI = RTTI_PlayerCameraTransitionState;
		inline static constexpr auto VTABLE = VTABLE_PlayerCameraTransitionState;

		~PlayerCameraTransitionState() override;  // 00

		// override (TESCameraState)
		void Begin() override;                                               // 01
		void End() override;                                                 // 02
		void Update(BSTSmartPointer<TESCameraState>& a_nextState) override;  // 03
		void GetRotation(NiQuaternion& a_rotation) override;                 // 04
		void GetTranslation(NiPoint3& a_translation) override;               // 05
		void SaveGame(BGSSaveFormBuffer* a_buf) override;                    // 06
		void LoadGame(BGSLoadFormBuffer* a_buf) override;                    // 07
		void Revert(BGSLoadFormBuffer* a_buf) override;                      // 08

		// members
		std::uint64_t   unk20;           // 20
		TESCameraState* transitionFrom;  // 28
		TESCameraState* transitionTo;    // 30
		std::uint16_t   unk38;           // 38
	};
	static_assert(sizeof(PlayerCameraTransitionState) == 0x40);
}
