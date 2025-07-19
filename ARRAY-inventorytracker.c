#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
} Item;

Item inventory[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS){
        printf("Inventory is full!\n");
        return;
    }

    printf("Enter item name: ");
    scanf(" %[^\n]", inventory[itemCount].name);

    printf("Enter quantity: ");
    scanf("%d", &inventory[itemCount].quantity);

    itemCount++;
    printf("Item added successfully!\n\n");
}

void updateItem(){
    char name[NAME_LENGTH];
    printf("Enter item name to update: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < itemCount; i++){
        if (strcmp(inventory[i].name, name) == 0){
            printf("Current quantity: %d\n", inventory[i].quantity);
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Item updated successfully!\n\n");
            return;
        }
    }
    printf("Item not found!\n\n");
}

void displayInventory() {
    printf("\n--- INVENTORY ---\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item %d: %s - %d units\n", i + 1, inventory[i].name, inventory[i].quantity);
    }
    printf("\n");
}

void searchItem() {
    char name[NAME_LENGTH];
    printf("Enter item name to search: ");
    scanf(" %[^\n]", name);

    for (int i = 0; i < itemCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            printf("Found: %s - %d units\n\n", inventory[i].name, inventory[i].quantity);
            return;
        }
    }
    printf("Item not found!\n\n");
}

int main() {
    int choice;

    while (1) {
        printf("=== Inventory Tracker ===\n");
        printf("1. Add Item\n2. Update Quantity\n3. Display Inventory\n4. Search Item\n5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addItem(); break;
            case 2: updateItem(); break;
            case 3: displayInventory(); break;
            case 4: searchItem(); break;
            case 5: return 0;
            default: printf("Invalid choice.\n");
        }
    }

    return 0;
}

