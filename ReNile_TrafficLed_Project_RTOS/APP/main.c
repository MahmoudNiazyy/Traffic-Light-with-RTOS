#include  "../LIB/BIT_MATH.h"
#include  "../LIB/STD_TYPE.h"
#include "../MCAL/DIO/DIO_INTERFACE.h"
#include "../APP/Traffic_Led/T_Led.h"
#include "../FREE_RTOS/FreeRTOS.h"
#include "../FREE_RTOS/FreeRTOSConfig.h"
#include "../FREE_RTOS/task.h"
#include "../FREE_RTOS/semphr.h"

// CREATE SEMAPHOR KEY
xSemaphoreHandle LCD_KEY;
volatile u8 Flag = 1;
volatile u8 Flag1 = 4;
// CREATE TASK FOR BUTTON 1
void button_task1(void *pvParameters)
{

	// CHECK semaphore TAKE KEY OR NO
	if(xSemaphoreTake(LCD_KEY,0) == pdPASS)
	{
		Yellow_Disable();
		EAST_WEST_GREENDisable();
		North_South_GreenDisable();
		vSET_PIN_OUTPUT_VALUE(PORT_D,PIN_5, HIGH);

		vSET_PIN_OUTPUT_VALUE(PORT_D,PIN_4, LOW);

		Yellow_Enable();
		vTaskDelay(1000 );
		Yellow_Disable();
		EAST_WEST_GREENEnable();
		vTaskDelay(2000 );
		Yellow_Enable();
		vTaskDelay(1000 );
		// after finish Give semaphore
		xSemaphoreGive(LCD_KEY);
		Flag=1;
	}
	// Walk signal for 5 seconds
	vSET_PIN_OUTPUT_VALUE(PORT_D,PIN_5, LOW);
	vSET_PIN_OUTPUT_VALUE(PORT_D,PIN_4, HIGH);
	// DELETE TASK AFTER COMPLETE
	vTaskDelete( NULL );
}


// CREATE TASK FOR BUTTON 2
void button_task2(void *pvParameters)
{
	// CHECK semaphore TAKE KEY OR NO
	if(xSemaphoreTake(LCD_KEY,0) == pdPASS)
	{

		Yellow_Disable();
		EAST_WEST_GREENDisable();
		North_South_GreenDisable();
		vSET_PIN_OUTPUT_VALUE(PORT_D,PIN_7, HIGH);
		vSET_PIN_OUTPUT_VALUE(PORT_D,PIN_6, LOW);

		Yellow_Enable();
		vTaskDelay(1000 );
		Yellow_Disable();
		North_South_GreenEnable();
		vTaskDelay(2000 );
		Yellow_Enable();
		vTaskDelay(1000 );
		Flag = 2;
		// after finish Give semaphore
		xSemaphoreGive(LCD_KEY);
	}
	// Walk signal for 5 seconds
	vSET_PIN_OUTPUT_VALUE(PORT_D,PIN_7, LOW);
	vSET_PIN_OUTPUT_VALUE(PORT_D,PIN_6, HIGH);
	// DELETE TASK AFTER COMPLETE
	vTaskDelete( NULL );
}


// ISR FOR EXTERNAL INTERRUPT 1
// DETECT THE BUTTON IS PRESSED BY FALLING EDGE
void __vector_1 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_1 (void) {
	// Set pedestrian request for North-South direction
	// create task every press on button
	xTaskCreate(&button_task1, NULL, 70, NULL, 3, NULL);
}

// ISR FOR EXTERNAL INTERRUPT 2
// DETECT THE BUTTON IS PRESSED BY FALLING EDGE
void __vector_2 (void) __attribute__ ((signal,used, externally_visible)) ; \
void __vector_2 (void) {
	// Set pedestrian request for East-West direction
	// create task every press on button
	xTaskCreate(&button_task2, NULL, 70, NULL, 3, NULL);
}


void trafficLightControlTask(void *pvParameters) {
	while (1) {
		// North-South Green
		if(Flag == 1 ){
			North_South_GreenEnable();
			Yellow_Disable();
			EAST_WEST_GREENDisable();
			vTaskDelay(5000); // Green for 5 seconds
			// North-South Yellow
			Yellow_Enable();

			vTaskDelay(2000 ); // Yellow for 2 seconds
			// EAST-WEST GREEN
			North_South_GreenDisable();
			Yellow_Disable();
			EAST_WEST_GREENEnable();
			vTaskDelay(5000 ); // Red for 5 seconds
			// EAST-WEST Yellow

			Yellow_Enable();
			vTaskDelay(2000 ); // Yellow for 2 seconds
		}
		if (Flag == 2)
		{
			North_South_GreenDisable();
			Yellow_Disable();
			EAST_WEST_GREENEnable();
			vTaskDelay(5000 ); // Red for 5 seconds
			// EAST-WEST Yellow
			Yellow_Enable();
			vTaskDelay(2000 ); // Yellow for 2 seconds

			North_South_GreenEnable();
			Yellow_Disable();
			EAST_WEST_GREENDisable();
			vTaskDelay(5000); // Green for 5 seconds

			// North-South Yellow
			Yellow_Enable();

			vTaskDelay(2000 ); // Yellow for 2 seconds


		}
	}
}

int main()
{
	vSET_PIN_OUTPUT_VALUE(PORT_D,PIN_6,HIGH);
	vSET_PIN_OUTPUT_VALUE(PORT_D,PIN_4,HIGH);
	// SETUP ALL DIRECTION FOR LED
	vSetUp_TrafficLed_Direction();
	// SETUP ALL BUTTON DIRECTION
	vSetUp_TrafficButton_Direction();
	// CREATE COUNT SEMAPHOR
	LCD_KEY = xSemaphoreCreateCounting(1, 1);
	// CHECK CREATE DONE OR NO
	if (LCD_KEY == NULL) {
		// Handle semaphore creation failure
		while (1);
	}
	// Create task
	xTaskCreate(&trafficLightControlTask, NULL, 250, NULL, 1, NULL);
	// Start scheduler
	vTaskStartScheduler();
	while (1)
	{  }

	return 0;

}
