#include "common_headers.h"

#include "texture.h"

#include <SFML\Graphics\Image.hpp>
#include <SFML\Graphics\Texture.hpp>

#pragma comment(lib, "FreeImage.lib")

/*CTexture tTextures[NUMTEXTURES];

void LoadAllTextures()
{
	// Load textures

	string sTextureNames[] = { "fungus.dds", "sand_grass_02.jpg", "rock_2_4w.jpg", "sand.jpg", "path.png", "scifi_metal.jpg", "particle.bmp" };

	FOR(i, NUMTEXTURES)
	{
		tTextures[i].LoadTexture2D("data\\textures\\" + sTextureNames[i], true);
		tTextures[i].SetFiltering(TEXTURE_FILTER_MAG_BILINEAR, TEXTURE_FILTER_MIN_BILINEAR_MIPMAP);
	}
}*/

CTexture::CTexture(const char* path)
{
	textura.loadFromFile(path);
}

CTexture::CTexture(sf::Image& image)
{
	textura.loadFromImage(image);
}

CTexture::CTexture(const void *data, std::size_t size)
{
	textura.loadFromMemory(data, size);
}

CTexture::CTexture(sf::InputStream &stream)
{
	textura.loadFromStream(stream);
}
CTexture::CTexture(unsigned int x, unsigned int y)
{
	textura.create(x, y);
}

/*void CTexture::releaseTexture()
{
	glDeleteSamplers(1, &uiSampler);
	glDeleteTextures(1, &uiTexture);
}*/

sf::Color CTexture::AccessPixel(unsigned int x, unsigned int y)
{
	return textura.copyToImage().getPixel(x, y);
}
void CTexture::BindTexture()
{
	sf::Texture::bind(&textura);
}

unsigned int CTexture::GetHeight()
{
	return textura.getSize().y;
}
unsigned int CTexture::GetWidth()
{
	return textura.getSize().x;
}

CTexture::~CTexture()
{
}
