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
#include "fonts/fonts.h"
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
	bool SigSecond=0; // what second are we at during the minute?
	uint8_t BitASample=0; // for counting the strikes in the BitA window 
	uint8_t BitBSample=0; // for counting the strikes in the BitB window
	uint8_t BitCSample=0; // for counting the strikes in the remainder of the first half of the second
	bool BitA[60]={false}; // BitA array (one minute's worth)
	bool BitB[60]={false}; // BitB array (one minute's worth)
	bool BitC=false; // BitC - just for the current second as it has no use other than for the minute marker
	
	bool PinState=false;
	bool PrevPinState=false;
	
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
				}
				if (PinState) fb.drawPixel(x,y); // draw pixel to show raw signal
			}

			for(uint8_t j=0; j<=9; j++){
				
				if (LEdgeCount[j]>=1) {  // increment counter if there has been a hit in this bin this second
					LEdgeSum[j]++;
				}
				else
				{
					LEdgeSum[j]=0;  // else set count of number of consecutive seconds to zero
				}
				fb.drawRectangle(j*12,63-LEdgeSum[j],(j+1)*12,63);  // display bar for bin on OLED screen
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
				fb.drawVLine((LEdgeSMin/100)*12,25,5); // Mark range that we're searching in with two small v lines
				fb.drawVLine(((LEdgeSMin/100)+1)*12,25,5);
				LESecsInMode++;
				if (LESecsInMode>=30) { // we've been searching in 10ms bins for 30 seconds now, so revert to 100ms bins
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
			
			// DISPLAY SIGNAL AND BIT BOUNDARIES
			
			x=0;  // Buffer byte counter
			y=0;  // Buffer bit counter	
			LEdgeDetect=false; // no edge detected yet
			
			BitASample=0;
			BitBSample=0;
			BitCSample=0;
			
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
							
//				if (PinState) fb.drawPixel(x,y+2); // draw pixel to show raw signal		
				if (PinState) fb.drawPixel(i/10,i%10); // draw pixel to show raw signal
				
					
				if (PinState && i>=100 && i<=199) BitASample++;
				if (PinState && i>=200 && i<=299) BitBSample++;
				if (PinState && i>=300 && i<=499) BitCSample++;
				
				if (i==500) {  // resolve samples into bits
					if (BitASample>=85) BitA[SigSecond]=true;
					if (BitBSample>=85) BitB[SigSecond]=true;
					if (BitCSample>=170) BitC=true;
					BitASample=0; // reset samples ready for next second
					BitBSample=0;
					BitCSample=0;
					if (!MMarkFound && BitA[0] && BitB[0] && BitC) { // test for minute marker if not found
						MMarkFound=true;
						SigSecond=0;
					}
				}
			
			
			}
			fb.drawVLine(9,10,3); // draw bit boundaries in signal display area
			fb.drawVLine(19,10,3);
			fb.drawVLine(29,10,3);
			fb.drawVLine(49,10,3);	
			
			if (MMarkFound) {
				fb.drawRectangle(0,60,3,63,true); // draw a filled square bottom left corner if minute marker found 
				SigSecond=SigSecond+1;
				if (SigSecond>=60) SigSecond=0;
			}
		}
		// --------------------------------------------------------------------------------------


		
		fb.show(); // update OLED screen
		
		
	}
}

