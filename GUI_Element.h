#ifndef GUI_Element
#define GUI_Element

#include <Adafruit_ILI9341.h>

class SimpleSwitch {
	public:
		SimpleSwitch(int x, int y, int width, int height,
					int color, void (*func)(), Adafruit_ILI9341 *lcd);
		void updateAndDraw(int x, int y);
	private:
		bool checkTouch(int x, int y);
		int _x;
		int _y;
		int _width;
		int _height;
		int _color;
		void (*_func)();
		Adafruit_ILI9341 *_lcd;
		bool _last_touch;
};

class ToggleSwitch {
	public:
		ToggleSwitch(int x, int y, int width, int height,
			int off_color, int on_color, void (*off_func)(),
			void (*on_func)(), Adafruit_ILI9341 *lcd);
		void updateAndDraw(int x, int y);
	private:
		bool checkTouch(int x, int y);
		int _x;
		int _y;
		int _width;
		int _height;
		int _off_color;
		int _on_color;
		void (*_off_func)();
		void (*_on_func)();
		Adafruit_ILI9341 *_lcd;
		bool _toggle_state;
		bool _last_touch;
};

class Slider {
	public:
		Slider(int x, int size, int color, float *parameter,
			float init, float min, float max, Adafruit_ILI9341 *lcd);
		void updateAndDraw(int x, int y);
	private:
		bool checkTouch(int x, int y);
		int _x;
		int _size;
		int _color;
		float *_parameter;
		float _init;
		float _min;
		float _max;
		Adafruit_ILI9341 *_lcd;
		int _length;
};

#endif