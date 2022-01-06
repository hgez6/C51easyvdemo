#ifndef __OneWire_h_
#define __OneWire_h_
unsigned char OneWire_Init();
void OneWire_SendBit(unsigned char b);
unsigned char OneWire_ReceiveBit();
void OneWire_SendByte(unsigned char Byte);
unsigned char OneWire_ReceiveByte();

#endif