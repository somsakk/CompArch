#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ==========================================
// 1. DATA STRUCTURES & IMPLEMENTATIONS
// ==========================================

typedef struct Node {
    int val;
    struct Node* next;
} Node;

// --- Insertion Sort (Array) ---
// O(N^2) algorithm
void insertion_sort_array(int* arr, int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// --- Insertion Sort (Linked List) ---
// O(N^2) algorithm, but has larger constant in the front
Node* insertion_sort_linked_list(Node* head) {
    Node dummy;
    dummy.next = NULL;
    Node* curr = head;

    while (curr != NULL) {
        Node* next_node = curr->next;
        Node* prev = &dummy;

        while (prev->next != NULL && prev->next->val < curr->val) {
            prev = prev->next;
        }

        curr->next = prev->next;
        prev->next = curr;

        curr = next_node;
    }

    return dummy.next;
}

// --- Quicksort (Array) ---
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int* arr, int low, int high) {
    // Pick middle element as pivot to prevent O(N^2) on sorted data
    int mid = low + (high - low) / 2;
    swap(&arr[mid], &arr[high]);

    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// O(N log N) algorithm
void quicksort_array(int* arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort_array(arr, low, pi - 1);
        quicksort_array(arr, pi + 1, high);
    }
}

// ==========================================
// 2. HELPER FUNCTIONS
// ==========================================

Node* create_linked_list(const int* arr, int n) {
    if (n == 0) return NULL;
    Node* head = (Node*)malloc(sizeof(Node));
    head->val = arr[0];
    head->next = NULL;
    
    Node* curr = head;
    for (int i = 1; i < n; i++) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->val = arr[i];
        new_node->next = NULL;
        curr->next = new_node;
        curr = new_node;
    }
    return head;
}

void free_linked_list(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

double get_time_sec(clock_t start, clock_t end) {
    return ((double)(end - start)) / CLOCKS_PER_SEC;
}

// ==========================================
// 3. MAIN BENCHMARK RUNNER
// ==========================================

void run_test(const char* name, const int* original_data, int n) {
    // Dedicated copies for each implementation
    int* arr_insertion = (int*)malloc(n * sizeof(int));
    int* arr_quick = (int*)malloc(n * sizeof(int));
    int* ll_data = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        arr_insertion[i] = original_data[i];
        arr_quick[i] = original_data[i];
        ll_data[i] = original_data[i];
    }

    // 1. Array Insertion Sort
    clock_t start = clock();
    insertion_sort_array(arr_insertion, n);
    clock_t end = clock();
    double t_arr_insertion = get_time_sec(start, end);

    // 2. Linked List Insertion Sort
    Node* ll_head = create_linked_list(ll_data, n);
    start = clock();
    ll_head = insertion_sort_linked_list(ll_head);
    end = clock();
    double t_ll_insertion = get_time_sec(start, end);

    // 3. Array Quicksort
    start = clock();
    quicksort_array(arr_quick, 0, n - 1);
    end = clock();
    double t_arr_quick = get_time_sec(start, end);

    // Cleanup
    free(arr_insertion);
    free(arr_quick);
    free(ll_data);
    free_linked_list(ll_head);

    printf("%-18s | %-14.6f | %-14.6f | %.6f\n", 
           name, t_arr_insertion, t_ll_insertion, t_arr_quick);
}

void run_test_testbench(int N) {
    // int N = 10000;
    printf("=== Sorting Benchmark (N = %d) ===\n", N);
    printf("%-18s | %-14s | %-14s | %s\n", 
           "Data Pattern", "Array Insertion", "LL Insertion", "Array Quicksort");
    printf("--------------------------------------------------------------------------\n");

    int* random_data = (int*)malloc(N * sizeof(int));
    int* ascending_data = (int*)malloc(N * sizeof(int));

    srand(42);
    for (int i = 0; i < N; i++) {
        random_data[i] = rand() % 100000;
        ascending_data[i] = i;
    }

    run_test("Random", random_data, N);
    run_test("Ascending", ascending_data, N);

    free(random_data);
    free(ascending_data);

    // return 0;
}

int main() {
    int N = 1000;
    for (int i=1; i<=64; i *= 2) {
        run_test_testbench(N*i);
        printf("\n******************************\n");
    }
}