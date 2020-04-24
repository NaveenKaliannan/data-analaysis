#include<iostream>
#include<cmath>
#include<fstream>
#include<typeinfo>
#include<cstdlib>
#include<string>

using namespace std;

int main(int argc, char* argv[])
{

  unsigned int no_of_files = atoi(argv[1]);
  unsigned int no_of_coloumn = atoi(argv[2]);
  unsigned int no_of_lines = atoi(argv[3]);

  uint density_size = 100;
  float dt = 0.1;
  float x[density_size][density_size];
  float y[density_size][density_size];
  float density[density_size][density_size];
  for(uint i = 0; i < density_size; ++i)
    {
      for(uint j = 0;j < density_size;++j)
        {
         density[i][j] = 0;
         x[i][j] = -1.0*j*0.25;
         y[i][j] = -1.0*i*0.25;
        }
    }


  for(unsigned int i = 0;i < no_of_files;++i)
    {
      string filename = argv[4] + to_string(i+1);// + ".dat" ;
      ifstream infile(filename);
      for( unsigned int l = 0;l < no_of_lines; ++l )
        {
          for(unsigned int c = 0;c < no_of_coloumn; ++c)
            {
              float temp1, temp2;
              infile >> temp1 >> temp2; 
              //density condition 
              for(uint ii = 0; ii < density_size; ++ii)
                {
                  for(uint jj = 0;jj < density_size;++jj)
                    {
                      if(temp1 < y[ii][jj] + 0.25 && temp1 > y[ii][jj] - 0.25 && temp2 < x[ii][jj] + 0.25 && temp2 > x[ii][jj] - 0.25  ) 
                        {
                          density[ii][jj] += 1; 
                        }
                    }
                }              
            } 
        }      
      infile.close();
      infile.clear();
    } 

  uint count = 0;
  for(uint i = 0; i < density_size; ++i)
    {
      for(uint j = 0;j < density_size;++j)
        {
         count += density[i][j];
        }
    }

  ofstream outfile(argv[5]);
  for(uint i = 0; i < density_size; ++i)
    {
      for(uint j = 0;j < density_size;++j)
        {
         outfile << -1.0*j*0.25 << " " << -1.0*i*0.25 << " " << density[i][j]  << endl;
        }
    }
  outfile.close();
  outfile.clear();


 
  return 0;
}
