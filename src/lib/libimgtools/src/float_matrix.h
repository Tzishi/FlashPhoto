/*******************************************************************************
 * Name            : float_matrix.h
 * Project         : FlashPhoto
 * Module          : kernel
 * Description     : Header file for FloatMatrix class.
 * Copyright       : 2016 CSCI3081W TAs. All rights reserved.
 * Creation Date   : 4/1/15
 * Original Author : Seth Johnson
 *
 ******************************************************************************/

#ifndef PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_FLOAT_MATRIX_H_
#define PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_FLOAT_MATRIX_H_

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <vector>

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
namespace image_tools {

/*******************************************************************************
 * Class Definitions
 ******************************************************************************/
/**
 * @brief Set the value for a pixel within the buffer/on the screen
 */
class FloatMatrix {
 public:
  FloatMatrix();
 /**
   * @brief Set the value for a pixel within the buffer/on the screen
   */
  FloatMatrix(int w, int h);
  virtual ~FloatMatrix() {}

  /**
   * @brief Get the float array
   *
   * @return The float array
   */
  float const *float_array(void) const { return &float_array_[0]; }

  /**
   * @brief Get the width of the float matrix
   *
   *
   * @return The width
   */
  int width() const { return width_;}

  /**
   * @brief Get the height of the float matrix
   *
   *
   * @return The height of the float matrix
   */
  int height() const {return height_;}

  /**
   * @brief Get the value of an element of the float matrix
   *
   * @return The floating point value
   */
  virtual float value(int x, int y) const;

 protected:
  /**
   * @brief Set the value of an element (x,y) of the float matrix
   *
   */
  void value(int x, int y, float v);

  /**
   * @brief Multiply every element in FloatMatrix by a constant
   *
   */
  void operator*(const float c);

 private:
  /* Copy assignment/construction is disallowed */
  FloatMatrix(const FloatMatrix &rhs) = delete;
  FloatMatrix& operator=(const FloatMatrix &rhs) = delete;
  /**
   * @brief height
   *
   */
  const int height_;
  /**
   * @brief width
   *
   */
  const int width_;
  std::vector<float> float_array_; /**< The actual float array  */
};

} /* namespace image_tools */

#endif  /* PROJECT_ITERATION3_SRC_LIB_LIBIMGTOOLS_SRC_FLOAT_MATRIX_H_ */
