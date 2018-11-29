/*******************************************************************************
 * Name            : f_blur.h
 * Project         : FlashPhoto
 * Module          : filter
 * Description     : Header file for FBlur class.
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 4/2/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

#ifndef PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_F_BLUR_H_
#define PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_F_BLUR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include "lib/libimgtools/src/filter_convolve.h"
#include "lib/libimgtools/src/k_gaussian.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Implements a blurring filter using a Gaussian kernel (i.e. blurs
 * equally in all directions).
 */

class FBlur : public FilterConvolve {
 public:
  /**
   * @brief constructor
   *
   */
  explicit FBlur(float amount) : FilterConvolve(new KGaussian(amount), true) {}
};

}  /* namespace image_tools */

#endif  /* PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_F_BLUR_H_ */
