/*******************************************************************************
 * Name            : color_data.h
 * Project         : BrushWork
 * Module          : utils
 * Description     : Header file for ColorData class.
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 2/15/15
 * Original Author : Seth Johnson
 *
******************************************************************************/

#ifndef PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_COLOR_DATA_H_
#define PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_COLOR_DATA_H_

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief This color data class stores color in floating point format.
 *
 * The Red, Green, Blue, and Alpha channels range from 0.0 to 1.0.
 */
class ColorData {
 public:
  ColorData(void);
  /**
   * @brief constructor with 3 args
   *
   */
  ColorData(float r, float g, float b);
  /**
   * @brief constructor with 4 argument
   *
   */
  ColorData(float r, float g, float b, float a);
  /**
   * @brief get red lolor
   *
   */
  inline void red(float r) { red_ = r; }
  /**
   * @brief get green lolor
   *
   */
  inline void green(float g) { green_ = g; }
  /**
   * @brief get blue lolor
   *
   */
  inline void blue(float b) { blue_ = b; }
  /**
   * @brief get alpha lolor
   *
   */
  inline void alpha(float a) { alpha_ = a; }
  /**
   * @brief get red lolor
   *
   */
  inline float red(void) const { return red_; }
  /**
   * @brief get green lolor
   *
   */
  inline float green(void) const { return green_; }
  /**
   * @brief get blue lolor
   *
   */
  inline float blue(void) const { return blue_; }
  /**
   * @brief get alpha lolor
   *
   */
  inline float alpha(void) const { return alpha_;}

  /**
   * @brief Get the "brightness" of the color according to a perceptual metric
   * that weights the red, green, and blue components of the color
   * non-uniformly.
   */
  float luminance(void) const;

  /**
   * @brief Return a clamped version of a ColorData instance
   *
   * All colors and the alpha value are restricted to [0.0,1.0]
   */
  ColorData clamped_color(void) const;
  /**
   * @brief Arithmetic operators (friends so that non-member functions can access
   *
   */
  friend ColorData operator* (const ColorData& a, float f);
  /**
   * @brief + operator
   *
   */
  friend ColorData operator+ (const ColorData& a, const ColorData& b);
  /**
   * @brief - operator
   *
   */
  friend ColorData operator- (const ColorData& a, const ColorData& b);
  /**
   * @brief - operator
   *
   */
  friend bool operator== (const ColorData& a, const ColorData& b);

 private:
  /**
   * @brief  get clamp value
   *
   */
  static inline float clamp_value(float input, float a, float b)
  { return input < a ? a : (input > b ? b : input);}
  /**
   * @brief private members to hold a flot value for loor
   *
   */
  float red_;
  /**
   * @brief private member
   *
   */
  float green_;
  /**
   * @brief private member
   *
   */
  float blue_;
  /**
   * @brief private member
   *
   */
  float alpha_;
};

}  /* namespace image_tools */

#endif  /* PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_COLOR_DATA_H_ */
