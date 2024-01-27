#include <GUI_Elements.h>

// simple momentary switch to call a function on button release
SimpleSwitch::SimpleSwitch(int x, int y, int width, int height,
						int color, void (*func)()) {
	_x=x;
	_y=y;
	_width=width;
	_height=height;
	_color=color;
	_func=func;
}

void SimpleSwitch::updateAndDraw(int x, int y) {
	if (checkTouch(x,y)) {
		//code
	}
	else {
		//code
	}
}

bool SimpleSwitch::checkTouch(int x, int y) {
	return ((x>=_x)&&(y>=_y)&&(x<=_x+_width)&&(y<=_y+_height));
}

//toggle switch to call a function on button release depending on toggle state
ToggleSwitch::ToggleSwitch(int x, int y, int width, int height,
						int off_color, int on_color, void (*off_func)(),
						void (*on_func)()) {
	_x=x;
	_y=y;
	_width=width;
	_height=height;
	_off_color=off_color;
	_on_color=on_color;
	_off_func=off_func;
	_on_func=on_func;
	
	_toggle_state=true;
	_last_touch=true;
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
	return ((x>=_x)&&(y>=_y)&&(x<=_x+_width)&&(y<=_y+_height));
}

//vertical slider to change value of a parameter
Slider::Slider(int x, int y, int size, int color, float *parameter,
			float init, float min, float max, Adafruit_ILI9341 *ts) {
	_x=x;
	_y=y;
	_size=size;
	_color=color;
	_parameter=parameter;
	_init=init;
	_min=min;
	_max=max;
	_ts=ts;
}

void Slider::updateAndDraw(int x, int y) {
	if (checkTouch(x,y)) {
		//code
	}
}

bool Slider::checkTouch(int x, int y) {
	return ((x>=_x-_size/2)&&(x<=_x+size/2.0));
}