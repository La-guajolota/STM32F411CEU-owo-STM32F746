#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

/*
 * Actualizacion de informacion en
 * la pantalla CAN y UART
 */
void Screen1View::uart_Data (char *data)
{
	//TEXTO
	TEXTO.setWideTextAction(touchgfx::WIDE_TEXT_WORDWRAP);
	Unicode::strncpy(TEXTOBuffer, data, TEXTO_SIZE);

	//GAUGE
	gauge.setValue((int)data[0]);

	gauge.invalidate();
	TEXTO.invalidate();
}

void Screen1View::can_Data (int podometro)
{

	gauge.setValue(podometro);

	//Refescamos la pantalla por paarte
	//text y memidor
	gauge.invalidate();
}
