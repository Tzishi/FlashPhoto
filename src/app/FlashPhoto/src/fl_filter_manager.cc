/*******************************************************************************
 * Name            : filter_manager.cc
 * Project         : FlashPhoto
 * Module          : filter_manager
 * Description     : Implementation of FilterManager class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : Wed Sep 21 18:47:02 2016
 * Original Author : jharwell
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "app/FlashPhoto/src/fl_filter_manager.h"
#include <iostream>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/


FLFilterManager::FLFilterManager(void) :
  FilterManager() {}

/*******************************************************************************
* Member Functions
******************************************************************************/
GLUI_Panel* FLFilterManager::InitGlui(const GLUI *const glui,
                           void (*s_gluicallback)(int)) {
new GLUI_Column(const_cast<GLUI*>(glui), true);
GLUI_Panel *filter_panel = new GLUI_Panel(const_cast<GLUI*>(glui), "Filters");
{
  AddSharpenToGLUI(filter_panel, s_gluicallback);
  AddMotionBlurToGLUI(filter_panel, s_gluicallback);
  AddEdgeDetectToGLUI(filter_panel, s_gluicallback);
  AddThresholdToGLUI(filter_panel, s_gluicallback);
  AddBlurToGLUI(filter_panel, s_gluicallback);

  new GLUI_Column(filter_panel, true);
  // AddSaturationToGLUI(filter_panel, s_gluicallback);
  {
    GLUI_Panel *satur_panel = new GLUI_Panel(filter_panel, "Special");

    new GLUI_Button(satur_panel, "Apply",
    UICtrl::UI_APPLY_SPECIAL_FILTER,
    s_gluicallback);
  }
  AddSaturationToGLUI(filter_panel, s_gluicallback);
  AddChannelToGLUI(filter_panel, s_gluicallback);
  AddQuantizationToGLUI(filter_panel, s_gluicallback);
  }

  return filter_panel;
} /* FLFilterManager::InitGlui() */

}  /* namespace image_tools */
