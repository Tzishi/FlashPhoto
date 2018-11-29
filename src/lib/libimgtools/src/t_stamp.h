/*******************************************************************************
 * Name            : t_stamp.h
 * Project         : image_tools
 * Module          : Tool
 * Description     : Header file for Stamp tool class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 4/4/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

#ifndef PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_T_STAMP_H_
#define PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_T_STAMP_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include <string>
#include "lib/libimgtools/src/tool.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief A stamp tool that is meant to be applied in a "click" rather than a
 * "click and drag" motion like all the other canvas tools. It can stamp images
 * of any size onto the canvas. The stamp image must be explicitly set after
 * initializing the stamp tool.
 *
 */
class TStamp: public Tool {
 public:
  /* constructor  */
  TStamp();
  /* destructor */
  virtual ~TStamp();

  std::string name() { return "Stamp"; }

  /* getters and setters that depend on the stamp_buffer_ not being null */
  int width() { return stamp_buffer_? stamp_buffer_->width()-1 : 0; }
  /* gets the height of the stamp_buffer_  */
  int height() { return stamp_buffer_? stamp_buffer_->height()-1 : 0; }
  /**
   * @brief The maximum value of smear not equal to 0
   * @return
   */
  void set_stamp_buffer(PixelBuffer *buffer) {
    if (stamp_buffer_) {
      delete stamp_buffer_;
    }
    stamp_buffer_ = buffer;
  }

 private:
  /**
  * @brief The maximum value of smear not equal to 0
  * @return
  */
  PixelBuffer *stamp_buffer_;
  virtual ColorData process_pixel(int mask_x, int mask_y, ColorData tool_color,
                                 PixelBuffer* buffer, int buffer_x,
                                 int buffer_y);
  /* Copy assignment/construction is disallowed */
  TStamp(const TStamp &rhs) = delete;
  /* Copy assignment/construction is disallowed */
  TStamp& operator=(const TStamp &rhs) = delete;
};

}  /* namespace image_tools */

#endif  /* PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_T_STAMP_H_ */
