#include "student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Tsipora Stone, 114110213, 0305, tstone97 */
Student *new_student(const char name[], unsigned int id, float shoe_size) {
  Student *new_s = malloc(sizeof(Student));
  if (name == NULL){
    new_s -> name = malloc(1);
  } else {
    new_s -> name = malloc(sizeof(char) * (strlen(name) + 1));
  }
  if (name == NULL) {
    strcpy(new_s -> name, "");
  }
  else {
    strcpy(new_s -> name, name);
  }
  new_s -> id = id;
  new_s -> shoe_size = shoe_size;
  return new_s;
}

unsigned int has_id(Student *const student, unsigned int id) {
  unsigned int rval = 0;
  if (student == NULL) {
    return 0;
  }
  else {
    if (student -> id == id) {
      rval = 1;
    }
  }
  return rval;
}

int has_name(Student *const student, const char name[]) {
  int rval = 0;
 
  if (student == NULL) {
    return 0;
  }
  else {
    if (name != NULL && strcmp(student -> name, name) == 0) {
      rval = 1;
    }
  }
  
  return rval;
}

unsigned int get_id(Student *const student) {
  if (student == NULL) {
    return 0;
  }
  return student -> id;
}

float get_shoe_size(Student *const student) {
  if (student == NULL) {
    return 0.0;
  }
  return student -> shoe_size;
}

void change_shoe_size(Student *const student, float new_shoe_size) {
  if (student != NULL) {
    student -> shoe_size = new_shoe_size;
  }
}

void change_name(Student *const student, const char new_name[]) {
  char *new_n;
  if (new_name == NULL){
    new_n = malloc(1);
  } else {
    new_n = malloc(sizeof(char) * (strlen(new_name) + 1));
  }
  
  if (student != NULL) {
    if (new_name == NULL) {
      strcpy(new_n, "");
    }
    else {
      strcpy(new_n, new_name);
    }
    student -> name = new_n;
  }
}

void copy_student(Student *student1, Student *const student2) {
  char *new_name;
  if (student1 != NULL && student2 != NULL) {
    new_name = malloc(sizeof(char) * (strlen(student2 -> name) + 1));
    strcpy(new_name, student2 -> name);
    strcpy(student1 -> name, new_name);
    student1 -> id = student2 -> id;
    student1 -> shoe_size = student2 -> shoe_size;
  }  
}
