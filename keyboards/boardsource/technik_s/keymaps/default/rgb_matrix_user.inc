// !!! DO NOT ADD #pragma once !!! //

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(my_cool_effect)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

enum KCOL_KEYTYPES {
	KCOL_ALPHA,
	KCOL_NUM,
	KCOL_MOD,
	KCOL_LAYER,
	KCOL_SYMBOL,
	KCOL_BLANK,
	KCOL_FN
};

enum KCOL_KEYTYPES get_colour_keytype (int key);

// e.g: A simple effect, self-contained within a single method
static bool my_cool_effect(effect_params_t* params) {
  RGB_MATRIX_USE_LIMITS(led_min, led_max);
  for (int i = led_min; i < led_max; i++) {
    RGB_MATRIX_TEST_LED_FLAGS();
   
    enum KCOL_KEYTYPES type=get_colour_keytype (i);

    int16_t dx   = g_led_config.point[i].x - k_rgb_matrix_center.x;
    int16_t dy   = g_led_config.point[i].y - k_rgb_matrix_center.y;
    uint8_t dist = sqrt16(dx * dx + dy * dy);
    uint8_t time = scale16by8(g_rgb_timer+dist*32, qadd8(rgb_matrix_config.speed / 4, 1));
    unsigned char cost = cos8(time) >> 5;
   
    int v=rgb_matrix_config.hsv.v;
    if (v>255)
    	v = 255;
    unsigned char vh=v, vm=(v>>1);
    unsigned char uh=rgb_matrix_config.hsv.h>>1;
    if (cost > vm)
        cost = vm;
    if (uh*2>vh)
    	uh=vh>>1;
//    unsigned char um=uh>>1;
    unsigned char z=(0xFF-rgb_matrix_config.hsv.s)>>2;
    if (z>vh) 
    	z=vh;
    unsigned char r=vm-cost, g=vm, b=vm;
    if (type==KCOL_MOD) {
        r=uh; g=vh-uh; b=z;
    } else if (type==KCOL_LAYER) {
    	r=z; g=uh; b=vh;
    } else if (type==KCOL_SYMBOL) {
    	r=vh-cost; g=vh; b=vh;
    } else if (type==KCOL_FN) {
    	r=vh-uh; b=uh; g=z;
    } else if (type==KCOL_NUM) {
    	r=z; g=vm-cost; b=vh-uh*2;
    } else if (type==KCOL_BLANK) {
        r=0;g=0;b=0;
    }
    rgb_matrix_set_color(i, r, g, b);
  }
  return led_max < DRIVER_LED_TOTAL;
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
