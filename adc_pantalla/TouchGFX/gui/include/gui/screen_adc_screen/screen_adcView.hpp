#ifndef SCREEN_ADCVIEW_HPP
#define SCREEN_ADCVIEW_HPP

#include <gui_generated/screen_adc_screen/screen_adcViewBase.hpp>
#include <gui/screen_adc_screen/screen_adcPresenter.hpp>

class screen_adcView : public screen_adcViewBase
{
public:
    screen_adcView();
    virtual ~screen_adcView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void ADC_Plot_Value(uint16_t val);
protected:
};

#endif // SCREEN_ADCVIEW_HPP
