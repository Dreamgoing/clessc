#ifndef __Color_h__
#define __Color_h__

#include "Value.h"
#include <algorithm>
using namespace std;

#define RGB_RED 0
#define RGB_GREEN 1
#define RGB_BLUE 2
#define abs(x) (x < 0 ? 0 - x : x)

class Color: public Value {
private:
  unsigned int color[3];

  double maxArray(double* array, int len);
  double minArray(double* array, int len);
public:
  Color(Token* token);
  Color(unsigned int red, unsigned int green, unsigned int blue);
  virtual ~Color();

  Token* getToken();
  
  bool add(Value* v);
  bool substract(Value* v);
  bool multiply(Value* v);
  bool divide(Value* v);

  /**
   * The HSL to RGB conversion on
   * http://en.wikipedia.org/wiki/HSL_and_HSV did not work at all so
   * the calculations are from
   * http://130.113.54.154/~monger/hsl-rgb.html, which does not list a
   * source. 
   */
  void setHSL(double hue, double saturation, double lightness);
  void lighten(double percent);
  void darken(double percent);
  void saturate(double percent);
  void desaturate(double percent);
  void fadein(double percent);
  void fadeout(double percent);
  void spin(double degrees);

  /**
   * Returns the the amount of red in the color.
   *
   * @return an int value between 0-255
   */
  unsigned int getRed();
  /**
   * Returns the the amount of green in the color.
   *
   * @return an int value between 0-255
   */
  unsigned int getGreen();
  /**
   * Returns the the amount of blue in the color.
   *
   * @return an int value between 0-255
   */
  unsigned int getBlue();
  
  /**
   * Converts the internal RGB value to HSL. The source of the
   * calculations is http://en.wikipedia.org/wiki/HSL_and_HSV except
   * for the saturation value, which did not work.
   */
  double* getHSL();

  /**
   * Find the hue value for the color.
   * @see getHSL();
   */
  int getHue();

  /**
   * Find the saturation value for the color.
   * @see getHSL();
   */
  int getSaturation();

  /**
   * Find the lightness value for the color.
   * @see getHSL();
   */
  int getLightness();
};

#endif
