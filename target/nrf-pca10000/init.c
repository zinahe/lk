/*
 * Copyright (c) 2012 Travis Geiselbrecht
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */
#include <lk/err.h>
#include <lk/debug.h>
#include <target.h>
#include <lk/compiler.h>
#include <dev/gpio.h>
#include <kernel/timer.h>
#include <platform/gpio.h>
#include <platform/nrf51.h>
#include <target/gpioconfig.h>

void target_early_init(void) {
    NRF_CLOCK->XTALFREQ = CLOCK_XTALFREQ_XTALFREQ_16MHz;

    /* configure the usart1 pins */
    gpio_config(GPIO_LED1, GPIO_OUTPUT);
    gpio_config(GPIO_LED2, GPIO_OUTPUT);
    gpio_config(GPIO_LED3, GPIO_OUTPUT);

    gpio_set(GPIO_LED1,1);
    gpio_set(GPIO_LED2,1);
    gpio_set(GPIO_LED3,1);

    gpio_config(UART0_RTS_PIN, GPIO_OUTPUT);
    gpio_set(UART0_RTS_PIN,0);              //placate flow control requirements of pca10000

    nrf51_debug_early_init();
}

void target_init(void) {
    nrf51_debug_init();
    dprintf(SPEW,"Target: PCA10000 DK...\n");
}
