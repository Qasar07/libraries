/*
 * Tools.cpp
 *
 *  Created on: 2014/04/10
 *      Author: sin
 */

#include <Print.h>

#include "Tools.h"

size_t printByte(Print & prn, const uint8_t p) {
	printBytes(prn, &p, 1);
}

size_t printBytes(Print & prn, const uint8_t * p, const uint8_t length, char sep) {
	size_t n = 0;
	int i = 0;
	while ( i < length ) {
		n += prn.print(*p>>4&0x0f, HEX);
		n += prn.print(*p&0x0f, HEX);
    p++;
		i++;
		if ( i < length && sep )
			n += prn.print(sep);
	}
	return n;
}

size_t printASCII(Print & prn, const uint8_t * p, const uint8_t length, char sep) {
	size_t n = 0;
	int i = 0;
	while ( i < length ) {
		if ( isprint(*p) ) {
			n += prn.print((char) *p);
		} else {
			n += prn.print("0x");
			n += prn.print(*p>>4&0x0f, HEX);
			n += prn.print(*p&0x0f, HEX);
		}
		p++;
		i++;
		if ( i < length && sep)
			n += prn.print(sep);
	}
	return n;
}


