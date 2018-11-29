/*******************************************************************************
* Name            : mia_commandline_manager.h
* Project         : MIA
* Module          : mia_commandline_manager
* Description     : Implementation of MIACommandlineManager class
* Copyright       : 2016 CSCI3081W Student. All rights reserved.
* Creation Date   : Wed Dec 10 2016
* Original Author : padil031
******************************************************************************/
#ifndef PROJECT_ITERATION3_SRC_APP_MIA_SRC_MIA_COMMANDLINE_MANAGER_H_
#define PROJECT_ITERATION3_SRC_APP_MIA_SRC_MIA_COMMANDLINE_MANAGER_H_

#include <vector>
#include <string>
#include "app/MIA/src/mia_filter_manager.h"
#include "app/MIA/src/mia_io_manager.h"
#include "lib/libimgtools/src/imgtools.h"

namespace image_tools {

/*******************************************************************************
* Class Definitions
******************************************************************************/
/**
* @brief The manager for performing options chosen from commandline in MIA. 
* This includes comparing two files, changing the extension type, and 
* applying several different filters.
*/
class MIACommandlineManager {
 public:
  MIACommandlineManager();
  ~MIACommandlineManager() { }

  /**
  * @brief Will check and perform all of the requested actions from  
  *        commandline arguments
  * 
  * This will check for any invalid input within the commandline 
  * arguments.  Then will perform all flags in order given.  If there 
  * are any problems such as no files valid files found when trying to 
  * find a sequence of files, it will return 1 otherwise 0. 
  * 
  * The one exception to this is if the -compare flag is chosen.  This 
  * will compare two files.  If these two are identical then return 1 
  * otherwise return 0.
  */
  int Parse(int argc, char **argv);

  /*! \var InputType
  * \brief Describes the type of datatype a var should have.
  */
  enum InputType {
    INT,
    FLOAT,
    OTHER
  };

 protected:
  /**
  * @brief Manager for all filter operations
  */
  FilterFactory filter_manager_;
  /**
  * @brief Handler for all I/O operations
  */
  ImageHandler io_handler_;
  /**
  * @brief Canvas to hold all incoming images while being edited
  */
  PixelBuffer * display_buffer_;
  /**
  * @brief List of input files in order holding images to be edited.
  */
  std::vector<std::string> in_file_names_;
  /**
  * @brief List of all output files in order.
  */
  std::vector<std::string> out_file_names_;
  /**
  * @brief Code to be returned if an errors occurs
  */
  const int kError = 1;
  /**
  * @brief Code to be returned if no errors occurs
  */
  const int kNoError = 0;
  /**
  * @brief Code to be returned if compare succeeds.
  */
  const int kCompareSuccess = 1;

  /**
  * @brief Will parse through the commandline arguments looking for 
  *        errors.
  * 
  * Takes in the argc and argv from the commandline and checks for 
  * invalid combinations.  This includes flags not being followed by 
  * correct number of arguments and/or being given the wrong type of 
  * argument. 
  */
  bool IsValidFlags(int argc, char **argv);

  /**
  * @brief Will perform all of the requested actions from commandline 
  *        arguments
  * 
  * This will perform all flags in order given.  If there are any 
  * problems such as no files valid files found when trying to find a 
  * sequence of files, it will return 1 otherwise 0. 
  * 
  * The one exception to this is if the -compare flag is chosen.  This 
  * will compare two files.  If these two are identical then return 1 
  * otherwise return 0.
  */
  int PerformFlags(int argc, char **argv);

  /**
  * @brief Will print out Usage statement and error (if any) that 
  *        caused the usage statement to be printed out.
  */
  void Usage(const std::string & err);

  /**
  * @brief Will determine the type of the argument given in 
  *        commandline
  * 
  *        Determines whether or not argument given is a float, int or other.  
  *        This type is an enum, InputType
  */
  int FlagInputType(char *input);

  /**
  * @brief Will determine if given filename is an existing file
  */
  bool IsValidImageFile(const std::string & name);

  /**
  * @brief Will determine if this is a valid file name so it can be 
  *        created or edited
  */
  bool IsValidImageFileName(const std::string & name);

  /**
  * @brief Determine if a file name contains a give suffix
  */
  bool HasSuffix(const std::string & str, const std::string & suffix);

  /**
  * @brief Determines if file name is fits the following pattern: 
  *        <sequence name>###.<extension>
  *
  *        Will take in file_name the name of potential sequence filename and will 
  *        return TRUE if yes, FALSE otherwise
  */
  bool IsSeq(const std::string & file_name);

  /**
  * @brief Determines if file name is fits the following pattern: 
  *        <sequence name>###.<extension>
  *
  *        Will fill in_file_names_ with the individual filenames for files
  *        to be loads and out_file_names with the corresponding output 
  *        filenames.  NOTE: Both params must be valid sequence names or 
  *        regular valid filenames.
  * 
  *        This will take in both the input filename and output filename and produce
  *        two list of valid filenames to have be have the performed on.
  */
  int AddInOutFileNames(char* in_file_names, char * out_file_names);

  /**
  * @brief Will produce filename with desired three digit ending
  * 
  *        This takes sequence file name and produces a filename with the 
  *        offset ending.  
  * 
  *        So <sequence name>###.<extension> => <sequence name>offset.<extension>
  *        This will return the resulting string. 
  */
  std::string ImageNamePlusSeqOffset(
    const std::string& filename,
    int offset);
};

}  /* namespace image_tools */

#endif  // PROJECT_ITERATION3_SRC_APP_MIA_SRC_MIA_COMMANDLINE_MANAGER_H_
