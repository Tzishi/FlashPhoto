/*******************************************************************************
 * Name            : i_png_handler.h
 * Project         : image_tools
 * Module          : io_handler
 * Description     : Header file for PNG I/O handler
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 4/2/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

#ifndef PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_I_PNG_HANDLER_H_
#define PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_I_PNG_HANDLER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "lib/libimgtools/src/image_handler.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Handles PNG image loading/saving via the libpng library. This is a
 * static class, serving as more of a namespace for grouping common
 * functionality.
 *
 */
class IPNGHandler : public ImageHandler {
 public:
  /**
   * @brief load image to canvas
   *
   */
  static PixelBuffer* LoadImage(const std::string file_name);
  /**
   * @brief save image
   *
   */
  static bool SaveImage(const std::string file_name,
                        const PixelBuffer* buffer);
};

} /* namespace image_tools */

#endif  /* PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_I_PNG_HANDLER_H_ */
