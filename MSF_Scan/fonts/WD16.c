//
//  Font data for Wingdings 16pt
//
#include <avr/pgmspace.h>
#include <stdint.h>
#include "bitmap_db.h"

// Character bitmaps for Wingdings 16pt
const uint8_t wingdings_16ptBitmaps[]PROGMEM =
{
	// @0 '�' (15 pixels wide)
	0x00, 0x00, //
	0xFF, 0xFE, // ###############
	0xFF, 0xFE, // ###############
	0xC0, 0x06, // ##           ##
	0xC0, 0x06, // ##           ##
	0xC0, 0x06, // ##           ##
	0xC0, 0x06, // ##           ##
	0xC0, 0x06, // ##           ##
	0xC0, 0x06, // ##           ##
	0xC0, 0x06, // ##           ##
	0xC0, 0x06, // ##           ##
	0xC0, 0x06, // ##           ##
	0xC0, 0x06, // ##           ##
	0xC0, 0x06, // ##           ##
	0xFF, 0xFE, // ###############
	0xFF, 0xFE, // ###############

	// @32 '�' (15 pixels wide)
	0x00, 0x00, //
	0xFF, 0xFE, // ###############
	0xFF, 0xFE, // ###############
	0xC0, 0x06, // ##           ##
	0xC4, 0x06, // ##   #       ##
	0xCC, 0x66, // ##  ##   ##  ##
	0xCE, 0xF6, // ##  ### #### ##
	0xC7, 0xC6, // ##   #####   ##
	0xC3, 0x86, // ##    ###    ##
	0xC7, 0xC6, // ##   #####   ##
	0xCE, 0xF6, // ##  ### #### ##
	0xDE, 0x66, // ## ####  ##  ##
	0xCC, 0x06, // ##  ##       ##
	0xC0, 0x06, // ##           ##
	0xFF, 0xFE, // ###############
	0xFF, 0xFE, // ###############

	// @64 '�' (16 pixels wide)
	0x00, 0x01, //                #
	0xFF, 0xFE, // ###############
	0xFF, 0xFE, // ###############
	0xC0, 0x0E, // ##          ###
	0xC0, 0x16, // ##         # ##
	0xC0, 0x26, // ##        #  ##
	0xC0, 0x66, // ##       ##  ##
	0xD8, 0xC6, // ## ##   ##   ##
	0xDD, 0x86, // ## ### ##    ##
	0xCD, 0x86, // ##  ## ##    ##
	0xC7, 0x06, // ##   ###     ##
	0xC6, 0x06, // ##   ##      ##
	0xC4, 0x06, // ##   #       ##
	0xC0, 0x06, // ##           ##
	0xFF, 0xFE, // ###############
	0xFF, 0xFE, // ###############
};

// Character descriptors for Wingdings 16pt
// { [Char width in bits], [Offset into wingdings_16ptCharBitmaps in bytes] }
const FONT_CHAR_INFO wingdings_16ptDescriptors[] =
{
	{15, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{0, 0}, 		// �
	{15, 32}, 		// �
	{16, 64}, 		// �
};

// Font information for Wingdings 16pt
const FONT_INFO wingdings_16ptFontInfo =
{
	2, //  Character height
	'�', //  Start character
	'�', //  End character
	2, //  Width, in pixels, of space character
	wingdings_16ptDescriptors, //  Character descriptor array
	wingdings_16ptBitmaps, //  Character bitmap array
};

