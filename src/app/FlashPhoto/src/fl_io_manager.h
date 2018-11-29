/*******************************************************************************
 * Name            : io_manager.h
 * Project         : FlashPhoto
 * Module          : io_manager
 * Description     : Header for IoManager class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : Wed Sep 21 20:40:20 2016
 * Original Author : jharwell
 *
 ******************************************************************************/

#ifndef PROJECT_ITERATION3_SRC_APP_FLASHPHOTO_SRC_FL_IO_MANAGER_H_
#define PROJECT_ITERATION3_SRC_APP_FLASHPHOTO_SRC_FL_IO_MANAGER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "GL/glui.h"
#include "lib/libimgtools/src/imgtools.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The manager for I/O operations in FlashPhoto. This includes
 * initializing GLUI control elements related to image loading/saving, as well
 * as handling the load/save operations themselves. The load operation includes
 * validating the image type and filesystem permissions before the load will
 * proceed. It also handles loading an image from a file to the stamp.
 */

class FLIOManager : public IOManager {
 public:
  FLIOManager();
  ~FLIOManager() {}

  /**
   * @brief Initialize GLUI control elements for IO management
   *
   * @param glui GLUI handle
   * @param s_gluicallback Callback to install
   * @return The initialized IO panel handle
   */
  GLUI_Panel* InitGlui(const GLUI *const glui,
                        void (*s_gluicallback)(int));
};

}  /* namespace image_tools */

#endif  /* PROJECT_ITERATION3_SRC_APP_FLASHPHOTO_SRC_FL_IO_MANAGER_H_ */
