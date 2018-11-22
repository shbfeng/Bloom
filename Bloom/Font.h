/***********************************************
 * File: Font.h
 *
 * Author: LYG
 * Date: ʮһ�� 2018
 *
 * Purpose:
 *
 * 
 **********************************************/
#pragma once
#include <vector>
#include <map>
#include <ft2build.h>
#include FT_FREETYPE_H

#include "Math/Vector2.h"

enum FontType
{
	MFDingHei,
	MFFanSong,
	MFJingYue,
	MFJinHua,
	MFLingYi,
	MFMengYuan,
	MFNianZhen,
	MFSiYan,
	MFSuBai,
	MFWenShang,
	MFXingYan,
	MFXiYue,
	MFYiFeng,
	MFYuYi,
	MFZhuoHei,

	FontMax,
};
class D3d11Texture;

struct TextInfo
{
	Vector2 UVLeftTop;
	Vector2 UVRightBottom;

	D3d11Texture* Tex;
};

class Font
{
	friend class FontManager;
	struct TextureUsed
	{
	public:
		TextureUsed();
		~TextureUsed();

		// if return false, the texture is full, need a new trxture.
		bool AddText(TextInfo& TI, FT_GlyphSlot Glyph);
		D3d11Texture* Tex;
		int XOffset;
		int YOffset;
		int MaxRowHeight;
		static int TextureIndex;
		char FontTextureName[128];
		unsigned char* TextureBuffer;
		int BufferLen;
	};
public:
	FontType GetFontType() const;
	unsigned int GetFontSize() const;

	TextInfo* GetTextInfo(unsigned long CH);
protected:
	Font();
	~Font();

	FT_Face mFTFace;
	FontType mFontType;
	unsigned int mFontSize;
	std::map<unsigned long, TextInfo*> mTextMap;
	std::vector<TextureUsed*> mTextureUesedArray;
};

class FontManager
{
	friend class Scene;
public:
	Font* GetFont(FontType FT, unsigned int FontSize);
protected:
	FontManager();
	~FontManager();
	FT_Library mFTLibrary;
	std::vector<Font*> mFontArray;
};