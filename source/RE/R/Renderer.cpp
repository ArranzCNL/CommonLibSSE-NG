#include "PCH.h"

#include "RE/R/Renderer.h"

namespace RE
{
	namespace BSGraphics
	{
		Renderer* Renderer::GetSingleton() noexcept
		{
			static REL::Relocation<Renderer*> singleton{ RELOCATION_ID(524907, 411393) };
			return singleton.get();
		}

		NiTexture::RendererData* Renderer::CreateRenderTexture(std::uint32_t a_width, std::uint32_t a_height)
		{
			using func_t = decltype(&Renderer::CreateRenderTexture);
			static REL::Relocation<func_t> func{ RELOCATION_ID(75507, 77299) };
			return func(this, a_width, a_height);
		}

		void Renderer::SaveRenderTargetToFile(RENDER_TARGET a_renderTarget, const char* a_filePath, BSGraphics::TextureFileFormat a_textureFileFormat)
		{
			using func_t = decltype(&Renderer::SaveRenderTargetToFile);
			static REL::Relocation<func_t> func{ RELOCATION_ID(75522, 77316) };
			return func(this, a_renderTarget, a_filePath, a_textureFileFormat);
		}

		void Renderer::Init(RendererInitOSData* a_data, ApplicationWindowProperties* windowProps, WinAPI::HWND window)
		{
			using func_t = decltype(&Renderer::Init);
			static REL::Relocation<func_t> func{ RELOCATION_ID(75445, 77226) };
			return func(this, a_data, windowProps, window);
		}

		void Renderer::Begin(std::uint32_t windowID)
		{
			using func_t = decltype(&Renderer::Begin);
			static REL::Relocation<func_t> func{ RELOCATION_ID(75460, 77245) };
			return func(this, windowID);
		}

		void Renderer::CreateSwapChain(WinAPI::HWND* window, bool setCurrent)
		{
			using func_t = decltype(&Renderer::CreateSwapChain);
			static REL::Relocation<func_t> func{ RELOCATION_ID(75457, 77242) };
			return func(this, window, setCurrent);
		}

		void Renderer::End()
		{
			using func_t = decltype(&Renderer::End);
			static REL::Relocation<func_t> func{ RELOCATION_ID(75461, 77246) };
			return func(this);
		}

		void Renderer::KillWindow(std::uint32_t windowID)
		{
			using func_t = decltype(&Renderer::KillWindow);
			static REL::Relocation<func_t> func{ RELOCATION_ID(75452, 77237) };
			return func(this, windowID);
		}

		void Renderer::Lock()
		{
			using func_t = decltype(&Renderer::Lock);
			static REL::Relocation<func_t> func{ RELOCATION_ID(75458, 77243) };
			return func(this);
		}

		void Renderer::Unlock()
		{
			using func_t = decltype(&Renderer::Unlock);
			static REL::Relocation<func_t> func{ RELOCATION_ID(75459, 77244) };
			return func(this);
		}

		void Renderer::ResizeWindow(std::uint32_t windowID, std::uint32_t width, std::uint32_t height, bool fullscreen, bool borderless)
		{
			using func_t = decltype(&Renderer::ResizeWindow);
			static REL::Relocation<func_t> func{ RELOCATION_ID(75454, 77239) };
			return func(this, windowID, width, height, fullscreen, borderless);
		}

		void Renderer::RequestWindowResize(std::uint32_t width, std::uint32_t height)
		{
			using func_t = decltype(&Renderer::RequestWindowResize);
			static REL::Relocation<func_t> func{ RELOCATION_ID(75450, 77235) };
			return func(this, width, height);
		}

		void Renderer::SetWindowPosition(std::uint32_t windowID, std::int32_t x, std::int32_t y)
		{
			using func_t = decltype(&Renderer::SetWindowPosition);
			static REL::Relocation<func_t> func{ RELOCATION_ID(75448, 77233) };
			return func(this, windowID, x, y);
		}

		void Renderer::SetWindowActiveState(bool show)
		{
			using func_t = decltype(&Renderer::SetWindowActiveState);
			static REL::Relocation<func_t> func{ RELOCATION_ID(75451, 77236) };
			return func(this, show);
		}

		void Renderer::WindowSizeChanged(std::uint32_t windowID)
		{
			using func_t = decltype(&Renderer::WindowSizeChanged);
			static REL::Relocation<func_t> func{ RELOCATION_ID(75453, 77238) };
			return func(this, windowID);
		}

		void Renderer::ResetWindow(std::uint32_t windowID)
		{
			using func_t = decltype(&Renderer::ResetWindow);
			static REL::Relocation<func_t> func{ RELOCATION_ID(75454, 77239) };
			return func(this, windowID);
		}

		void Renderer::UpdateViewPort(std::uint32_t a_unk, std::uint32_t b_unk, bool c_unk)
		{
			using func_t = decltype(&Renderer::UpdateViewPort);
			static REL::Relocation<func_t> func{ RELOCATION_ID(75455, 77240) };
			return func(this, a_unk, b_unk, c_unk);
		}

		void Renderer::Shutdown()
		{
			using func_t = decltype(&Renderer::Shutdown);
			static REL::Relocation<func_t> func{ RELOCATION_ID(75447, 77228) };
			return func(this);
		}

		RendererData* Renderer::GetRendererDataSingleton()
		{
			// Location is a global pointer to the RendererData in the Renderer singleton
			static REL::Relocation<RendererData**> singleton{ RELOCATION_ID(524728, 411347) };
			return *singleton;
		}

		ScreenSize Renderer::GetScreenSize()
		{
			// This is a global managed by Renderer, but not part of the RendererData struct.
			// We pass back the value so users are not tempted to modify this directly.
			static REL::Relocation<ScreenSize*> singleton{ RELOCATION_ID(525002, 411483) };
			return *singleton;
		}

		ID3D11Device* Renderer::GetDevice()
		{
			// Location is a global pointer to the device in the Renderer Data
			static REL::Relocation<ID3D11Device**> device{ RELOCATION_ID(524729, 411348) };
			return *device;
		}

		RendererWindow* Renderer::GetCurrentRenderWindow()
		{
			// Location is a global pointer to the current renderWindow (which is not necessarily at index 0 in the renderWindows array)
			static REL::Relocation<RendererWindow**> renderWindow{ RELOCATION_ID(524730, 411349) };
			return *renderWindow;
		}
	}
}
