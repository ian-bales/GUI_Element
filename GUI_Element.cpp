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
	
	_last_touch = true;
	_start = true;
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
	
	_last_touch = true;
	_start = true;
}

//call this every loop to update (including drawing for the first
//time) state of button and call corresponding function(s) - no need
//to draw button before loop that checks button state
void SimpleSwitch::updateAndDraw(int x, int y) {
	if (checkTouch(x, y)) {
		if (!_last_touch) {
			_lcd->fillRect(_x, _y, _width + 6, _height + 6, ILI9341_WHITE);
			_lcd->fillRoundRect(_x + 6, _y + 6, _width, _height, 15, ILI9341_BLACK);
			_lcd->fillRoundRect(_x + 3, _y + 3, _width, _height, 15, _color);

			_last_touch=true;
		}
	}
	else if (_last_touch) {
		_lcd->fillRect(_x, _y, _width + 6, _height + 6, ILI9341_WHITE);
		_lcd->fillRoundRect(_x + 6, _y + 6, _width, _height, 15, ILI9341_BLACK);
		_lcd->fillRoundRect(_x, _y, _width, _height, 15, _color);
		
		if (!_start)
			_func();
		else
			_start=false;

		_last_touch=false;
	}
}

//touch point assuming proper rotation according to LCD screen rotation
bool SimpleSwitch::checkTouch(int x, int y) {
	return ((x >= _x) && (y >= _y) && (x <= _x + _width + 6) && (y <= _y + _height + 6));
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
	int button_color;

	if (checkTouch(x, y)) {
		if (!_last_touch) {
			if (_toggle_state)
				button_color=_on_color;
			else
				button_color=_off_color;

			_lcd->fillRect(_x, _y, _width + 9, _height + 9, ILI9341_WHITE);
			_lcd->fillRoundRect(_x + 9, _y + 9, _width, _height, 15, ILI9341_BLACK);
			_lcd->fillRoundRect(_x + 6, _y + 6, _width, _height, 15,button_color);

			_last_touch=true;
		}
	}
	else if (_last_touch) {
		_toggle_state=!_toggle_state;
		_lcd->fillRect(_x, _y, _width + 9, _height + 9, ILI9341_WHITE);
		
		if (_toggle_state) {
			_lcd->fillRoundRect(_x + 9, _y + 9, _width, _height, 15, ILI9341_BLACK);
			_lcd->fillRoundRect(_x + 3, _y + 3, _width, _height, 15, _on_color);
			_on_func();
		}
		else {
			_lcd->fillRoundRect(_x + 9, _y + 9, _width, _height, 15, ILI9341_BLACK);
			_lcd->fillRoundRect(_x, _y, _width, _height, 15, _off_color);
			_off_func();
		}

		_last_touch=false;
	}
}

bool ToggleSwitch::checkTouch(int x, int y) {
	return ((x >= _x) && (y >= _y) && (x <= _x + _width + 9) && (y <= _y + _height + 9));
}

//vertical slider to change value of a parameter
Slider::Slider() = default;

Slider::Slider(int x, int size, int color, float *parameter,
				float init, float min, float max, Adafruit_ILI9341 *lcd) {
	_x = x;
	_size = size;
	_color = color;
	_parameter = parameter;
	*parameter=init;
	_min = min;
	_max = max;
	_lcd = lcd;
	
	_length = ILI9341_TFTWIDTH-60; //pixels
	_start=true;
}

void Slider::setSpecs(int x, int size, int color, float *parameter,
						float init, float min, float max, Adafruit_ILI9341 *lcd) {
	_x = x;
	_size = size;
	_color = color;
	_parameter = parameter;
	*parameter=init;
	_min = min;
	_max = max;
	_lcd = lcd;
	
	_length = ILI9341_TFTWIDTH-60; //pixels
	_start=true;
}

void Slider::updateAndDraw(int x, int y) {	
	if (_start) {
		_lcd->fillRoundRect(_x - 2, 30, 5, _length, 2, ILI9341_DARKGREY);
		_lcd->fillRoundRect(_x - 1.5 * _size / 2, ILI9341_TFTWIDTH - (30 + _length * (*_parameter - _min) / (_max - _min) + _size / 2), 1.5 * _size, _size, 10, _color);
		_start=false;
	}
	
	if (checkTouch(x, y)) {
		_lcd->fillRect(_x - 1.5 * _size / 2, ILI9341_TFTWIDTH - (30 + _length * (*_parameter - _min) / (_max - _min) + _size / 2), 1.5 * _size, _size, ILI9341_WHITE);
		
		*_parameter = _max - (_max - _min) * (y - 30) / _length;
		
		if (*_parameter > _max)
			*_parameter = _max;
		else if (*_parameter < _min)
			*_parameter = _min;
		
		_lcd->fillRoundRect(_x - 2, 30, 5, _length, 2, ILI9341_DARKGREY);
		_lcd->fillRoundRect(_x - 1.5 * _size / 2, ILI9341_TFTWIDTH - (30 + _length * (*_parameter - _min) / (_max - _min) + _size / 2), 1.5 * _size, _size, 10, _color);
	}
}

bool Slider::checkTouch(int x, int y) {
	return ((x >= _x - 1.5 * _size / 2) && ( x <= _x + 1.5 * _size / 2));
}