#include <ecl_grid.h>
#include <stdlib.h>
#include <stdio.h>



int main(int argc, char ** argv) {
  if (argc < 2) {
    fprintf(stderr,"%s: filename \n",argv[0]);
    exit(1);
  }
  {
    bool endian_flip = true;
    ecl_grid_type * ecl_grid;
    const char    * grid_file = argv[1];
    
    
    ecl_grid = ecl_grid_alloc(grid_file , endian_flip);
    printf("	Grid file .......: %s  \n",grid_file);
    ecl_grid_summarize(ecl_grid);
    if (argc >= 3) {
      ecl_grid_type * grid2 = ecl_grid_alloc( argv[2] , endian_flip );
      ecl_grid_compare( ecl_grid , grid2);
      ecl_grid_free( grid2 );
    }
    ecl_grid_free(ecl_grid);
  }
}
