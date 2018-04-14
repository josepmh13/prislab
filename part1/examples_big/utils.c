#include "utils.h"


//in case of int, define on compile time
#ifdef INT_X
typedef int DATA_T;
#endif

//in case of double, define on compile time
#ifdef DOUBLE_X
typedef double DATA_T;
#endif

/* macro, to be used later */
#define SORT_MAIN_FN_CORE(sort_type, nr_nrs, nrs_data)  {            \
            /*printf("Sort type: %d\n", sort_type);*/                \
            switch(sort_type){                                       \
              case 0:                                                \
                merge(nrs_data, nr_nrs);                             \
                break;                                               \
              case 1:                                                \
                quick(nrs_data, nr_nrs);                             \
                break;                                               \
              case 2:                                                \
                bubble(nrs_data, nr_nrs);                            \
                break;                                               \
              case 3:                                                \
                insertion(nrs_data, nr_nrs);                         \
                break;                                               \
              default:                                               \
                printf("Selected sorting option not available.\n");  \
                break;                                               \
            }                                                        \
        }



void* sort_nrs(void* nrs, char* sort_type, int nr_nrs)
{
  int sort_label = -1;

  if(!strcmp(sort_type, "merge")){ sort_label = 0; }
  else if(!strcmp(sort_type, "quick")){ sort_label = 1; }
  else if(!strcmp(sort_type, "bubble")){ sort_label = 2; }
  else if(!strcmp(sort_type, "insertion")){ sort_label = 3; }

  struct timeval start, end;
  gettimeofday(&start, NULL);
  DATA_T* nrs_data = (DATA_T*)nrs;
  SORT_MAIN_FN_CORE(sort_label, nr_nrs, nrs_data) //macro defined above
  gettimeofday(&end, NULL);
  printf("\nTotal exec time: %ld us\n", ((end.tv_sec * 1000000 + end.tv_usec)
                  - (start.tv_sec * 1000000 + start.tv_usec)));

  /* displaying array to sort */
  /*
  int i, upper_limit; //'upper_limit' is nr_nrs or 50 if nr_nrs>50
  upper_limit = (nr_nrs>50) ? 50 : nr_nrs;

  printf("Array to sort: ");
  for(i=0; i<(upper_limit-1); i++)
  {
    #ifdef INT_X
    printf("%d, ", nrs_data[i]);
    #endif
    #ifdef DOUBLE_X
    printf("%f, ", nrs_data[i]);
    #endif
  }
  if(nr_nrs != upper_limit)
  {
    printf(" ..., ");
  }
  //print last nr without a ',' at the end
  #ifdef INT_X
  printf("%d\n", nrs_data[nr_nrs-1]);
  #endif
  #ifdef DOUBLE_X
  printf("%f\n", nrs_data[nr_nrs-1]);
  #endif
  */
}

/* n log(n) */
void* merge(void* nrs_data, int nr_nrs){}

/* n^2 */
void* insertion(void* nrs_data, int nr_nrs){}



/* quick sort implementation */

/* n log(n) */
void* quick(void* nrs_data, int nr_nrs)
{
  // TODO !
}

/* ------------------------- */


/* bubble sort implementation */

/* n^2 */
void* bubble(void* nrs_data, int nr_nrs)
{
  int swapped = 1;
  int i;
  DATA_T buff;
  DATA_T* in_data = (DATA_T*)nrs_data;

  while(swapped)
  {
    swapped = 0;
    for(i=1; i<nr_nrs; i++)
    {
      if(in_data[i-1] > in_data[i])
      {
        buff = in_data[i-1];
        in_data[i-1] = in_data[i];
        in_data[i] = buff;
        swapped = 1;
      }
    }
  }

  return (void*)in_data;
}

/* -------------------------- */
