//
//  Font data for Wingdings 8pt
//
#include <avr/pgmspace.h>
#include <stdint.h>
#include "bitmap_db.h"

// Character bitmaps for Wingdings 8pt
const uint8_t wingdings_8ptBitmaps[]PROGMEM =
{
	// @0 '�' (8 pixels wide)
	0xFF, // ########
	0x81, // #      #
	0x81, // #      #
	0x81, // #      #
	0x81, // #      #
	0x81, // #      #
	0x81, // #      #
	0xFF, // ########

	// @8 '�' (8 pixels wide)
	0xFF, // ########
	0x81, // #      #
	0xA5, // # #  # #
	0xB9, // # ###  #
	0x99, // #  ##  #
	0xE7, // ###  ###
	0x81, // #      #
	0xFF, // ########

	// @16 '�' (8 pixels wide)
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
	{8, 0}, 		// �
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
	{8, 8}, 		// �
	{8, 16}, 		// �
};

// Font information for Wingdings 8pt
const FONT_INFO wingdings_8ptFontInfo =
{
	1, //  Character height
	'�', //  Start character
	'�', //  End character
	2, //  Width, in pixels, of space character
	wingdings_8ptDescriptors, //  Character descriptor array
	wingdings_8ptBitmaps, //  Character bitmap array
};

