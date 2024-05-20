#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{

}

void Screen1Presenter::deactivate()
{

}

void Screen1Presenter::uart_Data (char *data)
{
	view.uart_Data(data);
}

void Screen1Presenter::can_Data (int data)
{
	view.can_Data(data);
}
