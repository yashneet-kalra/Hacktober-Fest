
#include <stdio.h>
#include <string.h>
struct Item {
char item_name[20];

int id_num;

float latest_cost;

int number_of_items;

int number_of_items_sold;

float profit_from_sales;

};



void display(struct Item items[], int n);
void display_profit (struct Item items[], int n);
void add(struct Item items[], int n);
int add_new_items (struct Item items[], int n);
void saleitem(struct Item items[], int n);
void quit(struct Item items[], int n);

int main() {

struct Item items[10];

int count = 0;

FILE *fptr = fopen("inventorycontrol.txt", "r");

  

while(fptr && !feof(fptr)) {

fscanf(fptr, "%s %d %f %d %d %f", items[count].item_name, &items[count].id_num, &items[count].latest_cost, &items[count].number_of_items, &items[count].number_of_items_sold, &items[count].profit_from_sales);

if(feof(fptr)) {

break;

}

count++;

}

char choice;

do {


printf("\nMenu:\n");

printf("a. Show the name, identification number and number of each item in stock and cost of each item and profit value of each item.\n");

printf("b. Show the number of units sold of each item, th eprofit for each item in stock and total store profit\n");

printf("c. Order more of an existing item.\n");

printf("d. Order new items\n");

printf("e. Enter sale of an item\n");

printf("f. Quit\n");

printf("Enter your choice: ");

scanf(" %c", &choice);

switch (choice)

{

case 'a':

display(items, count);

break;

case 'b':

display_profit(items, count);

break;

case 'c':

add(items, count);

break;

case 'd':

count = add_new_items(items, count);

break;

case 'e':

saleitem(items, count);

break;
case 'f':
quit(items,count);


default:

break;

}

}while(choice != 'f' && choice != 'F');

fclose(fptr);

return 0;

}

// end of main()

void display(struct Item items[], int n) {

// function corresponding to switch case a

if(n == 0) {

printf("No items in inventory currently.\n");

return;

}

for(int i = 0; i < n; i++) {

printf("\nItem Name: %s", items[i].item_name);

printf("\nID: %d", items[i].id_num);

printf("\nNumber of units in Stock: %d", items[i].number_of_items);

printf("\nCost per unit: %.2f", items[i].latest_cost);

printf("\nProfit Value: %.2f\n", items[i].profit_from_sales);

}

}

void display_profit(struct Item items[], int n) {

// function corresponding to switch case b

if(n == 0) {

printf("No items in inventory currently.\n");

return;

}

float total_store_profit = 0;

for(int i = 0; i < n; i++) {

printf("\nItem Name: %s", items[i].item_name);

printf("\nNumber of units sold: %d", items[i].number_of_items_sold);

printf("\nProfit Value: %.2f\n", items[i].profit_from_sales);

total_store_profit += items[i].profit_from_sales;

}

printf("\nTotal Store profit = %.2f\n", total_store_profit);

}

void add(struct Item items[], int n) {

// function corresponding to switch case c

int add_on;

char item[20];

printf("Enter the name of item for which you want to order more items: ");

scanf(" %s", item);

for(int i = 0; i < n; i++) {

if(strcmp(item, items[i].item_name) == 0) {

printf("How many more units you want to order? ");

scanf("%d", &add_on);

items[i].number_of_items += add_on;

printf("Order successful!\n");

return;

}

}

printf("Item does not exist in the inventory.\n");

}

int add_new_items(struct Item items[], int n) {

// function corresponding to switch case d

if(n == 10) {

printf("Inventory full. No more items can be added.\n");

return n;

}

printf("Enter item name: ");

scanf(" %s", (items[n].item_name));

printf("Enter identification number: ");

scanf("%d", &(items[n].id_num));

printf("Enter number of units in stock: ");

scanf("%d", &(items[n].number_of_items));

printf("Enter latest purchase price per unit: ");

scanf("%f", &items[n].latest_cost);

items[n].number_of_items_sold = 0;

items[n].profit_from_sales = 0;

n++;

printf("Item added to the inventory.\n");

return n;

}

void saleitem(struct Item items[], int n) {

// function corresponding to switch case e

int sale_units;

char item[20];

printf("Enter the name of item for which you want to enter sales for: ");

scanf(" %s", item);

for(int i = 0; i < n; i++) {

if(strcmp(item, items[i].item_name) == 0) {

printf("How many more units were sold? ");

scanf("%d", &sale_units);

items[i].number_of_items -= sale_units;

items[i].number_of_items_sold += sale_units;

items[i].profit_from_sales += (sale_units * (items[i].latest_cost/2));

printf("Successful!\n");

return;

}

}

printf("Item does not exist in the inventory.\n");

  

}

void quit(struct Item items[], int n) {



FILE *fp1 = fopen("inventorycontrol.txt", "wt");

for(int i = 0; i < n; i++) {

fprintf(fp1, "%s\t%d\t", items[i].item_name, items[i].id_num );

fprintf(fp1, "%.2f\t%d\t", items[i].latest_cost, items[i].number_of_items);

fprintf(fp1, "%d\t%.2f\n", items[i].number_of_items_sold, items[i].profit_from_sales);

}

fclose(fp1);

}
