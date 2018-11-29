/*******************************************************************************
* Name            : mia_commandline_manager.cc
* Project         : MIA
* Module          : mia_commandline_manager
* Description     : Implementation of MIACommandlineManager class
* Copyright       : 2016 CSCI3081W Student. All rights reserved.
* Creation Date   : Wed Dec 10 2016
* Original Author : padil031
******************************************************************************/
#include "app/MIA/src/mia_commandline_manager.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "app/MIA/src/mia_io_manager.h"
#include "app/MIA/src/mia_filter_manager.h"

namespace image_tools {
/***********************************************************************
* Constructors
* ********************************************************************/
MIACommandlineManager::MIACommandlineManager() : filter_manager_(),
                                                 io_handler_(),
                                                 display_buffer_(nullptr) {}

/*******************************************************************************
* Member Functions
******************************************************************************/
int MIACommandlineManager::Parse(int argc , char ** argv) {
  if (!IsValidFlags(argc,  argv)) {
    return kError;
  }
  return PerformFlags(argc, argv);
}

bool MIACommandlineManager::IsValidFlags(int argc, char ** argv) {
  int index = 2, input_index = 1, output_index = argc - 1;

  // Checking for -h or the two filenames on either side.
  if (strcmp(argv[input_index], "-h") == 0) {
    if (argc != 2) {
      Usage("See -h usage");
      return false;
    } else {
      return true;
    }
  } else if ((!IsValidImageFile(argv[input_index]) &&
            !IsValidImageFile(argv[output_index]) ) &&
            (!IsSeq(std::string(argv[input_index])) &&
            !IsSeq(std::string(argv[output_index])))) {
    std::cerr << "infile: " << argv[input_index] << std::endl;
    std::cerr << "outfile: " << argv[output_index] << std::endl;
    Usage("Invalid File");
    return false;
  }

  // Check all other flags for invalid arguments.
  while (index < argc - 1) {
    if (strcmp(argv[index], "-sharpen") == 0) {
      if (FlagInputType(argv[index+1]) == OTHER ||
          atof(argv[index+1]) < 0) {
        Usage("See -channel usage");
        return false;
      }
      index = index +2;
    } else if (strcmp(argv[index], "-edge") == 0) {
      index = index + 1;
    } else if (strcmp(argv[index], "-threshold") == 0) {
      if (FlagInputType(argv[index+1]) == OTHER ||
          atof(argv[index+1]) < 0 ||
          atof(argv[index+1]) > 1) {
        Usage("See -threshold usage");
        return false;
      }
      index = index +2;
    } else if (strcmp(argv[index], "-quantize") == 0) {
      if (FlagInputType(argv[index+1]) != INT ||
          atoi(argv[index+1]) < 0) {
        Usage("See -quantize usage");
        return false;
      }
      index = index +2;
    } else if (strcmp(argv[index], "-blur") == 0) {
      if (FlagInputType(argv[index+1]) == OTHER ||
          atof(argv[index+1]) < 0) {
        Usage("See -blur usage");
        return false;
      }
      index = index +2;
    } else if (strcmp(argv[index], "-saturate") == 0) {
      if (FlagInputType(argv[index+1]) == OTHER) {
        Usage("See -saturate usage");
        return false;
      }
      index = index +2;
    } else if (strcmp(argv[index], "-channel") == 0) {
      for (int i = 1 ; i < 4; i++) {
        if ( FlagInputType(argv[index+i]) == OTHER ||
            atof(argv[index+i]) < 0) {
          Usage("See -channel usage");
          return false;
        }
      }
      index = index +4;
    } else if (strcmp(argv[index], "-compare") == 0) {
      if (argc != 4) {
        Usage("See -compare usage");
        return false;
      }
      index = index +1;
    } else {
      return false;
    }
  }
  return true;
}

int MIACommandlineManager::PerformFlags(int argc, char **argv) {
  bool compare_checked = false;
  Filter * f;
  int index, input_index = 1, output_index = argc - 1;
  int num_of_files, num_successfully_compared = 0, flag_start = 2;

  if (strcmp(argv[input_index], "-h") == 0) {
    Usage("");
    return kNoError;
  }
  // add in an if here to go through a list of files to input and output
  num_of_files = AddInOutFileNames(argv[input_index], argv[output_index]);
  if ( num_of_files < 1 ) {
    return kError;
  }

  // Loop through all indicated files
  for (int i = 0 ; i < num_of_files; i++) {
    index = flag_start;
    display_buffer_ = io_handler_.LoadImage(in_file_names_.front());
    in_file_names_.erase(in_file_names_.begin());
    // Perform each of the options
    while (index < argc - 1) {
      if (strcmp(argv[index], "-sharpen") == 0) {
        f = FilterFactory::CreateFilter(FilterFactory::FILTER_SHARPEN,
            1,
            atof(argv[index+1]));
        index = index +2;
      } else if (strcmp(argv[index], "-edge") == 0) {
        f = FilterFactory::CreateFilter(
            FilterFactory::FILTER_EDGE_DETECT,
            0);
        index = index+1;
      } else if (strcmp(argv[index], "-threshold") == 0) {
        f = FilterFactory::CreateFilter(FilterFactory::FILTER_THRESHOLD,
            1,
            atof(argv[index+1]));
        index = index +2;
      } else if (strcmp(argv[index], "-quantize") == 0) {
        f = FilterFactory::CreateFilter(FilterFactory::FILTER_QUANTIZE,
            1,
            atoi(argv[index+1]));
        index = index +2;
      } else if (strcmp(argv[index], "-blur") == 0) {
        f = FilterFactory::CreateFilter(FilterFactory::FILTER_BLUR,
            1,
            atof(argv[index+1]));
        index = index +2;
      } else if (strcmp(argv[index], "-saturate") == 0) {
        f = FilterFactory::CreateFilter(
            FilterFactory::FILTER_SATURATION,
            1,
            atof(argv[index+1]));
        index = index +2;
      } else if (strcmp(argv[index], "-channel") == 0) {
        f = FilterFactory::CreateFilter(FilterFactory::FILTER_CHANNELS,
            3,
            atof(argv[index+1]),
            atof(argv[index+2]),
            atof(argv[index+3]));
        index = index + 4;
      } else if (strcmp(argv[index], "-compare") == 0) {
        compare_checked = true;
        index = index +1;
        break;
      }

      FilterFactory::ApplyFilter(*f, &display_buffer_);
      delete f;
    }
    // Will compare specified files else save image to specified image
    if (compare_checked) {
      PixelBuffer * temp_buffer = io_handler_.LoadImage(
          out_file_names_.front());
      out_file_names_.erase(out_file_names_.begin());

      if ( (*display_buffer_ == *temp_buffer) == false ) {
        delete temp_buffer;
        return kNoError;
      }
      num_successfully_compared++;
      delete temp_buffer;
      if ( num_successfully_compared == num_of_files ) {
        return kCompareSuccess;
      }
    } else {
      if (!io_handler_.SaveImage(out_file_names_.front(), display_buffer_)) {
        return kError;
      }
      out_file_names_.erase(out_file_names_.begin());
    }
    delete display_buffer_;
  }
  return kNoError;
}

void MIACommandlineManager::Usage(const std::string & err) {
  std::cout << err << std::endl;
  std::cout << "usage: ./bin/MIA/bin/MIA \t\t\t\tRun using GUI" <<  std::endl;
  std::cout << "   or: ./bin/MIA/bin/MIA -h \t\t\t\tprint usage statement"
    <<  std::endl;
  std::cout << "   or: ./bin/MIA/bin/MIA file1 -compare file2 " <<
    "\t\tcompares the contents of two files and will return 1 for "<<
    "identical, 0 otherwise" <<  std::endl;
  std::cout << "   or: ./bin/MIA/bin/MIA infile [arguments] outfile" <<
    "\twill modify picture as specified by arguments" <<  std::endl
    << std::endl;

  std::cout << "Files:" <<  std::endl;
  std::cout << "   file1,file2\t\tTwo files being compared" <<  std::endl;
  std::cout << "   infile\t\tInput file holding image to be modified"
    <<  std::endl;
  std::cout << "   outfile\t\tOutput file where any changes to image will"
    "be saved" <<  std::endl;
  std::cout << "   infile### outfile###\tWill result in all files with"
    << "the ### replaced with numbers 000 to 999 being processed and"
    << "outputed" << std::endl << std::endl;

  std::cout << "Arguments:" <<  std::endl;
  std::cout << "   -h\t\t\tPrint Help (this message) and exit" << std::endl;
  std::cout << "   -sharpen n\t\tSharpen an image by amount " <<
    "n <float> and save the output to a new image" << std::endl <<
    "\t\t\tn >= 0" << std::endl;
  std::cout << "   -edge\t\tRun an edge detection filter and save " <<
    "the output to a new image" << std::endl;
  std::cout << "   -threshold n\t\tAdjust threashold by amount n" <<
    " <float>"<< std::endl << "\t\t\t0.0 <= n <= 1.0 " << std::endl;
  std::cout << "   -quantize n\t\tReduce the number of possible " <<
    "colors by binning each color value into of bins n <int> specified"
    << std::endl << "\t\t\tn >= 0 " << std::endl;
  std::cout << "   -blur n\t\tBlur the image proportional to " <<
    "amount n <float>" << std::endl << "\t\t\tn >= 0 " << std::endl;
  std::cout << "   -saturate n\t\tEither increase, decrease, " <<
    "or invert the colorfulness of your image based on n <float>"
    << std::endl;
  std::cout << "   -channel r g b " <<
    "\tIncrease/decrease the intensity of each color channel: " <<
    "red r <float>, green g <float>, blue b <float>" << std::endl <<
    "\t\t\tr, g, b >=0" << std::endl;
}

int MIACommandlineManager::FlagInputType(char *input) {
  int length = strlen(input), number_of_decimals = 0;
  InputType result = INT;

  for (int i = 0; i < length; i++) {
    if (input[i] == '.') {
      if (number_of_decimals == 0 && i != 0 && i != length - 1) {
        result = FLOAT;
      } else {
        return OTHER;
      }
    }
    if (input[i] == '-' && i != 0) {
      return OTHER;
    }
    if ((input[i] != '-' && input[i] != '.' && input[i] < '0') ||
        input[i] > '9') {
      return OTHER;
    }
  }
  return result;
}

bool MIACommandlineManager::IsValidImageFile(const std::string & name) {
  FILE *f;
  bool is_valid = false;
  if (IsValidImageFileName(name)) {
    if ((f = fopen(name.c_str(), "r"))) {
      is_valid = true;
      fclose(f);
    }
  }
  return is_valid;
}

bool MIACommandlineManager::IsValidImageFileName(const std::string & name) {
  if (HasSuffix(name, ".png") || HasSuffix(name, ".jpg")
      || HasSuffix(name, ".jpeg")) {
    return true;
  }
  return false;
}

bool MIACommandlineManager::HasSuffix(const std::string & str,
                                      const std::string & suffix) {
  return str.find(suffix, str.length()-suffix.length()) != std::string::npos;
}

bool MIACommandlineManager::IsSeq(const std::string & file_name) {
  const int kDigitCount = 3;
  std::string extension, name, number;
  size_t dot_pos = file_name.find_last_of(".");
  if (dot_pos ==  std::string::npos || dot_pos == 0) {
    return "";
  }

  extension = file_name.substr(dot_pos+1);
  name = file_name.substr(0, dot_pos);
  if (static_cast<int>(name.length()) < kDigitCount) {
    return "";
  }

  number = name.substr(name.length()-kDigitCount);

  if (number.compare("###") == 0) {
    return true;
  }
  return false;
}

int MIACommandlineManager::AddInOutFileNames(char * in_file_names,
                                             char * out_file_names) {
  MIAIOManager io_manager;
  const int kSeqMin = 0;
  const int kSeqMax = 999;
  int num_of_files = 0;
  std::string next_in_file_name, next_out_file_name;

  if ( !IsSeq(in_file_names) && !IsSeq(out_file_names) &&
      IsValidImageFile(in_file_names) &&
      IsValidImageFileName(out_file_names)) {
    // If valid names and not sequence add to files to be modified.
    in_file_names_.push_back(std::string(in_file_names));
    out_file_names_.push_back(std::string(out_file_names));
    num_of_files = 1;
  } else if (IsSeq(in_file_names) && IsSeq(out_file_names)) {
    // If sequence add valid corresponding names to files to be modified.
    for (int i = kSeqMin; i < kSeqMax + 1; i++) {
      next_in_file_name = ImageNamePlusSeqOffset(in_file_names, i);
      next_out_file_name = ImageNamePlusSeqOffset(out_file_names, i);

      if ( IsValidImageFile(next_in_file_name) &&
          IsValidImageFileName(next_in_file_name)) {
        in_file_names_.push_back(std::string(next_in_file_name));
        out_file_names_.push_back(std::string(next_out_file_name));
        num_of_files = num_of_files + 1;
      }
    }
  } else {
    // One or both files are neither a valid filename nor a sequence name.
    Usage("Invalid File");
    return -1;
  }
  return num_of_files;
}

std::string MIACommandlineManager::ImageNamePlusSeqOffset(
    const std::string& filename,
    int offset) {
  const int kDigitCount = 3;
  std::string extension, name, number;
  size_t dot_pos = filename.find_last_of(".");
  if (dot_pos ==  std::string::npos || dot_pos == 0) {
    return "";
  }

  extension = filename.substr(dot_pos+1);
  name = filename.substr(0, dot_pos);
  if (static_cast<int>(name.length()) < kDigitCount) {
    return "";
  }

  number = name.substr(name.length()-kDigitCount);
  name = name.substr(0, name.length()-kDigitCount);
  int num;
  std::istringstream(number) >> num;
  int output_num = num +offset;
  if (output_num < 0) {
    return "";
  }
  std::stringstream ss;
  ss << output_num;
  std::string output_number;
  ss >> output_number;

  // Append zero chars
  int str_length = output_number.length();
  for (int i = 0; i < kDigitCount - str_length; i++) {
    output_number = "0" + output_number;
  }

  return (name + output_number + "." + extension);
}

} /* namespace image_tools */
