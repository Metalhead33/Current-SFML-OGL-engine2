#pragma once
#include <SFML\Graphics\Texture.hpp>

enum ETextureFiltering
{
	TEXTURE_FILTER_MAG_NEAREST = 0, // Nearest criterion for magnification
	TEXTURE_FILTER_MAG_BILINEAR, // Bilinear criterion for magnification
	TEXTURE_FILTER_MIN_NEAREST, // Nearest criterion for minification
	TEXTURE_FILTER_MIN_BILINEAR, // Bilinear criterion for minification
	TEXTURE_FILTER_MIN_NEAREST_MIPMAP, // Nearest criterion for minification, but on closest mipmap
	TEXTURE_FILTER_MIN_BILINEAR_MIPMAP, // Bilinear criterion for minification, but on closest mipmap
	TEXTURE_FILTER_MIN_TRILINEAR, // Bilinear criterion for minification on two closest mipmaps, then averaged
};

class CTexture
{
public:
	unsigned int GetHeight();
	unsigned int GetWidth();
	CTexture(const char* path);
	CTexture(sf::Image& image);
	CTexture(const void *data, std::size_t size);
	CTexture(sf::InputStream &stream);
	CTexture(unsigned int x, unsigned int y);
	~CTexture();
	sf::Color AccessPixel(unsigned int x, unsigned int y);
	void BindTexture();
	//void releaseTexture();
protected:
	sf::Texture textura;
	unsigned int width;
	unsigned int height;
};

