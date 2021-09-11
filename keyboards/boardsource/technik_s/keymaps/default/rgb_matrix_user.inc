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
    int v=rgb_matrix_config.hsv.v;
    unsigned char vh=v, vm=(v>>1);
    unsigned char r=vm, g=vm, b=vm;
    enum KCOL_KEYTYPES type=get_colour_keytype (i);
    if (type==KCOL_MOD) {
        r=0; g=vh; b=0;
    } else if (type==KCOL_LAYER) {
    	r=0; g=0; b=vh;
    } else if (type==KCOL_SYMBOL) {
    	r=vh; g=vh; b=vh;
    } else if (type==KCOL_FN) {
    	r=vh; b=0; g=0x0;
    } else if (type==KCOL_NUM) {
    	r=0; b=vh;
    } else if (type==KCOL_BLANK) {
        r=0;g=0;b=0;
    }
    rgb_matrix_set_color(i, r, g, b);
  }
  return led_max < DRIVER_LED_TOTAL;
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
