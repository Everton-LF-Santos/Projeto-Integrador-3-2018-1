/* -----------------------------------------------------------------------------
 * Project:     Project Name
 * File:        fileName.c
 * Author:      Project Author
 * Created:		2017-03-16
 * Modified:	2017-03-16
 * Version:     1.0
 * Purpose:     What this project does.
 * -------------------------------------------------------------------------- */

// -----------------------------------------------------------------------------
// System definitions ----------------------------------------------------------

#define F_CPU 16000000UL

// -----------------------------------------------------------------------------
// Header files ----------------------------------------------------------------

#include "globalDefines.h"
#include "ATmega328.h"


// -----------------------------------------------------------------------------
// Project definitions ---------------------------------------------------------

// -----------------------------------------------------------------------------
// New data types --------------------------------------------------------------
typedef union systemFlags_t{
	struct{
		uint8 update_Buffer	: 1;
		uint8 adc_Conv_Flag	: 1;
		uint8 unused_Bits	: 6;
	};
	uint8 allFlags;
} systemFlags_t;
// -----------------------------------------------------------------------------
// Function declaration --------------------------------------------------------

// -----------------------------------------------------------------------------
// Global variables ------------------------------------------------------------
volatile systemFlags_t systemFlags;
volatile uint8 emc_read = 0;
// -----------------------------------------------------------------------------
// Main function ---------------------------------------------------------------

int main(void)
{
	// INPUT/OUTPUT Config
	DDRB = 0x01;
	
	adcConfig(ADC_MODE_AUTO_TIMER1_COMPB, ADC_REFERENCE_POWER_SUPPLY, ADC_PRESCALER_OFF);
	adcDataPresentation(ADC_LEFT_ADJUSTED);
	adcSelectChannel(ADC_CHANNEL_0);
	adcDisableDigitalInput(ADC_CHANNEL_0);
	adcEnable();
	adcActivateInterrupt();
	
	
	// Usart Config
	usartConfig(USART_MODE_ASYNCHRONOUS, USART_BAUD_9600, USART_DATA_BITS_8, USART_PARITY_NONE, USART_STOP_BIT_SINGLE);
	usartActivateTransmissionCompleteInterrupt();
	usartEnableTransmitter();
	usartStdio();
	
	timer1Config(TIMER_B_MODE_CTC, TIMER_A_PRESCALER_OFF);
	timer1SetCompareAValue(14746);
	
	// Variable declaration
	uint8_t bt_buffer[10];
	uint8 bf_index = 0;
	
	// Variable initialization
	systemFlags.adc_Conv_Flag = 0;
	systemFlags.update_Buffer = 0;
	
	// Enable Global Interrupts
	sei();

	while(1)
	{
		if(systemFlags.update_Buffer)
		{
			//usartTransmit(emc_read);
			printf("%d\n", emc_read);
			systemFlags.update_Buffer = 0;
		}		
	}

	return 0;
}

// -----------------------------------------------------------------------------
// Interruption handlers -------------------------------------------------------

ISR(ADC_vect)
{
	cplBit(PORTB, 0);
	emc_read = ADCH;
	systemFlags.update_Buffer = 1;
	timer1ClearCompareBInterruptRequest();
}
// -----------------------------------------------------------------------------

// Function definitions --------------------------------------------------------
