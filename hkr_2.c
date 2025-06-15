#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct triangle {
    int a;
    int b;
    int c;
};

typedef struct triangle triangle;

double calculate_area(triangle tr) {
    double s = (tr.a + tr.b + tr.c) / 2.0; // Semi-perimeter
    return sqrt(s * (s - tr.a) * (s - tr.b) * (s - tr.c)); // Heron's formula
}

int compare_areas(const void *a, const void *b) {
    double areaA = calculate_area(*(triangle *)a);
    double areaB = calculate_area(*(triangle *)b);
    return (areaA > areaB) - (areaA < areaB);
}

void sort_by_area(triangle *tr, int n) {
    qsort(tr, n, sizeof(triangle), compare_areas);
}

int main() {
    int n;
    scanf("%d", &n);
    triangle *tr = malloc(n * sizeof(triangle));
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
    }
    sort_by_area(tr, n);
    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
    }
    free(tr); // Free allocated memory
    return 0;
}
