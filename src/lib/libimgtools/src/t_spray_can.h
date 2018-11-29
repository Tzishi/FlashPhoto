/*******************************************************************************
 * Name            : t_spray_can.h
 * Project         : image_tools
 * Module          : Tool
 * Description     : Header file for SprayCan tool class
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 2/15/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

#ifndef PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_T_SPRAY_CAN_H_
#define PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_T_SPRAY_CAN_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <string>
#include "lib/libimgtools/src/tool.h"
#include "lib/libimgtools/src/m_linear.h"

/*******************************************************************************
 * Namespace Definitions
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Implementation of a spray can tool
 *
 */
class TSprayCan : public Tool {
 public:
  TSprayCan(void) { mask(new MLinear(30, 0.2)); }

  std::string name(void) { return "Spray Can"; }
};

}  /* namespace image_tools */

#endif  /* PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_T_SPRAY_CAN_H_ */
