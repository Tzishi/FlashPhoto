/*******************************************************************************
 * Name            : mia_io_manager.h
 * Project         : MIO
 * Module          : io_manager
 * Description     : Header for MIA IOManager class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : Wed Sep 21 20:40:20 2016
 * Original Author : jharwell
 *
 ******************************************************************************/

#ifndef PROJECT_ITERATION3_SRC_APP_MIA_SRC_MIA_IO_MANAGER_H_
#define PROJECT_ITERATION3_SRC_APP_MIA_SRC_MIA_IO_MANAGER_H_

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
 * @brief The manager for I/O operations in MIA. This includes
 * initializing GLUI control elements related to image loading/saving, as well
 * as handling the load/save operations themselves. The load operation includes
 * validating the image type and filesystem permissions before the load will
 * proceed. It also handles loading an image from a file to the stamp.
 */
class MIAIOManager : public IOManager {
 public:
  MIAIOManager();
  ~MIAIOManager() {}

  /**
   * @brief Initialize GLUI control elements for IO management
   *
   * @param glui GLUI handle
   * @param s_gluicallback Callback to install
   * @return The initialized IO panel handle
   */
  GLUI_Panel* InitGlui(const GLUI *const glui,
                       void (*s_gluicallback)(int));

  void LoadImageToCanvas(PixelBuffer **buffer);
  /**
   * @brief load the next image in the stack
   *
   */
  void LoadNextImage(PixelBuffer **buffer);
  /**
   * @brief load previous image in the stack
   *
   */
  void LoadPreviousImage(PixelBuffer **buffer);
  void set_image_file(const std::string & fname_in);
  /**
   * @brief load image to the stamp
   *
   */
  void LoadCertainImageToStamp(PixelBuffer **buffer,
                               const std::string & fname_in);
  /**
   * @brief image name and its offset in the file
   *
   */
  std::string image_name_plus_seq_offset(const std::string& filename,
                                         int offset);

 private:
  /**
   * @brief kernel digit count
   *
   */
  const int kDigitCount = 3;

  /* Copy/move assignment/construction disallowed */
  MIAIOManager(const MIAIOManager &rhs) = delete;
  MIAIOManager& operator=(const MIAIOManager &rhs) = delete;
  /**
   * @brief previous image toggle
   *
   */
  void prev_image_toggle(bool enabled) {
    UICtrl::button_toggle(prev_image_btn_, enabled);
  }
  /**
   * @brief next image toggle
   *
   */
  void next_image_toggle(bool enabled) {
    UICtrl::button_toggle(next_image_btn_, enabled);
  }

    /**
   * @brief next image button on UI window
   *
   */
  GLUI_Button* next_image_btn_;
  /**
   * @brief previous button on the UI window
   *
   */
  GLUI_Button* prev_image_btn_;
  /**
   * @brief previous file name 
   *
   */
  std::string prev_file_name_;
  /**
   * @brief next file name
   *
   */
  std::string next_file_name_;
};

}  /* namespace image_tools */

#endif  /* PROJECT_ITERATION3_SRC_APP_MIA_SRC_MIA_IO_MANAGER_H_ */
