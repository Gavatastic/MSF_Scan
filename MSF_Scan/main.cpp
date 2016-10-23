#define F_CPU 16000000UL
#define CHECK_BIT(var,pos) ((var) & (1<<(pos)))

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <util/delay.h>
//#include "SSD1306.h"
#include "Framebuffer.h"
#include <avr/pgmspace.h>
#include "fonts.h"
#include "fonts/WD8.h"


//  CAUTION: Region! - Constants
#pragma region Constants
const uint8_t LEFT=0;
const uint8_t CENTRE=1;
const uint8_t RIGHT=2;
const uint8_t FREEPOS=3;

const uint8_t EXCLAMATION = 0;
const uint8_t DQUOTE = 1;
const uint8_t HASH = 2;
const uint8_t DOLLAR = 3;
const uint8_t PERCENT = 4;
const uint8_t AMPERSAND = 5;
const uint8_t SQUOTE = 6;
const uint8_t OBRACKET = 7;
const uint8_t CBRACKET = 8;
const uint8_t ASTERISK = 9;
const uint8_t PLUS = 10;
const uint8_t COMMA = 11;
const uint8_t DASH = 12;
const uint8_t DOT = 13;
const uint8_t FSLASH = 14;
const uint8_t ZERO = 15;
const uint8_t COLON = 25;
const uint8_t SCOLON = 26;
const uint8_t LTHAN = 27;
const uint8_t EQUALS = 28;
const uint8_t GTHAN = 29;
const uint8_t QUESTION = 30;
const uint8_t AT = 31;
const uint8_t CAPA = 32;
const uint8_t OSQUARE = 58;
const uint8_t BSLASH = 59;
const uint8_t CSQUARE = 60;
const uint8_t CARET = 61;
const uint8_t USCORE = 62;
const uint8_t OQUOTE = 63;
const uint8_t LOWERA = 64;
const uint8_t OCURL = 90;
const uint8_t PIPE = 91;
const uint8_t CCURL = 92;
const uint8_t TILDE = 93;

#pragma endregion

// Global variables
Framebuffer fb;
volatile bool TICK = false;
volatile uint16_t TC = 0;
volatile uint8_t buffer[128]={0x7f};
volatile bool LEdgeSearch = true; // are we in LEdge search mode?
volatile uint16_t LEdge=0; // position of leading edge

const uint8_t Atomic [] PROGMEM = {
	0x00, 0x00, 0x00, 0x07, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0xF0, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x3C, 0x38, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0x1C, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x60, 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x01, 0xC0, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x80, 0x03, 0x80, 0x00, 0x00,
	0x00, 0x00, 0x03, 0x80, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x01, 0xC0, 0x00, 0x00,
	0x00, 0x00, 0x03, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0xC0, 0x00, 0x00,
	0x00, 0x3F, 0xC6, 0x00, 0x00, 0x67, 0xFC, 0x00, 0x01, 0xFF, 0xFE, 0x00, 0x00, 0xFF, 0xFF, 0x80,
	0x07, 0xC0, 0x3F, 0xC0, 0x03, 0xFC, 0x03, 0xC0, 0x07, 0x00, 0x0F, 0xF8, 0x1F, 0xF0, 0x00, 0xE0,
	0x0C, 0x00, 0x0C, 0x3E, 0xFC, 0x30, 0x00, 0x70, 0x0C, 0x00, 0x0C, 0x0F, 0xE0, 0x30, 0x00, 0x30,
	0x18, 0x00, 0x1C, 0x0F, 0xF0, 0x30, 0x00, 0x38, 0x18, 0x00, 0x18, 0x3E, 0x78, 0x30, 0x00, 0x38,
	0x18, 0x00, 0x18, 0x78, 0x1E, 0x18, 0x00, 0x38, 0x1C, 0x00, 0x19, 0xE0, 0x07, 0x98, 0x00, 0x30,
	0x0C, 0x00, 0x1F, 0x80, 0x01, 0xF8, 0x00, 0x30, 0x0C, 0x00, 0x1F, 0x00, 0x00, 0xF8, 0x00, 0x70,
	0x06, 0x00, 0x3C, 0x00, 0x00, 0x38, 0x00, 0x60, 0x06, 0x00, 0x78, 0x00, 0x00, 0x1E, 0x00, 0xE0,
	0x03, 0x00, 0xF0, 0x00, 0x00, 0x1F, 0x00, 0xC0, 0x03, 0x81, 0xF0, 0x00, 0x00, 0x1F, 0x81, 0xC0,
	0x01, 0xC7, 0xB0, 0x03, 0x80, 0x19, 0xC3, 0x80, 0x00, 0xCE, 0x30, 0x07, 0xE0, 0x1C, 0xF7, 0x00,
	0x00, 0xFC, 0x30, 0x0F, 0xE0, 0x1C, 0x3E, 0x00, 0x00, 0x78, 0x30, 0x0F, 0xF0, 0x1C, 0x1C, 0x00,
	0x00, 0x78, 0x30, 0x0F, 0xF0, 0x1C, 0x1C, 0x00, 0x00, 0xFC, 0x30, 0x0F, 0xE0, 0x1C, 0x3E, 0x00,
	0x00, 0xCE, 0x30, 0x07, 0xE0, 0x1C, 0xF7, 0x00, 0x01, 0xC7, 0xB0, 0x03, 0xC0, 0x19, 0xC3, 0x80,
	0x03, 0x81, 0xF0, 0x00, 0x00, 0x1F, 0x81, 0xC0, 0x03, 0x00, 0xF0, 0x00, 0x00, 0x1F, 0x00, 0xC0,
	0x06, 0x00, 0x78, 0x00, 0x00, 0x1E, 0x00, 0xE0, 0x06, 0x00, 0x3C, 0x00, 0x00, 0x38, 0x00, 0x60,
	0x0C, 0x00, 0x1F, 0x00, 0x00, 0xF8, 0x00, 0x30, 0x0C, 0x00, 0x1F, 0x80, 0x01, 0xF8, 0x00, 0x30,
	0x1C, 0x00, 0x19, 0xE0, 0x07, 0x98, 0x00, 0x30, 0x18, 0x00, 0x18, 0xF8, 0x1E, 0x18, 0x00, 0x38,
	0x18, 0x00, 0x18, 0x3E, 0x7C, 0x30, 0x00, 0x18, 0x18, 0x00, 0x1C, 0x0F, 0xF0, 0x30, 0x00, 0x38,
	0x1C, 0x00, 0x0C, 0x07, 0xE0, 0x30, 0x00, 0x30, 0x0C, 0x00, 0x0C, 0x3F, 0xFC, 0x30, 0x00, 0x30,
	0x0E, 0x00, 0x0F, 0xF8, 0x1F, 0xF0, 0x00, 0x60, 0x07, 0xC0, 0x3F, 0xC0, 0x07, 0xF8, 0x03, 0xE0,
	0x01, 0xFF, 0xFE, 0x00, 0x00, 0xFF, 0xFF, 0x80, 0x00, 0x7F, 0xE6, 0x00, 0x00, 0x67, 0xFE, 0x00,
	0x00, 0x00, 0x06, 0x00, 0x00, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0xC0, 0x00, 0x00,
	0x00, 0x00, 0x03, 0x00, 0x01, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x01, 0x80, 0x00, 0x00,
	0x00, 0x00, 0x01, 0x80, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x01, 0xC0, 0x03, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0xE0, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x0E, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x30, 0x1C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x38, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x0F, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xC0, 0x00, 0x00, 0x00
};

uint8_t Punctuate(char mark)
{
	switch (mark)
	{
		case '!': return EXCLAMATION; break;
		case '"' : return DQUOTE; break;
		case '#' : return HASH; break;
		case '$' : return DOLLAR; break;
		case '%' : return PERCENT; break;
		case '&' : return AMPERSAND; break;
		case '\'' : return SQUOTE; break;
		case '(' : return OBRACKET; break;
		case ')' : return CBRACKET; break;
		case '*' : return ASTERISK; break;
		case '+' : return PLUS; break;
		case ',' : return COMMA; break;
		case '-' : return DASH; break;
		case '.' : return DOT; break;
		case '/' : return FSLASH; break;
		case '0' : return ZERO; break;
		case ':' : return COLON; break;
		case ';' : return SCOLON; break;
		case '<' : return LTHAN; break;
		case '=' : return EQUALS; break;
		case '>' : return GTHAN; break;
		case '?' : return QUESTION; break;
		case '@' : return AT; break;
		case 'A' : return CAPA; break;
		case '[' : return OSQUARE; break;
		case '\\' : return BSLASH; break;
		case ']' : return CSQUARE; break;
		case '^' : return CARET; break;
		case '_' : return USCORE; break;
		case '`' : return OQUOTE; break;
		case 'a' : return LOWERA; break;
		case '{' : return OCURL; break;
			case '|' : return PIPE; break;
		case '}' : return CCURL; break;
		case '~' : return TILDE; break;
		
	}
	return QUESTION;
}

void WriteText(const FONT_INFO *fontp, const char text[], uint8_t x, uint8_t y, uint8_t orient )
{
	
	//uint8_t chars[sizeof(text)];
	uint8_t nChars = (strlen(text));
	uint8_t chars[nChars]={0};
	
	uint8_t width=0;

	
	//for (uint8_t i=0; i<sizeof(text);i++)
	for (uint8_t i=0; i<nChars;i++)
	{
		if ((uint8_t)text[i]==0x20) width=width+fontp->spacePixels;
		else
		{
			if ((uint8_t)text[i]>=0x41 && (uint8_t)text[i]<=0x5A) chars[i]=(uint8_t)text[i]-0x41+CAPA;
			if ((uint8_t)text[i]>=0x61 && (uint8_t)text[i]<=0x7A) chars[i]=(uint8_t)text[i]-0x61+LOWERA;
			if ((uint8_t)text[i]>=0x30 && (uint8_t)text[i]<=0x39) chars[i]=(uint8_t)text[i]-0x30+ZERO;
			if (chars[i]==0) chars[i]=Punctuate(text[i]);
			width=width+pgm_read_byte(&(fontp->charInfo[chars[i]].widthBits))+2;
		}
	}
	switch(orient)
	{
		case LEFT: x=0; break;
		case CENTRE: x=64-(width/2); break;
		case RIGHT: x=128-width; break;
	}
	//for (uint8_t i=0; i<sizeof(text);i++)
	for (uint8_t i=0; i<nChars;i++)
	{
		if ((uint8_t)text[i]==0x20) x=x+fontp->spacePixels;
		else
		{
			fb.drawBitmap(fontp->data +pgm_read_word(&(fontp->charInfo[chars[i]].offset)),fontp->heightPixels,pgm_read_byte(&(fontp->charInfo[chars[i]].widthBits)),x,y);
			x=x+pgm_read_byte(&(fontp->charInfo[chars[i]].widthBits))+2;
		}
	}
	
}

void Byte2String (char* outstr ,uint8_t u8t)
{
	
	if((uint8_t)u8t/100==0){
		outstr[0]=0x20;
	} else {
		outstr[0]=0x30 + (uint8_t)u8t/100;
	}	
	
	if((uint8_t)u8t/100==0 && (uint8_t)(u8t%100)/10==0){
		outstr[1]=0x20;
	} else {
		outstr[1]= 0x30 + (uint8_t)(u8t%100)/10;
	}
	
	outstr[2]=0x30 + (uint8_t)(u8t%10);
}


ISR(TIMER1_COMPA_vect) { 

	TC++;
	if ((PIND & (1<<DDD3))) {
		
//		fb.buffer[(uint16_t)(TC%8)*128+(TC/8)]=0xFF;
		buffer[(uint16_t)TC/8] |= (1<<(TC%8));
	
	} else {
//		fb.buffer[(uint16_t)(TC%8)*128+(TC/8)]=0x00;	
		buffer[(uint16_t)TC/8] &= ~(1<<(TC%8));
	
	}
	if (TC>=1000) {
		TC=0;

	}	

	if (TC==LEdge) { 
		TICK=true;	
		TC=0;
		LEdge=0;
	}

}



int main(void)
{
	// millisecond counter and buffer access variables
	uint16_t i=0;
	uint16_t x=0;
	uint16_t y=0;
	
	// Leading Edge detection variables
	uint16_t LEdgeSMin=0; // bottom of leading edge search range
	uint8_t LEdgeSRange=100; // leading edge search bin size - effectively acts as Ledge Search mode too
	uint8_t LEdgeCount[10]={0}; // count of hits in each bin for current second
	uint8_t LEdgeSum[10]={0};	// count of consecutive seconds that a bin has had a hit
	uint8_t LEMax=0; // bin with highest number of consecutive hits
	uint8_t LE2Max=0; // bin with second highest number of consecutive hits
	uint8_t LESecsInMode=0; // number of seconds that we have been in this LEdge Search mode
	
	// Leading Edge adjustment variables
	bool LEdgeDetect= false;
	
	// Time decoding variables
	bool MMarkFound=false; // has the Minute Marker been found
	uint8_t SigSecond=0; // what second are we at during the minute?
	uint8_t BitASample=0; // for counting the strikes in the BitA window 
	uint8_t BitBSample=0; // for counting the strikes in the BitB window
	uint8_t BitCSample=0; // for counting the strikes in the remainder of the first half of the second
	bool BitA[60]={false}; // BitA array (one minute's worth)
	bool BitB[60]={false}; // BitB array (one minute's worth)
	bool BitC=false; // BitC - just for the current second as it has no use other than for the minute marker
	uint8_t SigMinute=0;
	uint8_t SigHour=0;
	uint8_t SigDoW=0;
	uint8_t SigDay=0;
	uint8_t SigMonth=0;
	uint8_t SigYear=0;
		
	bool PinState=false;
	bool PrevPinState=false;
	
	// Character array for displaying bytes as text
	char BString[4]="   ";
	
	// Show splash-screen
	fb.clear();
	fb.drawBitmap(Atomic,64,64,32,0);
	fb.show();
	_delay_ms(3000);
	fb.clear();
	fb.show();


	// Enable atomic clock pulse pin for input
	DDRD &= ~(1<<DDD3);// // pin PC3
	PORTD |= (1<<DDD3); //  pin PC3 set to pulled-up
	
	
	// Initialise ticker
	TCCR1B |= (1 << WGM12); // Configure timer 1 for CTC mode
	TCCR1B |= (1 << CS11); // Start timer at Fcpu/8
	TIMSK1 |= (1 << OCIE1A); // Enable CTC interrupt
	sei(); // Enable global interrupts
	OCR1A = 1999; // Set CTC compare value to 1000Hz at 16MHz AVR clock, with a prescaler of 8
	
	
	
	/* Replace with your application code */
	while (1)
	{
		while (!TICK); // wait for a tick
		TICK=false;
		
		fb.clear();

		

		// Leading Edge Search Region below
		#pragma region LeadingEdgeSearch
		if (LEdgeSearch) {		
			
			fb.drawRectangle(10,12,113,25); // main signal window - shows whole second
			for (uint8_t j=0; j<=49; j++) {
				fb.drawPixel(12+j*2,43);
			}
			
			if (LEdgeSRange==100) WriteText(&IM8_FontInfo,"Search : 100ms",63,0,CENTRE);
			if (LEdgeSRange==10) {
				WriteText(&IM8_FontInfo,"Search : 10ms",63,0,CENTRE);
				fb.drawRectangle(10,31,113,40);
				Byte2String(BString,20-LESecsInMode);
				WriteText(&IM8_FontInfo,BString,127,0,RIGHT);
			}
			
			x=0;  // Buffer byte counter
			y=0;  // Buffer bit counter
			for (i=0; i<=999; i++) {   // millisecond counter
				y++;
				if (y==8) {  
					y=0;
					x++;
				}
				PrevPinState=PinState;
				PinState=CHECK_BIT(buffer[x],y);  // read pin state
			
				if (i>=LEdgeSMin && i<=LEdgeSMin+(10*LEdgeSRange)-1) // id ms counter within Leading Edge search range
				{
					if (!PrevPinState && PinState) 	LEdgeCount[(i-LEdgeSMin)/LEdgeSRange]++; // leading Edge found, increment counter for current bin
					if (PinState && LEdgeSRange==10) fb.drawVLine(12+(i-LEdgeSMin),33,6);
				}
				if (PinState) fb.drawPixel((i/10)+12,(i%10)+14); // draw pixel to show raw signal
				
			}

			for(uint8_t j=0; j<=9; j++){
				
				if (LEdgeCount[j]>=1) {  // increment counter if there has been a hit in this bin this second
					LEdgeSum[j]++;
				}
				else
				{
					LEdgeSum[j]=0;  // else set count of number of consecutive seconds to zero
				}
				fb.drawRectangle(12+(j*10),63-LEdgeSum[j]*2,12+((j+1)*10),63);  // display bar for bin on OLED screen
				LEdgeCount[j]=0;  // reset count of hits this second ready for next second
			}

			for(uint8_t j=0; j<=9; j++){  // identify bins with first and second highest counts of leading edges
				if(LEdgeSum[j]>LEdgeSum[LEMax]) {LE2Max=LEMax; LEMax=j;}
				if(LEdgeSum[j]>LE2Max && LEdgeSum[j]<LEMax) LE2Max=j;
			}


			if (LEdgeSRange==100 && LEdgeSum[LEMax]>=10) { // one of the 100ms-wide bins has more than 10 consecutive hits
				LEdgeSRange=10; // so we're going to narrow the search with 10ms wide bins ...
				LEdgeSMin=100*LEMax; // ... in the bin that had the most consecutive hits
				for(uint8_t j=0; j<=9; j++) { // reset the bin counts
					LEdgeSum[j]=0; 
				}
			}

			if (LEdgeSRange==10) {
				fb.drawVLine(12+(LEdgeSMin/100)*10,25,5); // Mark range that we're searching in with two small v lines
				fb.drawVLine(12+((LEdgeSMin/100)+1)*10,25,5);
				LESecsInMode++;
				if (LESecsInMode>=20) { // we've been searching in 10ms bins for 30 seconds now, so revert to 100ms bins
					LEdgeSRange=100;
					LEdgeSMin=0;
					for(uint8_t j=0; j<=9; j++) { // reset the bin counts
						LEdgeSum[j]=0;
					}	
					TC=TC+(rand() & 0xFF);
					LESecsInMode=0;			
				}
				
				if (LEdgeSum[LEMax]>=10){  // *** START OF SECOND FOUND ***
					LEdge=LEdgeSMin+(LEMax*10)+5; // << This is what we'll treat as the start of the second
					LEdgeSMin=0; // reset these variables ready for next time
					LEdgeSRange=100;
					for(uint8_t j=0; j<=9; j++) { // reset the bin counts
						LEdgeSum[j]=0;
					}		
					LEdgeSearch=false;		
				}
			}
		}
		#pragma endregion
		
		// --------------------------------------------------------------------------------------

		if (!LEdgeSearch) {	
			
			// Display mode at top of OLED, draw box around signal with segment marks
			if (!MMarkFound) {
				WriteText(&IM8_FontInfo,"Min mark search",63,0,CENTRE);
			} else {
				WriteText(&IM8_FontInfo,"Min mark found",63,0,CENTRE);
			}
			fb.drawRectangle(10,12,113,25); // signal window (shows whole second)
			fb.drawVLine(22,25,3);
			fb.drawVLine(32,25,3);
			fb.drawVLine(42,25,3);
			fb.drawVLine(62,25,3);
			
			// increment signal second counter if MMark found
			if (MMarkFound) {
				SigSecond++;
				if (SigSecond>=60) SigSecond=0;
			}
			
			// DISPLAY SIGNAL AND BIT BOUNDARIES
			x=0;  // Buffer byte counter
			y=0;  // Buffer bit counter	
			LEdgeDetect=false; // no edge detected yet
			
			BitASample=0;
			BitBSample=0;
			BitCSample=0;

			BitA[SigSecond]=false;
			BitB[SigSecond]=false;
			BitC=false;
			
			for (i=0; i<=999; i++) {
				y++;
				if (y==8) {
					y=0;
					x++;
				}

				PinState=CHECK_BIT(buffer[x],y);  // read pin state
				
				//if (!LEdgeDetect && PinState && i<25) { // adjust tick counter for drift
					//TC=TC-i;
					//LEdgeDetect=true;
				//}
	
				if (PinState) fb.drawPixel((i/10)+12,(i%10)+14); // draw pixel to show raw signal
					
				if (PinState && i>=100 && i<=199) BitASample++;
				if (PinState && i>=200 && i<=299) BitBSample++;
				if (PinState && i>=300 && i<=499) BitCSample++;
				
				if (i==500) {  // resolve samples into bits
					if (BitASample>=85) BitA[SigSecond]=true;
					if (BitBSample>=85) BitB[SigSecond]=true;
					if (BitCSample>=170) BitC=true;

					if (!MMarkFound && BitA[0] && BitB[0] && BitC) { // test for minute marker if not found
						MMarkFound=true;
						SigSecond=0;
					}

					if (!MMarkFound) {					
						// if no minute marker found display bit samples and results 
						WriteText(&IM8_FontInfo,"BitA",0,30,LEFT);
						WriteText(&IM8_FontInfo,BitA[SigSecond] ? "1" : "0",35,30,FREEPOS);
						Byte2String(BString,BitASample);
						WriteText(&IM8_FontInfo,BString,45,30,FREEPOS);

						WriteText(&IM8_FontInfo,"BitB",0,42,LEFT);
						WriteText(&IM8_FontInfo,BitB[SigSecond] ? "1" : "0",35,42,FREEPOS);
						Byte2String(BString,BitBSample);
						WriteText(&IM8_FontInfo,BString,45,42,FREEPOS);

						WriteText(&IM8_FontInfo,"BitC",0,54,LEFT);
						WriteText(&IM8_FontInfo,BitC ? "1" : "0",35,54,FREEPOS);
						Byte2String(BString,BitCSample);
						WriteText(&IM8_FontInfo,BString,45,54,FREEPOS);
								
						BitASample=0; // reset samples ready for next second
						BitBSample=0;
						BitCSample=0;											
					}
					
					if (MMarkFound) { // if minute marker found...
						// ... interpret data collected
						if (SigSecond==24) SigYear=BitA[17]*80 + BitA[18]*40 + BitA[19]*20 + BitA[20]*10 + BitA[21]*8 + BitA[22]*4 + BitA[23]*2 + BitA[24];
						if (SigSecond==29) SigMonth=BitA[25]*10 + BitA[26]*8 + BitA[27]*4 + BitA[28]*2 + BitA[29];
						if (SigSecond==35) SigDay=BitA[30]*20 + BitA[31]*10 + BitA[32]*8 + BitA[33]*4 + BitA[34]*2 + BitA[35];
						if (SigSecond==38) SigDoW=BitA[36]*4 + BitA[37]*2 + BitA[38];
						if (SigSecond==44) SigHour=BitA[39]*20 + BitA[40]*10 + BitA[41]*8 + BitA[42]*4 + BitA[43]*2 + BitA[44];
						if (SigSecond==51) SigMinute=BitA[45]*40 + BitA[46]*20 + BitA[47]*10 + BitA[48]*8 + BitA[49]*4 + BitA[50]*2 + BitA[51];

						if (SigSecond>=24) {
							Byte2String(BString,SigYear);
							WriteText(&IM8_FontInfo,BString,40,30,FREEPOS);
						}
						if (SigSecond>=29) {
							Byte2String(BString,SigMonth);
							WriteText(&IM8_FontInfo,BString,20,30,FREEPOS);
						}
						if (SigSecond>=35) {
							Byte2String(BString,SigDay);
							WriteText(&IM8_FontInfo,BString,0,30,FREEPOS);
						}
						if (SigSecond>=38) {
							Byte2String(BString,SigDoW);
							WriteText(&IM8_FontInfo,BString,70,30,FREEPOS);
						}
						if (SigSecond>=44) {
							Byte2String(BString,SigHour);
							WriteText(&IM8_FontInfo,BString,0,42,FREEPOS);
						}
						if (SigSecond>=51) {
							Byte2String(BString,SigMinute);
							WriteText(&IM8_FontInfo,BString,20,42,FREEPOS);
						}
						
						
					}
					
				}
			
			
			}
			
			if (MMarkFound) {
				Byte2String(BString,SigSecond);
				WriteText(&IM8_FontInfo,BString,128,0,RIGHT);
			}
		}
		// --------------------------------------------------------------------------------------


		
		fb.show(); // update OLED screen
		
		
	}
}

