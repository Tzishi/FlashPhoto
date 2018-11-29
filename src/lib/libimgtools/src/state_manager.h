/*******************************************************************************
 * Name            : state_manager.h
 * Project         : FlashPhoto
 * Module          : state_manager
 * Description     : Header for IoHandler class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : Wed Sep 21 20:40:20 2016
 * Original Author : jharwell
 *
 ******************************************************************************/

#ifndef PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_STATE_MANAGER_H_
#define PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_STATE_MANAGER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include <deque>
#include <stack>
#include "GL/glui.h"
#include "lib/libimgtools/src/ui_ctrl.h"
#include "lib/libimgtools/src/pixel_buffer.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief The manager for simulation state in FlashPhoto.
 *
 * Simulation state is defined as the sequence of operations that comprises the
 * current canvas. An operation is defined as what happens during 1 click/drag
 * operation, or when 1 button on the control panel that affects the canvas is
 * clicked.
 *
 * A sequence of undos followed by some edits, followed by more undos will
 * FIRST undo the new edits, until you get back to the state before you made the
 * edits. You will not be able to go back any further.
 */
class StateManager {
 public:
  StateManager();
  ~StateManager() {}
/**
   * @brief initialize the Glui
   */
  void InitGlui(const GLUI *const glui,
                void (*s_gluicallback)(int));

  /**
   * @brief Undoes the last operation applied to the canvas (not permanently; it
   * can still be re-done later)
   *
   */
  void UndoOperation(PixelBuffer **display_buffer);

  /**
   * @brief Re-does the last un-done operation applied to the canvas (not
   * permanently; it can be undone again later)
   *
   */
  void RedoOperation(PixelBuffer **display_buffer);
/**
   * @brief CommitState point method
   */
  PixelBuffer* CommitState(PixelBuffer *display_buffer);

 private:
  /**
   * @brief redo button of ui control
   */
  void redo_toggle(bool select) {
    UICtrl::button_toggle(redo_btn_, select);
  }
  /**
   * @brief redo button of ui control
   */
  void undo_toggle(bool select) {
    UICtrl::button_toggle(undo_btn_, select);
  }

  /* Copy/move assignment/construction disallowed */
  StateManager(const StateManager &rhs) = delete;
  StateManager& operator=(const StateManager &rhs) = delete;

  /**
   * @brief data members
   */
  GLUI_Button *undo_btn_;

  /**
   * @brief data members
   */
  GLUI_Button *redo_btn_;

  /**
   * @brief data members
   */
  unsigned max_undos_;

  /**
   * @brief data members
   */
  std::deque<PixelBuffer*> history_states_;

  /**
   * @brief data members
   */
  std::stack<PixelBuffer*> redo_states_;
};

}  /* namespace image_tools */

#endif  /* PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_STATE_MANAGER_H_ */
