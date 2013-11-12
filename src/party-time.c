#include <pebble.h>

static Window *window;
static TextLayer *text_time_layer;

static void init(void) {
  /* Create a black background, animated window */
  window = window_create();
  window_stack_push(window, true /* Animated */);
  window_set_background_color(window, GColorBlack);

  /* Get the root layer */
  Layer *window_layer = window_get_root_layer(window);

  /* Construct a text layer with static text */
  text_time_layer = text_layer_create(GRect(7, 30, 144-7, 168-20));
  text_layer_set_text_color(text_time_layer, GColorWhite);
  text_layer_set_background_color(text_time_layer, GColorClear);
  text_layer_set_font(text_time_layer, fonts_get_system_font(FONT_KEY_BITHAM_42_BOLD));
  text_layer_set_text(text_time_layer, "Party Time!");

  /* Attach the text layer to the root layer */
  layer_add_child(window_layer, text_layer_get_layer(text_time_layer));
}

static void deinit(void) {
  window_destroy(window);
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
