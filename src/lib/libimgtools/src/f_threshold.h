/*******************************************************************************
 * Name            : f_threshold.h
 * Project         : FlashPhoto
 * Module          : filter
 * Description     : Header file for FThreshold class.
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 4/4/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

#ifndef PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_F_THRESHOLD_H_
#define PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_F_THRESHOLD_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "lib/libimgtools/src/filter.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A threshold filter
 *
 * The effect of this filter is to set the RGB components of all pixels that it
 * operates on to 1 if the RGB value is greater than the threshold, and 0
 * otherwise.
 */
class FThreshold : public Filter {
 public:
  /**
   * @brief threshold constructor
   *
   */
  explicit FThreshold(float threshold) : threshold_(threshold) {}

 private:
  /**
   * @brief generate pixel
   *
   */
  virtual ColorData GeneratePixel(const PixelBuffer & buffer,
                                   int x, int y) const;
  /**
   * @brief threshold amount
   *
   */
    float threshold_;
};

} /* namespace image_tools */


#endif  /* PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_F_THRESHOLD_H_ */
