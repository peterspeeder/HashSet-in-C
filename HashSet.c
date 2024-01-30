#include <stdio.h>
#include <stdbool.h>

#define MAX_SET_SIZE 100

/*represents the set*/
typedef struct{
    int elements[MAX_SET_SIZE];
    int size;
}HashSet;

/*init a empty set*/
void initHashSet(HashSet* set){
    set->size = 0;
}

bool addToHashSet(HashSet* set, int element){
    /*checks if element is in set*/
    for(int i=0; i < set->size; ++i){
        if(set->elements[i] == element){
            return false;   //element is in use
        }
    }
    /*add element to set*/
    if(set->size < MAX_SET_SIZE){
        set->elements[set->size] = element;
        set->size++;
        return true; //element added flawlessly
    }else{
        return false;
    }
}

/*chech if element is already in set*/
bool containsInHashSet(const HashSet* set, int element){
    for (int i = 0; i < set->size; ++i){
       if(set->elements[i] == element){
        return true;
       }
    }
    return false;
}

void count(HashSet* set) {
    for (size_t i = 0; i < set->size; i++){
        printf("%d\n", set->elements[i]);
    }
    
}

int main(){
    HashSet mySet;
    initHashSet(&mySet);

    addToHashSet(&mySet, 1);
    addToHashSet(&mySet, 2);
    addToHashSet(&mySet, 3);
    addToHashSet(&mySet, 9);
    addToHashSet(&mySet, 7);
    addToHashSet(&mySet, 3);

    count(&mySet);

    if (containsInHashSet(&mySet, 2)){
        printf("contains 2\n");
    }
    else{
        printf("Doesnt contain 2\n");
    }

    return 0;
}
