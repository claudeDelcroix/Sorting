#ifndef SORTS_H
#define SORTS_H

#include <stddef.h>  // pour size_t

/* ============================
        TRIS SIMPLES
   ============================ */

void bubble_sort(int arr[], int n);
void cocktail_sort(int arr[], int n);
void insertion_sort(int arr[], int n);
void selection_sort(int arr[], int n);
void gnome_sort(int arr[], int n);
void comb_sort(int arr[], int n);

/* ============================
        TRIS EFFICACES
   ============================ */

void quicksort(int arr[], int left, int right);

void mergesort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

void heapsort(int arr[], int n);
void heapify(int arr[], int n, int i);

void shell_sort(int arr[], int n);

/* ============================
       TRIS NON COMPARATIFS
   ============================ */

void counting_sort(int arr[], int n, int max_value);

void radix_sort(int arr[], int n);
int  get_max(int arr[], int n);
void counting_sort_digit(int arr[], int n, int exp);

void pigeonhole_sort(int arr[], int n);

/* ============================
       TRIS EXOTIQUES
   ============================ */

int  is_sorted(int arr[], int n);
void shuffle(int arr[], int n);
void bogosort(int arr[], int n);

void bozosort(int arr[], int n);

void stooge_sort(int arr[], int left, int right);

/* ============================
     TRIS BONUS / AVANCÉS
   ============================ */

/* qsort() existe déjà dans stdlib.h 
   mais voici notre tri générique */

void swap_generic(void *a, void *b, size_t size);

void bubble_sort_generic(void *base, size_t n, size_t size,
                         int (*cmp)(const void*, const void*));

/* Introsort */
void heapify_intro(int arr[], int n, int i);
void heapsort_intro(int arr[], int n);
void introsort(int arr[], int n, int depth_limit);
void sort_introsort(int arr[], int n);

/* Timsort */
#define RUN 32
void insertion_sort_run(int arr[], int left, int right);
void merge_timsort(int arr[], int l, int m, int r);
void timsort(int arr[], int n);

#endif
