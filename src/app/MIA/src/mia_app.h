/*******************************************************************************
> * Name            : mia_app.h
 * Project         : MIA
 * Module          : App
 * Description     : Header file for MIA class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 5/15/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

#ifndef PROJECT_ITERATION3_SRC_APP_MIA_SRC_MIA_APP_H_
#define PROJECT_ITERATION3_SRC_APP_MIA_SRC_MIA_APP_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "lib/libimgtools/src/imgtools.h"
#include "app/MIA/src/mia_filter_manager.h"
#include "app/MIA/src/mia_io_manager.h"
#include "app/MIA/src/tool_factory.h"
/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief MIA app supper class definition
 *
 */
class MIAApp : public BaseGfxApp {
 public:
  /**
   * @brief MIA app constructor
   *
   */
  MIAApp(int width, int height, const std::string& marker_fname);
  virtual ~MIAApp(void);

  void MouseDragged(int x, int y);
  void MouseMoved(int x, int y) {}
  void LeftMouseDown(int x, int y);
  void LeftMouseUp(int x, int y) {}
  /**
   * @brief display
   *
   */
  void Display(void);
  void GluiControl(int control_id);

  /**
   * @brief Initialize MIA
   *
   * @param[in] argc Unused--required by BaseGfxApp
   * @param[in] argv Unused--required by BaseGfxApp
   * @param[in] x Unused--required by BaseGfxApp
   * @param[in] y Unused--required by BaseGfxApp
   * @param[in] background_color The initial canvas color
   */
  void Init(
      int argc,
      char *argv[],
      int x,
      int y,
      ColorData background_color);

 private:
  /**
   * @brief Initialize the GLUI interface
   *
   */
  void InitGlui(void);
/**
   * @brief Initialize the Graphic interface
   *
   */
  void InitGraphics(void);

  /**
   * @brief Initialize the buffers for the main window
   */
  void InitializeBuffers(ColorData initial_color,
                         int width, int height);

  /* Copy/move assignment/construction disallowed */
  MIAApp(const MIAApp &rhs) = delete;
  MIAApp& operator=(const MIAApp &rhs) = delete;

  /**
   * @brief Manager for all filter operations
   */
  MIAFilterManager filter_manager_;

  /**
   * @brief Manager for all I/O operations
   */
  MIAIOManager io_manager_;

  /**
   * @brief Manager for redo/undo stack
   */
  StateManager state_manager_;

   /**
   * @brief This is the pointer to the buffer where the display PixelBuffer is stored
   */
  PixelBuffer* display_buffer_;
  /**
   * @brief the path to marker file
   */
  std::string marker_fname_;
 /**
   * @brief  Currently selected tool from UI
   */
  int cur_tool_;
 /**
   * @brief These are used to store the selections from the GLUI user interface
   */
  Tool **tools_;
 /**
   * @brief  Previous mouse coordinates for interpolating mouse moves
   */
  int mouse_last_x_;
 /**
   * @brief  Previous mouse coordinates for interpolating mouse moves
   */
  int  mouse_last_y_;
 /**
   * @brief set the current color to red
   */
  float cur_color_red_ = 1.0;
 /**
   * @brief  set the current color to green
   */
  float cur_color_green_ = 0.0;
 /**
   * @brief  set the current color to blue
   */
  float cur_color_blue_ = 0.0;
};

}  /* namespace image_tools */

#endif  // PROJECT_ITERATION3_SRC_APP_MIA_SRC_MIA_APP_H_
