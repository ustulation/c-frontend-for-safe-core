#include <stdio.h>

extern int init_logging();
extern int execute(char*, void*);
extern int client_issued_gets(void*);
extern int create_unregistered_client(void**);
extern char* execute_for_content(char*, int*, int*, int*, void*);

int main() {
    int res = -11111;
    int size, capacity;

    char* content = 0;

    void* ffi_handle = 0;
    void** ptr_to_ffi_handle = &ffi_handle;

    printf("\n=========================================================================\n\n");
    printf("Initial value of result: %d\n\n", res);

    printf("\nInvoking to initialise logging...\n");
    res = init_logging();
    printf("Invoked and got result: %d\n\n", res);

    printf("\nCreating unregistered client...\n");
    res = create_unregistered_client(ptr_to_ffi_handle);
    printf("Invoked and got result: %d\n\n", res);

    printf("\nGetting stats for GETs...\n");
    res = client_issued_gets(ffi_handle);
    printf("Invoked and got stats for GETs: %d\n\n", res);

    printf("\nInvoking execute with invalid JSON...\n");
    res = execute("This is an invalid JSON.", ffi_handle);
    printf("Invoked and got result: %d\n\n", res);

    printf("\nInvoking execute with valid JSON (Getting service \"www\" for long-name \"spandan\")"
            "...\n");
    content = execute_for_content("{\"module\": \"dns\",\"action\": \"get-home-dir\", \"data\": "
                                  "{\"long_name\": \"spandan\", \"service_name\": \"www\"}}",
                                  &size, &capacity, &res, ffi_handle);
    printf("Invoked and got result: %d", res);
    if (!res) {
        printf("\nContent: %s\n\n", content);
    } else {
        printf("\n\n");
    }

    printf("\nGetting stats for GETs...\n");
    res = client_issued_gets(ffi_handle);
    printf("Invoked and got stats for GETs: %d\n\n", res);

    printf("=========================================================================\n\n");
    return 0;
}
