#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>
#include <stdint.h>

extern "C"{
	volatile uint8_t adc_data_rdy;
	volatile uint16_t  adc_raw;
}

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
#ifndef SIMULATOR

	if(adc_data_rdy == 1){
		ModelListener->ADC_plot_Value(adc_raw);
		adc_data_rdy = 0;
	}
#endif /* SIMULATOR*/
}
