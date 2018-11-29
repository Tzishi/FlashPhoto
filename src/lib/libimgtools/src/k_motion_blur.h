/*******************************************************************************
 * Name            : k_motion_blur.h
 * Project         : FlashPhoto
 * Module          : kernel
 * Description     : Header file for motion blur kernel class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 4/4/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

#ifndef PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_K_MOTION_BLUR_H_
#define PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_K_MOTION_BLUR_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "lib/libimgtools/src/kernel.h"
#include "lib/libimgtools/src/ui_ctrl.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A directional motion blurring kernel
 *
 * Defines a kernel that blurs pixels along a straight line when convolved
 * with an image.
 */
class KMotionBlur : public Kernel {
 public:
  /**
   * @brief constructor
   *
   */
  KMotionBlur(float amount, enum UICtrl::MotionBlurDirection);

 protected:
  /**
   * @brief Get intensity
   *
   */
  float get_intensity(int x, int y, float radius);

 private:
  /**
   * @brief the amount of blur effect
   *
   */
  float amount_;
  /**
   * @brief motion blur direction
   *
   */
  int direction_;
};

} /* namespace image_tools */

#endif /* PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_K_MOTION_BLUR_H_ */
