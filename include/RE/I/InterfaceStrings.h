#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	class InterfaceStrings : public BSTSingletonSDM<InterfaceStrings>
	{
	public:
		static InterfaceStrings* GetSingleton();

		struct RUNTIME_DATA_SE
		{
#define RUNTIME_DATA_CONTENT_SE                                                                                                               \
			BSFixedString titleSequenceMenu;        /* 1A0 - "TitleSequence Menu" */                                                           \
			BSFixedString consoleNativeUIMenu;      /* 1A8 - "Console Native UI Menu" */                                                       \
			BSFixedString kinectMenu;               /* 1B0 - "Kinect Menu" */                                                                  \
			BSFixedString loadWaitSpinner;          /* 1B8 - "LoadWaitSpinner" */                                                              \
			BSFixedString streamingInstallMenu;     /* 1C0 - "StreamingInstallMenu" */                                                         \
			BSFixedString textWidget;               /* 1C8 - "TextWidget" */                                                                   \
			BSFixedString buttonBarWidget;          /* 1D0 - "ButtonBarWidget" */                                                              \
			BSFixedString graphWidget;              /* 1D8 - "GraphWidget" */                                                                  \
			BSFixedString textureWidget;            /* 1E0 - "TextureWidget" */                                                                \
			BSFixedString uiMenuOK;                 /* 1E8 - "UIMenuOK" */                                                                     \
			BSFixedString uiMenuCancel;             /* 1F0 - "UIMenuCancel" */                                                                 \
			BSFixedString showText;                 /* 1F8 - "Show Text" */                                                                    \
			BSFixedString hideText;                 /* 200 - "Hide Text" */                                                                    \
			BSFixedString showList;                 /* 208 - "Show List" */                                                                    \
			BSFixedString voiceReady;               /* 210 - "Voice Ready" */                                                                  \
			BSFixedString dmfoStr;                  /* 218 - "DMFOStr" */                                                                      \
			BSFixedString showJournal;              /* 220 - "Show Journal" */                                                                 \
			BSFixedString journalSettingsSaved;     /* 228 - "Journal Settings Saved" */                                                       \
			BSFixedString closeMenu;                /* 230 - "CloseMenu" */                                                                    \
			BSFixedString closingAllMenus;          /* 238 - "Closing All Menus" */                                                            \
			BSFixedString refreshMenu;              /* 240 - "RefreshMenu" */                                                                  \
			BSFixedString cancelLoading;            /* 248 - "CancelLoading" */                                                                \
			BSFixedString menuTextureDegradeEvent;  /* 250 - "Menu Texture Degrade Event" */                                                   \
			BSFixedString diamondMarker;            /* 258 - "<img src='DiamondMarker' width='10' height='15' align='baseline' vspace='5'>" */

			RUNTIME_DATA_CONTENT_SE
		};

		struct RUNTIME_DATA_LATEST
		{
#define RUNTIME_DATA_CONTENT_LATEST                                                                                                          \
			BSFixedString loginMenu;               /* 1A0 - "Login Menu" - 1.6.1130 */                                                        \
			BSFixedString marketplaceMenu;         /* 1A8 - "Marketplace Menu" - 1.6.629 */                                                   \
			BSFixedString titleSequenceMenu;       /* 1B0 - "TitleSequence Menu" */                                                           \
			BSFixedString consoleNativeUIMenu;     /* 1B8 - "Console Native UI Menu" */                                                       \
			BSFixedString kinectMenu;              /* 1C0 - "Kinect Menu" */                                                                  \
			BSFixedString loadWaitSpinner;         /* 1C8 - "LoadWaitSpinner" */                                                              \
			BSFixedString streamingInstallMenu;    /* 1D0 - "StreamingInstallMenu" */                                                         \
			BSFixedString textWidget;              /* 1D8 - "TextWidget" */                                                                   \
			BSFixedString buttonBarWidget;         /* 1E0 - "ButtonBarWidget" */                                                              \
			BSFixedString graphWidget;             /* 1E8 - "GraphWidget" */                                                                  \
			BSFixedString textureWidget;           /* 1F0 - "TextureWidget" */                                                                \
			BSFixedString uiMenuOK;                /* 1F8 - "UIMenuOK" */                                                                     \
			BSFixedString uiMenuCancel;            /* 200 - "UIMenuCancel" */                                                                 \
			BSFixedString showText;                /* 208 - "Show Text" */                                                                    \
			BSFixedString hideText;                /* 210 - "Hide Text" */                                                                    \
			BSFixedString showList;                /* 218 - "Show List" */                                                                    \
			BSFixedString voiceReady;              /* 220 - "Voice Ready" */                                                                  \
			BSFixedString dmfoStr;                 /* 228 - "DMFOStr" */                                                                      \
			BSFixedString showJournal;             /* 230 - "Show Journal" */                                                                 \
			BSFixedString journalSettingsSaved;    /* 238 - "Journal Settings Saved" */                                                       \
			BSFixedString closeMenu;               /* 240 - "CloseMenu" */                                                                    \
			BSFixedString closingAllMenus;         /* 248 - "Closing All Menus" */                                                            \
			BSFixedString refreshMenu;             /* 250 - "RefreshMenu" */                                                                  \
			BSFixedString cancelLoading;           /* 258 - "CancelLoading" */                                                                \
			BSFixedString userSettingsLoaded;      /* 260 - "UserSettingsLoaded" - v1.6.629 */                                                \
			BSFixedString activityStarted;         /* 268 - "activityStarted" - v1.6.629 */                                                   \
			BSFixedString menuTextureDegradeEvent; /* 270 - "Menu Texture Degrade Event" */                                                   \
			BSFixedString diamondMarker;           /* 278 - "<img src='DiamondMarker' width='10' height='15' align='baseline' vspace='5'>" */

			RUNTIME_DATA_CONTENT_LATEST
		};

		[[nodiscard]] inline RUNTIME_DATA_SE& GetRuntimeDataSE() noexcept
		{
			return REL::RelocateMember<RUNTIME_DATA_SE>(this, 0x1A0, 0x1A0);
		}

		[[nodiscard]] inline const RUNTIME_DATA_SE& GetRuntimeDataSE() const noexcept
		{
			return REL::RelocateMember<RUNTIME_DATA_SE>(this, 0x1A0, 0x1A0);
		}

		[[nodiscard]] inline RUNTIME_DATA_LATEST& GetRuntimeDataLatest() noexcept
		{
			return REL::RelocateMember<RUNTIME_DATA_LATEST>(this, 0x1A0, 0x1A0);
		}

		[[nodiscard]] inline const RUNTIME_DATA_LATEST& GetRuntimeDataLatest() const noexcept
		{
			return REL::RelocateMember<RUNTIME_DATA_LATEST>(this, 0x1A0, 0x1A0);
		}

		// members
		std::uint8_t  pad001;                   // 001
		std::uint16_t pad002;                   // 002
		std::uint32_t pad004;                   // 004
		BSFixedString faderData;                // 008 - "FaderData"
		BSFixedString hudData;                  // 010 - "HUDData"
		BSFixedString hudCamData;               // 018 - "HUDCamData"
		BSFixedString floatingQuestMarkers;     // 020 - "FloatingQuestMarkers"
		BSFixedString consoleData;              // 028 - "ConsoleData"
		BSFixedString quantityData;             // 030 - "QuantityData"
		BSFixedString messageBoxData;           // 038 - "MessageBoxData"
		BSFixedString bsUIScaleformData;        // 040 - "BSUIScaleformData"
		BSFixedString bsUIMessageData;          // 048 - "BSUIMessageData"
		BSFixedString bsUIAnalogData;           // 050 - "BSUIAnalogData"
		BSFixedString inventoryUpdateData;      // 058 - "InventoryUpdateData"
		BSFixedString refHandleUIData;          // 060 - "RefHandleUIData"
		BSFixedString tesFormUIData;            // 068 - "TESFormUIData"
		BSFixedString loadingMenuData;          // 070 - "LoadingMenuData"
		BSFixedString kinectStateData;          // 078 - "KinectStateChangeData"
		BSFixedString kinectUserEventData;      // 080 - "KinectUserEventData"
		BSFixedString inventoryMenu;            // 088 - "InventoryMenu"
		BSFixedString console;                  // 090 - "Console"
		BSFixedString dialogueMenu;             // 098 - "Dialogue Menu"
		BSFixedString hudMenu;                  // 0A0 - "HUD Menu"
		BSFixedString mainMenu;                 // 0A8 - "Main Menu"
		BSFixedString messageBoxMenu;           // 0B0 - "MessageBoxMenu"
		BSFixedString cursorMenu;               // 0B8 - "Cursor Menu"
		BSFixedString faderMenu;                // 0C0 - "Fader Menu"
		BSFixedString magicMenu;                // 0C8 - "MagicMenu"
		BSFixedString topMenu;                  // 0D0 - "Top Menu"
		BSFixedString overlayMenu;              // 0D8 - "Overlay Menu"
		BSFixedString overlayInteractionMenu;   // 0E0 - "Overlay Interaction Menu"
		BSFixedString loadingMenu;              // 0E8 - "Loading Menu"
		BSFixedString tweenMenu;                // 0F0 - "TweenMenu"
		BSFixedString barterMenu;               // 0F8 - "BarterMenu"
		BSFixedString giftMenu;                 // 100 - "GiftMenu"
		BSFixedString debugTextMenu;            // 108 - "Debug Text Menu"
		BSFixedString mapMenu;                  // 110 - "MapMenu"
		BSFixedString lockpickingMenu;          // 118 - "Lockpicking Menu"
		BSFixedString quantityMenu;             // 120 - "Quantity Menu"
		BSFixedString statsMenu;                // 128 - "StatsMenu"
		BSFixedString containerMenu;            // 130 - "ContainerMenu"
		BSFixedString sleepWaitMenu;            // 138 - "Sleep/Wait Menu"
		BSFixedString levelUpMenu;              // 140 - "LevelUp Menu"
		BSFixedString journalMenu;              // 148 - "Journal Menu"
		BSFixedString bookMenu;                 // 150 - "Book Menu"
		BSFixedString favoritesMenu;            // 158 - "FavoritesMenu"
		BSFixedString raceSexMenu;              // 160 - "RaceSex Menu"
		BSFixedString craftingMenu;             // 168 - "Crafting Menu"
		BSFixedString trainingMenu;             // 170 - "Training Menu"
		BSFixedString mistMenu;                 // 178 - "Mist Menu"
		BSFixedString tutorialMenu;             // 180 - "Tutorial Menu"
		BSFixedString creditsMenu;              // 188 - "Credits Menu"
		BSFixedString modManagerMenu;           // 190 - "Mod Manager Menu"
		BSFixedString creationClubMenu;         // 198 - "Creation Club Menu"

#if !defined(ENABLE_SKYRIM_AE) && defined(ENABLE_SKYRIM_SE)
		RUNTIME_DATA_CONTENT_SE;
#else
		RUNTIME_DATA_CONTENT_LATEST;
#endif
	};

#if !defined(ENABLE_SKYRIM_AE) && defined(ENABLE_SKYRIM_SE)
	static_assert(sizeof(InterfaceStrings) == 0x260);
#else
	static_assert(sizeof(InterfaceStrings) == 0x280);
#endif
}
#undef RUNTIME_DATA_CONTENT_SE
#undef RUNTIME_DATA_CONTENT_LATEST
