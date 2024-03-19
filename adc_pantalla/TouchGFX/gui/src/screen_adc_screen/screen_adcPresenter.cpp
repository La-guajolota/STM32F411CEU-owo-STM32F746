#include <gui/screen_adc_screen/screen_adcView.hpp>
#include <gui/screen_adc_screen/screen_adcPresenter.hpp>

screen_adcPresenter::screen_adcPresenter(screen_adcView& v)
    : view(v)
{

}

void screen_adcPresenter::activate()
{

}

void screen_adcPresenter::deactivate()
{

}

void screen_adcPresenter::ADC_Plot_Value(uint16_t val){
	view.ADC_Plot_Value(val);
}
