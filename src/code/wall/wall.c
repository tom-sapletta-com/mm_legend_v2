/*
 * file:	wall.c
 * author:	GAndaLF
 * brief:   Wall detection task.
 */

#include "platform_specific.h"

#include "led/led.h"
#include "adc/adc.h"
#include "adc2dist.h"

#include "wall.h"

/** Data structure containing internal wall module parameters. */
struct wall_params {
    int32_t front_l;
    int32_t front_r;
    int32_t diag_l;
    int32_t diag_r;
    int32_t side_l;
    int32_t side_r;
};

/** Internal wall module parameters. */
PRIVATE struct wall_params wall_data;

/**
 * Wall sensor task handler.
 *
 * @param params            Task parameters - unused.
 */
static void wall_task(void *params);

void wall_init(void)
{
    //led_init();
    //adc_init();
    /* led and adc initialized earlier by vbat task. */

    rtos_task_create(wall_task, "wall", WALL_STACKSIZE, WALL_PRIORITY);
}

int32_t wall_side_l_dist_mm_get(void)
{
    return wall_data.side_l;
}

int32_t wall_side_r_dist_mm_get(void)
{
    return wall_data.side_r;
}

int32_t wall_diag_l_dist_mm_get(void)
{
    return wall_data.diag_l;
}

int32_t wall_diag_r_dist_mm_get(void)
{
    return wall_data.diag_r;
}

int32_t wall_front_l_dist_mm_get(void)
{
    return wall_data.front_l;
}

int32_t wall_front_r_dist_mm_get(void)
{
    return wall_data.front_r;
}

static void wall_task(void *params)
{
    (void) params;

    int32_t front_r_off;
    int32_t front_l_off;
    int32_t diag_r_off;
    int32_t diag_l_off;
    int32_t side_r_off;
    int32_t side_l_off;

    int32_t front_r_on;
    int32_t front_l_on;
    int32_t diag_r_on;
    int32_t diag_l_on;
    int32_t side_r_on;
    int32_t side_l_on;

    while (1)
    {
        rtos_delay(10);

        front_r_off = adc_val_get(ADC_PHOTO_FRONT_R);

        //TODO: measure ambient line on all sensors
        //TODO: change order of lighting leds to avoid interference.
        led_on(LED_IR_FRONT_R);
        rtos_delay(1);
        front_r_on = adc_val_get(ADC_PHOTO_FRONT_R);
        wall_data.front_r = adc2dist(front_r_on - front_r_off);
        led_off(LED_IR_FRONT_R);

//        led_on(LED_IR_FRONT_L);
//        rtos_delay(1);
//        wall_data.front_l = adc_val_get(ADC_PHOTO_FRONT_L);
//        led_off(LED_IR_FRONT_L);
//
//        led_on(LED_IR_SIDE_R);
//        rtos_delay(1);
//        wall_data.side_r = adc_val_get(ADC_PHOTO_SIDE_R);
//        led_off(LED_IR_SIDE_R);
//
//        led_on(LED_IR_SIDE_L);
//        rtos_delay(1);
//        wall_data.side_l = adc_val_get(ADC_PHOTO_SIDE_L);
//        led_off(LED_IR_SIDE_L);
//
//        led_on(LED_IR_DIAG_R);
//        rtos_delay(1);
//        wall_data.diag_r = adc_val_get(ADC_PHOTO_DIAG_R);
//        led_off(LED_IR_DIAG_R);
//
//        led_on(LED_IR_DIAG_L);
//        rtos_delay(1);
//        wall_data.diag_l = adc_val_get(ADC_PHOTO_DIAG_L);
//        led_off(LED_IR_DIAG_L);
    }
}
