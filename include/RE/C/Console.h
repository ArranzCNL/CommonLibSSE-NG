#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/I/IMenu.h"
#include "RE/N/NiSmartPointer.h"
#include "SKSE/Version.h"

namespace RE
{
	class TESObjectREFR;

	// menuDepth = 12
	// flags = kPausesGame | kAlwaysOpen | kUsesCursor | kAllowSaving
	// context = kConsole
	class Console : public IMenu
	{
	public:
		inline static constexpr auto      RTTI = RTTI_Console;
		constexpr static std::string_view MENU_NAME = "Console";

		struct RUNTIME_DATA_SE
		{
#define RUNTIME_DATA_CONTENT_SE            \
			void*         opcode;  /* 00 */ \
			std::uint64_t unk38;   /* 08 */ \
			std::uint64_t unk40;   /* 10 */ \
			std::uint64_t unk48;   /* 18 */ \
			std::uint64_t unk50;   /* 20 */

			RUNTIME_DATA_CONTENT_SE
		};
		static_assert(sizeof(RUNTIME_DATA_SE) == 0x28);

		struct RUNTIME_DATA_LATEST
		{
#define RUNTIME_DATA_CONTENT_LATEST                                            \
			void*         opcode;                  /* 00 */                     \
			std::uint64_t unk38;                   /* 08 */                     \
			std::uint64_t unk40;                   /* 10 */                     \
			std::uint32_t unk48;                   /* 48 */                     \
			std::uint8_t  unk4c;                   /* 4c */                     \
			bool          showAchievementWarning;  /* 4d -- only used in ctor*/ \
			bool          ctrlKeyHeld;             /* 4e */                     \
			std::uint8_t  pad4f;                   /* 4f */

			RUNTIME_DATA_CONTENT_LATEST
		};
		static_assert(sizeof(RUNTIME_DATA_LATEST) == 0x20);

		~Console() override;  // 00

		// override (IMenu)
		void               Accept(CallbackProcessor* a_processor) override;  // 01
		UI_MESSAGE_RESULTS ProcessMessage(UIMessage& a_message) override;    // 04

		static NiPointer<TESObjectREFR> GetSelectedRef();
		static ObjectRefHandle          GetSelectedRefHandle();

		void SetSelectedRef(NiPointer<TESObjectREFR> a_refPtr);
		void SetSelectedRef(TESObjectREFR* a_ref);
		void SetSelectedRef(ObjectRefHandle a_handle);

		[[nodiscard]] inline RUNTIME_DATA_SE& GetRuntimeDataSE() noexcept
		{
			return REL::RelocateMember<RUNTIME_DATA_SE>(this, 0x30, 0x40);
		}

		[[nodiscard]] inline const RUNTIME_DATA_SE& GetRuntimeDataSE() const noexcept
		{
			return REL::RelocateMember<RUNTIME_DATA_SE>(this, 0x30, 0x40);
		}

		[[nodiscard]] inline RUNTIME_DATA_LATEST* GetRuntimeDataLatest() noexcept
		{
			if SKYRIM_REL_CONSTEXPR (REL::Module::IsAE()) {
				if (REL::Module::get().version().compare(SKSE::RUNTIME_SSE_1_6_1130) != std::strong_ordering::less) {
					return REL::RelocateMember<RUNTIME_DATA_LATEST*>(this, 0x30);
				}
			}
			return nullptr;
		}

		[[nodiscard]] inline const RUNTIME_DATA_LATEST* GetRuntimeDataLatest() const noexcept
		{
			if SKYRIM_REL_CONSTEXPR (REL::Module::IsAE()) {
				if (REL::Module::get().version().compare(SKSE::RUNTIME_SSE_1_6_1130) != std::strong_ordering::less) {
					return REL::RelocateMember<RUNTIME_DATA_LATEST*>(this, 0x30);
				}
			}
			return nullptr;
		}
		// members
#if defined(ENABLE_SKYRIM_AE)
		RUNTIME_DATA_CONTENT_LATEST
#elif defined(ENABLE_SKYRIM_SE)
		RUNTIME_DATA_CONTENT_SE
#endif

	protected:
		void SetSelectedRef_Impl(ObjectRefHandle& a_handle);
	};
#if defined(ENABLE_SKYRIM_AE)
	static_assert(sizeof(Console) == 0x50);
#elif defined(ENABLE_SKYRIM_SE)
	static_assert(sizeof(Console) == 0x58);
#endif
}
#undef RUNTIME_DATA_CONTENT_SE
#undef RUNTIME_DATA_CONTENT_LATEST
