/******************************************************************************
* Includes
******************************************************************************/
#include "cmd_func.h"
#include "esp_log.h"
#include "C:/Users/Dominykas/Desktop/CANOpen/CANopen-ESP32-nodes/Forks/Guillermo_ruffino/node_one/components/configurations/dunker.h"
//#include "CANopen.h"
/******************************************************************************
* Private definitions and macros
******************************************************************************/

/******************************************************************************
* Private types
******************************************************************************/

/******************************************************************************
* Private constants
******************************************************************************/

/******************************************************************************
* Private variables
******************************************************************************/

/******************************************************************************
* Exported variables and references
******************************************************************************/

/******************************************************************************
* Prototypes of private functions
******************************************************************************/

/******************************************************************************
* Definitions of private functions
******************************************************************************/

/******************************************************************************
* Definitions of exported functions
******************************************************************************/
void CMD_Send_Byte_GIMLI_Control (bool state) {
    uint8_t sdo_tx_data_GIMLI_open = 1;
    uint8_t sdo_tx_data_GIMLI_close = 0;

    if (state == 1) {
        CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x6304,  0x00, &sdo_tx_data_GIMLI_open, 1, 0);
	    int err =  dunker_coProcessDownloadSDO();
        if  (err < 0 ) {
            ESP_LOGE("GIMLI_CONTROL", "failed to send SDO:\n err code: %d", err);
        } 
    } else if (state == 0) {
        CO_SDOclientDownloadInitiate(CO->SDOclient[0], 0x6304,  0x00, &sdo_tx_data_GIMLI_close, 1, 0);
	    int err =  dunker_coProcessDownloadSDO();
        if  (err < 0 ) {
            ESP_LOGE("GIMLI_CONTROL", "failed to send SDO:\n err code: %d", err);
        } 
    }
}

void CMD_Send_Byte_Central_Control (bool state) {
   
        uint16_t len = 0;
						//len =  CO_OD_Entry_Length(CO->SDO[0], 0x6304, 0x00);
						ESP_LOGE("maintask", "1008 OD Length: %d", len);
						uint8_t sdo_rx_data_buffer[4];
						memset(sdo_rx_data_buffer, 0, sizeof(sdo_rx_data_buffer));

        ESP_LOGE("CENTRAL_SUPPORT_CONTROL", "tryjing to upload sdo");
        CO_SDOclientUploadInitiate(CO->SDOclient[0], 0x6304, 0, sdo_rx_data_buffer, 4, 0);
        //CO_SDOclientUploadInitiate(CO->SDOclient[0], 0x1008,  0x00, &sdo_tx_data_central_support_close, 1, 0);
        ESP_LOGE("CENTRAL_SUPPORT_CONTROL", "needto process upload");
	    int err = 0;
        err = dunker_coProcessUploadSDO();
        if  (err < 0 ) {
            ESP_LOGE("CENTRAL_SUPPORT_CONTROL", "failed to send SDO:\n err code: %d", err);
        } 
        	ESP_LOGE("mainTask", "Slave device name: %d %d %d %d\n\r Error:  %d", sdo_rx_data_buffer[0],sdo_rx_data_buffer[1], sdo_rx_data_buffer[2],sdo_rx_data_buffer[3],
																																		err);
    
}

//Darant SDO uplao minimnalus buferio dydis turi buti  4 baitai,  nes 4-7 data baitai gali buti , nors OD entry yra tik 1 baitodydzio.
