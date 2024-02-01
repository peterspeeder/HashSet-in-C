/*A hashset in C */

#include <stdio.h>
#include <stdbool.h>

#define MAX_SET_SIZE 100


/* The set */
typedef struct {
  int element[MAX_SET_SIZE];
  int size;
}HashSet;

/* Init a empty set */
void initHashSet(HashSet* set){
  set->size = 0;
}

bool addToHash(HashSet* set, int element){
  /*check if element in set*/
  for (size_t i=0; i < set->size; ++i) {
    if (set->element[i] == element) {
      return false;
    }
  }

  /* add element to the set */
  if (set->size < MAX_SET_SIZE) {
    set->element[set->size++] = element;
    return true;  // Element successfully added to the set
  } else {
    return false;  // Set is full, cannot add more elements
  }
}


// check if element in set 
bool inSet(const HashSet* set, int element){
  for (int i = 0; i < set->size; ++i){
    if (set->element[i] == element)
    {
      return true;
    }
  }

  return false;
}

void count(HashSet* set) {
  for (size_t i = 0; i < set->size; ++i)
  {
    printf("%d\n", set->element[i]);
  }
}






int main(){
  HashSet my_set;
  initHashSet(&my_set);

  addToHash(&my_set, 1);
  addToHash(&my_set, 2);
  addToHash(&my_set, 3);
  addToHash(&my_set, 4);
  addToHash(&my_set, 5);

  printf("\nElements Below: \n");
  count(&my_set);



	return 0;
}
