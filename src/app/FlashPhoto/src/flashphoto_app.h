/*******************************************************************************
 * Name            : flashphoto_app.h
 * Project         : FlashPhoto
 * Module          : App
 * Description     : Header file for FlashPhotoApp class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 2/15/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

#ifndef PROJECT_ITERATION3_SRC_APP_FLASHPHOTO_SRC_FLASHPHOTO_APP_H_
#define PROJECT_ITERATION3_SRC_APP_FLASHPHOTO_SRC_FLASHPHOTO_APP_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "lib/libimgtools/src/imgtools.h"
#include "app/FlashPhoto/src/fl_filter_manager.h"
#include "app/FlashPhoto/src/fl_io_manager.h"
#include "app/FlashPhoto/src/tool_factory.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {
/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief flash photo app class
 *
 */
class FlashPhotoApp : public BaseGfxApp {
 public:
  /**
   * @brief constructor
   *
   */
  FlashPhotoApp(int width, int height);
  virtual ~FlashPhotoApp(void);

  void MouseDragged(int x, int y);
  void MouseMoved(int x, int y);
  void LeftMouseDown(int x, int y);
  void LeftMouseUp(int x, int y);
  /**
   * @brief display
   *
   */
  void Display(void);
  void GluiControl(int control_id);

  /**
   * @brief Initialize the FlashPhotoApp
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
   * @brief Update the colors displayed on the GLUI control panel after updating
   * their values in FlashPhoto
   *
   */
  void update_colors(void);
  /**
   * @brief initialize the GLUI
   *
   */
  void InitGlui(void);
  /**
   * @brief initialize the Graphics
   *
   */
  void InitGraphics(void);

  /**
   * @brief Initialize the buffers for the main window
   */
  void InitializeBuffers(ColorData initial_color,
                         int width, int height);

  /* Copy/move assignment/construction disallowed */
  FlashPhotoApp(const FlashPhotoApp &rhs) = delete;
  FlashPhotoApp& operator=(const FlashPhotoApp &rhs) = delete;

  /**
   * @brief Manager for all filter operations
   */
  FLFilterManager filter_manager_;

  /**
   * @brief Manager for all I/O operations
   */
  FLIOManager io_manager_;

  /**
   * @brief Manager for redo/undo stack
   */
  StateManager state_manager_;

  /**
   * @brief A collection of GLUI spinners for RGB control elements.
   */
  struct {
    GLUI_Spinner *spinner_red;
    GLUI_Spinner *spinner_green;
    GLUI_Spinner *spinner_blue;
  } glui_ctrl_hooks_;

  /** Pointer to pixel data for the screen */
  PixelBuffer *display_buffer_;

  /**
   * @brief These are used to store the selections from the GLUI user interface
   *Currently selected tool from UI
   */
  int cur_tool_;
  /**
   * @brief These are used to store the selections from the GLUI user interface
   */
  Tool **tools_;
  /**
   * @brief Previous mouse coordinates for interpolating mouse moves
   */
  int mouse_last_x_;
  /**
   * @brief Previous mouse coordinates for interpolating mouse moves
   */
  int  mouse_last_y_;
  /**
   * @brief tool current color 
   */
  float cur_color_red_;
  /**
   * @brief tool current color
   */
  float cur_color_green_;
  /**
   * @brief tool current color
   */
  float cur_color_blue_;
};

}  /* namespace image_tools */

#endif  // PROJECT_ITERATION3_SRC_APP_FLASHPHOTO_SRC_FLASHPHOTO_APP_H_
