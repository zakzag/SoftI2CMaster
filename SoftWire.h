/*
  SoftWire.h - A Wire compatible wrapper for SoftI2CMaster
  Copyright (c) 2016 Bernhard Nebel.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _SoftWire_h
#define _SoftWire_h

#include <SoftI2CMaster.h>
#include <inttypes.h>
#include "Stream.h"

#define BUFFER_LENGTH 32

// WIRE_HAS_END means Wire has end()
#define WIRE_HAS_END 1



class SoftWire : public Stream
{
private:
    uint8_t rxBuffer[BUFFER_LENGTH];
    uint8_t rxBufferIndex;
    uint8_t rxBufferLength;
    uint8_t transmitting;
    uint8_t error;
public:
    SoftWire(void);

    void begin(void);
    void end(void);
    void setClock(uint32_t);
    void beginTransmission(uint8_t);
    void beginTransmission(int);
    uint8_t endTransmission(uint8_t);
    uint8_t endTransmission(void);
    size_t write(uint8_t);
    size_t write(const uint8_t*, size_t);

    uint8_t requestFrom(uint8_t, uint8_t, uint32_t, uint8_t, uint8_t);
    uint8_t requestFrom(uint8_t, uint8_t, uint8_t);
    uint8_t requestFrom(int, int, int);
    uint8_t requestFrom(uint8_t, uint8_t);
    uint8_t requestFrom(int, int);
    int available(void);
    int read(void);
    int peek(void);
    void flush(void);
    size_t write(unsigned long);
    size_t write(long n);
    size_t write(unsigned int);
    size_t write(int n);
    using Print::write;
};

extern SoftWire wire;

#endif
