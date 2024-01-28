#include <GUI_Element.h>

// simple momentary switch to call a function on button release
SimpleSwitch::SimpleSwitch() = default;

SimpleSwitch::SimpleSwitch(int x, int y, int width, int height, int color,
							void (*func)(), Adafruit_ILI9341 *lcd) {								
	_x = x;
	_y = y;
	_width = width;
	_height = height;
	_color = color;
	_func = func;
	_lcd = lcd;
}

void SimpleSwitch::setSpecs(int x, int y, int width, int height, int color,
							void (*func)(), Adafruit_ILI9341 *lcd) {								
	_x = x;
	_y = y;
	_width = width;
	_height = height;
	_color = color;
	_func = func;
	_lcd = lcd;
}

//call this every loop to update (including drawing for the first
//time) state of button and call corresponding function(s)
void SimpleSwitch::updateAndDraw(int x, int y) {
	if (checkTouch(x,y)) {
		//code
	}
	else {
		//code
	}
}

bool SimpleSwitch::checkTouch(int x, int y) {
	return ((x >= _x) && (y >= _y) && (x <= _x+_width) && (y <= _y+_height));
}

//toggle switch to call a function on button release depending on toggle state
ToggleSwitch::ToggleSwitch() = default;

ToggleSwitch::ToggleSwitch(int x, int y, int width, int height,
							int off_color, int on_color, void (*off_func)(),
							void (*on_func)(), Adafruit_ILI9341 *lcd) {
	_x = x;
	_y = y;
	_width = width;
	_height = height;
	_off_color = off_color;
	_on_color = on_color;
	_off_func = off_func;
	_on_func = on_func;
	_lcd = lcd;
	
	_toggle_state = true;
	_last_touch = true;
}

void ToggleSwitch::setSpecs(int x, int y, int width, int height,
							int off_color, int on_color, void (*off_func)(),
							void (*on_func)(), Adafruit_ILI9341 *lcd) {
	_x = x;
	_y = y;
	_width = width;
	_height = height;
	_off_color = off_color;
	_on_color = on_color;
	_off_func = off_func;
	_on_func = on_func;
	_lcd = lcd;
	
	_toggle_state = true;
	_last_touch = true;
}

void ToggleSwitch::updateAndDraw(int x, int y) {
	if (checkTouch(x,y)) {
		//code
	}
	else {
		//code
	}
}

bool ToggleSwitch::checkTouch(int x, int y) {
	return ((x >= _x) && (y >= _y) && (x <= _x+_width) && (y <= _y+_height));
}

//vertical slider to change value of a parameter
Slider::Slider() = default;

Slider::Slider(int x, int size, int color, float *parameter,
						float init, float min, float max, Adafruit_ILI9341 *lcd) {
	_x = x;
	_size = size;
	_color = color;
	_parameter = parameter;
	_init = init;
	_min = min;
	_max = max;
	_lcd = lcd;
	
	_length = 200; //pixels
}

void Slider::setSpecs(int x, int size, int color, float *parameter,
						float init, float min, float max, Adafruit_ILI9341 *lcd) {
	_x = x;
	_size = size;
	_color = color;
	_parameter = parameter;
	_init = init;
	_min = min;
	_max = max;
	_lcd = lcd;
	
	_length = 200; //pixels
}

void Slider::updateAndDraw(int x, int y) {
	if (checkTouch(x,y)) {
		//code
	}
}

bool Slider::checkTouch(int x, int y) {
	return ((x >= _x-_size/2) && (x <= _x+_size/2.0));
}