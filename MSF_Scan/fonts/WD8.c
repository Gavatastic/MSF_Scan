//
//  Font data for Wingdings 8pt
//
#include <avr/pgmspace.h>
#include <stdint.h>
#include "bitmap_db.h"

// Character bitmaps for Wingdings 8pt
const uint8_t wingdings_8ptBitmaps[]PROGMEM =
{
	// @0 '¨' (8 pixels wide)
	0xFF, // ########
	0x81, // #      #
	0x81, // #      #
	0x81, // #      #
	0x81, // #      #
	0x81, // #      #
	0x81, // #      #
	0xFF, // ########

	// @8 'ý' (8 pixels wide)
	0xFF, // ########
	0x81, // #      #
	0xA5, // # #  # #
	0xB9, // # ###  #
	0x99, // #  ##  #
	0xE7, // ###  ###
	0x81, // #      #
	0xFF, // ########

	// @16 'þ' (8 pixels wide)
	0xFF, // ########
	0x83, // #     ##
	0x85, // #    # #
	0xA9, // # # #  #
	0xF9, // #####  #
	0x91, // #  #   #
	0x81, // #      #
	0xFF, // ########
};

// Character descriptors for Wingdings 8pt
// { [Char width in bits], [Offset into wingdings_8ptCharBitmaps in bytes] }
const FONT_CHAR_INFO wingdings_8ptDescriptors[] =
{
	{8, 0}, 		// ¨
	{0, 0}, 		// ©
	{0, 0}, 		// ª
	{0, 0}, 		// «
	{0, 0}, 		// ¬
	{0, 0}, 		// ­
	{0, 0}, 		// ®
	{0, 0}, 		// ¯
	{0, 0}, 		// °
	{0, 0}, 		// ±
	{0, 0}, 		// ²
	{0, 0}, 		// ³
	{0, 0}, 		// ´
	{0, 0}, 		// µ
	{0, 0}, 		// ¶
	{0, 0}, 		// ·
	{0, 0}, 		// ¸
	{0, 0}, 		// ¹
	{0, 0}, 		// º
	{0, 0}, 		// »
	{0, 0}, 		// ¼
	{0, 0}, 		// ½
	{0, 0}, 		// ¾
	{0, 0}, 		// ¿
	{0, 0}, 		// À
	{0, 0}, 		// Á
	{0, 0}, 		// Â
	{0, 0}, 		// Ã
	{0, 0}, 		// Ä
	{0, 0}, 		// Å
	{0, 0}, 		// Æ
	{0, 0}, 		// Ç
	{0, 0}, 		// È
	{0, 0}, 		// É
	{0, 0}, 		// Ê
	{0, 0}, 		// Ë
	{0, 0}, 		// Ì
	{0, 0}, 		// Í
	{0, 0}, 		// Î
	{0, 0}, 		// Ï
	{0, 0}, 		// Ð
	{0, 0}, 		// Ñ
	{0, 0}, 		// Ò
	{0, 0}, 		// Ó
	{0, 0}, 		// Ô
	{0, 0}, 		// Õ
	{0, 0}, 		// Ö
	{0, 0}, 		// ×
	{0, 0}, 		// Ø
	{0, 0}, 		// Ù
	{0, 0}, 		// Ú
	{0, 0}, 		// Û
	{0, 0}, 		// Ü
	{0, 0}, 		// Ý
	{0, 0}, 		// Þ
	{0, 0}, 		// ß
	{0, 0}, 		// à
	{0, 0}, 		// á
	{0, 0}, 		// â
	{0, 0}, 		// ã
	{0, 0}, 		// ä
	{0, 0}, 		// å
	{0, 0}, 		// æ
	{0, 0}, 		// ç
	{0, 0}, 		// è
	{0, 0}, 		// é
	{0, 0}, 		// ê
	{0, 0}, 		// ë
	{0, 0}, 		// ì
	{0, 0}, 		// í
	{0, 0}, 		// î
	{0, 0}, 		// ï
	{0, 0}, 		// ð
	{0, 0}, 		// ñ
	{0, 0}, 		// ò
	{0, 0}, 		// ó
	{0, 0}, 		// ô
	{0, 0}, 		// õ
	{0, 0}, 		// ö
	{0, 0}, 		// ÷
	{0, 0}, 		// ø
	{0, 0}, 		// ù
	{0, 0}, 		// ú
	{0, 0}, 		// û
	{0, 0}, 		// ü
	{8, 8}, 		// ý
	{8, 16}, 		// þ
};

// Font information for Wingdings 8pt
const FONT_INFO wingdings_8ptFontInfo =
{
	1, //  Character height
	'¨', //  Start character
	'þ', //  End character
	2, //  Width, in pixels, of space character
	wingdings_8ptDescriptors, //  Character descriptor array
	wingdings_8ptBitmaps, //  Character bitmap array
};

