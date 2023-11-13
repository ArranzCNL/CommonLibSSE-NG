#pragma once

#include "RE/B/BSSoundHandle.h"
#include "RE/N/NiMatrix3.h"
#include "RE/N/NiSmartPointer.h"
#include "RE/T/ThirdPersonState.h"

namespace RE
{
	class NiAVObject;

	class BleedoutCameraState : 
		public ThirdPersonState
	{
	public:
		inline static constexpr auto RTTI = RTTI_BleedoutCameraState;
		inline static constexpr auto VTABLE = VTABLE_BleedoutCameraState;

		~BleedoutCameraState() override;  // 00

		// override (ThirdPersonState)
		void Begin() override;                                               // 01
		void End() override;                                                 // 02
		void Update(BSTSmartPointer<TESCameraState>& a_nextState) override;  // 03
		void GetRotation(NiQuaternion& a_rotation) override;                 // 04
		void GetTranslation(NiPoint3& a_translation) override;               // 05
		void SaveGame(BGSSaveFormBuffer* a_buf) override;                    // 06
		void LoadGame(BGSLoadFormBuffer* a_buf) override;                    // 07
		void Revert(BGSLoadFormBuffer* a_buf) override;                      // 08
		void SetCameraHandle(RefHandle& a_handle) override;                  // 09 - { return; }
		void Unk_0A(void) override;                                          // 0A - { return; }
		void ProcessWeaponDrawnChange(bool a_drawn) override;                // 0B
		bool GetFreeRotationMode() const override;                           // 0C
		void SetFreeRotationMode(bool a_weaponSheathed) override;            // 0D
		void HandleLookInput(const NiPoint2& a_input) override;              // 0F

		// override (PlayerInputHandler)
		bool CanProcess(InputEvent* a_event) override;                                          // 01
		void ProcessButton(ButtonEvent* a_event, PlayerControlsData* a_movementData) override;  // 04

		// members
		NiMatrix3             rotationMtx;        // 0E8
		float                 zoom;               // 10C
		float                 pitch;              // 110
		float                 yaw;                // 114
		float                 randHeading;        // 118
		std::uint32_t         pad11C;             // 11C
		NiPointer<NiAVObject> animatedBone;       // 120
		BSSoundHandle         activeSound;        // 128
		bool                  useCurrentHeading;  // 134
		std::uint8_t          pad135;             // 135
		std::uint16_t         pad136;             // 136
	};
	static_assert(sizeof(BleedoutCameraState) == 0x138);
}
