#pragma once

#include "RE/A/AITimer.h"
#include "RE/B/BSAtomic.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/C/CombatState.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class CombatAimController;
	class CombatAreaStandard;
	class CombatBehaviorController;
	class CombatBlackboard;
	class CombatGroup;
	class CombatInventory;
	class CombatTargetSelectorStandard;
	class CombatState;
	class TESCombatStyle;

	class CombatController
	{
	public:
		struct RUNTIME_DATA_SE
		{
#define RUNTIME_DATA_CONTENT_SE                                                                       \
			CombatAimController*                    currentAimController;    /* 68 */                  \
			CombatAimController*                    previousAimController;   /* 70 */                  \
			BSTArray<CombatAreaStandard*>           areas;                   /* 78 */                  \
			CombatAreaStandard*                     currentArea;             /* 90 */                  \
			BSTArray<CombatTargetSelectorStandard*> targetSelectors;         /* 98 */                  \
			CombatTargetSelectorStandard*           currentTargetSelector;   /* B0 */                  \
			CombatTargetSelectorStandard*           previousTargetSelector;  /* B8 */                  \
			std::uint32_t                           handleCount;             /* C0 */                  \
			std::int32_t                            unkC4;                   /* C4 */                  \
			NiPointer<Actor>                        cachedAttacker;          /* C8 - attackerHandle */ \
			NiPointer<Actor>                        cachedTarget;            /* D0 - targetHandle */

			RUNTIME_DATA_CONTENT_SE
		};

		struct RUNTIME_DATA_LATEST
		{
#define RUNTIME_DATA_CONTENT_LATEST                                                  \
			mutable BSSpinLock                      aimControllerLock;       /* 68 */

			RUNTIME_DATA_CONTENT_LATEST
		};

		[[nodiscard]] inline RUNTIME_DATA_SE& GetRuntimeDataSE() noexcept
		{
			return REL::RelocateMemberIfNewer<RUNTIME_DATA_SE>(SKSE::RUNTIME_SSE_1_6_629, this, 0x68, 0x70);
		}

		[[nodiscard]] inline const RUNTIME_DATA_SE& GetRuntimeDataSE() const noexcept
		{
			return REL::RelocateMemberIfNewer<RUNTIME_DATA_SE>(SKSE::RUNTIME_SSE_1_6_629, this, 0x68, 0x70);
		}

		[[nodiscard]] inline RUNTIME_DATA_LATEST* GetRuntimeDataLatest() noexcept
		{
			if SKYRIM_REL_CONSTEXPR (REL::Module::IsAE()) {
				if (REL::Module::get().version().compare(SKSE::RUNTIME_SSE_1_6_629) != std::strong_ordering::less) {
					return REL::RelocateMember<RUNTIME_DATA_LATEST*>(this, 0x68);
				}
			}
			return nullptr;
		}

		[[nodiscard]] inline const RUNTIME_DATA_LATEST* GetRuntimeDataLatest() const noexcept
		{
			if SKYRIM_REL_CONSTEXPR (REL::Module::IsAE()) {
				if (REL::Module::get().version().compare(SKSE::RUNTIME_SSE_1_6_629) != std::strong_ordering::less) {
					return REL::RelocateMember<RUNTIME_DATA_LATEST*>(this, 0x68);
				}
			}
			return nullptr;
		}

		[[nodiscard]] bool IsFleeing() const
		{
			return state->isFleeing;
		}

		// members
		CombatGroup*                            combatGroup;             // 00
		CombatState*                            state;                   // 08
		CombatInventory*                        inventory;               // 10
		CombatBlackboard*                       blackboard;              // 18
		CombatBehaviorController*               behaviorController;      // 20
		ActorHandle                             attackerHandle;          // 28
		ActorHandle                             targetHandle;            // 2C
		ActorHandle                             previousTargetHandle;    // 30
		std::uint8_t                            unk34;                   // 34
		bool                                    startedCombat;           // 35
		std::uint8_t                            unk36;                   // 36
		std::uint8_t                            unk37;                   // 37
		TESCombatStyle*                         combatStyle;             // 38
		bool                                    stoppedCombat;           // 40
		bool                                    unk41;                   // 41 - isbeingMeleeAttacked?
		bool                                    ignoringCombat;          // 42
		bool                                    inactive;                // 43
		AITimer                                 unk44;                   // 44
		float                                   unk4C;                   // 4C
		BSTArray<CombatAimController*>          aimControllers;          // 50

#if defined(ENABLE_SKYRIM_AE)
		RUNTIME_DATA_CONTENT_LATEST;
#endif
		RUNTIME_DATA_CONTENT_SE;
	};
#if !defined(ENABLE_SKYRIM_AE) && defined(ENABLE_SKYRIM_SE)
	static_assert(sizeof(CombatController) == 0xD8);
#else
	static_assert(sizeof(CombatController) == 0xE0);
#endif
}
#undef RUNTIME_DATA_CONTENT_SE
#undef RUNTIME_DATA_CONTENT_LATEST
