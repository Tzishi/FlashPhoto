/*******************************************************************************
 * Name            : pixel_buffer.h
 * Project         : BrushWork
 * Module          : utils
 * Description     : Header file for PixelBuffer class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 2/15/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

#ifndef PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_PIXEL_BUFFER_H_
#define PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_PIXEL_BUFFER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>
#include "lib/libimgtools/src/color_data.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Stores an array of ColorData, such as an image that can be drawn to
 * the screen.
 * In this class, (0,0) is the top left corner of the screen/image, which is the
 * not the same as the coordinate system defined by GLUT, where (0,0) is the
 * bottom left corner of the screen. Your implementation will need to account
 * for this.
 */
class PixelBuffer {
 public:
 /**
   * @brief Set the value for a pixel within the buffer/on the screen
   */
  PixelBuffer(int w, int h, ColorData background_color);
 /**
   * @brief Set the value for a pixel within the buffer/on the screen
   */
  PixelBuffer(const PixelBuffer&rhs);
  virtual ~PixelBuffer(void) {}
 /**
   * @brief Set the value for a pixel within the buffer/on the screen
   */
  PixelBuffer& operator=(const PixelBuffer &rhs);

  /**
   * @brief Set the value for a pixel within the buffer/on the screen
   */
  void set_pixel(int x, int y, const ColorData& color);
 /**
   * @brief Set the value for a pixel within the buffer/on the screen
   */
  inline ColorData const *data(void) const { return &pixels_[0]; }
 /**
   * @brief Set the value for a pixel within the buffer/on the screen
   */
  inline int height(void) const { return height_; }
 /**
   * @brief Set the value for a pixel within the buffer/on the screen
   */
  inline int width(void) const { return width_; }

  /**
   * @brief Get the background color that was used to initialize the PixelBuffer
   * @return The background color
   */
  const ColorData& background_color(void) const { return background_color_; }

  /**
   * @brief Get the color of a specific pixel
   * @return The color associated with a specific pixel
   */
  ColorData get_pixel(int x, int y) const;
  /**
   * @brief operator
   */
  friend bool operator== (const PixelBuffer& buf1, const PixelBuffer& buf2);

 private:
  /**
   * @brief Set the value for a pixel within the buffer/on the screen
   */
  const int width_; /**< X dimension--cannot be changed  */

  const int height_; /**< Y dimension--cannot be changed  */

  std::vector<ColorData> pixels_; /**< Raw pixel data */
  /**
   * @brief Set the value for a pixel within the buffer/on the screen
   */
  ColorData background_color_; /** Color used to initialize the pixel buffer */
};

}  /* namespace image_tools */

#endif  /* PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_PIXEL_BUFFER_H_ */
