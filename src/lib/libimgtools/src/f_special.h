/*******************************************************************************
 * Name            : f_special.h
 * Project         : FlashPhoto
 * Module          : filter
 * Description     : Header file for FSpecial class.
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 4/7/15
 * Original Author : Sarit Ghildayal
 *
******************************************************************************/

#ifndef PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_F_SPECIAL_H_
#define PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_F_SPECIAL_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include "lib/libimgtools/src/filter.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Implements a "night-vision" filter
 *
 */
class FSpecial: public Filter {
 public:
  PixelBuffer *GenerateFilteredBuffer(const PixelBuffer &input_buffer)const;

 private:
  /**
   * @brief generate pixel
   *
   */
  virtual ColorData GeneratePixel(const PixelBuffer &buffer,
                                   const PixelBuffer &blurred_buffer,
                                   int x, int y) const;
};

} /* namespace image_tools */

#endif  /* PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_F_SPECIAL_H_ */
