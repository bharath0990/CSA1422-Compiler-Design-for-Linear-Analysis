#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 100
struct Symbol {
    char name[50];
    char type[20];
    int address;
};
struct SymbolTable {
    struct Symbol symbols[TABLE_SIZE];
    int count;
};
void initializeTable(struct SymbolTable *table) {
    table->count = 0;
}
void insertSymbol(struct SymbolTable *table, char *name, char *type, int address) {
    if (table->count < TABLE_SIZE) {
        strcpy(table->symbols[table->count].name, name);
        strcpy(table->symbols[table->count].type, type);
        table->symbols[table->count].address = address;
        table->count++;
    }
}
int searchSymbol(struct SymbolTable *table, char *name) {
    for (int i = 0; i < table->count; i++) {
        if (strcmp(table->symbols[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}
void displayTable(struct SymbolTable *table) {
    printf("Index\tName\tType\tAddress\n");
    for (int i = 0; i < table->count; i++) {
        printf("%d\t%s\t%s\t%d\n", i, table->symbols[i].name, table->symbols[i].type, table->symbols[i].address);
    }
}
int main() {
    struct SymbolTable table;
    initializeTable(&table);
    insertSymbol(&table, "x", "int", 100);
    insertSymbol(&table, "y", "float", 104);
    insertSymbol(&table, "z", "char", 108);
    displayTable(&table);
    char searchKey[50];
    printf("Enter symbol to search: ");
    scanf("%s", searchKey);
    int index = searchSymbol(&table, searchKey);
    if (index != -1) {
        printf("Symbol found at index %d\n", index);
    } else {
        printf("Symbol not found\n");
    }
    return 0;
}
