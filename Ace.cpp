/*
  Ace.cpp - Very simple library for Bourns ACE absolute encoder.
  Created by Bolkar Altuntas, March 14, 2019.
  Beerware License
*/

#include "Arduino.h"
#include "Ace.h"

Ace::Ace(int pin1, int pin2, int pin3, int pin4, int pin5, int pin6, int pin7, int pin8)
{
	_pin1 = pin1;
	_pin2 = pin2;
	_pin3 = pin3;
	_pin4 = pin4;
	_pin5 = pin5;
	_pin6 = pin6;
	_pin7 = pin7;
	_pin8 = pin8;

	pinMode(_pin1, INPUT);
	pinMode(_pin2, INPUT);
	pinMode(_pin3, INPUT);
	pinMode(_pin4, INPUT);
	pinMode(_pin5, INPUT);
	pinMode(_pin6, INPUT);
	pinMode(_pin7, INPUT);
	pinMode(_pin8, INPUT);

	digitalWrite(_pin1, HIGH);
	digitalWrite(_pin2, HIGH);
	digitalWrite(_pin3, HIGH);
	digitalWrite(_pin4, HIGH);
	digitalWrite(_pin5, HIGH);
	digitalWrite(_pin6, HIGH);
	digitalWrite(_pin7, HIGH);
	digitalWrite(_pin8, HIGH);
}

int Ace::read()
{
	int position = 0;
	uint8_t inputs = 0;

	bitWrite(inputs,0, digitalRead(_pin1));
	bitWrite(inputs,1, digitalRead(_pin2));
	bitWrite(inputs,2, digitalRead(_pin3));
	bitWrite(inputs,3, digitalRead(_pin4));
	bitWrite(inputs,4, digitalRead(_pin5));
	bitWrite(inputs,5, digitalRead(_pin6));
	bitWrite(inputs,6, digitalRead(_pin7));
	bitWrite(inputs,7, digitalRead(_pin8));

	for(int i=0; i<256; i++){
	if(_ace_map[i] == inputs){
	  position = i;
	  break;
	}
	}

	return position;
}