/*
 * This file is part of `et engine`
 * Copyright 2009-2014 by Sergey Reznik
 * Please, do not modify content without approval.
 *
 */

#pragma once

#include <et/app/events.h>
#include <et/apiobjects/texture.h>
#include <et/apiobjects/apiobjectfactory.h>
#include <et/apiobjects/textureloadingthread.h>

namespace et
{
	class TextureFactoryPrivate;
	class TextureFactory : public APIObjectFactory, public TextureLoadingThreadDelegate
	{
	public:
		ET_DECLARE_POINTER(TextureFactory)
		
	public:
		TextureFactory(RenderContext*);
		~TextureFactory();
		
		Texture loadTexture(const std::string& file, ObjectsCache& cache, bool async = false,
			TextureLoaderDelegate* delegate = nullptr);

		Texture loadTexturesToCubemap(const std::string& posx, const std::string& negx,
			const std::string& posy, const std::string& negy, const std::string& posz,
			const std::string& negz, ObjectsCache& cache);

		Texture genNoiseTexture(const vec2i& size, bool normalize, const std::string& aName);
		Texture genCubeTexture(int32_t internalformat, GLsizei size, uint32_t format, uint32_t type,
			const std::string& aName);
		
		Texture genTexture(TextureDescription::Pointer desc);
		Texture genTexture(uint32_t target, int32_t internalformat, const vec2i& size, uint32_t format,
			uint32_t type, const BinaryDataStorage& data, const std::string& aName);
		
		Texture createTextureWrapper(uint32_t texture, const vec2i& size, const std::string& aName);

		ObjectLoader::Pointer objectLoader();
		
		ET_DECLARE_EVENT1(textureDidStartLoading, Texture)
		ET_DECLARE_EVENT1(textureDidLoad, Texture)

	private:
		ET_DENY_COPY(TextureFactory)
		
		friend class RenderContext;
		friend class TextureFactoryPrivate;
		
		void reloadObject(LoadableObject::Pointer, ObjectsCache&);
		void textureLoadingThreadDidLoadTextureData(TextureLoadingRequest* request);
		
	private:
		AutoPtr<TextureLoadingThread> _loadingThread;
		
		ET_DECLARE_PIMPL(TextureFactory, 64)

		CriticalSection _csTextureLoading;
		ObjectLoader::Pointer _loader;
	};

}
