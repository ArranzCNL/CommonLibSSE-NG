#include "PCH.h"

#include "RE/B/BSSoundHandle.h"

#include "RE/N/NiPoint3.h"

namespace RE
{
	BSSoundHandle::BSSoundHandle() :
		soundID(kInvalidID),
		assumeSuccess(false),
		pad05(0),
		pad06(0),
		state(AssumedState::kInitialized)
	{}

	bool BSSoundHandle::FadeInPlay(std::uint16_t a_fadeTimeMS)
	{
		using func_t = decltype(&BSSoundHandle::FadeInPlay);
		static REL::Relocation<func_t> func{ RELOCATION_ID(66384, 67645) };
		return func(this, a_fadeTimeMS);
	}

	bool BSSoundHandle::FadeOutAndRelease(std::uint16_t a_fadeTimeMS)
	{
		using func_t = decltype(&BSSoundHandle::FadeOutAndRelease);
		static REL::Relocation<func_t> func{ RELOCATION_ID(66385, 67646) };
		return func(this, a_fadeTimeMS);
	}

	bool BSSoundHandle::IsPlaying() const
	{
		using func_t = decltype(&BSSoundHandle::IsPlaying);
		static REL::Relocation<func_t> func{ RELOCATION_ID(66359, 67620) };
		return func(this);
	}

	bool BSSoundHandle::IsValid() const
	{
		using func_t = decltype(&BSSoundHandle::IsValid);
		static REL::Relocation<func_t> func{ Offset::BSSoundHandle::IsValid };
		return func(this);
	}

	bool BSSoundHandle::SetFrequency(float a_frequency)
	{
		using func_t = decltype(&BSSoundHandle::SetFrequency);
		static REL::Relocation<func_t> func{ RELOCATION_ID(66366, 67627) };
		return func(this, a_frequency);
	}

	bool BSSoundHandle::SetPosition(NiPoint3 a_pos)
	{
		using func_t = decltype(&BSSoundHandle::SetPosition);
		static REL::Relocation<func_t> func{ Offset::BSSoundHandle::SetPosition };
		return func(this, a_pos);
	}

	void BSSoundHandle::SetObjectToFollow(NiAVObject* a_node)
	{
		using func_t = decltype(&BSSoundHandle::SetObjectToFollow);
		static REL::Relocation<func_t> func{ Offset::BSSoundHandle::SetObjectToFollow };
		return func(this, a_node);
	}

	bool BSSoundHandle::SetVolume(float a_volume)
	{
		using func_t = decltype(&BSSoundHandle::SetVolume);
		static REL::Relocation<func_t> func{ RELOCATION_ID(66365, 67626) };
		return func(this, a_volume);
	}

	bool BSSoundHandle::Stop()
	{
		using func_t = decltype(&BSSoundHandle::Stop);
		static REL::Relocation<func_t> func{ Offset::BSSoundHandle::Stop };
		return func(this);
	}

	bool BSSoundHandle::Play()
	{
		using func_t = decltype(&BSSoundHandle::Play);
		static REL::Relocation<func_t> func{ Offset::BSSoundHandle::Play };
		return func(this);
	}

	bool BSSoundHandle::Pause()
	{
		using func_t = decltype(&BSSoundHandle::Pause);
		static REL::Relocation<func_t> func{ Offset::BSSoundHandle::Pause };
		return func(this);
	}
}
