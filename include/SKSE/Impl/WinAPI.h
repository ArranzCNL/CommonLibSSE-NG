#pragma once

#undef CP_UTF8
#undef FILE_ATTRIBUTE_READONLY
#undef FILE_ATTRIBUTE_HIDDEN
#undef FILE_ATTRIBUTE_SYSTEM
#undef FILE_ATTRIBUTE_DIRECTORY
#undef FILE_ATTRIBUTE_ARCHIVE
#undef IMAGE_SCN_MEM_EXECUTE
#undef IMAGE_SCN_MEM_WRITE
#undef INVALID_HANDLE_VALUE
#undef MAX_PATH
#undef MEM_COMMIT
#undef MEM_RESERVE
#undef MEM_RELEASE
#undef PAGE_EXECUTE_READWRITE
#undef HKEY_LOCAL_MACHINE

#undef GetEnvironmentVariable
#undef GetFileVersionInfoSize
#undef GetModuleFileName
#undef VerQueryValue
#undef GetFileVersionInfo
#undef GetModuleHandle
#undef LoadLibrary
#undef MessageBox
#undef OutputDebugString

namespace SKSE::WinAPI
{
	inline constexpr auto CP_UTF8{ 65001u };
	inline constexpr auto FILE_ATTRIBUTE_READONLY{ 0x00000001u };
	inline constexpr auto FILE_ATTRIBUTE_HIDDEN{ 0x00000002u };
	inline constexpr auto FILE_ATTRIBUTE_SYSTEM{ 0x00000004u };
	inline constexpr auto FILE_ATTRIBUTE_DIRECTORY{ 0x00000010u };
	inline constexpr auto FILE_ATTRIBUTE_ARCHIVE{ 0x00000020u };
	inline constexpr auto IMAGE_SCN_MEM_EXECUTE{ 0x20000000u };
	inline constexpr auto IMAGE_SCN_MEM_WRITE{ 0x80000000u };
	inline const auto     INVALID_HANDLE_VALUE{ reinterpret_cast<void*>(static_cast<std::intptr_t>(-1)) };
	inline constexpr auto MAX_PATH{ 260u };
	inline constexpr auto MEM_COMMIT{ 0x00001000u };
	inline constexpr auto MEM_RESERVE{ 0x00002000u };
	inline constexpr auto MEM_RELEASE{ 0x00008000u };
	inline constexpr auto PAGE_EXECUTE_READWRITE{ 0x40u };

	struct CRITICAL_SECTION
	{
	public:
		// members
		void*          DebugInfo;       // 00
		std::int32_t   LockCount;       // 08
		std::int32_t   RecursionCount;  // 0C
		void*          OwningThread;    // 10
		void*          LockSemaphore;   // 18
		std::uint64_t* SpinCount;       // 20
	};
	static_assert(sizeof(CRITICAL_SECTION) == 0x28);

	struct _FILETIME
	{
	public:
		// members
		std::uint32_t dwLowDateTime;   // 00
		std::uint32_t dwHighDateTime;  // 04
	};
	static_assert(sizeof(_FILETIME) == 0x8);
	using FILETIME = _FILETIME;

	struct _GUID
	{
		std::uint32_t Data1;
		std::uint16_t Data2;
		std::uint16_t Data3;
		std::uint8_t  Data4[8];
	};
	static_assert(sizeof(_GUID) == 0x10);
	using GUID = _GUID;

	struct HWND__;
	using HWND = HWND__*;

	struct HINSTANCE__;
	using HINSTANCE = HINSTANCE__*;
	using HMODULE = HINSTANCE;

	struct HKEY__;
	using HKEY = HKEY__*;

	inline auto HKEY_LOCAL_MACHINE = reinterpret_cast<HKEY>(static_cast<uintptr_t>(0x80000002));

	struct _WIN32_FIND_DATAA
	{
	public:
		// members
		std::uint32_t dwFileAttributes;
		FILETIME      ftCreationTime;
		FILETIME      ftLastAccessTime;
		FILETIME      ftLastWriteTime;
		std::uint32_t nFileSizeHigh;
		std::uint32_t nFileSizeLow;
		std::uint32_t dwReserved0;
		std::uint32_t dwReserved1;
		char          cFileName[MAX_PATH];
		char          cAlternateFileName[14];
	};
	static_assert(sizeof(_WIN32_FIND_DATAA) == 0x140);
	using WIN32_FIND_DATAA = _WIN32_FIND_DATAA;

	struct _WIN32_FIND_DATAW
	{
	public:
		// members
		std::uint32_t dwFileAttributes;
		FILETIME      ftCreationTime;
		FILETIME      ftLastAccessTime;
		FILETIME      ftLastWriteTime;
		std::uint32_t nFileSizeHigh;
		std::uint32_t nFileSizeLow;
		std::uint32_t dwReserved0;
		std::uint32_t dwReserved1;
		wchar_t       cFileName[MAX_PATH];
		wchar_t       cAlternateFileName[14];
	};
	static_assert(sizeof(_WIN32_FIND_DATAW) == 0x250);
	using WIN32_FIND_DATAW = _WIN32_FIND_DATAW;

	struct tagRECT
	{
		std::int32_t left;
		std::int32_t top;
		std::int32_t right;
		std::int32_t bottom;
	};
	using RECT = tagRECT;

	struct tagPOINT
	{
		std::int32_t x;
		std::int32_t y;
	};
	using POINT = tagPOINT;

	using HRESULT = std::int32_t;

	[[nodiscard]] bool FindClose(void* a_findFile) noexcept;

	[[nodiscard]] void* FindFirstFile(
		const char*       a_fileName,
		WIN32_FIND_DATAA* a_findFileData) noexcept;

	[[nodiscard]] void* FindFirstFile(
		const wchar_t*    a_fileName,
		WIN32_FIND_DATAW* a_findFileData) noexcept;

	[[nodiscard]] bool FindNextFile(
		void*             a_findFile,
		WIN32_FIND_DATAA* a_findFileData) noexcept;

	[[nodiscard]] bool FindNextFile(
		void*             a_findFile,
		WIN32_FIND_DATAW* a_findFileData) noexcept;

	bool FreeLibrary(HMODULE a_module) noexcept;

	[[nodiscard]] void* GetCurrentModule() noexcept;

	[[nodiscard]] void* GetCurrentProcess() noexcept;

	[[nodiscard]] std::uint32_t GetCurrentThreadID() noexcept;

	[[nodiscard]] std::uint32_t GetEnvironmentVariable(
		const char*   a_name,
		char*         a_buffer,
		std::uint32_t a_size) noexcept;

	[[nodiscard]] std::uint32_t GetEnvironmentVariable(
		const wchar_t* a_name,
		wchar_t*       a_buffer,
		std::uint32_t  a_size) noexcept;

	[[nodiscard]] bool GetFileVersionInfo(
		const char*   a_filename,
		std::uint32_t a_handle,
		std::uint32_t a_len,
		void*         a_data) noexcept;

	[[nodiscard]] bool GetFileVersionInfo(
		const wchar_t* a_filename,
		std::uint32_t  a_handle,
		std::uint32_t  a_len,
		void*          a_data) noexcept;

	[[nodiscard]] std::uint32_t GetFileVersionInfoSize(
		const char*    a_filename,
		std::uint32_t* a_handle) noexcept;

	[[nodiscard]] std::uint32_t GetFileVersionInfoSize(
		const wchar_t* a_filename,
		std::uint32_t* a_handle) noexcept;

	[[nodiscard]] int GetKeyNameText(
		std::int32_t a_lParam,
		char*        a_buffer,
		int          a_size) noexcept;

	[[nodiscard]] int GetKeyNameText(
		std::int32_t a_lParam,
		wchar_t*     a_buffer,
		int          a_size) noexcept;

	[[nodiscard]] std::int16_t GetKeyState(int nVirtKey) noexcept;

	[[nodiscard]] std::size_t GetMaxPath() noexcept;

	[[nodiscard]] std::uint32_t GetModuleFileName(
		void*         a_module,
		char*         a_filename,
		std::uint32_t a_size) noexcept;

	[[nodiscard]] std::uint32_t GetModuleFileName(
		void*         a_module,
		wchar_t*      a_filename,
		std::uint32_t a_size) noexcept;

	[[nodiscard]] HMODULE GetModuleHandle(const char* a_moduleName) noexcept;

	[[nodiscard]] HMODULE GetModuleHandle(const wchar_t* a_moduleName) noexcept;

	[[nodiscard]] std::uint32_t GetPrivateProfileString(
		const char*   a_appName,
		const char*   a_keyName,
		const char*   a_default,
		char*         a_outString,
		std::uint32_t a_size,
		const char*   a_fileName) noexcept;

	[[nodiscard]] std::uint32_t GetPrivateProfileString(
		const wchar_t* a_appName,
		const wchar_t* a_keyName,
		const wchar_t* a_default,
		wchar_t*       a_outString,
		std::uint32_t  a_size,
		const wchar_t* a_fileName) noexcept;

	[[nodiscard]] void* GetProcAddress(
		void*       a_module,
		const char* a_procName) noexcept;

	[[nodiscard]] bool IsDebuggerPresent() noexcept;

	[[nodiscard]] HMODULE LoadLibrary(const char* a_libFileName) noexcept;

	[[nodiscard]] HMODULE LoadLibrary(const wchar_t* a_libFileName) noexcept;

	std::int32_t MessageBox(
		void*        a_wnd,
		const char*  a_text,
		const char*  a_caption,
		unsigned int a_type) noexcept;

	std::int32_t MessageBox(
		void*          a_wnd,
		const wchar_t* a_text,
		const wchar_t* a_caption,
		unsigned int   a_type) noexcept;

	[[nodiscard]] int MultiByteToWideChar(
		unsigned int  a_codePage,
		std::uint32_t a_flags,
		const char*   a_multiByteStr,
		int           a_multiByte,
		wchar_t*      a_wideCharStr,
		int           a_wideChar);

	void OutputDebugString(
		const char* a_outputString) noexcept;

	void OutputDebugString(
		const wchar_t* a_outputString) noexcept;

	long RegGetValueW(HKEY hkey, const char* subKey, const char* value, unsigned long flags, unsigned long* type,
		void* data, unsigned long* length);

	long RegGetValueW(HKEY hkey, const wchar_t* subKey, const wchar_t* value, unsigned long flags, unsigned long* type,
		void* data, unsigned long* length);

	[[nodiscard]] int ShowCursor(bool bShow) noexcept;

	[[noreturn]] void TerminateProcess(
		void*        a_process,
		unsigned int a_exitCode) noexcept;

	[[nodiscard]] void* TlsGetValue(std::uint32_t a_tlsIndex) noexcept;

	bool TlsSetValue(
		std::uint32_t a_tlsIndex,
		void*         a_tlsValue) noexcept;

	bool VirtualFree(
		void*         a_address,
		std::size_t   a_size,
		std::uint32_t a_freeType) noexcept;

	[[nodiscard]] bool VerQueryValue(
		const void*   a_block,
		const char*   a_subBlock,
		void**        a_buffer,
		unsigned int* a_len) noexcept;

	[[nodiscard]] bool VerQueryValue(
		const void*    a_block,
		const wchar_t* a_subBlock,
		void**         a_buffer,
		unsigned int*  a_len) noexcept;

	[[nodiscard]] bool VirtualProtect(
		void*          a_address,
		std::size_t    a_size,
		std::uint32_t  a_newProtect,
		std::uint32_t* a_oldProtect) noexcept;

	[[nodiscard]] int WideCharToMultiByte(
		unsigned int   a_codePage,
		std::uint32_t  a_flags,
		const wchar_t* a_wideCharStr,
		int            a_wideChar,
		char*          a_multiByteStr,
		int            a_multiByte,
		const char*    a_defaultChar,
		int*           a_usedDefaultChar);
}

namespace RE::ClibUtil
{
	struct Vector4
	{
	public:
		// members
		float f32[4];
	};
	static_assert(sizeof(Vector4) == 0x10);

	struct Matrix
	{
	public:
		// members
		float f32[4][4];
	};
	static_assert(sizeof(Matrix) == 0x40);
}

#define CP_UTF8 ::SKSE::WinAPI::CP_UTF8
#define FILE_ATTRIBUTE_READONLY ::SKSE::WinAPI::FILE_ATTRIBUTE_READONLY
#define FILE_ATTRIBUTE_HIDDEN ::SKSE::WinAPI::FILE_ATTRIBUTE_HIDDEN
#define FILE_ATTRIBUTE_SYSTEM ::SKSE::WinAPI::FILE_ATTRIBUTE_SYSTEM
#define FILE_ATTRIBUTE_DIRECTORY ::SKSE::WinAPI::FILE_ATTRIBUTE_DIRECTORY
#define FILE_ATTRIBUTE_ARCHIVE ::SKSE::WinAPI::FILE_ATTRIBUTE_ARCHIVE
#define IMAGE_SCN_MEM_EXECUTE ::SKSE::WinAPI::IMAGE_SCN_MEM_EXECUTE
#define IMAGE_SCN_MEM_WRITE ::SKSE::WinAPI::IMAGE_SCN_MEM_WRITE
#define INVALID_HANDLE_VALUE ::SKSE::WinAPI::INVALID_HANDLE_VALUE
#define MAX_PATH ::SKSE::WinAPI::MAX_PATH
#define MEM_COMMIT ::SKSE::WinAPI::MEM_COMMIT
#define MEM_RESERVE ::SKSE::WinAPI::MEM_RESERVE
#define MEM_RELEASE ::SKSE::WinAPI::MEM_RELEASE
#define PAGE_EXECUTE_READWRITE ::SKSE::WinAPI::PAGE_EXECUTE_READWRITE
#define HKEY_LOCAL_MACHINE ::SKSE::WinAPI::HKEY_LOCAL_MACHINE

#define GetEnvironmentVariable ::SKSE::WinAPI::GetEnvironmentVariable
#define GetFileVersionInfoSize ::SKSE::WinAPI::GetFileVersionInfoSize
#define GetModuleFileName ::SKSE::WinAPI::GetModuleFileName
#define VerQueryValue ::SKSE::WinAPI::VerQueryValue
#define GetFileVersionInfo ::SKSE::WinAPI::GetFileVersionInfo
#define GetModuleHandle ::SKSE::WinAPI::GetModuleHandle
#define LoadLibrary ::SKSE::WinAPI::LoadLibrary
#define MessageBox ::SKSE::WinAPI::MessageBox
#define OutputDebugString ::SKSE::WinAPI::OutputDebugString
