#include <gui/screen_adc_screen/screen_adcView.hpp>

screen_adcView::screen_adcView()
{

}

void screen_adcView::setupScreen()
{
    screen_adcViewBase::setupScreen();
}

void screen_adcView::tearDownScreen()
{
    screen_adcViewBase::tearDownScreen();
}

void screen_adcView::ADC_Plot_Value(uint16_t val){
	dynamicGraph_ADC.addDataPoint(val);
}
