/*******************************************************************************
 * Name            : i_jpeg_handler.h
 * Project         : image_tools
 * Module          : io_handler
 * Description     : Header file for JPEG I/O handler
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 4/2/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

#ifndef PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_I_JPEG_HANDLER_H_
#define PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_I_JPEG_HANDLER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <stdio.h>
#include <jpeglib.h>
#include <setjmp.h>
#include <string>
#include "lib/libimgtools/src/image_handler.h"
#include "lib/libimgtools/src/pixel_buffer.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Handles JPEG image loading/saving using the libjpeg library. This is a
 * static class, serving as more of a namespace for grouping common
 * functionality.
 *
 */
class IJPEGHandler : public ImageHandler {
 public:
  /**
   * @brief load image
   *
   */
  static PixelBuffer* LoadImage(const std::string file_name);
  /**
   * @brief save image
   *
   */
  static bool SaveImage(const std::string file_name,
                        const PixelBuffer* buffer);

 private:
  /**
   * @brief public members
   *
   */
  struct my_error_mgr {
  /**
   * @brief public members
   *
   */
  jpeg_error_mgr pub;
  /**
   * @brief for return to caller
   *
   */
  jmp_buf setjmp_buffer;
  };
};

} /* namespace image_tools */

#endif  /* PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_I_JPEG_HANDLER_H_ */
