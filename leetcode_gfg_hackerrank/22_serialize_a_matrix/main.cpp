

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  cout << " code starts here " << endl;

  fstream file_handle;

  vector<int> matrix_size = {5, 5};

  file_handle.open("matrix.txt", ios::out);

  for (int i = 0; i < matrix_size[0]; i++)
  {
    for (int j = 0; j < matrix_size[1]; j++)
    {
      file_handle << rand() % 100 + 1 << ' ';
    }
    file_handle << endl;
  }
  file_handle.close();

  // -- serialize the matrix
  // write down the serialized matrix in a file
  fstream serialized_file;
  serialized_file.open("serialized_mat.txt", ios::out);
  file_handle.open("matrix.txt", ios::in);
  int val;

  for (int i = 0; i < matrix_size[0]; i++)
  {
    for (int j = 0; j < matrix_size[1]; j++)
    {
      file_handle >> val;
      cout << " reading: " << val << endl;
      serialized_file << val << endl;
    }
  }

  serialized_file.close();
  file_handle.close();

  // -- deserialize the matrix
  fstream deserialized_file;
  deserialized_file.open("deserialized_mat.txt", ios::out);

  serialized_file.open("serialized_mat.txt", ios::in);

  for (int i = 0; i < matrix_size[0]; i++)
  {
    for (int j = 0; j < matrix_size[1]; j++)
    {
      serialized_file >> val;
      cout << " reading: " << val << endl;
      deserialized_file << val << ' ';
    }
    deserialized_file << endl;
  }

  deserialized_file.close();
  serialized_file.close();

  // --- CSR serialization
  fstream sparse_handle;
  sparse_handle.open("matrix_sparse.txt", ios::in);

  fstream csr;
  csr.open("csr.txt", ios::out);

  vector<int> smat, col_ind, ind;

  for (int i = 0; i < matrix_size[0]; i++)
  {
    ind.push_back(smat.size());
    for (int j = 0; j < matrix_size[1]; j++)
    {
      sparse_handle >> val;
      cout << " reading: " << val << endl;
      if (val == 0) continue;
      smat.push_back(val);
      col_ind.push_back(j);
    }
  }

  for (int i = 0; i < smat.size(); i++) csr << smat[i] << ' ';
  csr << endl;
  for (int i = 0; i < col_ind.size(); i++) csr << col_ind[i] << ' ';
  csr << endl;
  for (int i = 0; i < ind.size(); i++) csr << ind[i] << ' ';
  csr << endl;

  // --- CSR deserialization
  fstream deserialize_csr;
  deserialize_csr.open("deserialize_csr.txt", ios::out);
  int index1 = 0, index2 = 0;
  for (int i = 0; i < matrix_size[0]; i++)
  {
    for (int j = 0; j < matrix_size[1]; j++)
    {
      val = 0;
      if (j == col_ind[index1])
      {
        val = smat[index1];
        index1++;
      }

      deserialize_csr << val << ' ';
    }
    deserialize_csr << endl;
  }

  cout << " end of the code" << endl;
  return 0;
}
