//
//  Font data for Arimo 8pt
//
#include <avr/pgmspace.h>
#include <stdint.h>
#include "fonts/bitmap_db.h"

// Character bitmaps for Arimo 8pt
const uint8_t arimo_8ptBitmaps[] PROGMEM =
{
	// @0 '-' (2 pixels wide)
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0xC0, // ##
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x00, //

	// @10 '0' (6 pixels wide)
	0x78, //  ####
	0x48, //  #  #
	0x88, // #   #
	0x84, // #    #
	0x84, // #    #
	0x88, // #   #
	0x48, //  #  #
	0x30, //   ##
	0x00, //
	0x00, //

	// @20 '1' (5 pixels wide)
	0x60, //  ##
	0xA0, // # #
	0x20, //   #
	0x20, //   #
	0x20, //   #
	0x20, //   #
	0x20, //   #
	0xF8, // #####
	0x00, //
	0x00, //

	// @30 '2' (4 pixels wide)
	0xF0, // ####
	0x90, // #  #
	0x10, //    #
	0x10, //    #
	0x20, //   #
	0x40, //  #
	0x80, // #
	0xF0, // ####
	0x00, //
	0x00, //

	// @40 '3' (5 pixels wide)
	0xF0, // ####
	0x90, // #  #
	0x10, //    #
	0x60, //  ##
	0x10, //    #
	0x08, //     #
	0x90, // #  #
	0xF0, // ####
	0x00, //
	0x00, //

	// @50 '4' (6 pixels wide)
	0x18, //    ##
	0x18, //    ##
	0x28, //   # #
	0x48, //  #  #
	0x48, //  #  #
	0xFC, // ######
	0x08, //     #
	0x08, //     #
	0x00, //
	0x00, //

	// @60 '5' (5 pixels wide)
	0xF0, // ####
	0x80, // #
	0x80, // #
	0xF0, // ####
	0x10, //    #
	0x08, //     #
	0x90, // #  #
	0xF0, // ####
	0x00, //
	0x00, //

	// @70 '6' (5 pixels wide)
	0x70, //  ###
	0x90, // #  #
	0x80, // #
	0xF0, // ####
	0x90, // #  #
	0x88, // #   #
	0x90, // #  #
	0x70, //  ###
	0x00, //
	0x00, //

	// @80 '7' (4 pixels wide)
	0xF0, // ####
	0x10, //    #
	0x10, //    #
	0x20, //   #
	0x20, //   #
	0x40, //  #
	0x40, //  #
	0x40, //  #
	0x00, //
	0x00, //

	// @90 '8' (6 pixels wide)
	0x78, //  ####
	0x48, //  #  #
	0x48, //  #  #
	0x30, //   ##
	0x48, //  #  #
	0x84, // #    #
	0x48, //  #  #
	0x78, //  ####
	0x00, //
	0x00, //

	// @100 '9' (5 pixels wide)
	0x70, //  ###
	0x48, //  #  #
	0x88, // #   #
	0x48, //  #  #
	0x78, //  ####
	0x08, //     #
	0x48, //  #  #
	0x70, //  ###
	0x00, //
	0x00, //

	// @110 ':' (1 pixels wide)
	0x00, //
	0x00, //
	0x80, // #
	0x00, //
	0x00, //
	0x00, //
	0x00, //
	0x80, // #
	0x00, //
	0x00, //

	// @120 'A' (8 pixels wide)
	0x18, //    ##
	0x18, //    ##
	0x24, //   #  #
	0x24, //   #  #
	0x26, //   #  ##
	0x7E, //  ######
	0x42, //  #    #
	0x81, // #      #
	0x00, //
	0x00, //

	// @130 'B' (5 pixels wide)
	0xF0, // ####
	0x88, // #   #
	0x88, // #   #
	0xF0, // ####
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0xF8, // #####
	0x00, //
	0x00, //

	// @140 'C' (6 pixels wide)
	0x78, //  ####
	0x88, // #   #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x8C, // #   ##
	0x78, //  ####
	0x00, //
	0x00, //

	// @150 'D' (6 pixels wide)
	0xF0, // ####
	0x88, // #   #
	0x88, // #   #
	0x8C, // #   ##
	0x8C, // #   ##
	0x88, // #   #
	0x88, // #   #
	0xF0, // ####
	0x00, //
	0x00, //

	// @160 'E' (5 pixels wide)
	0xF0, // ####
	0x80, // #
	0x80, // #
	0xF0, // ####
	0x80, // #
	0x80, // #
	0x80, // #
	0xF8, // #####
	0x00, //
	0x00, //

	// @170 'F' (5 pixels wide)
	0xF8, // #####
	0x80, // #
	0x80, // #
	0x80, // #
	0xF0, // ####
	0x80, // #
	0x80, // #
	0x80, // #
	0x00, //
	0x00, //

	// @180 'G' (6 pixels wide)
	0x78, //  ####
	0x84, // #    #
	0x80, // #
	0x80, // #
	0x9C, // #  ###
	0x84, // #    #
	0x84, // #    #
	0x78, //  ####
	0x00, //
	0x00, //

	// @190 'H' (5 pixels wide)
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0xF8, // #####
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0x00, //
	0x00, //

	// @200 'I' (1 pixels wide)
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x00, //
	0x00, //

	// @210 'J' (4 pixels wide)
	0x30, //   ##
	0x10, //    #
	0x10, //    #
	0x10, //    #
	0x10, //    #
	0x10, //    #
	0x90, // #  #
	0x70, //  ###
	0x00, //
	0x00, //

	// @220 'K' (5 pixels wide)
	0x88, // #   #
	0x90, // #  #
	0xA0, // # #
	0xC0, // ##
	0xA0, // # #
	0x90, // #  #
	0x88, // #   #
	0x88, // #   #
	0x00, //
	0x00, //

	// @230 'L' (5 pixels wide)
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0xF8, // #####
	0x00, //
	0x00, //

	// @240 'M' (6 pixels wide)
	0x84, // #    #
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xCC, // ##  ##
	0xB4, // # ## #
	0xB4, // # ## #
	0xB4, // # ## #
	0x84, // #    #
	0x00, //
	0x00, //

	// @250 'N' (5 pixels wide)
	0x88, // #   #
	0xC8, // ##  #
	0xC8, // ##  #
	0xA8, // # # #
	0xA8, // # # #
	0x98, // #  ##
	0x98, // #  ##
	0x88, // #   #
	0x00, //
	0x00, //

	// @260 'O' (6 pixels wide)
	0x78, //  ####
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0x78, //  ####
	0x00, //
	0x00, //

	// @270 'P' (5 pixels wide)
	0xF0, // ####
	0x90, // #  #
	0x98, // #  ##
	0x90, // #  #
	0xF0, // ####
	0x80, // #
	0x80, // #
	0x80, // #
	0x00, //
	0x00, //

	// @280 'Q' (6 pixels wide)
	0x78, //  ####
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0x84, // #    #
	0x78, //  ####
	0x10, //    #
	0x1C, //    ###

	// @290 'R' (5 pixels wide)
	0xF8, // #####
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0xF0, // ####
	0x90, // #  #
	0x88, // #   #
	0x88, // #   #
	0x00, //
	0x00, //

	// @300 'S' (6 pixels wide)
	0x78, //  ####
	0x88, // #   #
	0x80, // #
	0xE0, // ###
	0x18, //    ##
	0x0C, //     ##
	0x88, // #   #
	0xF8, // #####
	0x00, //
	0x00, //

	// @310 'T' (6 pixels wide)
	0xFC, // ######
	0x10, //    #
	0x10, //    #
	0x10, //    #
	0x10, //    #
	0x10, //    #
	0x10, //    #
	0x10, //    #
	0x00, //
	0x00, //

	// @320 'U' (5 pixels wide)
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0x88, // #   #
	0x70, //  ###
	0x00, //
	0x00, //

	// @330 'V' (8 pixels wide)
	0x81, // #      #
	0x42, //  #    #
	0x42, //  #    #
	0x24, //   #  #
	0x24, //   #  #
	0x24, //   #  #
	0x18, //    ##
	0x18, //    ##
	0x00, //
	0x00, //

	// @340 'W' (10 pixels wide)
	0x84, 0x40, // #    #   #
	0x8C, 0x40, // #   ##   #
	0x4C, 0x80, //  #  ##  #
	0x4C, 0x80, //  #  ##  #
	0x52, 0x80, //  # #  # #
	0x52, 0x80, //  # #  # #
	0x33, 0x00, //   ##  ##
	0x21, 0x00, //   #    #
	0x00, 0x00, //
	0x00, 0x00, //

	// @360 'X' (5 pixels wide)
	0x88, // #   #
	0xC8, // ##  #
	0x50, //  # #
	0x20, //   #
	0x30, //   ##
	0x50, //  # #
	0x88, // #   #
	0x88, // #   #
	0x00, //
	0x00, //

	// @370 'Y' (6 pixels wide)
	0x84, // #    #
	0x84, // #    #
	0x48, //  #  #
	0x30, //   ##
	0x30, //   ##
	0x20, //   #
	0x20, //   #
	0x20, //   #
	0x00, //
	0x00, //

	// @380 'Z' (7 pixels wide)
	0x7C, //  #####
	0x04, //      #
	0x08, //     #
	0x10, //    #
	0x30, //   ##
	0x20, //   #
	0x40, //  #
	0xFE, // #######
	0x00, //
	0x00, //

	// @390 'a' (6 pixels wide)
	0x00, //
	0x00, //
	0x78, //  ####
	0x08, //     #
	0x78, //  ####
	0x48, //  #  #
	0x88, // #   #
	0x7C, //  #####
	0x00, //
	0x00, //

	// @400 'b' (5 pixels wide)
	0x80, // #
	0x80, // #
	0xF0, // ####
	0x90, // #  #
	0x88, // #   #
	0x88, // #   #
	0x90, // #  #
	0xF0, // ####
	0x00, //
	0x00, //

	// @410 'c' (5 pixels wide)
	0x00, //
	0x00, //
	0x70, //  ###
	0x88, // #   #
	0x80, // #
	0x80, // #
	0x88, // #   #
	0x70, //  ###
	0x00, //
	0x00, //

	// @420 'd' (5 pixels wide)
	0x08, //     #
	0x08, //     #
	0x78, //  ####
	0x48, //  #  #
	0x88, // #   #
	0x88, // #   #
	0x48, //  #  #
	0x78, //  ####
	0x00, //
	0x00, //

	// @430 'e' (6 pixels wide)
	0x00, //
	0x00, //
	0x78, //  ####
	0x48, //  #  #
	0xFC, // ######
	0xC0, // ##
	0x48, //  #  #
	0x78, //  ####
	0x00, //
	0x00, //

	// @440 'f' (4 pixels wide)
	0x30, //   ##
	0x40, //  #
	0xF0, // ####
	0x40, //  #
	0x40, //  #
	0x40, //  #
	0x40, //  #
	0x40, //  #
	0x00, //
	0x00, //

	// @450 'g' (5 pixels wide)
	0x00, //
	0x00, //
	0x78, //  ####
	0x48, //  #  #
	0x88, // #   #
	0x88, // #   #
	0x48, //  #  #
	0x78, //  ####
	0x08, //     #
	0x78, //  ####

	// @460 'h' (4 pixels wide)
	0x80, // #
	0x80, // #
	0xF0, // ####
	0x90, // #  #
	0x90, // #  #
	0x90, // #  #
	0x90, // #  #
	0x90, // #  #
	0x00, //
	0x00, //

	// @470 'i' (1 pixels wide)
	0x80, // #
	0x00, //
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x00, //
	0x00, //

	// @480 'j' (2 pixels wide)
	0x40, //  #
	0x00, //
	0x40, //  #
	0x40, //  #
	0x40, //  #
	0x40, //  #
	0x40, //  #
	0x40, //  #
	0x40, //  #
	0x80, // #

	// @490 'k' (4 pixels wide)
	0x80, // #
	0x80, // #
	0xA0, // # #
	0xA0, // # #
	0xC0, // ##
	0xC0, // ##
	0xA0, // # #
	0x90, // #  #
	0x00, //
	0x00, //

	// @500 'l' (1 pixels wide)
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x00, //
	0x00, //

	// @510 'm' (6 pixels wide)
	0x00, //
	0x00, //
	0xEC, // ### ##
	0xB4, // # ## #
	0x94, // #  # #
	0x94, // #  # #
	0x94, // #  # #
	0x94, // #  # #
	0x00, //
	0x00, //

	// @520 'n' (4 pixels wide)
	0x00, //
	0x00, //
	0xF0, // ####
	0x90, // #  #
	0x90, // #  #
	0x90, // #  #
	0x90, // #  #
	0x90, // #  #
	0x00, //
	0x00, //

	// @530 'o' (6 pixels wide)
	0x00, //
	0x00, //
	0x78, //  ####
	0x48, //  #  #
	0x84, // #    #
	0x84, // #    #
	0x48, //  #  #
	0x78, //  ####
	0x00, //
	0x00, //

	// @540 'p' (5 pixels wide)
	0x00, //
	0x00, //
	0xF0, // ####
	0x90, // #  #
	0x88, // #   #
	0x88, // #   #
	0x90, // #  #
	0xF0, // ####
	0x80, // #
	0x80, // #

	// @550 'q' (5 pixels wide)
	0x00, //
	0x00, //
	0x78, //  ####
	0x48, //  #  #
	0x88, // #   #
	0x88, // #   #
	0x48, //  #  #
	0x78, //  ####
	0x08, //     #
	0x08, //     #

	// @560 'r' (3 pixels wide)
	0x00, //
	0x00, //
	0xE0, // ###
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x80, // #
	0x00, //
	0x00, //

	// @570 's' (6 pixels wide)
	0x00, //
	0x00, //
	0x78, //  ####
	0x40, //  #
	0x60, //  ##
	0x18, //    ##
	0x84, // #    #
	0x78, //  ####
	0x00, //
	0x00, //

	// @580 't' (3 pixels wide)
	0x00, //
	0x40, //  #
	0xE0, // ###
	0x40, //  #
	0x40, //  #
	0x40, //  #
	0x40, //  #
	0x60, //  ##
	0x00, //
	0x00, //

	// @590 'u' (4 pixels wide)
	0x00, //
	0x00, //
	0x90, // #  #
	0x90, // #  #
	0x90, // #  #
	0x90, // #  #
	0x90, // #  #
	0xF0, // ####
	0x00, //
	0x00, //

	// @600 'v' (6 pixels wide)
	0x00, //
	0x00, //
	0x84, // #    #
	0x48, //  #  #
	0x48, //  #  #
	0x48, //  #  #
	0x30, //   ##
	0x30, //   ##
	0x00, //
	0x00, //

	// @610 'w' (8 pixels wide)
	0x00, //
	0x00, //
	0x99, // #  ##  #
	0x99, // #  ##  #
	0x99, // #  ##  #
	0x66, //  ##  ##
	0x66, //  ##  ##
	0x66, //  ##  ##
	0x00, //
	0x00, //

	// @620 'x' (4 pixels wide)
	0x00, //
	0x00, //
	0x90, // #  #
	0x90, // #  #
	0x60, //  ##
	0x60, //  ##
	0x90, // #  #
	0x90, // #  #
	0x00, //
	0x00, //

	// @630 'y' (6 pixels wide)
	0x00, //
	0x00, //
	0x84, // #    #
	0x48, //  #  #
	0x48, //  #  #
	0x28, //   # #
	0x30, //   ##
	0x30, //   ##
	0x20, //   #
	0xC0, // ##

	// @640 'z' (5 pixels wide)
	0x00, //
	0x00, //
	0x78, //  ####
	0x08, //     #
	0x10, //    #
	0x20, //   #
	0x40, //  #
	0xF8, // #####
	0x00, //
	0x00, //
};

// Character descriptors for Arimo 8pt
// { [Char width in bits], [Offset into arimo_8ptCharBitmaps in bytes] }
const FONT_CHAR_INFO arimo_8ptDescriptors[] =
{
	{2, 0}, 		// -
	{0, 0}, 		// .
	{0, 0}, 		// /
	{6, 10}, 		// 0
	{5, 20}, 		// 1
	{4, 30}, 		// 2
	{5, 40}, 		// 3
	{6, 50}, 		// 4
	{5, 60}, 		// 5
	{5, 70}, 		// 6
	{4, 80}, 		// 7
	{6, 90}, 		// 8
	{5, 100}, 		// 9
	{1, 110}, 		// :
	{0, 0}, 		// ;
	{0, 0}, 		// <
	{0, 0}, 		// =
	{0, 0}, 		// >
	{0, 0}, 		// ?
	{0, 0}, 		// @
	{8, 120}, 		// A
	{5, 130}, 		// B
	{6, 140}, 		// C
	{6, 150}, 		// D
	{5, 160}, 		// E
	{5, 170}, 		// F
	{6, 180}, 		// G
	{5, 190}, 		// H
	{1, 200}, 		// I
	{4, 210}, 		// J
	{5, 220}, 		// K
	{5, 230}, 		// L
	{6, 240}, 		// M
	{5, 250}, 		// N
	{6, 260}, 		// O
	{5, 270}, 		// P
	{6, 280}, 		// Q
	{5, 290}, 		// R
	{6, 300}, 		// S
	{6, 310}, 		// T
	{5, 320}, 		// U
	{8, 330}, 		// V
	{10, 340}, 		// W
	{5, 360}, 		// X
	{6, 370}, 		// Y
	{7, 380}, 		// Z
	{0, 0}, 		// [
	{0, 0}, 		// \
	{0, 0}, 		// ]
	{0, 0}, 		// ^
	{0, 0}, 		// _
	{0, 0}, 		// `
	{6, 390}, 		// a
	{5, 400}, 		// b
	{5, 410}, 		// c
	{5, 420}, 		// d
	{6, 430}, 		// e
	{4, 440}, 		// f
	{5, 450}, 		// g
	{4, 460}, 		// h
	{1, 470}, 		// i
	{2, 480}, 		// j
	{4, 490}, 		// k
	{1, 500}, 		// l
	{6, 510}, 		// m
	{4, 520}, 		// n
	{6, 530}, 		// o
	{5, 540}, 		// p
	{5, 550}, 		// q
	{3, 560}, 		// r
	{6, 570}, 		// s
	{3, 580}, 		// t
	{4, 590}, 		// u
	{6, 600}, 		// v
	{8, 610}, 		// w
	{4, 620}, 		// x
	{6, 630}, 		// y
	{5, 640}, 		// z
};

// Font information for Arimo 8pt
const FONT_INFO arimo_8ptFontInfo =
{
	10, //  Character height
	'-', //  Start character
	'z', //  End character
	2, //  Width, in pixels, of space character
	arimo_8ptDescriptors, //  Character descriptor array
	arimo_8ptBitmaps, //  Character bitmap array
};

