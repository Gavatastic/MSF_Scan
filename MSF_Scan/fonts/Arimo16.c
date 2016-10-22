//
//  Font data for Arimo 16pt
//
#include <avr/pgmspace.h>
#include <stdint.h>
#include "bitmap_db.h"

// Character bitmaps for Arimo 16pt
const uint8_t arimo_16ptBitmaps[] PROGMEM =
{
	// @0 '0' (10 pixels wide)
	0x1E, 0x00, //    ####
	0x7F, 0x80, //  ########
	0x61, 0x80, //  ##    ##
	0xC0, 0xC0, // ##      ##
	0xC0, 0xC0, // ##      ##
	0xC0, 0xC0, // ##      ##
	0xC0, 0xC0, // ##      ##
	0xC0, 0xC0, // ##      ##
	0xC0, 0xC0, // ##      ##
	0xC0, 0xC0, // ##      ##
	0xC0, 0xC0, // ##      ##
	0x61, 0x80, //  ##    ##
	0x7F, 0x80, //  ########
	0x1E, 0x00, //    ####

	// @28 '1' (9 pixels wide)
	0x18, 0x00, //    ##
	0x78, 0x00, //  ####
	0xD8, 0x00, // ## ##
	0x98, 0x00, // #  ##
	0x18, 0x00, //    ##
	0x18, 0x00, //    ##
	0x18, 0x00, //    ##
	0x18, 0x00, //    ##
	0x18, 0x00, //    ##
	0x18, 0x00, //    ##
	0x18, 0x00, //    ##
	0x18, 0x00, //    ##
	0xFF, 0x80, // #########
	0xFF, 0x80, // #########

	// @56 '2' (10 pixels wide)
	0x1F, 0x00, //    #####
	0x7F, 0x80, //  ########
	0x61, 0xC0, //  ##    ###
	0xC0, 0xC0, // ##      ##
	0x00, 0xC0, //         ##
	0x01, 0x80, //        ##
	0x03, 0x80, //       ###
	0x06, 0x00, //      ##
	0x0C, 0x00, //     ##
	0x18, 0x00, //    ##
	0x30, 0x00, //   ##
	0x60, 0x00, //  ##
	0xFF, 0xC0, // ##########
	0xFF, 0xC0, // ##########

	// @84 '3' (10 pixels wide)
	0x3F, 0x00, //   ######
	0x7F, 0x80, //  ########
	0xC1, 0x80, // ##     ##
	0xC0, 0xC0, // ##      ##
	0x00, 0xC0, //         ##
	0x01, 0x80, //        ##
	0x1E, 0x00, //    ####
	0x1F, 0x80, //    ######
	0x00, 0xC0, //         ##
	0x00, 0xC0, //         ##
	0xC0, 0xC0, // ##      ##
	0xC0, 0xC0, // ##      ##
	0x7F, 0x80, //  ########
	0x3F, 0x00, //   ######

	// @112 '4' (11 pixels wide)
	0x01, 0x80, //        ##
	0x03, 0x80, //       ###
	0x06, 0x80, //      ## #
	0x06, 0x80, //      ## #
	0x0C, 0x80, //     ##  #
	0x18, 0x80, //    ##   #
	0x30, 0x80, //   ##    #
	0x20, 0x80, //   #     #
	0x60, 0x80, //  ##     #
	0xFF, 0xE0, // ###########
	0x00, 0x80, //         #
	0x00, 0x80, //         #
	0x00, 0x80, //         #
	0x00, 0x80, //         #

	// @140 '5' (10 pixels wide)
	0x7F, 0x80, //  ########
	0x7F, 0x80, //  ########
	0x40, 0x00, //  #
	0x40, 0x00, //  #
	0xC0, 0x00, // ##
	0xDF, 0x00, // ## #####
	0xFF, 0x80, // #########
	0xC0, 0xC0, // ##      ##
	0x00, 0xC0, //         ##
	0x00, 0xC0, //         ##
	0xC0, 0xC0, // ##      ##
	0xC1, 0xC0, // ##     ###
	0x7F, 0x80, //  ########
	0x3F, 0x00, //   ######

	// @168 '6' (10 pixels wide)
	0x1F, 0x00, //    #####
	0x3F, 0x80, //   #######
	0x60, 0x80, //  ##     #
	0x60, 0x00, //  ##
	0xC0, 0x00, // ##
	0xDF, 0x00, // ## #####
	0xF3, 0x80, // ####  ###
	0xE0, 0xC0, // ###     ##
	0xC0, 0xC0, // ##      ##
	0xC0, 0xC0, // ##      ##
	0x40, 0xC0, //  #      ##
	0x60, 0xC0, //  ##     ##
	0x3B, 0x80, //   ### ###
	0x1F, 0x00, //    #####

	// @196 '7' (10 pixels wide)
	0xFF, 0xC0, // ##########
	0xFF, 0xC0, // ##########
	0x01, 0x80, //        ##
	0x01, 0x80, //        ##
	0x03, 0x00, //       ##
	0x02, 0x00, //       #
	0x06, 0x00, //      ##
	0x0C, 0x00, //     ##
	0x0C, 0x00, //     ##
	0x08, 0x00, //     #
	0x18, 0x00, //    ##
	0x18, 0x00, //    ##
	0x18, 0x00, //    ##
	0x18, 0x00, //    ##

	// @224 '8' (10 pixels wide)
	0x3F, 0x00, //   ######
	0x73, 0x80, //  ###  ###
	0xC0, 0xC0, // ##      ##
	0xC0, 0xC0, // ##      ##
	0xC0, 0xC0, // ##      ##
	0x61, 0x80, //  ##    ##
	0x3F, 0x00, //   ######
	0x73, 0x80, //  ###  ###
	0xC0, 0xC0, // ##      ##
	0xC0, 0xC0, // ##      ##
	0xC0, 0xC0, // ##      ##
	0xC0, 0xC0, // ##      ##
	0x73, 0x80, //  ###  ###
	0x3F, 0x00, //   ######

	// @252 '9' (10 pixels wide)
	0x3E, 0x00, //   #####
	0x7F, 0x80, //  ########
	0xE1, 0x80, // ###    ##
	0xC0, 0xC0, // ##      ##
	0xC0, 0xC0, // ##      ##
	0xC0, 0xC0, // ##      ##
	0xE1, 0xC0, // ###    ###
	0x77, 0xC0, //  ### #####
	0x3E, 0xC0, //   ##### ##
	0x00, 0xC0, //         ##
	0x00, 0x80, //         #
	0xC1, 0x80, // ##     ##
	0x77, 0x00, //  ### ###
	0x3E, 0x00, //   #####
};

// Character descriptors for Arimo 16pt
// { [Char width in bits], [Offset into arimo_16ptCharBitmaps in bytes] }
const FONT_CHAR_INFO arimo_16ptDescriptors[] =
{
	{10, 0}, 		// 0
	{9, 28}, 		// 1
	{10, 56}, 		// 2
	{10, 84}, 		// 3
	{11, 112}, 		// 4
	{10, 140}, 		// 5
	{10, 168}, 		// 6
	{10, 196}, 		// 7
	{10, 224}, 		// 8
	{10, 252}, 		// 9
};

// Font information for Arimo 16pt
const FONT_INFO arimo_16ptFontInfo =
{
	14, //  Character height
	'0', //  Start character
	'9', //  End character
	2, //  Width, in pixels, of space character
	arimo_16ptDescriptors, //  Character descriptor array
	arimo_16ptBitmaps, //  Character bitmap array
};

