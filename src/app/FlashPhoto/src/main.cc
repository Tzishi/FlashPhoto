/*******************************************************************************
 * Name            : main.cc
 * Project         : FlashPhoto
 * Module          : App
 * Description     : Do ALL THE THINGS!
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 2/15/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include "app/FlashPhoto/src/flashphoto_app.h"
#include "lib/libimgtools/src/imgtools.h"

/*******************************************************************************
 * Functions
 ******************************************************************************/
int main(int argc, char* argv[]) {
  image_tools::FlashPhotoApp *app = new image_tools::FlashPhotoApp(800, 800);
  app->Init(argc, argv, 50, 50,
            image_tools::ColorData(1, 1, static_cast<float>(0.95)));

  // runMainLoop returns when the user closes the graphics window.
  app->RunMainLoop();
  delete app;
  exit(0);
}
