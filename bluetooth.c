/* -----------------------------------------------------------------------------
 * Project:     Data Loger em Catão SD
 * File:        atividade_pratica_06.c
 * Author:      Bruna Martini

 * -------------------------------------------------------------------------- */

// -----------------------------------------------------------------------------
// System definitions ----------------------------------------------------------

#define F_CPU 16000000UL

// -----------------------------------------------------------------------------
// Header files ----------------------------------------------------------------

#include <avr/io.h>
#include <avr/interrupt.h>

#include <stdio.h>
#include <string.h>
#include "globaldefines.h"
#include "atmega328.h"
#include "ds1307.h"
#include "onewire.h"
#include "ff.h"

typedef volatile union systemFlags_t {
	uint8 allFlags;
	struct {
		uint8	intzero	: 1;
		uint8 conversionReady: 1;
		uint8 unusedFlags: 7;
		uint8 flag: 1;
	};
} systemFlags_t;


volatile uint16 rawsen;
volatile uint8 adc_channel;
volatile uint8 i = 0;
volatile uint8 j = 0;

systemFlags_t systemFlags;

int main(void)
{
	//variables
	owiDevice_t device;
	uint8 deviceCount = 0;
	FRESULT res;
	FIL file;
	setBit(DDRD, PD3);


	// USART configuration
	usartConfig(USART_MODE_ASYNCHRONOUS, USART_BAUD_9600, USART_DATA_BITS_8, USART_PARITY_NONE, USART_STOP_BIT_SINGLE);
	usartEnableTransmitter();
	usartEnableReceiver();
	usartStdio();


	sei();		//habilita interrupçoes

	systemFlags.allFlags = 0;

	// TIMER1 configuration
	timer1Config(TIMER_B_MODE_CTC_ICR, TIMER_A_PRESCALER_8);
	timer1SetInputCaptureValue(100);
	timer1SetCompareBValue(100);
	timer1ClearCompareBInterruptRequest();
	timer1ActivateCompareBInterrupt();

	//ADC Configuration
	adcConfig(ADC_MODE_SINGLE_CONVERSION, ADC_REFERENCE_POWER_SUPPLY, ADC_PRESCALER_128);
	adcSelectChannel(ADC_CHANNEL_1);
	adcDataPresentation(ADC_LEFT_ADJUSTED);
	adc_channel = ADC_CHANNEL_1;
	adcDisableDigitalInput(ADC_CHANNEL_1);
	adcEnable();
	adcActivateInterrupt();

	while(1) {
		if(systemFlags.conversionReady) {		//salva no arquivo data.csv
			//printf("%d ", rawsen);
			usartTransmit(rawsen);
			systemFlags.conversionReady = 0;
		}
	}
}


ISR(ADC_vect)		//Interrupçao do ADC
{
	rawsen = ADCH;
	systemFlags.conversionReady = 1;

}
ISR(TIMER1_COMPB_vect)		//Interrupçao timer1
{
	adcStartConversion();
}