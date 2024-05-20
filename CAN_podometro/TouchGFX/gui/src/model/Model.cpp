#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#ifndef SIMULATOR

#include "main.h"
#include "stdint.h"
#include "cmsis_os2.h"
#include <cstring>

extern "C"
{
	//por parte del UART
	extern osMessageQueueId_t uartQueueHandle;
	uartData_t *uartData_r;
	//por parte del CAN
	extern osMessageQueueId_t canQueueHandle;
	canData_t *canData_r;
}
#endif

Model::Model() : modelListener(0)
{

}

void Model::tick()
{
#ifndef SIMULATOR

	//Checamos la cantidad de colas
	if (osMessageQueueGetCount(uartQueueHandle)>0)
	{
		if(osMessageQueueGet(uartQueueHandle, &uartData_r, 0, 0) == osOK)
		{
			strncpy(RData, uartData_r->data, uartData_r->size);
			modelListener->uart_Data(RData);
		}
	}

	//las del can
	if (osMessageQueueGetCount(canQueueHandle)>0)
	{
		if(osMessageQueueGet(canQueueHandle, &canData_r, 0, 0) == osOK)
		{
			podometro = (int)canData_r->data[0];
			modelListener->can_Data(podometro);
		}
	}
#endif
}