/*******************************************************************************
 * Name            : main.cc
 * Project         : MIA
 * Module          : main
 * Description     : Entry point for MIA application
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 1/15/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "app/MIA/src/mia_app.h"
#include "lib/libimgtools/src/imgtools.h"
#include "app/MIA/src/mia_commandline_manager.h"
/*******************************************************************************
 * Non-Member Functions
 ******************************************************************************/
int main(int argc, char** argv) {
  if (argc == 1) {
    image_tools::MIAApp *app = new image_tools::MIAApp(
        400,
        400,
        "resources/marker.png");
    app->Init(argc, argv, 50, 50,
              image_tools::ColorData(1, 1, static_cast<float>(0.95)));
    app->RunMainLoop();
    delete app;
  } else {
    /* Create command line interface */
    image_tools::MIACommandlineManager clm;
    int result = clm.Parse(argc, argv);
    std::cerr << result << std::endl;
    return result;
  }
  return 0;
} /* main() */
