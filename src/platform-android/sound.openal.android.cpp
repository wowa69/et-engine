/*
 * This file is part of `et engine`
 * Copyright 2009-2012 by Sergey Reznik
 * Please, do not modify contents without approval.
 *
 */

#include <et/sound/sound.h>

#if (ET_PLATFORM_ANDROID)

#include <oal/al.h>
#include <oal/alc.h>
#include <et/platform-android/nativeactivity.h>

using namespace et;
using namespace audio;

namespace et
{
	extern android_app* sharedAndroidApplication();
	extern zip* sharedAndroidZipArchive();
	extern ALCdevice* getSharedDevice();
	extern ALCcontext* getSharedContext();
}

void Manager::nativePreInit()
{
	attachToThread();
}

void Manager::nativeInit()
{
}

void Manager::nativeRelease()
{
}

void Manager::nativePostRelease()
{
}

#endif // ET_PLATFORM_ANDROID
