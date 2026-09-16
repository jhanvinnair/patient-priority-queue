```c
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Patient {
    char name[20];
    int priority;
};

struct Patient heap[MAX];
int size = 0;

// Swap two patients
void swap(struct Patient *a, struct Patient *b) {
    struct Patient temp = *a;
    *a = *b;
    *b = temp;
}

// Add a patient to the priority queue
void addPatient(char name[], int priority) {
    int i;

    strcpy(heap[size].name, name);
    heap[size].priority = priority;
    i = size;
    size++;

    // Move the patient upward
    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent].priority <= heap[i].priority)
            break;

        swap(&heap[parent], &heap[i]);
        i = parent;
    }

    printf("Added: %s (Priority %d)\n", name, priority);
}

// Treat the patient with the highest priority
void treatNextPatient() {
    if (size == 0) {
        printf("No patients waiting.\n");
        return;
    }

    printf("Treating: %s (Priority %d)\n",
           heap[0].name, heap[0].priority);

    // Move the last patient to the root
    heap[0] = heap[size - 1];
    size--;

    // Move the patient downward
    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < size &&
            heap[left].priority < heap[smallest].priority)
            smallest = left;

        if (right < size &&
            heap[right].priority < heap[smallest].priority)
            smallest = right;

        if (smallest == i)
            break;

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}

int main() {

    // Add P1-P6
    addPatient("P1", 3);
    addPatient("P2", 1);
    addPatient("P3", 2);
    addPatient("P4", 1);
    addPatient("P5", 3);
    addPatient("P6", 2);

    printf("\n--- Treatment Order ---\n");

    // Treat first 3 patients
    treatNextPatient();
    treatNextPatient();
    treatNextPatient();

    // Add new Emergency patient
    printf("\n--- Adding New Emergency Patient ---\n");
    addPatient("P7", 1);

    // Treat remaining patients
    printf("\n--- Remaining Treatment Order ---\n");

    while (size > 0) {
        treatNextPatient();
    }

    return 0;
}
```
