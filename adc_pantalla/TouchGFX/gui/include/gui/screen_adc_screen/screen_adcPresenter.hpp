#ifndef SCREEN_ADCPRESENTER_HPP
#define SCREEN_ADCPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class screen_adcView;

class screen_adcPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    screen_adcPresenter(screen_adcView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~screen_adcPresenter() {}

    void ADC_Plot_Value(uint16_t val);

private:
    screen_adcPresenter();

    screen_adcView& view;
};

#endif // SCREEN_ADCPRESENTER_HPP
