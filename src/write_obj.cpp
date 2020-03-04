#include "write_obj.h"
#include <fstream>
#include <cassert>
#include <iostream>

bool write_obj(
  const std::string & filename,
  const Eigen::MatrixXd & V,//V
  const Eigen::MatrixXi & F,//F
  const Eigen::MatrixXd & UV,//VT
  const Eigen::MatrixXi & UF,
  const Eigen::MatrixXd & NV,//VN
  const Eigen::MatrixXi & NF)
{
  assert((F.size() == 0 || F.cols() == 3 || F.cols() == 4)
                && "F must have 3 or 4 columns");
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here:
  std::ofstream file;
  file.open(filename);

  if(!file) {
    return false;
  }
  // V - vertices
  for (i = 0; i < V.rows(); i++) {
    file << "v" << " ";
    for (index  = 0; index  < V.cols(); index ++){
      file << V[i][index] << " ";
    }
    file << std::endl;
  }
  // F - polygon faces
  for (i = 0; i < F.rows(); i++) {
    file << "f" << " ";
    for (index  = 0; index  < F.cols(); index ++){
      file << F[i][index] << " ";
    }
    file << std::endl;
  }

  // UV - UV positions
  for (i = 0; i < UV.rows(); i++) {
    file << "uv" << " ";
    for (index  = 0; index  < UV.cols(); index ++){
      file << UV[i][index] << " ";
    }
    file << std::endl;
  }
  // UF - poly mesh face indices into UV
  for (i = 0; i < UF.rows(); i++) {
    file << "f" << " ";
    for (index  = 0; index  < UF.cols(); index ++){
      file << UF[i][index] << " ";
    }
    file << std::endl;
  }

  //NV - Normal vectors
  for (i = 0; i < NV.rows(); i++) {
    file << "nv" << " ";
    for (index  = 0; index  < NV.cols(); index ++){
      file << NV[i][index] << " ";
    }
    file << std::endl;
  }
  // NF - poly mesh face indices into NV
  for (i = 0; i < NF.rows(); i++) {
    file << "f" << " ";
    for (index  = 0; index  < NF.cols(); index ++){
      file << NF[i][index] << " ";
    }
    file << std::endl;
  }


  //end of the object
  file.close()

  return true;

  ////////////////////////////////////////////////////////////////////////////
}
