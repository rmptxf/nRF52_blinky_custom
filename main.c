/**
 * Copyright (c) 2014 - 2019, Nordic Semiconductor ASA
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form, except as embedded into a Nordic
 *    Semiconductor ASA integrated circuit in a product or a software update for
 *    such product, must reproduce the above copyright notice, this list of
 *    conditions and the following disclaimer in the documentation and/or other
 *    materials provided with the distribution.
 *
 * 3. Neither the name of Nordic Semiconductor ASA nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * 4. This software, with or without modification, must only be used with a
 *    Nordic Semiconductor ASA integrated circuit.
 *
 * 5. Any software provided in binary form under this license must not be reverse
 *    engineered, decompiled, modified and/or disassembled.
 *
 * THIS SOFTWARE IS PROVIDED BY NORDIC SEMICONDUCTOR ASA "AS IS" AND ANY EXPRESS
 * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY, NONINFRINGEMENT, AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL NORDIC SEMICONDUCTOR ASA OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
/*
   Custom Blinky 
   Author : Abdelali Boussetta 

 */


#include <stdbool.h>

#include <stdint.h>

#include "nrf_delay.h"

#include "boards.h"


int button1_state, button2_state, button3_state, button4_state;

/**
 * @brief Function for application main entry.
 */
int main(void)
{
    // Configure the buttons as inputs and Pull them Up
    nrf_gpio_cfg_input(BUTTON_1,NRF_GPIO_PIN_PULLUP);
    nrf_gpio_cfg_input(BUTTON_2,NRF_GPIO_PIN_PULLUP);
    nrf_gpio_cfg_input(BUTTON_3,NRF_GPIO_PIN_PULLUP);
    nrf_gpio_cfg_input(BUTTON_4,NRF_GPIO_PIN_PULLUP);

    // Configure the leds as outputs
    nrf_gpio_cfg_output(LED_1);
    nrf_gpio_cfg_output(LED_2);
    nrf_gpio_cfg_output(LED_3);
    nrf_gpio_cfg_output(LED_4);

    // Turn the LEDs OFF
    nrf_gpio_pin_set(LED_1); 
    nrf_gpio_pin_set(LED_2); 
    nrf_gpio_pin_set(LED_3); 
    nrf_gpio_pin_set(LED_4);
     
    while (true)
    {
      // Read the buttons states  
      button1_state = nrf_gpio_pin_read(BUTTON_1);
      button2_state = nrf_gpio_pin_read(BUTTON_2);
      button3_state = nrf_gpio_pin_read(BUTTON_3);
      button4_state = nrf_gpio_pin_read(BUTTON_4);

      if(button1_state == 0) nrf_gpio_pin_clear(LED_1); // _clear() set the pin to LOW 
      else nrf_gpio_pin_set(LED_1);                     // _set() set the pin to HIGH 

      if(button2_state == 0) nrf_gpio_pin_clear(LED_2);
      else nrf_gpio_pin_set(LED_2);

      if(button3_state == 0) nrf_gpio_pin_clear(LED_3);
      else nrf_gpio_pin_set(LED_3);

      if(button4_state == 0) nrf_gpio_pin_clear(LED_4);
      else nrf_gpio_pin_set(LED_4);

    }
}

/**
 *@}
 **/
