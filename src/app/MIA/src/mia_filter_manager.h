/*******************************************************************************
 * Name            : mia_filter_manager.h
 * Project         : MIA
 * Module          : filter_manager
 * Description     : Header for MIAFilterManager class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : Wed Sep 21 18:40:20 2016
 * Original Author : jharwell
 *
 ******************************************************************************/

#ifndef PROJECT_ITERATION3_SRC_APP_MIA_SRC_MIA_FILTER_MANAGER_H_
#define PROJECT_ITERATION3_SRC_APP_MIA_SRC_MIA_FILTER_MANAGER_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
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
 * @brief Manager for all aspects of filters in FlashPhoto, including
 * initialization of GLUI control elements for filters, filter creation,
 * application, deletion.
 */
class MIAFilterManager : public FilterManager {
 public:
  MIAFilterManager();

  GLUI_Panel* InitGlui(const GLUI *const glui,
                       void (*s_gluicallback)(int));
};

}  /* namespace image_tools */

#endif  /* PROJECT_ITERATION3_SRC_APP_MIA_SRC_MIA_FILTER_MANAGER_H_ */
